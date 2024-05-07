#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>

template<typename T>
class Node{
    public:
        T value;
        Node* next;

        Node(T value){
            this->value = value;
            next = nullptr;
        };
};

class Vertex{
    public:
        size_t index;
        bool visited;

        Vertex() : index(0), visited(false){}
        Vertex(size_t index, bool visited){
            this->index = index;
            this->visited = visited;
        }
};

class Edge{
    public:
        Vertex v1;
        Vertex v2;
        size_t weight;

        Edge(Vertex v1, Vertex v2, size_t weight){
            this->v1 = v1;
            this->v2 = v2;
            this->weight = weight;
        }
};

#endif