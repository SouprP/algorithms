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
    
    std::vector<Vertex*> v_vector;
    std::vector<Edge*> e_vector;
    

  public:
    // TODO: implement
    static std::unique_ptr<Graph> createGraph(std::istream& is);

    /**
     * 
     *           UPDATE METHODS
     * 
    */

    void insertVertex(Vertex* v) override;
    void insertEdge(Vertex* v1, Vertex* v2, size_t weight) override;
    void removeVertex(Vertex* v) override;
    void removeEdge(Edge* edge) override;

    /**
     * 
     *           ITERATION METHODS
     * 
    */
    
    std::vector<Edge*> incidentEdges(Vertex* v) override;
    std::vector<Edge*> edges() override;
    std::vector<Vertex*> vertices() override;

    /**
     * 
     *           ACCESS METHODS
     * 
    */

    std::vector<Vertex*> endVertices(Edge* edge) override;
    Vertex* opposite(Vertex* v, Edge* egde) override;
    bool areAdjacent(Vertex* v1, Vertex* v2) override;
    void replace(Vertex* v, std::string label) override;
    void replace(Edge* edge, size_t weight) override; 

    /**
     * 
     *           UTILITY METHONDS
     * 
    */

    void visualise() override;
};

#endif /* ADJACENCY_MATRIX_GRAPH_HPP_ */
