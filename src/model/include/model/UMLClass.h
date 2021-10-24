#pragma once
#include "model/ClassBase.h"

namespace model
{
	class UMLClass : public ClassBase
	{
	public:

		UMLClass(const std::string& type);

	protected:

		void registerMap() override;
		void unregisterMap() override;
	};
}
