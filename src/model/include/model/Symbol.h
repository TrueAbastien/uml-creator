#pragma once
#include "model/UMLEntity.h"

namespace model
{
	class Symbol : public UMLEntity
	{
	protected:

		std::string m_type;

	public:

		void render(Agraph_t* graph) override;

		virtual std::string toString() const = 0;

	protected:

		Symbol(const std::string& type, const std::string& kind, const std::string& name);
	};
}
