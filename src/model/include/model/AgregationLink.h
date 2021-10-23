#pragma once
#include "model/ComposerLink.h"

namespace model
{
	class AgregationLink : public ComposerLink
	{
	public:

		AgregationLink(const std::shared_ptr<UMLNode>& origin, const std::shared_ptr<UMLNode>& target, const Cardinal& cardinal);

		void render(Agraph_t* graph) override;

	protected:

		void registerMap() override;
		void unregisterMap() override;
	};
}
