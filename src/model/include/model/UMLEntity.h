#pragma once
#include <graphviz/gvc.h>
#include <graphviz/cgraph.h>
#include <string>
#include <memory>
#include "model/NodeMapper.h"

namespace model
{
	class UMLEntity
	{
	private:

		std::string m_uid;

	protected:

		std::shared_ptr<NodeMapper> m_maps;

	protected:

		UMLEntity(const std::string& uid);

		std::string to_lower(const std::string& data) const;
		static std::string newUID(const std::string& kind = "");

		virtual void registerMap();
		virtual void unregisterMap();

	public:

		virtual std::string getUID() const;

		virtual void render(Agraph_t* graph) = 0;
		virtual bool isEquals(UMLEntity* entity) const;
		
		bool isEquals(const std::shared_ptr<UMLEntity>& entity) const;
		void setMapper(const std::shared_ptr<NodeMapper>& map);

		virtual ~UMLEntity();
	};
}
