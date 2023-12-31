#pragma once
#include "model/UMLDiagram.h"

namespace model
{
	class ClassDiagram : public UMLDiagram
	{
	public:

		ClassDiagram(const std::string& title);

		int verify(std::string& logs) const override;
	};
}
