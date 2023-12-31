#pragma once
#include "model/UMLDiagram.h"
#include "model/ClassDiagram.h"

namespace model
{
	class ObjectDiagram : public UMLDiagram
	{
	public:

		ObjectDiagram(const std::shared_ptr<ClassDiagram>& model, const std::string& title);

		int verify(std::string& logs) const override;

	private:

		std::shared_ptr<ClassDiagram> m_model;
	};
}
