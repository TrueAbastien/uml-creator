#pragma once
#include "model/UMLEntity.h"

namespace model
{
	class UMLNode : public UMLEntity
	{
	public:

		enum class DefinitionType : uint8_t
		{
			CONCRETE,
			ABSTRACT,
			INTERFACE
		};

	protected:

		UMLNode(const std::string& kind, const std::string& type);

	public:

		std::string getType() const;
		Agnode_t* getNode() const;

		virtual DefinitionType getDefinitionType() const;

	protected:

		std::string m_type;
		Agnode_t* m_node;
	};
}
