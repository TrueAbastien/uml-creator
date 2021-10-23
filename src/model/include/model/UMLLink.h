#pragma once
#include "model/UMLEntity.h"
#include "model/UMLNode.h"

namespace model
{
	class UMLLink : public UMLEntity
	{
	protected:

		UMLLink(const std::shared_ptr<UMLNode>& origin, const std::shared_ptr<UMLNode>& target, const std::string& kind, const std::string& other);

	public:

		Agedge_t* getEdge() const;
		std::shared_ptr<UMLNode> getOrigin() const;
		std::shared_ptr<UMLNode> getTarget() const;

	protected:

		Agedge_t* m_edge;
		std::shared_ptr<UMLNode> m_origin, m_target;
	};
}
