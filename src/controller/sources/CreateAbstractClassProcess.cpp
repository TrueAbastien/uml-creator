#include "controller/CreateAbstractClassProcess.h"

namespace controller
{
	CreateAbstractClassProcess::CreateAbstractClassProcess(UMLController* controller, std::shared_ptr<model::UMLDiagram>* diagram)
		: InputParentProcess(controller), m_diagram(diagram)
	{
		m_children = InputParentProcess::ChildrenMap
		{
			// TODO
		};
	}

	// ----------------------------------------------------------------------------------------- //
	int CreateAbstractClassProcess::PreProcess()
	{
		// Get Type
		std::string type = input("Type: ");
		if (!isAlphaNumeric(type))
		{
			debug("'" + type + "' is not Alpha Numeric...");
			return 1;
		}

		// Construct & Verify
		m_class = std::make_shared<model::UMLAbstractClass>(type);
		if (!(*m_diagram)->addEntity(m_class))
		{
			debug("Abstract class already exists...");
			return 2;
		}

		return 0;
	}

	// ----------------------------------------------------------------------------------------- //
	int CreateAbstractClassProcess::PostProcess()
	{
		// TODO ?

		return 0;
	}
}
