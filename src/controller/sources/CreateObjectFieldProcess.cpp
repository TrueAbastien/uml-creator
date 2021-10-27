#include "controller/CreateObjectFieldProcess.h"

namespace controller
{
	CreateObjectFieldProcess::CreateObjectFieldProcess(UMLController* controller, std::shared_ptr<model::UMLDiagram>* diagram, std::shared_ptr<model::ClassBase>* object_base)
		: InputProcessBase(controller), m_diagram(diagram), m_object(object_base)
	{
	}

	// ----------------------------------------------------------------------------------------- //
	int CreateObjectFieldProcess::Process()
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

		// Get Value
		std::string value = input("Value: ");
		// TODO ?

		// Get Visibility
		std::string visi_str = input("Visibility: ");
		model::Member::Visibility visibility;
		if (visi_str == "private") visibility = model::Member::Visibility::PRIVATE;
		else if (visi_str == "protected") visibility = model::Member::Visibility::PROTECTED;
		else if (visi_str == "public") visibility = model::Member::Visibility::PUBLIC;
		else
		{
			debug("'" + visi_str + "' is not a valid Visibility...");
			return 3;
		}

		// Verify Field
		auto field = std::make_shared<model::ObjectField>(name, type, visibility, value, (*m_object)->getType());
		if (!(*m_object)->addMember(field) || !(*m_diagram)->addEntity(field))
		{
			debug("Field already exists...");
			return 4;
		}

		return 0;
	}
}
