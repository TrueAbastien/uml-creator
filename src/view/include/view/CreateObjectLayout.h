#pragma once
#include "view/LayoutBase.h"

namespace view
{
	class CreateObjectLayout : public LayoutBase
	{
	public:

		LAYOUT_CONSTRUCTOR(CreateObjectLayout);

	protected:

		std::string headerMessage() const override;
		void render() override;
	};
}
