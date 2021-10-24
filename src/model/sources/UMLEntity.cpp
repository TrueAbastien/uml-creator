#include "model/UMLEntity.h"
#include <algorithm>
#include <cctype>

namespace model
{
	static int freshUID;

	UMLEntity::UMLEntity(const std::string& uid)
		: m_uid(uid), m_maps(nullptr)
	{
		freshUID = 0;
	}

	// ----------------------------------------------------------------------------------------- //
	std::string UMLEntity::to_lower(const std::string& data) const
	{
		std::string result = data;
		std::transform(result.begin(), result.end(), result.begin(),
			[](unsigned char c) { return std::tolower(c); });
		return result;
	}

	// ----------------------------------------------------------------------------------------- //
	std::string UMLEntity::newUID(const std::string& kind)
	{
		return "uniq." + (kind.empty() ? "" : kind + ".") + std::to_string(++freshUID);
	}

	// ----------------------------------------------------------------------------------------- //
	void UMLEntity::registerMap()
	{
	}

	// ----------------------------------------------------------------------------------------- //
	void UMLEntity::unregisterMap()
	{
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
	int UMLEntity::verify(const std::shared_ptr<NodeMapper>& maps, std::string& logs) const
	{
		return 0;
	}

	// ----------------------------------------------------------------------------------------- //
	bool UMLEntity::isEquals(const std::shared_ptr<UMLEntity>& entity) const
	{
		return isEquals(entity.get());
	}

	// ----------------------------------------------------------------------------------------- //
	void UMLEntity::setMapper(const std::shared_ptr<NodeMapper>& map)
	{
		m_maps = map;
		
		registerMap();
	}

	// ----------------------------------------------------------------------------------------- //
	UMLEntity::~UMLEntity()
	{
		unregisterMap();
	}
}
