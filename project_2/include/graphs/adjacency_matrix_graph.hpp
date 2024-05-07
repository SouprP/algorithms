#ifndef ADJACENCY_MATRIX_GRAPH_HPP_
#define ADJACENCY_MATRIX_GRAPH_HPP_

#include <memory>

#include "graphs/graph.hpp"
#include <structures/matrix.hpp>
#include <utils/file.hpp>

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
    Matrix<int>* matrix;

  public:
    // TODO: implement
    static std::unique_ptr<Graph> createGraph(std::istream& is);

    // use of virtual is optional here
    // but I am to lazy to remove it
    virtual void insertVertex(Vertex vertex);
    virtual void insertEdge(Vertex vertex_1, Vertex vertex_2);

    virtual void removeVertex(Vertex vertex);
    virtual void removeEdge(Edge edge);

    // list of edges connected to this vertex
    virtual std::vector<Edge> incidentEdges(Vertex vertex);

    // are vertex V1 and V2 connected by an edge
    virtual bool areAdjacent(Vertex vertex_1, Vertex vertex_2); 
};

#endif /* ADJACENCY_MATRIX_GRAPH_HPP_ */
