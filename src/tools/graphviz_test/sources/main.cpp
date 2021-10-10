
#include <iostream>
#include <fstream>
#include <graphviz/gvc.h>
#include <graphviz/cgraph.h>

int main(int argc, char** argv)
{
    // Define Context
    GVC_t* context = gvContext();
    if (context == nullptr)
    {
        std::cout << "Couldn't load context..." << std::endl;
        return 1;
    }

    // Create Graph
    Agraph_t* graph = agopen("Test", Agundirected, nullptr);

    // Graph Content
    {
        // Defaults
        agattr(graph, AGNODE, "shape", "record");
        agattr(graph, AGEDGE, "dir", "both");

        // Nodes
        Agnode_t* node_1 = agnode(graph, "First", 1);
        agsafeset(node_1, "label", "{First|...| + render()\\l...}", "");
        Agnode_t* node_2 = agnode(graph, "Second", 1);
        agsafeset(node_2, "label", "{Second| - value : int\\l...| + render()\\l...}", "");

        // Edges
        Agedge_t* edge_1 = agedge(graph, node_1, node_2, nullptr, 1);
        agsafeset(edge_1, "arrowtail", "empty", "");
        agsafeset(edge_1, "arrowhead", "none", "");
    }

    // Setup 'Correct' Graph
    gvLayout(context, graph, "dot");

    // Export Graph
    gvRenderFilename(context, graph, "dot", "test.dot");
    gvRenderFilename(context, graph, "png", "test.png");

    // Free Memory
    gvFreeLayout(context, graph);
    agclose(graph);
    gvFreeContext(context);

    return 0;
}