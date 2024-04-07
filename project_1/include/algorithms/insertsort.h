#ifndef SORTING_ALGORITHMS_INSERTSORT_H
#define SORTING_ALGORITHMS_INSERTSORT_H
#include <vector>

// sortowanie przez wstawianie

template <typename T>
class InsertSort
{
public:
    void sort(typename std::vector<T>::iterator start, typename std::vector<T>::iterator end){
        if(std::distance(start, end) <= 1)
            return;

        // loop from first element to the last
        // start + 1 is the seconds element
         for(auto i = start + 1; i < end; i++){
            // get the current element's vlue
            // and get the element just behind it
            auto value = *i;
            auto previous = i - 1;

            // loop to sort elements and swap them
            while(previous >= start && *previous > value){
                *(previous + 1) = *previous;
                previous--;
            }
            *(previous + 1) = value;
        }
    };
};

#endif //SORTING_ALGORITHMS_INSERTSORT_H
