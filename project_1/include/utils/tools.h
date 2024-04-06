#ifndef TOOLS_H
#define TOOLS_H

#include <iostream>
#include <algorithm>
#include <utils/generator.h>

template<typename T>
class Tools{
    public:
        void sort_perc(typename std::vector<T>::iterator start, typename std::vector<T>::iterator end, uint8_t perc){
            if(perc < 0 || perc > 100)
                return;

            // get the point where 0.perc * distance is
            size_t distance = std::distance(start, end);
            float_t dec_perc = (float_t) perc / 100;
            dec_perc = dec_perc * distance;

            // sort from beggining to pivot
            auto pivot = start + (size_t) dec_perc;
            std::sort(start, pivot);
        }

        void sort_reverse(typename std::vector<T>::iterator start, typename std::vector<T>::iterator end){
            std::sort(start, end, std::greater<>());
        }
};

#endif