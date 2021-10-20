#include "model/InheritanceLink.h"

namespace model
{
	InheritanceLink::InheritanceLink(const std::shared_ptr<UMLNode>& origin, const std::shared_ptr<UMLNode>& target)
		: UMLLink(origin, target, "inheritance", origin->getType() + "." + target->getType())
	{
	}

	// ----------------------------------------------------------------------------------------- //
	void InheritanceLink::render(Agraph_t* graph)
	{
		if (m_origin->getNode() != nullptr && m_target->getNode() != nullptr)
		{
			auto type = m_target->getDefinitionType();
			if ((uint8_t)type >= (uint8_t)m_origin->getDefinitionType())
			{
				m_edge = agedge(graph, m_origin->getNode(), m_target->getNode(), nullptr, 1);
				agsafeset(m_edge, (char*)"arrowtail", (char*)"none", (char*)"");

				if (type == UMLNode::DefinitionType::INTERFACE)
				{
					agsafeset(m_edge, (char*)"arrowhead", (char*)"empty", (char*)"");
					agsafeset(m_edge, (char*)"style", (char*)"dashed", (char*)"");
					agsafeset(m_edge, (char*)"label", (char*)"implements", (char*)"");
				}
				else
				{
					agsafeset(m_edge, (char*)"arrowhead", (char*)"normal", (char*)"");
					agsafeset(m_edge, (char*)"style", (char*)"solid", (char*)"");
				}
			}
		}
	}
}
