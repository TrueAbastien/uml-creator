#include "model/UMLClass.h"

namespace model
{
	UMLClass::UMLClass(const std::string& type)
		: ClassBase("class", type, type)
	{
	}

	// ----------------------------------------------------------------------------------------- //
	void UMLClass::registerMap()
	{
		m_maps->set(m_type, this);
	}

	// ----------------------------------------------------------------------------------------- //
	void UMLClass::unregisterMap()
	{
		m_maps->remove(m_type);
	}
}
