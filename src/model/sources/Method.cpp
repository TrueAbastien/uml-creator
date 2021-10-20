#include "model/Method.h"

namespace model
{
	Method::Method(const std::string& name, const std::string& type, const Visibility& visibility, const std::string& className)
		: m_parameters(0), Member(name, className, visibility, "method", type)
	{
	}

	// ----------------------------------------------------------------------------------------- //
	bool Method::addParam(const std::string& type, const std::string& name)
	{
		std::shared_ptr<Parameter> newParam = std::make_shared<Parameter>(type, m_className + "." + m_name, name);

		if (!m_parameters.empty())
		{
			for (auto param : m_parameters)
			{
				if (param->isEquals(newParam))
				{
					return false;
				}
			}
		}

		m_parameters.push_back(newParam);
		return true;
	}

	// ----------------------------------------------------------------------------------------- //
	std::string Method::toString() const
	{
		std::string result = visibility_string() + " " + m_name + "(";

		if (!m_parameters.empty())
		{
			result += m_parameters[0]->toString();

			size_t size = m_parameters.size();
			for (size_t ii = 1; ii < size; ++ii)
			{
				result += (", " + m_parameters[ii]->toString());
			}
		}

		return result + ")" + (m_type.empty() || m_type == "void" ? "" : " : " + m_type);
	}

	// ----------------------------------------------------------------------------------------- //
	uint8_t Method::memberTypeID() const
	{
		return (uint8_t)m_visibility + (uint8_t)Member::Visibility::__size__;
	}

	// ----------------------------------------------------------------------------------------- //
	std::string Method::getUID() const
	{
		return UMLEntity::getUID() + "." + std::to_string(m_parameters.size());
	}
}
