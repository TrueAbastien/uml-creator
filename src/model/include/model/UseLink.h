#pragma once
#include "model/UMLLink.h"

namespace model
{
	class UseLink : public UMLLink
	{
	public:

		UseLink(const std::shared_ptr<UMLNode>& origin, const std::shared_ptr<UMLNode>& target);

		void render(Agraph_t* graph) override;
	};
}
