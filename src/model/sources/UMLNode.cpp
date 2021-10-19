#include "model/UMLNode.h"

namespace model
{
	UMLNode::UMLNode(const std::string& kind, const std::string& type)
		: m_type(type), m_node(nullptr), UMLEntity(kind + "." + to_lower(type))
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
}
