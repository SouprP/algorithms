#include <iostream>
#include <vector>
#include <headers/generator.h>
#include <headers/quicksort.h>


int main(int argc, char** argv){
    std::chrono::high_resolution_clock::time_point seed 
    = std::chrono::high_resolution_clock::now();
    Generator *gen = new Generator(seed);

    //std::vector<int> data = {10, 10, 1, 5, 10, 9, 2};
    std::vector<int> data = gen->generate_int(100);

    Quicksort<int> quicksort;
    quicksort.set_data(data);
    quicksort.sort();


    auto returned_data = quicksort.get_data();
    //std::cout << "Sorted:       ";
    for(auto obj : returned_data)
        std::cout << obj << ", ";
    std::cout << std::endl;

    /*
    std::cout << "Unsorted:     ";    
    for(auto obj : data)
        std::cout << obj << ", ";

    std::cout << std::endl;
    */
    return 0;
}