#include <iostream>
#include <utils/generator.h>
#include <utils/file.h>

#include <structures/heap.h>
#include <algorithms/mergesort.h>
#include <algorithms/quicksort.h>

std::vector<int> getTestData()
{
    return {11,102,1,13,25,18,20,7,8,6,103,3,1}; /// Można modyfikować
}

int main(int argc, char* argv[])
{
    //Generator gen = Generator();
    //std::cout<< "Tu wykonujemy testy efektywności algorytmów"<<std::endl;
    //auto data = gen.generate_int(100);
    //QuickSort<int> sorter;
    //MergeSort<int> sorter;
    //sorter.sort(data.begin(), data.end());

    //FileIO<int> file;
    //file.write("data_test.txt", data);
    //auto read = file.read("data_test.txt");
    
    auto data = getTestData();


    Heap<int> heap = Heap(data);

    
    for(auto obj : data)
        std::cout << obj << std::endl;
    return 0;
}
