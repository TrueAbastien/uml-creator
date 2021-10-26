#pragma once
#include "view/LayoutBase.h"

namespace view
{
	class ExportLayout : public LayoutBase
	{
	public:

		LAYOUT_CONSTRUCTOR(ExportLayout);

	protected:

		std::string headerMessage() const override;
		void render() override;
	};
}
