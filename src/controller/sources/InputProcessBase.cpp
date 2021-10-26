#include "controller\InputProcessBase.h"

namespace controller
{
	InputProcessBase::InputProcessBase(UMLController* controller)
		: m_controller(controller)
	{
	}

	// ----------------------------------------------------------------------------------------- //
	bool InputProcessBase::isAlphaNumeric(const std::string& input) const
	{
		// Verify not Empty
		if (input.empty())
		{
			return false;
		}

		// First Character a-z, A-Z, _
		char fc = input[0];
		if ((fc < 'a' || fc > 'z')
			&& (fc < 'A' || fc > 'Z')
			&& (fc != '_'))
		{
			return false;
		}

		// Other Characters a-z, A-Z, 0-9, _
		size_t size = input.size();
		for (size_t ii = 1; ii < size; ++ii)
		{
			char c = input[ii];
			if ((c < 'a' || c > 'z')
				&& (c < 'A' || c > 'Z')
				&& (c < '0' || c > '9')
				&& (c != '_'))
			{
				return false;
			}
		}

		return true;
	}

	// ----------------------------------------------------------------------------------------- //
	bool InputProcessBase::isNumeric(const std::string& input) const
	{
		if (input.empty())
		{
			return false;
		}
		for (char c : input)
		{
			if (c < '0' || c > '9')
			{
				return false;
			}
		}
		return true;
	}

	// ----------------------------------------------------------------------------------------- //
	void InputProcessBase::debug(const std::string& message)
	{
		m_controller->getView()->display(message);
	}

	// ----------------------------------------------------------------------------------------- //
	std::string InputProcessBase::input(const std::string& message) const
	{
		return m_controller->getView()->ask(message);
	}

	// ----------------------------------------------------------------------------------------- //
	model::ModelPtr InputProcessBase::model() const
	{
		return m_controller->getModel();
	}
}

