#pragma once
#include "model/UMLNode.h"
#include <vector>

namespace model
{
	class UMLEnumeration : public UMLNode
	{
	public:

		class Item : public UMLEntity
		{
		public:

			Item(const std::string& name, const std::string& enumName);

			void render(Agraph_t* graph) override;
			std::string toString() const;

		private:

			std::string m_name;
		};

		typedef std::vector<std::shared_ptr<Item>> Items;

	public:

		UMLEnumeration(const std::string& type);

		void render(Agraph_t* graph) override;

	private:

		Items m_items;
	};
}
