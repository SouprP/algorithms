#include <iostream>
#include <vector>
#include <headers/quicksort.h>

int main(int argc, char** argv){
    std::vector<int> data = {5, 1, 2, 6, 8, 9, 2};

    Quicksort<int> quicksort;
    quicksort.set_data(data);
    quicksort.sort();

    auto returned_data = quicksort.get_data();
    for(auto obj : returned_data)
        std::cout << obj << std::endl;

    return 0;
}