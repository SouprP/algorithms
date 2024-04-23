#ifndef SORTING_ALGORITHMS_QUICKSORT_H
#define SORTING_ALGORITHMS_QUICKSORT_H
#include <vector>

// quicksort

template <typename T>
class QuickSort {
public:

    void sort(typename std::vector<T>::iterator start, typename std::vector<T>::iterator end) {

        if (std::distance(start, end) <= 1) return;

        typename std::vector<T>::iterator pivot = partition(start, end);
        sort(start, pivot);
        sort(pivot + 1, end);

    };

    typename std::vector<T>::iterator partition(typename std::vector<T>::iterator start, typename std::vector<T>::iterator end) {

        typename std::vector<T>::iterator pivot = end - 1;
        typename std::vector<T>::iterator i = start;
        typename std::vector<T>::iterator j = start;

        while (j != pivot) {

            while (*j >= *pivot) j++;
            std::iter_swap(i, j);
            j++;
            i++;

        }

        std::iter_swap(i, pivot);
        return i;

    }

};
#endif //SORTING_ALGORITHMS_QUICKSORT_H