#include "model/UMLObject.h"

namespace model
{
	Member::Vector::const_iterator UMLObject::matchingAttribute(const Member::Vector& attributes, const std::shared_ptr<Member>& attribute) const
	{
		for (int ii = 0; ii < attributes.size(); ++ii)
		{
			if (attributes[ii]->getName() == attribute->getName())
			{
				return attributes.begin() + ii;
			}
		}

		return attributes.end();
	}

	// ----------------------------------------------------------------------------------------- //
	int UMLObject::verifyAttributesFrom(const std::shared_ptr<NodeMapper>& maps, const Member::Vector& current_members, const std::string& current_id, Member::Vector& attributes, std::string& logs) const
	{
		// Verify Attributes
		{
			auto current_attributes = current_members;
			for (auto att : current_attributes)
			{
				if (att->memberTypeID() < (uint8_t)Member::Visibility::__size__)
				{
					auto attribute_it = matchingAttribute(attributes, att);
					if (attribute_it != attributes.end())
					{
						if (att->getType() == (*attribute_it)->getType())
						{
							attributes.erase(attribute_it);
						}
						else
						{
							logs += "'" + att->getName() + "' attribute is not of the right type.\n";
							return 1 << 2;
						}
					}
				}
			}
		}

		// Verify Parents
		auto parents = maps->get(NodeMapper::Type::INHERITAGE, current_id);
		int ec = 0;
		for (auto parent : parents)
		{
			ec |= verifyAttributesFrom(maps, parent.node->getMembers(), parent.node->getType(), attributes, logs);
		}

		return ec;
	}

	// ----------------------------------------------------------------------------------------- //
	UMLObject::UMLObject(const std::string& name, const std::string& type)
		: m_name(name), ClassBase("object", name, type)
	{
	}

	// ----------------------------------------------------------------------------------------- //
	bool UMLObject::addMember(const std::shared_ptr<Member>& member)
	{
		if (member->memberTypeID() < (uint8_t)Member::Visibility::__size__)
		{
			return ClassBase::addMember(member);
		}
		return false;
	}

	// ----------------------------------------------------------------------------------------- //
	std::string UMLObject::title() const
	{
		return m_name + ":";
	}

	// ----------------------------------------------------------------------------------------- //
	int UMLObject::verify(const std::shared_ptr<NodeMapper>& maps, std::string& logs) const
	{
		// Verify Type
		auto ref = maps->get(m_type);
		if (ref == nullptr)
		{
			logs += "'" + m_type + "' doesn't exist.\n";
			return 1;
		}
		if (ref->getDefinitionType() != UMLNode::DefinitionType::CONCRETE)
		{
			logs += "'" + m_name + "' belongs to an abstract type.\n";
			return 1 << 1;
		}

		// Verify Attributes Recursively
		auto attributes = m_members;
		for (int ii = 0; ii < attributes.size();)
		{
			if (attributes[ii]->memberTypeID() < (uint8_t)Member::Visibility::__size__)
			{
				attributes.erase(attributes.begin() + ii);
			}
			else ++ii;
		}
		int ec = verifyAttributesFrom(maps, m_maps->get(m_type)->getMembers(), m_type, attributes, logs);
		if (ec != 0)
		{
			return ec;
		}
		if (!attributes.empty())
		{
			logs += "'" + m_name + "' is missing some attributes.\n";
			return 1 << 3;
		}

		// Verify Any Association
		for (uint8_t ii = (uint8_t)NodeMapper::Type::ASSOCIATION; ii < (uint8_t)NodeMapper::Type::__size__; ++ii)
		{
			auto obj_associations = m_maps->get((NodeMapper::Type)ii, m_name);
			auto model_associations = maps->get((NodeMapper::Type)ii, m_type);

			for (auto model_assoc : model_associations)
			{
				std::string type_ref = model_assoc.node->getType();

				int counter = 0;
				for (size_t ii = 0; ii < obj_associations.size();)
				{
					if (obj_associations[ii].node->getType() == type_ref)
					{
						counter++;
						obj_associations.erase(obj_associations.begin() + ii);
					}
					else ++ii;
				}

				if (counter < model_assoc.cardinal.getMin())
				{
					logs += "'" + m_name + "' doesn't have enough '" + m_type + "' linked.\n";
					return 1 << 4;
				}
				else if (counter > model_assoc.cardinal.getMax())
				{
					logs += "'" + m_name + "' has too much '" + m_type + "' linked.\n";
					return 1 << 5;
				}

				if (obj_associations.size() > 0)
				{
					logs += "'" + m_name + "' has unspecified links.\n";
					return 1 << 6;
				}
			}
		}

		return 0;
	}

	// ----------------------------------------------------------------------------------------- //
	std::string UMLObject::getLinkUID() const
	{
		return m_name;
	}

	// ----------------------------------------------------------------------------------------- //
	void UMLObject::registerMap()
	{
		m_maps->set(m_name, this);
	}

	// ----------------------------------------------------------------------------------------- //
	void UMLObject::unregisterMap()
	{
		m_maps->remove(m_name);
	}
}
