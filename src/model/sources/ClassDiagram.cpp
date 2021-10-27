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
		size_t size = m_entities.size();
		for (size_t ii = 0; ii < size - 1; ++ii)
		{
			for (size_t jj = ii + 1; jj < size; ++jj)
			{
				if (m_entities[ii]->isEquals(m_entities[jj]))
				{
					return 1;
				}
			}
		}

		// TODO ?

		return 0;
	}
}
