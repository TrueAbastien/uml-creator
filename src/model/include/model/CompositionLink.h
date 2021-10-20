#pragma once
#include "model/ComposerLink.h"

namespace model
{
	class CompositionLink : public ComposerLink
	{
	public:

		CompositionLink(const std::shared_ptr<UMLNode>& origin, const std::shared_ptr<UMLNode>& target, const Cardinal& cardinal);

		void render(Agraph_t* graph) override;
	};
}
