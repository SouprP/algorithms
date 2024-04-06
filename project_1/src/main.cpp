#include <iostream>
#include <chrono>

#include <utils/generator.h>
#include <utils/file.h>
#include <utils/tools.h>

#include <algorithms/insertsort.h>
#include <algorithms/introsort.h>
#include <algorithms/heapsort.h>
#include <algorithms/mergesort.h>
#include <algorithms/quicksort.h>

// time utils definisions
typedef std::chrono::high_resolution_clock::time_point TimeVar;

#define duration(a) std::chrono::duration_cast<std::chrono::microseconds>(a).count()
#define timeNow() std::chrono::high_resolution_clock::now()


// data sizes
std::vector<size_t> DATA_SIZES = {10000, 50000, 100000, 500000, 1000000};


std::vector<int> getTestData()
{
    //Generator gen;
    //return gen.generate_int(10);
    return {11,102,1,13,25,18,20,7,8,6,103,3,1}; /// Można modyfikować
    //return {11,102,1,13,25,18,20,7,8,6};
}

int main(int argc, char* argv[])
{
    /*
    auto d = getTestData();
    Tools<int> tol;
    QuickSort<int> sorter;
    //tol.sort_perc(d.begin(), d.end(), 99.7);
    //tol.sort_reverse(d.begin(), d.end());
    //sorter.sort(d.begin(), d.end());

    for(auto obj : d)
        std::cout << obj << std::endl;
    


    return 0;
    */

    for(auto SIZE : DATA_SIZES){
        std::cout << SIZE << std::endl << std::endl;

        Tools<int> tools;

        QuickSort<int> quick_sort;
        MergeSort<int> merge_sort;
        IntroSort<int> intro_sort;

        TimeVar start;
        TimeVar end;

        size_t time_quick = 0;
        size_t time_merge = 0;
        size_t time_intro = 0;

        for(uint8_t i = 0; i < 100; i++){
            Generator gen; // Generator needs to be here as it uses srand()
            std::vector<int> data = gen.generate_int(SIZE);

            // uncomment when needed to sort only a part of data or sort in reverse
            //tools.sort_perc(data.begin(), data.end(), 90); // 25, 50, 75, 95, 99,7
            //tools.sort_reverse(data.begin(), data.end());

            // we sort temp_data, so we still have the original data 
            std::vector<int> temp_data = data;


            start = timeNow();
            quick_sort.sort(temp_data.begin(), temp_data.end());
            end = timeNow();
            time_quick += duration(end - start);


            temp_data = data;
            start = timeNow();
            merge_sort.sort(temp_data.begin(), temp_data.end());
            end = timeNow();
            time_merge += duration(end - start);

            temp_data = data;
            start = timeNow();
            intro_sort.sort(temp_data.begin(), temp_data.end());
            end = timeNow();
            time_intro += duration(end - start);
        }

        // print out average time of 100 executions
        std::cout << "QuickSort:  " << time_quick / 100 << "us" << std::endl;
        std::cout << "MergeSort:  " << time_merge / 100 << "us" << std::endl;
        std::cout << "IntroSort:  " << time_intro / 100 << "us" << std::endl;
        std::cout << std::endl;
    }
    return 0;
}
