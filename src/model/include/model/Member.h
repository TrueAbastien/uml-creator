#pragma once
#include "model/Symbol.h"

namespace model
{
	class Member : public Symbol
	{
	public:

		enum class Visibility : uint8_t
		{
			PRIVATE,
			PROTECTED,
			PUBLIC,

			__size__
		};

	protected:

		Visibility m_visibility;
		std::string m_name;
		std::string m_className;

	public:

		virtual uint8_t memberTypeID() const = 0;

	protected:

		Member(const std::string& name, const std::string& className, const Visibility& visibility, const std::string& kind, const std::string& type);

		std::string visibility_string() const;

	private:

		const std::string __visibilityStringMap[3] = { "-", "#", "+" };
	};
}
