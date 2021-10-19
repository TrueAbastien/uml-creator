#include "model/UMLAbstractClass.h"

namespace model
{
	UMLAbstractClass::UMLAbstractClass(const std::string& type)
		: ClassBase("abstract", type)
	{
	}

	// ----------------------------------------------------------------------------------------- //
	UMLNode::DefinitionType UMLAbstractClass::getDefinitionType() const
	{
		return DefinitionType::ABSTRACT;
	}

	// ----------------------------------------------------------------------------------------- //
	std::string UMLAbstractClass::title() const
	{
		return "abstract";
	}
}
