#include "model/CompositionLink.h"

namespace model
{
	CompositionLink::CompositionLink(const std::shared_ptr<UMLNode>& origin, const std::shared_ptr<UMLNode>& target, const Cardinal& cardinal)
		: ComposerLink(origin, target, cardinal, "composition")
	{
	}

	// ----------------------------------------------------------------------------------------- //
	void CompositionLink::render(Agraph_t* graph)
	{
		if (m_origin->getNode() != nullptr && m_target->getNode() != nullptr)
		{
			m_edge = agedge(graph, m_origin->getNode(), m_target->getNode(), nullptr, 1);
			agsafeset(m_edge, (char*)"arrowtail", (char*)"diamond", (char*)"");
			agsafeset(m_edge, (char*)"arrowhead", (char*)"none", (char*)"");
			agsafeset(m_edge, (char*)"headlabel", &(m_cardinal.toString()[0]), (char*)"");
		}
	}
}
