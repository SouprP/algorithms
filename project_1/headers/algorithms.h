#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include<vector>

template <class T>
class Quicksort{
    private:
        std::vector<T> data;
        
        get_pivot();

    public:
        sort();
        set_data(std::vector<T> data);
};

template<class T>
class Mergesort{

};

template<class T>
class Introsort{

};

#endif