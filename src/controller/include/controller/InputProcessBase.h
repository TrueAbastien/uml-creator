#pragma once
#include "controller/UMLController.h"
#include <core/Definitions.h>

namespace controller
{
	class InputProcessBase
	{
	protected:

		InputProcessBase(UMLController* controller);

		bool isAlphaNumeric(const std::string& input) const;
		bool isNumeric(const std::string& input) const;

		void debug(const std::string& message);
		std::string input(const std::string& message) const;
		model::ModelPtr model() const;

	public:

		virtual int Process() = 0;

	protected:

		UMLController* m_controller;
	};
}
