#include "view/CreateEntityLayout.h"

namespace view
{
	std::string CreateEntityLayout::headerMessage() const
	{
		return
			"-= Create Entity =-\n";
	}

	// ----------------------------------------------------------------------------------------- //
	void CreateEntityLayout::render()
	{
		notify(awaits(">"));
	}
}
