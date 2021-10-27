#pragma once
#include "controller/InputProcessBase.h"
#include <model/UMLEnumeration.h>

namespace controller
{
	class CreateEnumerationItemProcess : public InputProcessBase
	{
	public:

		CreateEnumerationItemProcess(UMLController* controller, std::shared_ptr<model::UMLEnumeration>* enumeration, std::shared_ptr<model::UMLDiagram>* diagram);

		int Process() override;

	private:

		std::shared_ptr<model::UMLEnumeration>* m_enumeration;
		std::shared_ptr<model::UMLDiagram>* m_diagram;
	};
}
