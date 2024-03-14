#include <headers/quicksort.h>

template<class T>
void Quicksort<T>::sort(){
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
void Quicksort<T>::sort(size_t low, size_t high){
    size_t pivot = get_pivot(low, high);

    sort(low, pivot-1);
    sort(pivot + 1, high);
}

template<class T>
void Quicksort<T>::swap(size_t index_low, size_t index_high){
    auto value_low = data.at(index_low);
    auto value_high = data.at(index_high);

    data.at(index_low) = value_high;
    data.at(index_high) = value_low;
}

template<class T>
void Quicksort<T>::set_data(std::vector<T> data){
    this->data = data;
}

template<class T>
size_t Quicksort<T>::get_pivot(size_t low, size_t high){
    auto pivot_value = data.at(high);
    size_t index= low - 1;

    for(size_t i = low; i < high; i++){
        if(data.at(i) < pivot_value){
            index++;
            swap(index, i);
        }
    }
    
    swap(index+1, high);
    return index+1;
}

template<class T>
std::vector<T> Quicksort<T>::get_data(){
    return data;
}