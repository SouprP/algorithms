#include <headers/mergesort.h>

template<class T>
void Mergesort<T>::sort(){
    if(data.size() == 0)
        return;

    size_t low = 0;
    size_t high = data.size() - 1;
    

    //std::cout << high << std::endl;
    //std::cout << "End:" << data.at(high) << std::endl;
    sort(low, high);
    //size_t pivot = get_pivot(low, high);

    //sort(low, pivot-1);
    //sort(pivot + 1, high);
}

template<class T>
void Mergesort<T>::sort(size_t low, size_t high){
    if(low>=high)
        return;

    size_t pivot = (low + high) / 2;

    sort(low, pivot);
    sort(pivot + 1, high);

    merge()
}

template<class T>
void Mergesort<T>::swap(size_t index_low, size_t index_high){
    auto value_low = data.at(index_low);
    auto value_high = data.at(index_high);

    data.at(index_low) = value_high;
    data.at(index_high) = value_low;
}

template<class T>
void Mergesort<T>::merge(size_t low, size_t pivot, size_t high){
    
}

template<class T>
void Mergesort<T>::set_data(std::vector<T> data){
    this->data = data;
}

template<class T>
std::vector<T> Mergesort<T>::get_data(){
    return data;
}