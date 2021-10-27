#pragma once
#include "controller/InputParentProcess.h"
#include <model/ObjectDiagram.h>

namespace controller
{
	class CreateObjectDiagramProcess : public InputParentProcess
	{
	public:

		CreateObjectDiagramProcess(UMLController* controller);

	protected:

		int PreProcess() override;
		int PostProcess() override;

	private:

		std::shared_ptr<model::ObjectDiagram> m_diagram;
	};
}
