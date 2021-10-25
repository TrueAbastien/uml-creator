#include "model/Symbol.h"

namespace model
{
	void Symbol::render(Agraph_t* graph)
	{
	}

	// ----------------------------------------------------------------------------------------- //
	std::string Symbol::getType() const
	{
		return m_type;
	}

	// ----------------------------------------------------------------------------------------- //
	Symbol::Symbol(const std::string& type, const std::string& kind, const std::string& name)
		: m_type(type), UMLEntity(kind + "." + to_lower(name))
	{
	}
}
