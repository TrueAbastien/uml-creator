#pragma once
#include <string>

namespace model
{
	class Cardinal
	{
	public:

		Cardinal(const std::string& min, const std::string& max = "", const std::string& tag = "");
		Cardinal(int min, const std::string& tag = "");
		Cardinal(int min, int max, const std::string& tag = "");

		std::string getRange() const;
		std::string getTag() const;

		std::string toString() const;

	private:

		std::string m_min, m_max, m_tag;
	};
}
