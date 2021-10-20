#include "model/UMLObject.h"

namespace model
{
	UMLObject::UMLObject(const std::string& name, const std::string& type)
		: m_name(name), ClassBase("object", name, type)
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

	// ----------------------------------------------------------------------------------------- //
	std::string UMLObject::title() const
	{
		return m_name + ":";
	}
}
