#pragma once
#include "model/Member.h"

namespace model
{
	class ClassField : public Member
	{
	public:

		ClassField(const std::string& name, const std::string& type, const Visibility& visibility, const std::string& className);

		std::string toString() const override;
		uint8_t memberTypeID() const override;
	};
}
