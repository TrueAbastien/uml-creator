#pragma once
#include "controller/InputProcessBase.h"
#include <model/UMLDiagram.h>
#include <model/ClassBase.h>
#include <model/ObjectField.h>

namespace controller
{
	class CreateObjectFieldProcess : public InputProcessBase
	{
	public:

		CreateObjectFieldProcess(UMLController* controller, std::shared_ptr<model::UMLDiagram>* diagram, std::shared_ptr<model::ClassBase>* object_base);

		int Process() override;

	private:

		std::shared_ptr<model::UMLDiagram>* m_diagram;
		std::shared_ptr<model::ClassBase>* m_object;
	};
}
