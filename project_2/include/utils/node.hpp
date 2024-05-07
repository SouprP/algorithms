#ifndef NODE_HPP
#define NODE_HPP

/*
class BaseNode{

};
*/
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

#endif