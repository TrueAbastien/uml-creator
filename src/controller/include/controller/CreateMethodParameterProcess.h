#pragma once
#include "controller/InputProcessBase.h"
#include <model/Parameter.h>
#include <model/Method.h>

namespace controller
{
	class CreateMethodParameterProcess : public InputProcessBase
	{
	public:

		CreateMethodParameterProcess(UMLController* controller, std::shared_ptr<model::Method>* method, std::shared_ptr<model::UMLDiagram>* diagram);

		int Process() override;

	private:

		std::shared_ptr<model::Method>* m_method;
		std::shared_ptr<model::UMLDiagram>* m_diagram;
	};
}

