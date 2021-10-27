#include "controller/CreateInterfaceProcess.h"

namespace controller
{
	CreateInterfaceProcess::CreateInterfaceProcess(UMLController* controller, std::shared_ptr<model::UMLDiagram>* diagram)
		: InputParentProcess(controller), m_diagram(diagram)
	{
		m_children = InputParentProcess::ChildrenMap
		{
			// TODO
		};
	}

	// ----------------------------------------------------------------------------------------- //
	int CreateInterfaceProcess::PreProcess()
	{
		// Get Type
		std::string type = input("Type: ");
		if (!isAlphaNumeric(type))
		{
			debug("'" + type + "' is not Alpha Numeric...");
			return 1;
		}

		// Construct & Verify
		m_interface = std::make_shared<model::UMLInterface>(type);
		if (!(*m_diagram)->addEntity(m_interface))
		{
			debug("Interface already exists...");
			return 2;
		}

		return 0;
	}

	// ----------------------------------------------------------------------------------------- //
	int CreateInterfaceProcess::PostProcess()
	{
		// TODO ?

		return 0;
	}
}
