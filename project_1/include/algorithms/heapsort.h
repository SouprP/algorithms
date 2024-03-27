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
            auto largest = end;
            auto low = start + (std::distance(start, end) * 2 + 1);
            auto high = start + (std::distance(start, end) * 2 + 2);

            if(low < end && *low > *largest)
                largest = low;
            
            if(high < end && *high > *largest)
                largest = high;

            if(largest != end){
                std::swap(*end, *largest);
                heap();
            }
        };

    private:
        void heap()
        {
            
        };
};

#endif //SORTING_ALGORITHMS_HEAPSORT_H
