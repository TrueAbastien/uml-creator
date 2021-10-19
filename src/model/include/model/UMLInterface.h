#pragma once
#include "model/UMLNode.h"
#include "model/Method.h"

namespace model
{
	class UMLInterface : public UMLNode
	{
	public:

		typedef std::vector<std::shared_ptr<Method>> Methods;

	public:

		UMLInterface(const std::string& type);

		bool addMethod(const std::shared_ptr<Method>& method);
		//

		void render(Agraph_t* graph) override;
		DefinitionType getDefinitionType() const override;

	private:

		Methods m_methods;
	};
}
