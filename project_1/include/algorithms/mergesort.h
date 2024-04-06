#ifndef SORTING_ALGORITHMS_MERGESORT_H
#define SORTING_ALGORITHMS_MERGESORT_H
#include <vector>

// sortowanie przez scalanie

template <typename T>
class MergeSort{
    public:
        void sort(typename std::vector<T>::iterator start,typename std::vector<T>::iterator end){
                if(std::distance(start, end) <= 1)
                    return;

                auto pivot = start + std::distance(start, end) / 2;
                sort(start, pivot);
                sort(pivot, end); 
                merge(start, pivot, end);
            };

    private:
        void merge(typename std::vector<T>::iterator start,
            typename std::vector<T>::iterator pivot,
            typename std::vector<T>::iterator end){
                std::vector<T> temp(std::distance(start, end));
                auto low = start;
                auto low_max = pivot;
                auto high = pivot;
                auto high_max = end;
                size_t temp_index = 0;

                while(low != low_max && high != high_max){
                    if(*high < *low){
                        temp[temp_index++] = *high;
                        high++;
                    }
                    else{
                        temp[temp_index++] = *low;
                        low++;;
                    }
                }

                std::copy(low, low_max, &temp[temp_index]);
                std::copy(high, high_max, &temp[temp_index]);
                std::copy(temp.begin(), temp.end(), start);
        };

};
#endif //SORTING_ALGORITHMS_MERGESORT_H
