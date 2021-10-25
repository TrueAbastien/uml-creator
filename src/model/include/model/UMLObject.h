#pragma once
#include "model/ClassBase.h"

namespace model
{
	class UMLObject : public ClassBase
	{
	private:

		Member::Vector::const_iterator matchingAttribute(const Member::Vector& attributes, const std::shared_ptr<Member>& attribute) const;
		int verifyAttributesFrom(const std::shared_ptr<NodeMapper>& maps, const Member::Vector& current_members, const std::string& current_id, Member::Vector& attributes, std::string& logs) const;
		//

	public:

		UMLObject(const std::string& name, const std::string& type);

		bool addMember(const std::shared_ptr<Member>& member) override;

		std::string title() const override;
		int verify(const std::shared_ptr<NodeMapper>& maps, std::string& logs) const override;
		std::string getLinkUID() const override;

	protected:

		void registerMap() override;
		void unregisterMap() override;

	private:

		std::string m_name;
	};
}
