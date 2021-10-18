#pragma once
#include "model/Member.h"
#include "model/Parameter.h"
#include <vector>
#include <memory>

namespace model
{
	class Method : public Member
	{
	public:

		typedef std::vector<std::shared_ptr<Parameter>> Parameters;

	public:

		Method(const std::string& name, const std::string& type, const Visibility& visibility, const std::string& className);

		bool addParam(const std::string& type, const std::string& name = "");
		//

		std::string toString() const override;
		uint8_t memberTypeID() const override;

		virtual std::string getUID() const override;

	private:

		Parameters m_parameters;
	};
}
