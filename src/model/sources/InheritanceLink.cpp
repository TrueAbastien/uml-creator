#include "model/InheritanceLink.h"

namespace model
{
	InheritanceLink::InheritanceLink(const std::shared_ptr<UMLNode>& origin, const std::shared_ptr<UMLNode>& target)
		: UMLLink(origin, target, "inheritance", origin->getLinkUID() + "." + target->getLinkUID())
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
				m_edge = agedge(graph, m_target->getNode(), m_origin->getNode(), nullptr, 1);
				agsafeset(m_edge, (char*)"arrowhead", (char*)"none", (char*)"");

				if (type == UMLNode::DefinitionType::INTERFACE)
				{
					agsafeset(m_edge, (char*)"arrowtail", (char*)"empty", (char*)"");
					agsafeset(m_edge, (char*)"style", (char*)"dashed", (char*)"");
					agsafeset(m_edge, (char*)"label", (char*)"implements", (char*)"");
				}
				else
				{
					agsafeset(m_edge, (char*)"arrowtail", (char*)"normal", (char*)"");
					agsafeset(m_edge, (char*)"style", (char*)"solid", (char*)"");
				}
			}
		}
	}

	// ----------------------------------------------------------------------------------------- //
	void InheritanceLink::registerMap()
	{
		m_maps->add(NodeMapper::Type::INHERITAGE, m_origin->getLinkUID(), m_target, Cardinal());
	}

	// ----------------------------------------------------------------------------------------- //
	void InheritanceLink::unregisterMap()
	{
		m_maps->remove(NodeMapper::Type::INHERITAGE, m_origin->getLinkUID());
	}
}
