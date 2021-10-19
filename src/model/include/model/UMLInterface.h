#pragma once
#include "model/UMLNode.h"
#include "model/Method.h"

namespace model
{
	class UMLInterface : public UMLNode
	{
	public:

		UMLInterface(const std::string& name);

		void addMethod(const std::shared_ptr<Method>& method);
		//


	};
}
