#include "model/ClassField.h"

namespace model
{
	ClassField::ClassField(const std::string& name, const std::string& type, const Visibility& visibility, const std::string& className)
		: Member(name, className, visibility, "field", type)
	{
	}

	// ----------------------------------------------------------------------------------------- //
	std::string ClassField::toString() const
	{
		return visibility_string() + " " + m_name + " : " + m_type;
	}

	// ----------------------------------------------------------------------------------------- //
	uint8_t ClassField::memberTypeID() const
	{
		return (uint8_t)m_visibility;
	}
}
