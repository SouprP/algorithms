#ifndef SORTING_ALGORITHMS_HEAPSORT_H
#define SORTING_ALGORITHMS_HEAPSORT_H
#include <vector>

// sortowanie przez kopcowanie. Należy samodzielnie zaimplementować odpowiedni kopiec, który kopcuje bez użycia dodatkowej pamięci.

template <typename T>
class HeapSort
{
    public:
        void sort(typename std::vector<T>::iterator start, 
                typename std::vector<T>::iterator end){
            if(std::distance(start, end) <= 1)
                return;

            auto size = end - start;
            for (auto i = size / 2 - 1; i >= 0; --i) {
                heapify(start, end, start + i);
            }

            for (auto it = end - 1; it > start; --it) {
                std::swap(*start, *it);
                heapify(start, it, start);
            }
        };

    private:

        void heapify(typename std::vector<T>::iterator start,
                typename std::vector<T>::iterator end,
                typename std::vector<T>::iterator root){
            // make a heap
            // get rid of old root
            // and get the new largest number (root)
            //
            //             (largest)
            //               root
            //             /      \
            //   left_child        right_child
            //
            //
            auto size = end - start;
            auto left_child = 2 * (root - start) + 1;
            auto right_child = left_child + 1;
            auto largest = root;

            if (left_child < size && *(start + left_child) > *largest)
                largest = start + left_child;
            if (right_child < size && *(start + right_child) > *largest)
                largest = start + right_child;

            if (largest != root) {
                std::swap(*root, *largest);
                heapify(start, end, largest);
            }
        };
};

#endif //SORTING_ALGORITHMS_HEAPSORT_H
