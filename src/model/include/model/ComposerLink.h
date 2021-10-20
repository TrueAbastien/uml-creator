#pragma once
#include "model/UMLLink.h"
#include "model/Cardinal.h"

namespace model
{
	class ComposerLink : public UMLLink
	{
	protected:

		ComposerLink(const std::shared_ptr<UMLNode>& origin, const std::shared_ptr<UMLNode>& target, const Cardinal& cardinal, const std::string& kind);

	public:

		Cardinal getCardinal() const;

	protected:

		Cardinal m_cardinal;
	};
}
