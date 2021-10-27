#pragma once
#include "controller/InputParentProcess.h"
#include <model/UMLDiagram.h>
#include <model/UMLEnumeration.h>

namespace controller
{
	class CreateEnumerationProcess : public InputParentProcess
	{
	public:

		CreateEnumerationProcess(UMLController* controller, std::shared_ptr<model::UMLDiagram>* diagram);

	protected:

		int PreProcess() override;
		int PostProcess() override;

	private:

		std::shared_ptr<model::UMLDiagram>* m_diagram;
		std::shared_ptr<model::UMLEnumeration> m_enumeration;
	};
}
