#pragma once
#include "view/LayoutBase.h"

namespace view
{
	class LoadModelLayout : public LayoutBase
	{
	public:

		LAYOUT_CONSTRUCTOR(LoadModelLayout);

	protected:

		std::string headerMessage() const override;
		void render() override;
	};
}
