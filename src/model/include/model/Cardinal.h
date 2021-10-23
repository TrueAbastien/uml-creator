#pragma once
#include <string>

namespace model
{
	class Cardinal
	{
	public:

		enum class Type : uint8_t
		{
			empty,

			NONE,
			ONE,
			MANY,

			__size__
		};

	private:

		std::string _typeString[(uint8_t)Type::__size__] =
		{
			"", "0", "1", "*"
		};

	public:

		Cardinal(const std::string& min, const std::string& max = "", const std::string& tag = "");
		Cardinal(int min, const std::string& tag = "");
		Cardinal(int min, int max, const std::string& tag = "");
		Cardinal(const Type& min, const std::string& tag = "");
		Cardinal(const Type& min, const Type& max, const std::string& tag = "");

		std::string getRange() const;
		std::string getTag() const;

		std::string toString() const;

	private:

		std::string m_min, m_max, m_tag;
	};
}
