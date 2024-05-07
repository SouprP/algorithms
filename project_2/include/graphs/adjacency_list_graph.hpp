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
};

#endif /* ADJACENCY_LIST_GRAPH_HPP_ */
