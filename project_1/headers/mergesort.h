#ifndef MERGESORT_H
#define MERGESORT_H

#include <iostream>
#include <vector>

template <class T>
class Mergesort{
    private:
        std::vector<T> data;
        
        void sort(size_t low, size_t high);
        void merge(size_t low, size_t pivot, size_t high);
        void swap(size_t index_low, size_t index_high);

    public:
        void sort();
        void set_data(std::vector<T> data);
        std::vector<T> get_data();
};


#include <mergesort.cpp>
#endif