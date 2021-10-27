#pragma once
#include "controller/InputProcessBase.h"
#include <model/ClassField.h>
#include <model/ClassBase.h>

namespace controller
{
	class CreateClassFieldProcess : public InputProcessBase
	{
	public:

		CreateClassFieldProcess(UMLController* controller, std::shared_ptr<model::ClassBase>* class_base, std::shared_ptr<model::UMLDiagram>* diagram);

		int Process() override;

	private:

		std::shared_ptr<model::ClassBase>* m_class;
		std::shared_ptr<model::UMLDiagram>* m_diagram;
	};
}
