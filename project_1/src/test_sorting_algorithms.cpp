#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"

//#include "algorithms/bubblesort.h"
#include "algorithms/insertsort.h"
#include "algorithms/heapsort.h"
#include "algorithms/mergesort.h"
//#include "algorithms/shellsort.h"
#include "algorithms/quicksort.h"
#include "algorithms/introsort.h"
#include <utils/generator.h>

using namespace std::string_literals;

std::vector<int> getTestData()
{
    return {11,102,1,13,25,18,20,7,8,6,103,3,1}; /// Można modyfikować
}

std::vector<int> getCustomData(){
    Generator gen;

    return gen.generate_int(1000);
}

std::vector<int> getSortedData()
{
    auto data = getTestData();
    std::sort(data.begin(),data.end());
    return data;
}

TEST_CASE("Quicksort")
{
    auto data = getTestData();
    auto resultData = getSortedData();

    //BubbleSort<int> bubbleSort;
    QuickSort<int> sorter;
    sorter.sort(data.begin(),data.end());

    REQUIRE(data == resultData);
}

TEST_CASE("Mergesort")
{
    auto data = getTestData();
    auto resultData = getSortedData();

    MergeSort<int> sorter;
    sorter.sort(data.begin(),data.end());

    REQUIRE(data == resultData);
}

/*
TEST_CASE("Heapsort")
{
    auto data = getTestData();
    auto resultData = getSortedData();

    HeapSort<int> sorter;
    sorter.sort(data.begin(),data.end());

    REQUIRE(data == resultData);
}
*/

TEST_CASE("Insertsort")
{
    auto data = getTestData();
    auto resultData = getSortedData();

    InsertSort<int> sorter;
    sorter.sort(data.begin(),data.end());

    REQUIRE(data == resultData);
}


TEST_CASE("Heapsort")
{
    auto data = getTestData();
    auto resultData = getSortedData();

    HeapSort<int> sorter;
    sorter.sort(data.begin(),data.end());

    REQUIRE(data == resultData);
}

TEST_CASE("Custom Heapsort")
{
    auto data = getCustomData();
    auto resultData = data;
    std::sort(resultData.begin(), resultData.end());

    HeapSort<int> sorter;
    sorter.sort(data.begin(),data.end());

    REQUIRE(data == resultData);
}


TEST_CASE("Introsort")
{
    auto data = getCustomData();
    auto resultData = data;
    std::sort(resultData.begin(), resultData.end());

        
    IntroSort<int> sorter;
    sorter.sort(data.begin(),data.end());

    REQUIRE(data == resultData);
}