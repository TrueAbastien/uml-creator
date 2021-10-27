#pragma once
#include "controller/InputParentProcess.h"
#include <model/UMLDiagram.h>
#include <model/UMLInterface.h>

namespace controller
{
	class CreateInterfaceProcess : public InputParentProcess
	{
	public:

		CreateInterfaceProcess(UMLController* controller, std::shared_ptr<model::UMLDiagram>* diagram);

	protected:

		int PreProcess() override;
		int PostProcess() override;

	private:

		std::shared_ptr<model::UMLDiagram>* m_diagram;
		std::shared_ptr<model::UMLInterface> m_interface;
	};
}
