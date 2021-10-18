#pragma once
#include "model/Symbol.h"

namespace model
{
	class Parameter : public Symbol
	{
	public:

		Parameter(const std::string& type, const std::string& method, const std::string& name = "");

		std::string toString() const;

	private:

		std::string m_name;
	};
}
