#include "model/UMLNode.h"

namespace model
{
	UMLNode::UMLNode(const std::string& kind, const std::string& other, const std::string& type)
		: m_type(type), m_node(nullptr), UMLEntity("node." + kind + "." + to_lower(other))
	{
	}

	// ----------------------------------------------------------------------------------------- //
	std::string UMLNode::getType() const
	{
		return m_type;
	}

	// ----------------------------------------------------------------------------------------- //
	Agnode_t* UMLNode::getNode() const
	{
		return m_node;
	}

	// ----------------------------------------------------------------------------------------- //
	UMLNode::DefinitionType UMLNode::getDefinitionType() const
	{
		return DefinitionType::CONCRETE;
	}
}
