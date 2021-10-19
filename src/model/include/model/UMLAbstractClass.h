#pragma once
#include "model/ClassBase.h"

namespace model
{
	class UMLAbstractClass : public ClassBase
	{
	public:

		UMLAbstractClass(const std::string& type);

		DefinitionType getDefinitionType() const override;

	protected:

		std::string title() const override;
	};
}
