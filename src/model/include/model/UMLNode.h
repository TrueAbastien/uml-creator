#pragma once
#include "model/UMLEntity.h"

namespace model
{
	class UMLNode : public UMLEntity
	{
	protected:

		UMLNode(const std::string& kind, const std::string& type);

	public:

		std::string getType() const;
		Agnode_t* getNode() const;

	protected:

		std::string m_type;
		Agnode_t* m_node;
	};
}
