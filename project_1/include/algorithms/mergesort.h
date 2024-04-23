#ifndef SORTING_ALGORITHMS_MERGESORT_H
#define SORTING_ALGORITHMS_MERGESORT_H
#include <vector>

// sortowanie przez scalanie

template <typename T>
class MergeSort {
public:
    void sort(typename std::vector<T>::iterator start, typename std::vector<T>::iterator end) {
        
        if (std::distance(start, end) <= 1) return;

        typename std::vector<T>::iterator pivot = start + std::distance(start, end) / 2;

        sort(start, pivot);
        sort(pivot, end);
        merge(start, pivot, end);

    };

    void merge(typename std::vector<T>::iterator start, typename std::vector<T>::iterator pivot, typename std::vector<T>::iterator end) {

        typename std::vector<T>::iterator i1 = start;
        typename std::vector<T>::iterator i2 = pivot;
        typename std::vector<T>::iterator j1 = pivot;
        typename std::vector<T>::iterator j2 = end;

        std::vector<T> temporary(std::distance(start, end));
        int iterator = 0;
        
        while (i1 != i2 && j1 != j2) {

            if (*i1 < *j1) {

                temporary[iterator] = *i1;
                iterator++;
                i1++;

            }
            else {

                temporary[iterator] = *j1;
                iterator++;
                j1++;

            }

            while (i1 != i2) {

                temporary[iterator] = *i1;
                iterator++;
                i1++;

            }

            while (j1 != j2) {

                temporary[iterator] = *j1;
                iterator++;
                j1++;

            }

            iterator = 0;

            for (auto x = start; x != end; x++) {

                *x = temporary[iterator];
                iterator++;

            }

        }

    }

};
#endif //SORTING_ALGORITHMS_MERGESORT_H