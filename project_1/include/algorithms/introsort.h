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
        if(std::distance(start, end) <= 1)
            return;

        size_t distance = std::distance(start, end);
        
        // when we use log2, heapsort is never used
        size_t depth = 2 * log2(distance); // log2 or log?
        
        sort_util(start, end, depth);
    };

    void sort_util(typename std::vector<T>::iterator start, typename std::vector<T>::iterator end, size_t depth){
        size_t distance = std::distance(start, end);

        if(distance < 16){
            InsertSort<int> sorter;
            sorter.sort(start, end);
            return;
        }
        
        if(depth == 0){
            HeapSort<int> sorter;
            sorter.sort(start, end);
            //std::cout << "heap for " << depth <<  std::endl;
            return;
        }

        auto pivot = partition(start, end - 1);
        sort_util(start, pivot, depth - 1);
        sort_util(pivot, end, depth - 1);
    }

    auto partition(typename std::vector<T>::iterator start, 
            typename std::vector<T>::iterator end){
                auto pivot = start + std::distance(start, end) / 2;
                auto pivot_value = *pivot;
            
                while(start <= end){
                    while(*start < pivot_value)
                        start++;

                    while(*end > pivot_value)
                        end--;

                    if(start <= end){
                        std::iter_swap(start, end);
                        start++;
                        end--;
                    }

            
                }
                return start;
            };
};
#endif //SORTING_ALGORITHMS_INTROSORT_H
