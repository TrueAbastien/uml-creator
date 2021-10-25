#include "view/ModelMenuLayout.h"

namespace view
{
	std::string ModelMenuLayout::headerMessage() const
	{
		return
			"================\n"
			"=  Model Menu  =\n"
			"================\n"
			"\n"
			"- load ?\n"
			"- create ?\n";
	}

	// ----------------------------------------------------------------------------------------- //
	void ModelMenuLayout::render()
	{
		notify(awaits(">"));
	}
}
