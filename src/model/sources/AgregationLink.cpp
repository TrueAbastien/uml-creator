#include "model/AgregationLink.h"

namespace model
{
	AgregationLink::AgregationLink(const std::shared_ptr<UMLNode>& origin, const std::shared_ptr<UMLNode>& target, const Cardinal& cardinal)
		: ComposerLink(origin, target, cardinal, "agregation")
	{
	}

	// ----------------------------------------------------------------------------------------- //
	void AgregationLink::render(Agraph_t* graph)
	{
		if (m_origin->getNode() != nullptr && m_target->getNode() != nullptr)
		{
			m_edge = agedge(graph, m_origin->getNode(), m_target->getNode(), nullptr, 1);
			agsafeset(m_edge, (char*)"arrowtail", (char*)"ediamond", (char*)"");
			agsafeset(m_edge, (char*)"arrowhead", (char*)"none", (char*)"");
			agsafeset(m_edge, (char*)"headlabel", &(m_cardinal.toString()[0]), (char*)"");
		}
	}
}
