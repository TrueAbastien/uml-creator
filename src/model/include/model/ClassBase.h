#pragma once
#include "model/UMLNode.h"
#include "model/Member.h"
#include <vector>

namespace model
{
	class ClassBase : public UMLNode
	{
	public:

		typedef std::vector<std::shared_ptr<Member>> Members;

	protected:

		ClassBase(const std::string& kind, const std::string& type);

		virtual std::string title() const;

	public:

		virtual bool addMember(const std::shared_ptr<Member>& member);
		//

		void render(Agraph_t* graph) override;

	protected:

		Members m_members;
	};
}
