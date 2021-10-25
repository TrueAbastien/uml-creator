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

		typedef std::vector<std::shared_ptr<Member>> Vector;

	protected:

		Visibility m_visibility;
		std::string m_name;
		std::string m_className;

	public:

		virtual uint8_t memberTypeID() const = 0;
		std::string getName() const;

	protected:

		Member(const std::string& name, const std::string& className, const Visibility& visibility, const std::string& kind, const std::string& type);

		std::string visibility_string() const;

	private:

		const std::string __visibilityStringMap[3] = { "-", "#", "+" };
	};
}
