#include "controller/CreateClassFieldProcess.h"

namespace controller
{
	CreateClassFieldProcess::CreateClassFieldProcess(UMLController* controller, const std::shared_ptr<model::ClassBase>& class_base, const std::shared_ptr<model::UMLDiagram>& diagram)
		: InputProcessBase(controller), m_class(class_base), m_diagram(diagram)
	{
	}

	// ----------------------------------------------------------------------------------------- //
	int CreateClassFieldProcess::Process()
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
		auto field = std::make_shared<model::ClassField>(name, type, visibility, m_class->getType());
		if (!m_class->addMember(field))
		{
			debug("Field already exists...");
			return 4;
		}

		m_diagram->addEntity(field);
		return 0;
	}
}
