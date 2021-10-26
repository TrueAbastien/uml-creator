#pragma once
#include "view/LayoutBase.h"

namespace view
{
	class CreateEntityLayout : public LayoutBase
	{
	public:

		LAYOUT_CONSTRUCTOR(CreateEntityLayout);

	protected:

		std::string headerMessage() const override;
		void render() override;
	};
}
