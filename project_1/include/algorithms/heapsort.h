#ifndef SORTING_ALGORITHMS_HEAPSORT_H
#define SORTING_ALGORITHMS_HEAPSORT_H
#include <vector>

// sortowanie przez kopcowanie. Należy samodzielnie zaimplementować odpowiedni kopiec, który kopcuje bez użycia dodatkowej pamięci.

template <typename T>
class HeapSort
{
    public:
        void sort(typename std::vector<T>::iterator start, 
            typename std::vector<T>::iterator end)
        {
            
        };

    private:
        void make_heap(typename std::vector<T>::iterator start,
            typename std::vector<T>::iterator end,
            typename std::vector<T>::iterator root)
        {

        };
};

#endif //SORTING_ALGORITHMS_HEAPSORT_H
