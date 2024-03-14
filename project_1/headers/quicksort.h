#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <iostream>
#include<vector>

template <class T>
class Quicksort{
    private:
        std::vector<T> data;
        
        size_t get_pivot(size_t low, size_t high);
        void sort(size_t low, size_t high);
        void swap(size_t index_low, size_t index_high);

    public:
        void sort();
        void set_data(std::vector<T> data);
        std::vector<T> get_data();
};


#include <quicksort.cpp>
#endif