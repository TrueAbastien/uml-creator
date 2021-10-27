#pragma once
#include "controller/InputParentProcess.h"
#include <model/UMLDiagram.h>
#include <model/UMLAbstractClass.h>

namespace controller
{
	class CreateAbstractClassProcess : public InputParentProcess
	{
	public:

		CreateAbstractClassProcess(UMLController* controller, std::shared_ptr<model::UMLDiagram>* diagram);

	protected:

		int PreProcess() override;
		int PostProcess() override;

	private:

		std::shared_ptr<model::UMLDiagram>* m_diagram;
		std::shared_ptr<model::UMLAbstractClass> m_class;
	};
}
