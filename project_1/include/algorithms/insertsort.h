#ifndef SORTING_ALGORITHMS_INSERTSORT_H
#define SORTING_ALGORITHMS_INSERTSORT_H
#include <vector>

// sortowanie przez wstawianie

template <typename T>
class InsertSort
{
public:
    void sort(typename std::vector<T>::iterator start, typename std::vector<T>::iterator end)
    {
         for(auto i = start + 1; i < end; i++){
            auto value = *i;
            auto previous = i - 1;

            while(previous >= start && *previous > value){
                *(previous + 1) = *previous;
                previous--;
            }
            *(previous + 1) = value;
        }
    };
};

#endif //SORTING_ALGORITHMS_INSERTSORT_H
