#pragma once
#include "controller/InputProcessBase.h"
#include <model/Cardinal.h>

namespace controller
{
	class CreateObjectLinkCardinalProcess : public InputProcessBase
	{
	public:

		CreateObjectLinkCardinalProcess(UMLController* controller, model::Cardinal* output);

		int Process() override;

	private:

		model::Cardinal* m_output;
	};
}
