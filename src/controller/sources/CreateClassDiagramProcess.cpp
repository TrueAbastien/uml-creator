#include "controller\CreateClassDiagramProcess.h"

namespace controller
{
	int CreateClassDiagramProcess::PreProcess()
	{
		// Get Name
		std::string name = input("Name: ");
		if (!isAlphaNumeric(name))
		{
			debug("'" + name + "' is not Alpha Numeric...");
			return 1;
		}

		// Construct Diagram
		m_diagram = std::make_shared<model::ClassDiagram>(name);
		if (model()->exists(m_diagram))
		{
			debug("'" + name + "' is already used...");
			return 2;
		}

		// Get Input
		awaitsID();

		return 0;
	}

	// ----------------------------------------------------------------------------------------- //
	int CreateClassDiagramProcess::PostProcess()
	{
		// Add Diagram
		if (!model()->add(m_diagram))
		{
			// TODO: Class Menu Interpreter

			debug("Created Diagram couldn't be added !");
			return 1;
		}

		// TODO: Object Menu Interpreter
		// TODO: Set Model
		return 0;
	}

	// ----------------------------------------------------------------------------------------- //
	CreateClassDiagramProcess::CreateClassDiagramProcess(UMLController* controller)
		: InputParentProcess(controller), m_diagram(nullptr)
	{
		m_children = InputParentProcess::ChildrenMap
		{
			// TODO
		};
	}
}
