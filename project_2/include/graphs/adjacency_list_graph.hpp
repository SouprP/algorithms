#ifndef ADJACENCY_LIST_GRAPH_HPP_
#define ADJACENCY_LIST_GRAPH_HPP_

#include <memory>

#include "graphs/graph.hpp"

class AdjacencyListGraph : public Graph
{
  /**
   *      ADJACENCY LIST
   * 
   *      A ------- C --------- D
   *       \       /
   *        \     /
   *         \   / 
   *           B
   * 
   *    The list of verticies it goes to
   *    A - [ B, C ]
   *    B - [ A, C ]
   *    C - [ A, B, D ]
   *    D - [ C ]
   * 
  */
  public:
    // TODO: implement all required methods

    static std::unique_ptr<Graph> createGraph(std::istream& is);

    // use of virtual is optional here
    // but I am to lazy to remove it
    void insertVertex(Vertex vertex) override;
    void insertEdge(Vertex vertex_1, Vertex vertex_2) override;

    void removeVertex(Vertex vertex) override;
    void removeEdge(Edge edge) override;

    // list of edges connected to this vertex
    std::vector<Edge> incidentEdges(Vertex vertex) override;

    // are vertex V1 and V2 connected by an edge
    bool areAdjacent(Vertex vertex_1, Vertex vertex_2) override;

    void visualise() override;
};

#endif /* ADJACENCY_LIST_GRAPH_HPP_ */
