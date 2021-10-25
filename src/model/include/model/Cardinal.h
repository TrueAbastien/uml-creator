#pragma once
#include <string>
#include <limits>

namespace model
{
	class Cardinal
	{
	public:

		static const int Many = INT_MAX;
		static const int Null = -1;

	private:

		std::string to_string(int value) const;

	public:

		Cardinal(int min = Cardinal::Null, const std::string& tag = "");
		Cardinal(int min, int max, const std::string& tag = "");

		int getMin() const;
		int getMax() const;

		std::string getRange() const;
		std::string getTag() const;

		std::string toString() const;

	private:

		int m_min, m_max;
		std::string m_tag;
	};
}
