#include "controller/CreateClassProcess.h"

namespace controller
{
	CreateClassProcess::CreateClassProcess(UMLController* controller, std::shared_ptr<model::UMLDiagram>* diagram)
		: InputParentProcess(controller), m_diagram(diagram)
	{
		m_children = InputParentProcess::ChildrenMap
		{
			// TODO
		};
	}

	// ----------------------------------------------------------------------------------------- //
	int CreateClassProcess::PreProcess()
	{
		// Get Type
		std::string type = input("Type: ");
		if (!isAlphaNumeric(type))
		{
			debug("'" + type + "' is not Alpha Numeric...");
			return 1;
		}

		// Construct & Verify
		m_class = std::make_shared<model::UMLClass>(type);
		if (!(*m_diagram)->addEntity(m_class))
		{
			debug("Class already exists...");
			return 2;
		}

		return 0;
	}

	// ----------------------------------------------------------------------------------------- //
	int CreateClassProcess::PostProcess()
	{
		// TODO ?

		return 0;
	}
}
