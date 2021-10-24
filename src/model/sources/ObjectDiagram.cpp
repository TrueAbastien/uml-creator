#include "model\ObjectDiagram.h"

namespace model
{
	ObjectDiagram::ObjectDiagram(const std::shared_ptr<ClassDiagram>& model, const std::string& title)
		: m_model(model), UMLDiagram(title)
	{
	}

	// ----------------------------------------------------------------------------------------- //
	int ObjectDiagram::verify(std::string& logs) const
	{
		int flag = 0;

		for (auto e : m_entities)
		{
			flag |= e->verify(m_linkMaps, logs);
		}

		return flag;
	}
}
