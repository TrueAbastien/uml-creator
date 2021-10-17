#pragma once
#include "controller/UMLController.h"
#include <core/Definitions.h>

namespace controller
{
	class InputProcessBase
	{
	public:

		InputProcessBase(UMLController* controller);

		virtual int Process() = 0;

	protected:

		UMLController* m_controller;
	};
}
