#include "graphs/adjacency_list_graph.hpp"

std::unique_ptr<Graph> AdjacencyListGraph::createGraph(std::istream& is)
{
    // TODO: implement

    return std::make_unique<AdjacencyListGraph>();
}

void AdjacencyListGraph::insertVertex(Vertex v)
{
}

void AdjacencyListGraph::insertEdge(Vertex v1, Vertex v2, size_t weight)
{
}

void AdjacencyListGraph::removeVertex(Vertex v)
{
}

void AdjacencyListGraph::removeEdge(Edge edge)
{
}

std::vector<Edge> AdjacencyListGraph::incidentEdges(Vertex v)
{
return std::vector<Edge>();
}

bool AdjacencyListGraph::areAdjacent(Vertex v1, Vertex v2)
{
return false;
}

void AdjacencyListGraph::visualise()
{
}
