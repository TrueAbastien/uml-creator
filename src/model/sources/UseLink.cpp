#include "model/UseLink.h"

namespace model
{
	UseLink::UseLink(const std::shared_ptr<UMLNode>& origin, const std::shared_ptr<UMLNode>& target)
		: UMLLink(origin, target, "use", origin->getType() + "." + target->getType())
	{
	}

	// ----------------------------------------------------------------------------------------- //
	void UseLink::render(Agraph_t* graph)
	{
		if (m_origin->getNode() != nullptr && m_target->getNode() != nullptr)
		{
			m_edge = agedge(graph, m_origin->getNode(), m_target->getNode(), nullptr, 1);
			agsafeset(m_edge, (char*)"arrowtail", (char*)"none", (char*)"");
			agsafeset(m_edge, (char*)"arrowhead", (char*)"open", (char*)"");
			agsafeset(m_edge, (char*)"style", (char*)"dotted", (char*)"");
			agsafeset(m_edge, (char*)"label", (char*)"use", (char*)"");
		}
	}
}
