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

    void insertVertex(Vertex vertex) override;
    void insertEdge(Vertex v1, Vertex v2, size_t weight) override;

    void removeVertex(Vertex v) override;
    void removeEdge(Edge edge) override;

    // list of edges connected to this vertex
    std::vector<Edge> incidentEdges(Vertex v) override;

    // are vertex V1 and V2 connected by an edge
    bool areAdjacent(Vertex v1, Vertex v2) override;

    void visualise() override;
};

#endif /* ADJACENCY_LIST_GRAPH_HPP_ */
