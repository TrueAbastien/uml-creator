#include "model/UMLClass.h"

namespace model
{
	UMLClass::UMLClass(const std::string& type)
		: ClassBase("class", type, type)
	{
	}
}
