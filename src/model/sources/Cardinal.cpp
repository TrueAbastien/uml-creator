#include "model/Cardinal.h"

namespace model
{
	Cardinal::Cardinal(const std::string& min, const std::string& max, const std::string& tag)
		: m_min(min), m_max(max), m_tag(tag)
	{
	}

	// ----------------------------------------------------------------------------------------- //
	Cardinal::Cardinal(int min, const std::string& tag)
		: Cardinal(std::to_string(min), "", tag)
	{
	}

	// ----------------------------------------------------------------------------------------- //
	Cardinal::Cardinal(int min, int max, const std::string& tag)
		: Cardinal(std::to_string(min), std::to_string(max), tag)
	{
	}

	// ----------------------------------------------------------------------------------------- //
	Cardinal::Cardinal(const Type& min, const std::string& tag)
		: Cardinal(min, Type::empty, tag)
	{
	}

	// ----------------------------------------------------------------------------------------- //
	Cardinal::Cardinal(const Type& min, const Type& max, const std::string& tag)
		: Cardinal(_typeString[(uint8_t)min], _typeString[(uint8_t)max], tag)
	{
	}

	// ----------------------------------------------------------------------------------------- //
	std::string Cardinal::getRange() const
	{
		return m_min + (m_max.empty() ? "" : ".." + m_max);
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
