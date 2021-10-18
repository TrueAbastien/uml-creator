#pragma once
#include "model/UMLEntity.h"

namespace model
{
	class UMLObject : public UMLEntity
	{
	protected:

		UMLObject(const std::string& kind, const std::string& type);

	public:

		std::string getType() const;

	protected:

		std::string m_type;
	};
}
