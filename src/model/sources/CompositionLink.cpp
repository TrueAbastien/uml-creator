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
			agsafeset(m_edge, (char*)"taillabel", &(m_cardinal.getTag()[0]), (char*)"");
			agsafeset(m_edge, (char*)"headlabel", &(m_cardinal.getRange()[0]), (char*)"");
		}
	}

	// ----------------------------------------------------------------------------------------- //
	void CompositionLink::registerMap()
	{
		m_maps->Add(NodeMapper::Type::COMPOSITION, m_origin->getType(), m_target);
	}

	// ----------------------------------------------------------------------------------------- //
	void CompositionLink::unregisterMap()
	{
		m_maps->Remove(NodeMapper::Type::COMPOSITION, m_origin->getType());
	}
}
