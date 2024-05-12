#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>
#include <sstream>

class Vertex{
    public:
        std::string label;
        size_t index;
        bool visited;

        //Vertex() : index(0), visited(false){}
        Vertex(size_t index, bool visited){
            std::stringstream ss;
            ss << index;
            
            this->label = ss.str();
            this->index = index;
            this->visited = visited;
        }
};

class Edge{
    public:
        Vertex* v1;
        Vertex* v2;
        int weight;

        Edge(Vertex* v1, Vertex* v2, int weight){
            this->v1 = v1;
            this->v2 = v2;
            this->weight = weight;
        }
};

#endif