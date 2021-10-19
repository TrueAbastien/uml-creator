#include "model/UMLObject.h"

namespace model
{
	UMLObject::UMLObject(const std::string& type)
		: ClassBase("object", type)
	{
	}

	// ----------------------------------------------------------------------------------------- //
	bool UMLObject::addMember(const std::shared_ptr<Member>& member)
	{
		if (member->memberTypeID() < (uint8_t)Member::Visibility::__size__)
		{
			return ClassBase::addMember(member);
		}
		return false;
	}
}
