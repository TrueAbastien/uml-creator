#include "model/NodeMapper.h"
#include "model/UMLLink.h"

namespace model
{
	NodeMapper::NodeMapper()
	{
		for (uint8_t ii = 0; ii < (uint8_t)Type::__size__; ++ii)
		{
			m_maps.emplace((Type)ii, NodeMap());
		}
	}

	// ----------------------------------------------------------------------------------------- //
	void NodeMapper::add(const Type& type, const std::string& id, const std::shared_ptr<UMLNode>& target)
	{
		m_maps[type][id].push_back(target);
	}

	// ----------------------------------------------------------------------------------------- //
	void NodeMapper::remove(const Type& type, const std::string& id)
	{
		m_maps[type].erase(id);
	}

	// ----------------------------------------------------------------------------------------- //
	void NodeMapper::clear(const Type& type)
	{
		m_maps[type].clear();
	}

	// ----------------------------------------------------------------------------------------- //
	std::vector<std::shared_ptr<UMLNode>> NodeMapper::get(const Type& type, const std::string& id) const
	{
		return m_maps.at(type).at(id);
	}
}
