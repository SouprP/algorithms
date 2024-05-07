#include "graphs/adjacency_list_graph.hpp"

std::unique_ptr<Graph> AdjacencyListGraph::createGraph(std::istream& is)
{
    // TODO: implement

    return std::make_unique<AdjacencyListGraph>();
}

void AdjacencyListGraph::insertVertex(Vertex vertex)
{
}

void AdjacencyListGraph::insertEdge(Vertex vertex_1, Vertex vertex_2)
{
}

void AdjacencyListGraph::removeVertex(Vertex vertex)
{
}

void AdjacencyListGraph::removeEdge(Edge edge)
{
}

std::vector<Edge> AdjacencyListGraph::incidentEdges(Vertex vertex)
{
return std::vector<Edge>();
}

bool AdjacencyListGraph::areAdjacent(Vertex vertex_1, Vertex vertex_2)
{
return false;
}

void AdjacencyListGraph::visualise()
{
}
