#pragma once
#include <memory>

namespace model
{
	class UMLModel
	{
	public:

		UMLModel();
	};

	typedef std::shared_ptr<UMLModel> ModelPtr;
}
