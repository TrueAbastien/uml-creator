#pragma once
#include "controller/InputParentProcess.h"
#include <model/UMLObject.h>

namespace controller
{
	class CreateObjectProcess : public InputParentProcess
	{
	public:

		CreateObjectProcess(UMLController* controller, std::shared_ptr<model::UMLDiagram>* diagram);

	protected:

		int PreProcess() override;
		int PostProcess() override;

	private:

		std::shared_ptr<model::UMLDiagram>* m_diagram;
		std::shared_ptr<model::UMLObject> m_object;
	};
}
