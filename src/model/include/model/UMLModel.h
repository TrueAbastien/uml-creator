#pragma once
#include <memory>
#include "model/UMLDiagram.h"

namespace model
{
	class UMLModel
	{
	public:

		typedef std::vector<std::shared_ptr<UMLDiagram>> Diagrams;

	public:

		UMLModel();

		bool exists(const std::shared_ptr<UMLDiagram>& diagram) const;
		bool add(const std::shared_ptr<UMLDiagram>& diagram);
		Diagrams getDiagrams() const;

	private:

		Diagrams m_diagrams;
	};

	typedef std::shared_ptr<UMLModel> ModelPtr;
}
