#include "controller/CreateObjectDiagramProcess.h"

namespace controller
{
	CreateObjectDiagramProcess::CreateObjectDiagramProcess(UMLController* controller)
		: InputParentProcess(controller)
	{
		m_children = InputParentProcess::ChildrenMap
		{
			// TODO
		};
	}

	// ----------------------------------------------------------------------------------------- //
	int CreateObjectDiagramProcess::PreProcess()
	{
		// Get Name
		std::string name = input("Name: ");
		if (!isAlphaNumeric(name))
		{
			debug("'" + name + "' is not Alpha Numeric...");
			return 1;
		}

		// Construct Diagram
		m_diagram = std::make_shared<model::ObjectDiagram>(model()->getClassModel(), name);
		if (model()->exists(m_diagram))
		{
			debug("'" + name + "' is already used...");
			return 2;
		}

		return 0;
	}

	// ----------------------------------------------------------------------------------------- //
	int CreateObjectDiagramProcess::PostProcess()
	{
		// TODO: Object Menu Interpreter
		
		// Add Diagram
		if (!model()->add(m_diagram))
		{
			debug("Created Diagram couldn't be added !");
			return 1;
		}
		
		return 0;
	}
}
