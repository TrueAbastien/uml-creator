#pragma once
#include "model/ClassBase.h"

namespace model
{
	class UMLObject : public ClassBase
	{
	public:

		UMLObject(const std::string& name, const std::string& type);

		bool addMember(const std::shared_ptr<Member>& member) override;

		std::string title() const override;
		int verify(const std::shared_ptr<NodeMapper>& maps, std::string& logs) const override;

	protected:

		void registerMap() override;
		void unregisterMap() override;

	private:

		std::string m_name;
	};
}
