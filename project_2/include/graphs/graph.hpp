#ifndef GRAPH_HPP_
#define GRAPH_HPP_

#include <vector>

struct Vertex{

};

struct Edge{

};

class Graph
{
  public:
    // TODO: implement all required methods
    virtual void insertVertex(Vertex vertex);
    virtual void insertEdge(Vertex vertex_1, Vertex vertex_2);

    virtual void removeVertex(Vertex vertex);
    virtual void removeEdge(Edge edge);

    // list of edges connected to this vertex
    virtual std::vector<Edge> incidentEdges(Vertex vertex);

    // are vertex V1 and V2 connected by an edge
    virtual bool areAdjacent(Vertex vertex_1, Vertex vertex_2);
};

#endif /* GRAPH_HPP_ */
