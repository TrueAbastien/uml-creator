#pragma once
#include "view/LayoutBase.h"

namespace view
{
	class LoadObjectLayout : public LayoutBase
	{
	public:

		LAYOUT_CONSTRUCTOR(LoadObjectLayout);

	protected:

		std::string headerMessage() const override;
		void render() override;
	};
}
