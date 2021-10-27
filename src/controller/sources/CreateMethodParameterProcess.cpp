#include "controller/CreateMethodParameterProcess.h"

namespace controller
{
	CreateMethodParameterProcess::CreateMethodParameterProcess(UMLController* controller, std::shared_ptr<model::Method>* method, const std::shared_ptr<model::UMLDiagram>& diagram)
		: InputProcessBase(controller), m_method(method), m_diagram(diagram)
	{
	}

	// ----------------------------------------------------------------------------------------- //
	int CreateMethodParameterProcess::Process()
	{
		// Get Name
		std::string name = input("Name: ");
		if (!name.empty() && !isAlphaNumeric(name))
		{
			debug("'" + name + "' is not Alpha Numeric...");
			return 1;
		}

		// Get Type
		std::string type = input("Type: ");
		if (!isAlphaNumeric(type))
		{
			debug("'" + type + "' is not Alpha Numeric...");
			return 2;
		}

		// Verify Type
		auto param = std::make_shared<model::Parameter>(type, (*m_method)->getName(), name);
		if (!(*m_method)->addParam(param) ||!m_diagram->addEntity(param))
		{
			debug("Parameter already exists...");
			return 3;
		}

		return 0;
	}
}
