#include "model/Cardinal.h"

namespace model
{
	std::string Cardinal::to_string(int value) const
	{
		switch (value)
		{
		case Null: return "";
		case Many: return "*";
		default: return std::to_string(value);
		}
	}

	// ----------------------------------------------------------------------------------------- //
	Cardinal::Cardinal(int min, const std::string& tag)
		: Cardinal(min, min, tag)
	{
	}

	// ----------------------------------------------------------------------------------------- //
	Cardinal::Cardinal(int min, int max, const std::string& tag)
		: m_min(min), m_max(max), m_tag(tag)
	{
		if (min > max)
		{
			throw std::exception("Cardinal minimal limit in gretater than the maximal limit !");
		}
	}

	// ----------------------------------------------------------------------------------------- //
	int Cardinal::getMin() const
	{
		return m_min;
	}

	// ----------------------------------------------------------------------------------------- //
	int Cardinal::getMax() const
	{
		return m_max;
	}

	// ----------------------------------------------------------------------------------------- //
	std::string Cardinal::getRange() const
	{
		return to_string(m_min) + (m_min == m_max ? "" : ".." + to_string(m_max));
	}

	// ----------------------------------------------------------------------------------------- //
	std::string Cardinal::getTag() const
	{
		return m_tag;
	}

	// ----------------------------------------------------------------------------------------- //
	std::string Cardinal::toString() const
	{
		return getRange() + (m_tag.empty() ? "" : "\\l" + m_tag);
	}
}
