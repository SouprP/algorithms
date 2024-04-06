#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include <utils/tools.h>

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

    return gen.generate_int(10000);
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


TEST_CASE("Introsort")
{
    auto data = getCustomData();
    auto resultData = data;
    std::sort(resultData.begin(), resultData.end());

    IntroSort<int> sorter;
    sorter.sort(data.begin(),data.end());

    REQUIRE(data == resultData);
}

TEST_CASE("Introsort Reverse"){
    auto data = getCustomData();
    auto resultData = data;

    Tools<int> tools;
    tools.sort_reverse(data.begin(),data.end());

    std::sort(resultData.begin(), resultData.end());
        
    IntroSort<int> sorter;
    sorter.sort(data.begin(),data.end());

    REQUIRE(data == resultData);
}


TEST_CASE("Introsort Percentage"){
    auto data = getCustomData();
    auto resultData = data;

    Tools<int> tools;
    tools.sort_perc(data.begin(),data.end(), 50);

    std::sort(resultData.begin(), resultData.end());
        
    IntroSort<int> sorter;
    sorter.sort(data.begin(),data.end());

    REQUIRE(data == resultData);
}
