#include <headers/quicksort.h>

template<class T>
void Quicksort<T>::sort(){
    if(data.size() == 0)
        return;

    size_t low = 0;
    size_t high = data.size() - 1;
    

    //std::cout << high << std::endl;
    //std::cout << "End:" << data.at(high) << std::endl;
    try{
        sort(low, high);
    }
    catch(const std::exception& ex){
        ex.what();
    }
    //sort(low, high);
    //size_t pivot = get_pivot(low, high);

    //sort(low, pivot-1);
    //sort(pivot + 1, high);
}

template<class T>
void Quicksort<T>::sort(size_t low, size_t high){
    if(low>=high)
        return;

    size_t pivot = get_pivot(low, high);

    sort(low, pivot-1);
    sort(pivot, high);
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
    size_t pivot = low + (high - low) / 2;
    auto pivot_value = data.at(pivot);

    size_t start = low;
    size_t end = high;
    while(start <= end){
        while(data.at(start) < pivot_value)
            start++;

        while(data.at(end) > pivot_value)
            end--;

        if(start <= end){
            swap(start, end);
            start++;
            end--;
        }
    }
    return start;
    /*int pivot = high;
    int start = low;
    auto pivot_value = data.at(pivot);


    for(int i = start; i < high; i++){
        if(data.at(i) < pivot_value){
            swap(i, start);
            start++;
        }
    }
    swap(start, pivot);
    return start;
    */
}

template<class T>
std::vector<T> Quicksort<T>::get_data(){
    return data;
}