#pragma once
#include "controller/InputProcessBase.h"
#include <model/Cardinal.h>

namespace controller
{
	class CreateClassLinkCardinalProcess : public InputProcessBase
	{
	public:

		CreateClassLinkCardinalProcess(UMLController* controller, model::Cardinal* output);

		int Process() override;

	private:

		model::Cardinal* m_output;
	};
}
