#pragma once
#include "view/LayoutBase.h"

namespace view
{
	class ModelMenuLayout : public LayoutBase
	{
	public:

		LAYOUT_CONSTRUCTOR(ModelMenuLayout);

	protected:

		std::string headerMessage() const override;
		void render() override;
	};
}
