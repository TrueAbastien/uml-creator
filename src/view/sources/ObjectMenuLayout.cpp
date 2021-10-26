#include "view/ObjectMenuLayout.h"

namespace view
{
	std::string ObjectMenuLayout::headerMessage() const
	{
		return
			"=================\n"
			"=  Object Menu  =\n"
			"=================\n"
			"\n"
			"- load ?\n"
			"- create ?\n"
			"- export ?\n"
			"- model ... ?\n";
	}

	// ----------------------------------------------------------------------------------------- //
	void ObjectMenuLayout::render()
	{
		notify(awaits(">"));
	}
}
