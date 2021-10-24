#include "model/ClassDiagram.h"

namespace model
{
	ClassDiagram::ClassDiagram(const std::string& title)
		: UMLDiagram(title)
	{
	}

	// ----------------------------------------------------------------------------------------- //
	int ClassDiagram::verify(std::string& logs) const
	{
		// TODO ?

		return 0;
	}
}
