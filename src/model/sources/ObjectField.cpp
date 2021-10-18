#include "model\ObjectField.h"

namespace model
{
	ObjectField::ObjectField(const std::string& name, const std::string& type, const Visibility& visibility, const std::string& value, const std::string& className)
		: m_value(value), Member(name, className, visibility, "obj_field", type)
	{
	}

	// ----------------------------------------------------------------------------------------- //
	std::string ObjectField::toString() const
	{
		return visibility_string() + " " + m_name + ":" + m_type + "=" + m_value;
	}

	// ----------------------------------------------------------------------------------------- //
	uint8_t ObjectField::memberTypeID() const
	{
		return (uint8_t)m_visibility;
	}
}
