#pragma once
#include "model/UMLLink.h"
#include "model/Cardinal.h"

namespace model
{
	class AssociationLink : public UMLLink
	{
	public:

		AssociationLink(const std::shared_ptr<UMLNode>& origin, const std::shared_ptr<UMLNode>& target, const Cardinal& originCardinal, const Cardinal& targetCardinal);

		void render(Agraph_t* graph) override;

		Cardinal getOriginCardinal() const;
		Cardinal getTargetCardinal() const;

	private:

		Cardinal m_originCardinal;
		Cardinal m_targetCardinal;
	};
}
