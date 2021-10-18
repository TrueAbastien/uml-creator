#include "model/UMLObject.h"

namespace model
{
	UMLObject::UMLObject(const std::string& kind, const std::string& type)
		: m_type(type), UMLEntity(kind + "." + to_lower(type))
	{
	}

	// ----------------------------------------------------------------------------------------- //
	std::string UMLObject::getType() const
	{
		return m_type;
	}
}
