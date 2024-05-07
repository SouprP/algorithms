#ifndef GRAPH_HPP_
#define GRAPH_HPP_

#include <vector>
#include <utils/node.hpp>

class Graph
{
  public:
    std::vector<Vertex> vertecies;
    std::vector<Edge> edges;

    // TODO: implement all required methods
    /**
     * 
     *           UPDATE METHODS
     * 
    */
    virtual void insertVertex(Vertex v) = 0;
    virtual void insertEdge(Vertex v1, Vertex v2, size_t weight) = 0;

    virtual void removeVertex(Vertex v) = 0;
    virtual void removeEdge(Edge edge) = 0;

    /**
     * 
     *           ITERATION METHODS
     * 
    */
    // list of edges connected to this vertex
    virtual std::vector<Edge> incidentEdges(Vertex v) = 0;

    /**
     * 
     *           ACCESS METHODS
     * 
    */
    virtual std::vector<Vertex> endVertices(Edge edge) = 0;
    virtual Vertex opposite(Vertex v, Edge egde) = 0;

    // are vertex V1 and V2 connected by an edge
    virtual bool areAdjacent(Vertex v1, Vertex v2) = 0;

    // change size_t ELEMENT to something else
    // or just delete it
    virtual void replace(Vertex v, size_t ELEMENT) = 0;
    virtual void replace(Edge edge, size_t ELEMENT) = 0; 

    virtual void visualise() = 0;
};

#endif /* GRAPH_HPP_ */