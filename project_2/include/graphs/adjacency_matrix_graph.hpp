#ifndef ADJACENCY_MATRIX_GRAPH_HPP_
#define ADJACENCY_MATRIX_GRAPH_HPP_

#include <memory>

#include "graphs/graph.hpp"
#include <structures/matrix.hpp>
#include <utils/file.hpp>
#include <utils/node.hpp>

class AdjacencyMatrixGraph : public Graph
{
  /**
   *      ADJACENCY MATRIX
   * 
   *      A ------- C --------- D
   *       \       /
   *        \     /
   *         \   / 
   *           B
   * 
   *    Matrix of verticisies we connect to
   *        A    B    C     D
   *    ---------------------
   *    A   0    X    X     0
   *    ---------------------
   *    B   X    0    X     0
   *    ---------------------
   *    C   X    X    0     X
   *    ---------------------
   *    D   0    0    X     0
   * 
  */
  private:
    Matrix<Edge*>* matrix;
    size_t size;

  public:
    // TODO: implement
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

#endif /* ADJACENCY_MATRIX_GRAPH_HPP_ */
