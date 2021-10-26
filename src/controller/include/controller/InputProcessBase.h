#pragma once
#include "controller/UMLController.h"
#include <core/Definitions.h>

namespace controller
{
	class InputProcessBase
	{
	protected:

		InputProcessBase(UMLController* controller);

	public:

		virtual int Process() = 0;

	protected:

		UMLController* m_controller;
	};
}
