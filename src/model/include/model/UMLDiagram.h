#pragma once
#include "model/UMLEntity.h"
#include <vector>

namespace model
{
	class UMLDiagram
	{
	public:

		typedef std::vector<std::shared_ptr<UMLEntity>> Entities;

	protected:

		UMLDiagram(const std::string& title);

	public:

		int Export(const std::string& filePath, const std::string& extension);
		// TODO: load/save

		std::string getTitle() const;
		bool addEntity(const std::shared_ptr<UMLEntity>& entity);
		std::shared_ptr<NodeMapper> getMaps() const;
		// TODO: getters/setters

		virtual int verify(std::string& logs) const = 0;
		// TODO: object-model verification

	protected:

		std::string m_title;
		Entities m_entities;

		std::shared_ptr<NodeMapper> m_linkMaps;
	};
}
