#include "model\Member.h"

namespace model
{
	Member::Member(const std::string& name, const std::string& className, const Visibility& visibility, const std::string& kind, const std::string& type)
		: m_name(name), m_className(className), m_visibility(visibility), Symbol(type, kind, name)
	{
	}

	// ----------------------------------------------------------------------------------------- //
	std::string Member::visibility_string() const
	{
		return __visibilityStringMap[(uint8_t)m_visibility];
	}
}

