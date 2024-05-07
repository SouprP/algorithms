#include "graphs/adjacency_matrix_graph.hpp"

std::unique_ptr<Graph> AdjacencyMatrixGraph::createGraph(std::istream& is)
{
    // TODO: implement
    FileReader<std::string> reader(is);

    for(auto obj : reader.get_lines())
        std::cout << obj << std::endl;
    
    

    return std::make_unique<AdjacencyMatrixGraph>();
}

void AdjacencyMatrixGraph::insertEdge(Vertex vertex_1, Vertex vertex_2){

}

void AdjacencyMatrixGraph::insertVertex(Vertex vertex){

}
