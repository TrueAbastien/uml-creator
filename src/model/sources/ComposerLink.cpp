#include "model/ComposerLink.h"

namespace model
{
	ComposerLink::ComposerLink(const std::shared_ptr<UMLNode>& origin, const std::shared_ptr<UMLNode>& target, const Cardinal& cardinal, const std::string& kind)
		: m_cardinal(cardinal), UMLLink(origin, target, kind, (cardinal.getTag().empty() ? UMLEntity::newUID() : cardinal.getTag()))
	{
	}

	// ----------------------------------------------------------------------------------------- //
	Cardinal ComposerLink::getCardinal() const
	{
		return m_cardinal;
	}
}
