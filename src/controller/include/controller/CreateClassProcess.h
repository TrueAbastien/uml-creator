#pragma once
#include "controller/InputParentProcess.h"
#include <model/UMLClass.h>

namespace controller
{
	class CreateClassProcess : public InputParentProcess
	{
	public:

		CreateClassProcess(UMLController* controller, std::shared_ptr<model::UMLDiagram>* diagram);

	protected:

		int PreProcess() override;
		int PostProcess() override;

	private:

		std::shared_ptr<model::UMLDiagram>* m_diagram;
		std::shared_ptr<model::UMLClass> m_class;
	};
}
