#include "model/UMLLink.h"

namespace model
{
	UMLLink::UMLLink(const std::shared_ptr<UMLNode>& origin, const std::shared_ptr<UMLNode>& target, const std::string& kind, const std::string& other)
		: m_origin(origin), m_target(target), m_edge(nullptr), UMLEntity("link." + kind + "." + to_lower(other))
	{
	}

	// ----------------------------------------------------------------------------------------- //
	Agedge_t* UMLLink::getEdge() const
	{
		return m_edge;
	}

	// ----------------------------------------------------------------------------------------- //
	std::shared_ptr<UMLNode> UMLLink::getOrigin() const
	{
		return m_origin;
	}

	// ----------------------------------------------------------------------------------------- //
	std::shared_ptr<UMLNode> UMLLink::getTarget() const
	{
		return m_target;
	}
}
