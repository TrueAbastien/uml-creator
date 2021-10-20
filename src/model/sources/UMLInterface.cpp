#include "model/UMLInterface.h"

namespace model
{
	UMLInterface::UMLInterface(const std::string& type)
		: m_methods(0), UMLNode("interface", type, type)
	{
	}

	// ----------------------------------------------------------------------------------------- //
	bool UMLInterface::addMethod(const std::shared_ptr<Method>& method)
	{
		for (auto m : m_methods)
		{
			if (m->isEquals(method))
			{
				return false;
			}
		}

		m_methods.push_back(method);
		return true;
	}

	// ----------------------------------------------------------------------------------------- //
	void UMLInterface::render(Agraph_t* graph)
	{
		std::string result;
		if (!m_methods.empty())
		{
			result = m_methods[0]->toString();

			size_t size = m_methods.size();
			for (size_t ii = 1; ii < size; ++ii)
			{
				result += ("\\l" + m_methods[ii]->toString());
			}
		}

		result = "{<<interface>>\\l" + m_type + "|" + result + "}";

		m_node = agnode(graph, &m_type[0], 1);
		agsafeset(m_node, &m_type[0], result.c_str(), (char*)"");
	}

	// ----------------------------------------------------------------------------------------- //
	UMLNode::DefinitionType UMLInterface::getDefinitionType() const
	{
		return DefinitionType::INTERFACE;
	}
}
