#pragma once
#include "view/LayoutBase.h"

namespace view
{
	class CreateModelLayout : public LayoutBase
	{
	public:

		LAYOUT_CONSTRUCTOR(CreateModelLayout);

	protected:

		std::string headerMessage() const override;
		void render() override;
	};
}
