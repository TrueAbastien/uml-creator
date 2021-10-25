#include "model\ClassBase.h"
#include <algorithm>

namespace model
{
	ClassBase::ClassBase(const std::string& kind, const std::string& other, const std::string& type)
		: m_members(0), UMLNode(kind, other, type)
	{
	}

	// ----------------------------------------------------------------------------------------- //
	std::string ClassBase::title() const
	{
		return "";
	}

	// ----------------------------------------------------------------------------------------- //
	bool ClassBase::addMember(const std::shared_ptr<Member>& member)
	{
		for (auto m : m_members)
		{
			if (m->isEquals(member))
			{
				return false;
			}
		}

		m_members.push_back(member);
		return true;
	}

	// ----------------------------------------------------------------------------------------- //
	Member::Vector ClassBase::getMembers() const
	{
		return m_members;
	}

	// ----------------------------------------------------------------------------------------- //
	void ClassBase::render(Agraph_t* graph)
	{
		// Sort Members
		std::sort(m_members.begin(), m_members.end(),
			[](const std::shared_ptr<Member>& lm, const std::shared_ptr<Member>& rm)
			{
				return lm->memberTypeID() < rm->memberTypeID();
			}
		);

		// Find the first Method
		size_t size = m_members.size(), method_index = 0;
		for (; method_index < size; ++method_index)
		{
			if (m_members[method_index]->memberTypeID() >= (uint8_t)Member::Visibility::__size__)
			{
				break;
			}
		}

		// Create the Field vector string result
		std::string field_result;
		for (size_t ii = 0; ii < method_index; ++ii)
		{
			field_result += (m_members[ii]->toString() + "\\l");
		}

		// Create the Method vector string result
		std::string method_result;
		for (size_t ii = method_index; ii < size; ++ii)
		{
			method_result += (m_members[ii]->toString() + "\\l");
		}

		// Create the final string result
		std::string result = "{" +
			this->title() + m_type +									// Title
			(field_result.empty() ? "" : "|" + field_result) +			// Fields
			(method_result.empty() ? "" : "|" + method_result) + "}";	// Methods

		// Create & Complete the Graph node
		m_node = agnode(graph, &m_type[0], 1);
		agsafeset(m_node, (char*)"label", result.c_str(), (char*)"");
	}
}
