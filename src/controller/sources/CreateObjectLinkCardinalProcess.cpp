#include "controller/CreateObjectLinkCardinalProcess.h"

namespace controller
{
	CreateObjectLinkCardinalProcess::CreateObjectLinkCardinalProcess(UMLController* controller, model::Cardinal* output)
		: InputProcessBase(controller), m_output(output)
	{
	}

	// ----------------------------------------------------------------------------------------- //
	int CreateObjectLinkCardinalProcess::Process()
	{
		// Get Tag
		std::string tag = input("Tag: ");
		if (!tag.empty() && !isAlphaNumeric(tag))
		{
			debug("'" + tag + "' tag is not Alpha Numeric...");
			return 1;
		}

		// Set Cardinal
		*m_output = model::Cardinal(model::Cardinal::Null, tag);
		return 0;
	}
}
