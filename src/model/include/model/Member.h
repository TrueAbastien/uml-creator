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

	public:

		//

	protected:

		Member(const std::string& name, const std::string&);
	};
}
