
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
    Agraph_t* graph = agopen((char*)"Test", Agundirected, nullptr);

    // Graph Content
    {
        // Defaults
        agattr(graph, AGNODE, (char*)"shape", (char*)"record");
        agattr(graph, AGEDGE, (char*)"dir", (char*)"both");

        // Nodes
        Agnode_t* node_1 = agnode(graph, (char*)"First", 1);
        agsafeset(node_1, (char*)"label", "{First|...| + render()\\l...}", (char*)"");
        Agnode_t* node_2 = agnode(graph, (char*)"Second", 1);
        agsafeset(node_2, (char*)"label", "{\\<\\<abstract\\>\\>\\lSecond| - value : int\\l}", (char*)"");

        // Edges
        Agedge_t* edge_1 = agedge(graph, node_1, node_2, nullptr, 1);
        agsafeset(edge_1, (char*)"arrowtail", (char*)"empty", (char*)"");
        agsafeset(edge_1, (char*)"arrowhead", (char*)"none", (char*)"");
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