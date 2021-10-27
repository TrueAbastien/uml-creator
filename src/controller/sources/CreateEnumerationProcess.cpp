#include "controller/CreateEnumerationProcess.h"

namespace controller
{
	CreateEnumerationProcess::CreateEnumerationProcess(UMLController* controller, std::shared_ptr<model::UMLDiagram>* diagram)
		: InputParentProcess(controller), m_diagram(diagram)
	{
		m_children = InputParentProcess::ChildrenMap
		{
			// TODO
		};
	}

	// ----------------------------------------------------------------------------------------- //
	int CreateEnumerationProcess::PreProcess()
	{
		// Get Type
		std::string type = input("Type: ");
		if (!isAlphaNumeric(type))
		{
			debug("'" + type + "' is not Alpha Numeric...");
			return 1;
		}

		// Construct & Verify
		m_enumeration = std::make_shared<model::UMLEnumeration>(type);
		if (!(*m_diagram)->addEntity(m_enumeration))
		{
			debug("Enumeration already exists...");
			return 2;
		}

		return 0;
	}

	// ----------------------------------------------------------------------------------------- //
	int CreateEnumerationProcess::PostProcess()
	{
		// TODO ?

		return 0;
	}
}
