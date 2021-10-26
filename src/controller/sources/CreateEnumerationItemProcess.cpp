#include "controller/CreateEnumerationItemProcess.h"

namespace controller
{
	CreateEnumerationItemProcess::CreateEnumerationItemProcess(UMLController* controller, const std::shared_ptr<model::UMLEnumeration>& enumeration, const std::shared_ptr<model::UMLDiagram>& diagram)
		: InputProcessBase(controller), m_enumeration(enumeration), m_diagram(diagram)
	{
	}

	// ----------------------------------------------------------------------------------------- //
	int CreateEnumerationItemProcess::Process()
	{
		// Get Name
		std::string name = input("Name: ");
		if (!isAlphaNumeric(name))
		{
			debug("'" + name + "' is not Alpha Numeric...");
			return 1;
		}

		// Verify Unique
		auto item = std::make_shared<model::UMLEnumeration::Item>(name, m_enumeration->getType());
		if (!m_enumeration->add(item))
		{
			debug("'" + name + "' item already exists...");
			return 2;
		}

		m_diagram->addEntity(item);
		return 0;
	}
}
