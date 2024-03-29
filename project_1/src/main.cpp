#include <iostream>
#include <utils/generator.h>
#include <utils/file.h>

#include <algorithms/mergesort.h>
#include <algorithms/quicksort.h>

int main(int argc, char* argv[])
{
    Generator gen = Generator();
    //std::cout<< "Tu wykonujemy testy efektywności algorytmów"<<std::endl;
    auto data = gen.generate_int(100);
    //QuickSort<int> sorter;
    //MergeSort<int> sorter;
    //sorter.sort(data.begin(), data.end());

    FileIO<int> file;
    file.write("data_test.txt", data);
    auto read = file.read("data_test.txt");
    
    for(auto obj : read)
        std::cout << obj << std::endl;
    return 0;
}
