#pragma once
#include "model/ClassBase.h"

namespace model
{
	class UMLObject : public ClassBase
	{
	public:

		UMLObject(const std::string& type);

		bool addMember(const std::shared_ptr<Member>& member) override;
	};
}
