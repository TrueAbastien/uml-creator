#include "model/UMLObject.h"

namespace model
{
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
			logs += "'" + m_type + "' doesn't exist...\n";
			return 1;
		}
		if (ref->getDefinitionType() != UMLNode::DefinitionType::CONCRETE)
		{
			logs += "'" + m_name + "' belongs to an abstract type...\n";
			return 2;
		}

		// Verify Attributes Recursively
		// TODO

		// Verify Associations Recursively
		// TODO

		return 0;
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
