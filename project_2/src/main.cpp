#include <iostream>
#include <fstream>
#include <filesystem>
#include <sstream>

#include <catch2/catch.hpp>
#include <structures/matrix.hpp>

#include <graphs/adjacency_matrix_graph.hpp>
#include <graphs/adjacency_list_graph.hpp>

#define DATA_DIR_PATH


const std::filesystem::path dataDirectoryPath{DATA_DIR_PATH};

int main(int argc, char* argv[])
{
    auto [inputFile, refFile] = GENERATE(std::make_tuple(dataDirectoryPath / "graph" / "graphV10D0.5.txt",
                                                         dataDirectoryPath / "sp_result" / "spV10D0.5.txt"),
                                         std::make_tuple(dataDirectoryPath / "graph" / "graphV30D0.25.txt",
                                                         dataDirectoryPath / "sp_result" / "spV30D0.25.txt"),
                                         std::make_tuple(dataDirectoryPath / "graph" / "graphV200D0.75.txt",
                                                         dataDirectoryPath / "sp_result" / "spV200D0.75.txt"));


    std::ifstream inputStream{inputFile}, refStream{refFile};


    auto graph = AdjacencyMatrixGraph::createGraph(inputStream);
    return 0;
}
