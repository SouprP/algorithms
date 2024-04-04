#ifndef SORTING_ALGORITHMS_INTROSORT_H
#define SORTING_ALGORITHMS_INTROSORT_H
#include <vector>

#include <algorithms/heapsort.h>
#include <algorithms/insertsort.h>
#include <algorithms/quicksort.h>

// sortowanie introspektywne

template <typename T>
class IntroSort
{
public:
    void sort(typename std::vector<T>::iterator start, typename std::vector<T>::iterator end)
    {
        size_t distance = std::distance(start, end);
        if(distance < 16){
            InsertSort<int> sorter;
            sorter.sort(start, end);
            return;
        }

        size_t depth = 2 * log2(distance);
        
        if(depth == 0){
            HeapSort<int> sorter;
            sorter.sort(start, end);
            return;
        }

        QuickSort<int> sorter;
        sorter.sort(start, end);
    };
};
#endif //SORTING_ALGORITHMS_INTROSORT_H
