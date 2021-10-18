#include "model\Parameter.h"

namespace model
{
	Parameter::Parameter(const std::string& type, const std::string& method, const std::string& name)
		: m_name(name), Symbol(type, "param." + to_lower(method), (name.empty() ? UMLEntity::newUID() : type + "." + name))
	{
	}

	// ----------------------------------------------------------------------------------------- //
	std::string Parameter::toString() const
	{
		return (m_name.empty() ? "" : m_name + " : ") + m_type;
	}
}
