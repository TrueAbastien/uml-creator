#include "controller/CreateMethodProcess.h"

namespace controller
{
	CreateMethodProcess::CreateMethodProcess(UMLController* controller, std::shared_ptr<model::UMLDiagram>* diagram, std::shared_ptr<model::ClassBase>* class_base)
		: CreateMethodProcess(controller, diagram)
	{
		m_class = class_base;
		m_interface = nullptr;
	}

	// ----------------------------------------------------------------------------------------- //
	CreateMethodProcess::CreateMethodProcess(UMLController* controller, std::shared_ptr<model::UMLDiagram>* diagram, std::shared_ptr<model::UMLInterface>* interface_base)
		: CreateMethodProcess(controller, diagram)
	{
		m_class = nullptr;
		m_interface = interface_base;
	}

	// ----------------------------------------------------------------------------------------- //
	CreateMethodProcess::CreateMethodProcess(UMLController* controller, std::shared_ptr<model::UMLDiagram>* diagram)
		: InputParentProcess(controller), m_diagram(diagram)
	{
		m_children = InputParentProcess::ChildrenMap
		{
			// TODO
		};
	}

	// ----------------------------------------------------------------------------------------- //
	int CreateMethodProcess::PreProcess()
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

		// Verify Method
		if (m_class != nullptr)
		{
			m_method = std::make_shared<model::Method>(name, type, visibility, (*m_class)->getType());
			if (!(*m_class)->addMember(m_method) || !(*m_diagram)->addEntity(m_method))
			{
				debug("Method already exists...");
				return 5;
			}
		}
		else if (m_interface != nullptr)
		{
			m_method = std::make_shared<model::Method>(name, type, visibility, (*m_interface)->getType());
			if (!(*m_interface)->addMethod(m_method) || !(*m_diagram)->addEntity(m_method))
			{
				debug("Method already exists...");
				return 6;
			}
		}
		else
		{
			debug("No Node given to the Method Process...");
			return 4;
		}

		return 0;
	}

	// ----------------------------------------------------------------------------------------- //
	int CreateMethodProcess::PostProcess()
	{
		// TODO ?

		return 0;
	}
}
