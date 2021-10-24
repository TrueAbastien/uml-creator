#include "model/UMLDiagram.h"

namespace model
{
	UMLDiagram::UMLDiagram(const std::string& title)
		: m_title(title), m_entities(0)
	{
		m_linkMaps = std::make_shared<NodeMapper>();
	}

	// ----------------------------------------------------------------------------------------- //
	int UMLDiagram::Export(const std::string& filePath, const std::string& extension)
	{
        // Define Context
        GVC_t* context = gvContext();
        if (context == nullptr) return 1;

        // Create Graph
        if (m_title.empty()) return 2;
        Agraph_t* graph = agopen(&m_title[0], Agundirected, nullptr);

        // Graph Default Content
        agattr(graph, AGNODE, (char*)"shape", (char*)"record");
        agattr(graph, AGEDGE, (char*)"dir", (char*)"both");

		// Render Graph Content
		for (auto entity : m_entities)
		{
			entity->render(graph);
		}

        // Setup 'Correct' Graph
        gvLayout(context, graph, "dot");

        // Export Graph
		std::string path = filePath.substr(0, filePath.find_last_of(".")) + "." + extension;
		int ec = gvRenderFilename(context, graph, extension.c_str(), path.c_str());
		if (ec != 0) return ec;

        // Free Memory
        gvFreeLayout(context, graph);
        agclose(graph);
        gvFreeContext(context);

		return 0;
	}

	// ----------------------------------------------------------------------------------------- //
	std::string UMLDiagram::getTitle() const
	{
		return m_title;
	}

	// ----------------------------------------------------------------------------------------- //
	bool UMLDiagram::addEntity(const std::shared_ptr<UMLEntity>& entity)
	{
		for (auto e : m_entities)
		{
			if (e->isEquals(entity))
			{
				return false;
			}
		}

		entity->setMapper(m_linkMaps);

		m_entities.push_back(entity);
		return true;
	}

	// ----------------------------------------------------------------------------------------- //
	std::shared_ptr<NodeMapper> UMLDiagram::getMaps() const
	{
		return m_linkMaps;
	}
}
