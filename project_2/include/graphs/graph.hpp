#ifndef GRAPH_HPP_
#define GRAPH_HPP_

#include <vector>
#include <utils/node.hpp>

class Graph
{
  public:   
    // TODO: implement all required methods
    /**
     * 
     *           UPDATE METHODS
     * 
    */

    virtual void insertVertex(Vertex* v) = 0;
    virtual void insertEdge(Vertex* v1, Vertex* v2, size_t weight) = 0;
    virtual void removeVertex(Vertex* v) = 0;
    virtual void removeEdge(Edge* edge) = 0;

    /**
     * 
     *           ITERATION METHODS
     * 
    */
    
    virtual std::vector<Edge*> incidentEdges(Vertex* v) = 0;
    virtual std::vector<Edge*> edges() = 0;
    virtual std::vector<Vertex*> vertices() = 0;

    /**
     * 
     *           ACCESS METHODS
     * 
    */

    virtual std::vector<Vertex*> endVertices(Edge* edge) = 0;
    virtual Vertex* opposite(Vertex* v, Edge* egde) = 0;
    virtual bool areAdjacent(Vertex* v1, Vertex* v2) = 0;
    virtual void replace(Vertex* v, std::string label) = 0;
    virtual void replace(Edge* edge, size_t weight) = 0; 

    /**
     * 
     *           UTILITY METHONDS
     * 
    */

    virtual void visualise() = 0;
    virtual Vertex* get_starting_vertex() = 0;
};

#endif /* GRAPH_HPP_ */