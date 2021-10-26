#include "controller/CreateClassLinkCardinalProcess.h"

namespace controller
{
	CreateClassLinkCardinalProcess::CreateClassLinkCardinalProcess(UMLController* controller, model::Cardinal* output)
		: InputProcessBase(controller), m_output(output)
	{
	}

	// ----------------------------------------------------------------------------------------- //
	int CreateClassLinkCardinalProcess::Process()
	{
		// Get Tag
		std::string tag = input("Tag: ");
		if (!tag.empty() && !isAlphaNumeric(tag))
		{
			debug("'" + tag + "' tag is not Alpha Numeric...");
			return 1;
		}

		// Get Min
		std::string min_str = input("Lower: ");
		int min = model::Cardinal::Null;
		if (!min_str.empty())
		{
			if (isNumeric(min_str))
			{
				min = std::atoi(min_str.c_str());
			}
			else
			{
				debug("'" + min_str + "' couldn't be parsed...");
				return 2;
			}
		}

		// Get Max
		std::string max_str = input("Upper: ");
		int max = model::Cardinal::Null;
		if (!max_str.empty())
		{
			if (max_str == "*")
			{
				max = model::Cardinal::Many;
			}
			else if (isNumeric(max_str))
			{
				max = std::atoi(max_str.c_str());
			}
			else
			{
				debug("'" + max_str + "' couldn't be parsed...");
				return 3;
			}
		}

		// Max/Min Verification
		if (min < max)
		{
			debug("Maximum value is lower than Minimum value...");
			return 4;
		}

		// Set Cardinal
		*m_output = model::Cardinal(min, max, tag);
		return 0;
	}
}
