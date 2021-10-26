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
	std::string UMLEnumeration::Item::getName() const
	{
		return m_name;
	}

	// ----------------------------------------------------------------------------------------- //
	UMLEnumeration::UMLEnumeration(const std::string& type)
		: UMLNode("enum", type, type)
	{
	}

	// ----------------------------------------------------------------------------------------- //
	void UMLEnumeration::render(Agraph_t* graph)
	{
		std::string result;
		size_t size = m_items.size();
		for (size_t ii = 0; ii < size; ++ii)
		{
			result += (m_items[ii]->toString() + "\\l");
		}

		result = "{\\<\\<enum\\>\\>\\n" + m_type + "|" + result + "}";

		m_node = agnode(graph, &m_type[0], 1);
		agsafeset(m_node, (char*)"label", result.c_str(), (char*)"");
	}

	// ----------------------------------------------------------------------------------------- //
	bool UMLEnumeration::add(const std::shared_ptr<Item>& item)
	{
		for (auto it : m_items)
		{
			if (it->getName() == item->getName())
			{
				return false;
			}
		}

		m_items.push_back(item);
		return true;
	}
}
