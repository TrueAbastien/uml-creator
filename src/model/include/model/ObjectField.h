#pragma once
#include "model/Member.h"

namespace model
{
	class ObjectField : public Member
	{
	public:

		ObjectField(const std::string& name, const std::string& type, const Visibility& visibility, const std::string& value, const std::string& className);

		std::string toString() const override;
		uint8_t memberTypeID() const override;

	private:

		std::string m_value;
	};
}
