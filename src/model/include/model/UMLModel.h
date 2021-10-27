#pragma once
#include <memory>
#include "model/UMLDiagram.h"
#include "model/ObjectDiagram.h"
#include "model/ClassDiagram.h"

namespace model
{
	class UMLModel
	{
	public:

		typedef std::vector<std::shared_ptr<UMLDiagram>> Diagrams;

	public:

		UMLModel();

		bool exists(const std::shared_ptr<UMLDiagram>& diagram) const;
		bool add(const std::shared_ptr<ClassDiagram>& diagram);
		bool add(const std::shared_ptr<ObjectDiagram>& diagram);
		Diagrams getDiagrams() const;
		std::shared_ptr<ClassDiagram> getClassModel() const;

	private:

		Diagrams m_diagrams;
		std::shared_ptr<ClassDiagram> m_classModel;
	};

	typedef std::shared_ptr<UMLModel> ModelPtr;
}
