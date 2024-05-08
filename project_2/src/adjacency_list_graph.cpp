#include "graphs/adjacency_list_graph.hpp"

std::unique_ptr<Graph> AdjacencyListGraph::createGraph(std::istream& is)
{
    // TODO: implement

    return std::make_unique<AdjacencyListGraph>();
}

void AdjacencyListGraph::insertVertex(Vertex* v)
{
}
void AdjacencyListGraph::insertEdge(Vertex* v1, Vertex* v2, size_t weight)
{
}
void AdjacencyListGraph::removeVertex(Vertex* v)
{
}
void AdjacencyListGraph::removeEdge(Edge* edge)
{
}
std::vector<Edge*> AdjacencyListGraph::incidentEdges(Vertex* v)
{
return std::vector<Edge*>();
}
std::vector<Edge*> AdjacencyListGraph::edges()
{
return std::vector<Edge*>();
}
std::vector<Vertex*> AdjacencyListGraph::vertices()
{
return std::vector<Vertex*>();
}
std::vector<Vertex*> AdjacencyListGraph::endVertices(Edge* edge)
{
return std::vector<Vertex*>();
}
Vertex* AdjacencyListGraph::opposite(Vertex* v, Edge* egde)
{
return nullptr;
}
bool AdjacencyListGraph::areAdjacent(Vertex* v1, Vertex* v2)
{
return false;
}
void AdjacencyListGraph::replace(Vertex* v, std::string label)
{
}
void AdjacencyListGraph::replace(Edge* edge, size_t weight)
{
}
void AdjacencyListGraph::visualise()
{
}