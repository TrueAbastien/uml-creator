#include "model/UMLEntity.h"
#include <algorithm>
#include <cctype>

namespace model
{
	UMLEntity::UMLEntity(const std::string& uid)
		: m_uid(uid)
	{
		freshUID = 0;
	}

	// ----------------------------------------------------------------------------------------- //
	std::string UMLEntity::to_lower(const std::string& data) const
	{
		std::string result;
		std::transform(data.begin(), data.end(), result.begin(),
			[](unsigned char c) { return std::tolower(c); });
		return result;
	}

	// ----------------------------------------------------------------------------------------- //
	std::string UMLEntity::newUID(const std::string& kind)
	{
		return "uniq." + (kind.empty() ? "" : kind + ".") + std::to_string(++freshUID);
	}

	// ----------------------------------------------------------------------------------------- //
	std::string UMLEntity::getUID() const
	{
		return m_uid;
	}

	// ----------------------------------------------------------------------------------------- //
	bool UMLEntity::isEquals(UMLEntity* entity) const
	{
		return m_uid == entity->getUID();
	}

	// ----------------------------------------------------------------------------------------- //
	bool UMLEntity::isEquals(const std::shared_ptr<UMLEntity>& entity) const
	{
		return isEquals(entity.get());
	}
}
