#include "model/AssociationLink.h"

namespace model
{
	AssociationLink::AssociationLink(const std::shared_ptr<UMLNode>& origin, const std::shared_ptr<UMLNode>& target, const Cardinal& originCardinal, const Cardinal& targetCardinal)
		: m_originCardinal(originCardinal), m_targetCardinal(targetCardinal), UMLLink(origin, target, "association",
			(originCardinal.getTag().empty() && targetCardinal.getTag().empty() ? newUID() :
				origin->getLinkUID() + "." + target->getLinkUID() + "." + originCardinal.getTag() + "." + targetCardinal.getTag()))
	{
	}

	// ----------------------------------------------------------------------------------------- //
	void AssociationLink::render(Agraph_t* graph)
	{
		if (m_origin->getNode() != nullptr && m_target->getNode() != nullptr)
		{
			m_edge = agedge(graph, m_origin->getNode(), m_target->getNode(), nullptr, 1);
			agsafeset(m_edge, (char*)"arrowtail", (char*)"none", (char*)"");
			agsafeset(m_edge, (char*)"arrowhead", (char*)"none", (char*)"");
			agsafeset(m_edge, (char*)"taillabel", &(m_originCardinal.toString()[0]), (char*)"");
			agsafeset(m_edge, (char*)"headlabel", &(m_targetCardinal.toString()[0]), (char*)"");
		}
	}

	// ----------------------------------------------------------------------------------------- //
	Cardinal AssociationLink::getOriginCardinal() const
	{
		return m_originCardinal;
	}

	// ----------------------------------------------------------------------------------------- //
	Cardinal AssociationLink::getTargetCardinal() const
	{
		return m_targetCardinal;
	}

	// ----------------------------------------------------------------------------------------- //
	void AssociationLink::registerMap()
	{
		m_maps->add(NodeMapper::Type::ASSOCIATION, m_origin->getLinkUID(), m_target, m_targetCardinal);
		m_maps->add(NodeMapper::Type::ASSOCIATION, m_target->getLinkUID(), m_origin, m_originCardinal);
	}

	// ----------------------------------------------------------------------------------------- //
	void AssociationLink::unregisterMap()
	{
		m_maps->remove(NodeMapper::Type::ASSOCIATION, m_origin->getLinkUID());
		m_maps->remove(NodeMapper::Type::ASSOCIATION, m_target->getLinkUID());
	}
}
