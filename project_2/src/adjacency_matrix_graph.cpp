#include "graphs/adjacency_matrix_graph.hpp"

std::unique_ptr<Graph> AdjacencyMatrixGraph::createGraph(std::istream& is)
{
    // TODO: implement
    FileReader reader(is);

    // first and last line of our istream
    std::string first_line = reader.get_lines().front();
    std::string last_line = reader.get_lines().back();

    // probably should make a function in FileReader
    // like get_graph_size(), as this thing below
    // looks like crap
    size_t graph_size = reader.parse(first_line).at(0); // number of vertices
    size_t edges_size = reader.parse(first_line).at(1); // number of edges

    size_t starting_vertex = reader.parse(last_line).at(0);
    //for(auto obj : reader.get_lines())
    //    std::cout << obj << std::endl;
    
    std::cout << "First: " << first_line << std::endl;
    std::cout << "Last: " << last_line << std::endl;
    std::cout << "Graph size: " << graph_size << std::endl;
    std::cout << "Number of edges: " << edges_size << std::endl;
    std::cout << "Starting vertex: " << starting_vertex << std::endl;

    return std::make_unique<AdjacencyMatrixGraph>();
}

void AdjacencyMatrixGraph::insertVertex(Vertex vertex)
{
}

void AdjacencyMatrixGraph::insertEdge(Vertex vertex_1, Vertex vertex_2)
{
}

void AdjacencyMatrixGraph::removeVertex(Vertex vertex)
{
}

void AdjacencyMatrixGraph::removeEdge(Edge edge)
{
}

std::vector<Edge> AdjacencyMatrixGraph::incidentEdges(Vertex vertex)
{
return std::vector<Edge>();
}

bool AdjacencyMatrixGraph::areAdjacent(Vertex vertex_1, Vertex vertex_2)
{
return false;
}

void AdjacencyMatrixGraph::visualise()
{
}
