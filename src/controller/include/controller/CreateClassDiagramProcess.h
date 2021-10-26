#pragma once
#include "controller/InputParentProcess.h"
#include <model/ClassDiagram.h>

namespace controller
{
	class CreateClassDiagramProcess : public InputParentProcess
	{
	protected:

		int PreProcess() override;
		int PostProcess() override;

	public:

		CreateClassDiagramProcess(UMLController* controller);

	private:

		std::shared_ptr<model::ClassDiagram> m_diagram;
	};
}
