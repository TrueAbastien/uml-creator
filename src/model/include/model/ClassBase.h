#pragma once
#include "model/UMLNode.h"
#include "model/Member.h"
#include <vector>

namespace model
{
	class ClassBase : public UMLNode
	{
	protected:

		ClassBase(const std::string& kind, const std::string& other, const std::string& type);

		virtual std::string title() const;

	public:

		virtual bool addMember(const std::shared_ptr<Member>& member);
		Member::Vector getMembers() const override;

		void render(Agraph_t* graph) override;

	protected:

		Member::Vector m_members;
	};
}
