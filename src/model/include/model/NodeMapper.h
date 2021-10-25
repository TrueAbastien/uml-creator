#pragma once
#include <map>
#include <memory>
#include <string>
#include <vector>
#include "model/Cardinal.h"

namespace model
{
	class UMLNode;
	class ClassBase;

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

		class Element
		{
		public:

			std::shared_ptr<UMLNode> node;
			Cardinal cardinal;

		public:

			Element(const std::shared_ptr<UMLNode>& _node, const Cardinal& _cardinal);
		};

		typedef std::map<std::string, std::vector<Element>> NodeMap;

	private:

		std::map<Type, NodeMap> m_maps;
		std::map<std::string, ClassBase*> m_nodes;

	public:

		NodeMapper();

		void add(const Type& type, const std::string& id, const std::shared_ptr<UMLNode>& target, const Cardinal& cardinal);
		void remove(const Type& type, const std::string& id);
		void clear(const Type& type);
		std::vector<Element> get(const Type& type, const std::string& id) const;

		void set(const std::string& id, ClassBase* node);
		void remove(const std::string& id);
		void clear();
		ClassBase* get(const std::string& id);
	};
}
