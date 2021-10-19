#include "model/UMLEnumeration.h"

namespace model
{
	UMLEnumeration::Item::Item(const std::string& name, const std::string& enumName)
		: m_name(name), UMLEntity("enum_item." + to_lower(enumName) + "." + to_lower(name))
	{
	}

	// ----------------------------------------------------------------------------------------- //
	void UMLEnumeration::Item::render(Agraph_t* graph)
	{
	}

	// ----------------------------------------------------------------------------------------- //
	std::string UMLEnumeration::Item::toString() const
	{
		return "+ " + m_name;
	}

	// ----------------------------------------------------------------------------------------- //
	UMLEnumeration::UMLEnumeration(const std::string& type)
		: UMLNode("enum", type)
	{
	}

	// ----------------------------------------------------------------------------------------- //
	void UMLEnumeration::render(Agraph_t* graph)
	{
		std::string result;
		if (!m_items.empty())
		{
			result = m_items[0]->toString();

			size_t size = m_items.size();
			for (size_t ii = 1; ii < size; ++ii)
			{
				result += ("\\l" + m_items[ii]->toString());
			}
		}

		result = "{<<enum>>\\l" + m_type + "|" + result + "}";

		m_node = agnode(graph, &m_type[0], 1);
		agsafeset(m_node, &m_type[0], result.c_str(), (char*)"");
	}
}
