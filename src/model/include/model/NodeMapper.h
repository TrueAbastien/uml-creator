#pragma once
#include <map>
#include <memory>
#include <string>
#include <vector>

namespace model
{
	class UMLNode;
	class UMLLink;

	class NodeMapper
	{
	public:

		enum class Type : uint8_t
		{
			INHERITAGE,
			ASSOCIATION,
			AGREGATION,
			COMPOSITION,

			__size__
		};

		typedef std::map<std::string, std::vector<std::shared_ptr<UMLNode>>> NodeMap;

	private:

		std::map<Type, NodeMap> m_maps;

	public:

		NodeMapper();

		void add(const Type& type, const std::string& id, const std::shared_ptr<UMLNode>& target);
		void remove(const Type& type, const std::string& id);
		void clear(const Type& type);
		std::vector<std::shared_ptr<UMLNode>> get(const Type& type, const std::string& id) const;
	};
}
