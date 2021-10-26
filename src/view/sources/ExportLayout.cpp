#include "view/ExportLayout.h"

namespace view
{
	std::string ExportLayout::headerMessage() const
	{
		return
			"---== Export ==---\n";
	}

	// ----------------------------------------------------------------------------------------- //
	void ExportLayout::render()
	{
		notify(awaits(">"));
	}
}
