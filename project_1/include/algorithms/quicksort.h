#ifndef SORTING_ALGORITHMS_QUICKSORT_H
#define SORTING_ALGORITHMS_QUICKSORT_H
#include <vector>

// quicksort

template <typename T>
class QuickSort{
    // std::swap
    // std::distance
    public:
        void sort(typename std::vector<T>::iterator start, typename std::vector<T>::iterator end){
                if(std::distance(start, end) <= 1)
                    return;

                // get the pivot point and recursively call sort()
                auto pivot = partition(start, end - 1);
                sort(start, pivot);
                sort(pivot, end); 
            };

    private:
        auto partition(typename std::vector<T>::iterator start, typename std::vector<T>::iterator end){
                // get pivot point
                auto pivot = start + std::distance(start, end) / 2;
                auto pivot_value = *pivot;
            
                // sorting
                while(start <= end){
                    while(*start < pivot_value)
                        start++;

                    while(*end > pivot_value)
                        end--;
                    
                    // swap values
                    if(start <= end){
                        std::iter_swap(start, end);
                        start++;
                        end--;
                    }

            
                }
                return start;
            };

    
};
#endif //SORTING_ALGORITHMS_QUICKSORT_H
