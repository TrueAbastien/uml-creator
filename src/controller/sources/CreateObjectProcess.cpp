#include "controller/CreateObjectProcess.h"

namespace controller
{
	CreateObjectProcess::CreateObjectProcess(UMLController* controller, std::shared_ptr<model::UMLDiagram>* diagram)
		: InputParentProcess(controller), m_diagram(diagram)
	{
		m_children = InputParentProcess::ChildrenMap
		{
			// TODO
		};
	}

	// ----------------------------------------------------------------------------------------- //
	int CreateObjectProcess::PreProcess()
	{
		// Get Name
		std::string name = input("Name: ");
		if (!isAlphaNumeric(name))
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

		// Construct & Verify
		m_object = std::make_shared<model::UMLObject>(name, type);
		if (!(*m_diagram)->addEntity(m_object))
		{
			debug("Object already exists...");
			return 3;
		}

		return 0;
	}

	// ----------------------------------------------------------------------------------------- //
	int CreateObjectProcess::PostProcess()
	{
		// TODO ?

		return 0;
	}
}
