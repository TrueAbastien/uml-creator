#include "model\ObjectDiagram.h"

namespace model
{
	ObjectDiagram::ObjectDiagram(const std::shared_ptr<ClassDiagram>& model, const std::string& title)
		: m_model(model), UMLDiagram(title)
	{
	}
}
