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
		if (method_index > 0)
		{
			field_result = m_members[0]->toString();

			for (size_t ii = 1; ii < method_index; ++ii)
			{
				field_result += ("\\l" + m_members[ii]->toString());
			}
		}

		// Create the Method vector string result
		std::string method_result;
		if (method_index < size - 1)
		{
			method_result = m_members[method_index]->toString();

			for (size_t ii = method_index; ii < size; ++ii)
			{
				method_result += ("\\l" + m_members[ii]->toString());
			}
		}

		// Create the final string result
		std::string result = "{" +
			this->title() + m_type +									// Title
			(field_result.empty() ? "" : "|" + field_result) +			// Fields
			(method_result.empty() ? "" : "|" + method_result) + "}";	// Methods

		// Create & Complete the Graph node
		m_node = agnode(graph, &m_type[0], 1);
		agsafeset(m_node, &m_type[0], result.c_str(), (char*)"");
	}
}
