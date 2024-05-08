#ifndef ADJACENCY_LIST_GRAPH_HPP_
#define ADJACENCY_LIST_GRAPH_HPP_

#include <memory>

#include "graphs/graph.hpp"
#include <utils/file.hpp>
#include <unordered_map>
#include <list>

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
  private:
    size_t size;

    std::unordered_map<Vertex*, std::list<Vertex*>> v_map;
    std::vector<Vertex*> v_vector;
    std::vector<Edge*> e_vector;

  public:
    // TODO: implement all required methods
    
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

#endif /* ADJACENCY_LIST_GRAPH_HPP_ */
