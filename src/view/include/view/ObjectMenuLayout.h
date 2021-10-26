#pragma once
#include "view/LayoutBase.h"

namespace view
{
	class ObjectMenuLayout : public LayoutBase
	{
	public:

		LAYOUT_CONSTRUCTOR(ObjectMenuLayout);

	protected:

		std::string headerMessage() const override;
		void render() override;
	};
}
