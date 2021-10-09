
#include <iostream>
#include <fstream>
#include <graphviz/gvc.h>
#include <graphviz/cgraph.h>

int main(int argc, char** argv)
{
    // Open File
    FILE* dot_file = fopen("test.dot", "w");
    if (dot_file == nullptr)
    {
        std::cout << "Couldn't open dot file..." << std::endl;
        return 1;
    }

    // Define Context
    GVC_t* context = gvContext();
    if (context == nullptr)
    {
        std::cout << "Couldn't load context..." << std::endl;
        return 1;
    }

    // Create Graph
    Agraph_t* graph = agopen("Test", Agdirected, nullptr);

    // Graph Content
    // -- Nodes
    Agnode_t* node_1 = agnode(graph, "First", 1);
    Agnode_t* node_2 = agnode(graph, "Second", 1);
    // -- Edges
    Agedge_t* edge_1 = agedge(graph, node_1, node_2, "label", 1);
    // -- Attributes
    agsafeset(node_1, "color", "red", "");

    // Print Graph
    agwrite(graph, stdout);

    // Draw Graph
    gvLayout(context, graph, "dot");

    // Export Graph
    gvRender(context, graph, "dot", dot_file);

    // Generate File
    int sys = std::system("dot -Tpng test.dot -o test.png");
    if (sys != 0)
    {
        std::cout << "Unable to export the dot file..." << std::endl;
    }

    // Free Memory
    gvFreeLayout(context, graph);
    agclose(graph);
    fclose(dot_file);

    return 0;
}