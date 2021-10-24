#include "model/NodeMapper.h"
#include "model/ClassBase.h"

namespace model
{
	NodeMapper::NodeMapper()
		: m_nodes{ }
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

	// ----------------------------------------------------------------------------------------- //
	void NodeMapper::set(const std::string& id, ClassBase* node)
	{
		m_nodes[id] = node;
	}

	// ----------------------------------------------------------------------------------------- //
	void NodeMapper::remove(const std::string& id)
	{
		m_nodes.erase(id);
	}

	// ----------------------------------------------------------------------------------------- //
	void NodeMapper::clear()
	{
		m_nodes.clear();
	}

	// ----------------------------------------------------------------------------------------- //
	ClassBase* NodeMapper::get(const std::string& id)
	{
		return m_nodes.at(id);
	}
}
