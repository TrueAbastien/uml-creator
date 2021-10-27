#pragma once
#include "controller/InputParentProcess.h"
#include <model/Method.h>
#include <model/ClassBase.h>
#include <model/UMLInterface.h>

namespace controller
{
	class CreateMethodProcess : public InputParentProcess
	{
	public:

		CreateMethodProcess(UMLController* controller, std::shared_ptr<model::UMLDiagram>* diagram, std::shared_ptr<model::ClassBase>* class_base);
		CreateMethodProcess(UMLController* controller, std::shared_ptr<model::UMLDiagram>* diagram, std::shared_ptr<model::UMLInterface>* interface_base);

	protected:

		CreateMethodProcess(UMLController* controller, std::shared_ptr<model::UMLDiagram>* diagram);

		int PreProcess() override;
		int PostProcess() override;

	private:

		std::shared_ptr<model::ClassBase>* m_class;
		std::shared_ptr<model::UMLInterface>* m_interface;
		std::shared_ptr<model::UMLDiagram>* m_diagram;
		std::shared_ptr<model::Method> m_method;
	};
}
