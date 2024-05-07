#include <iostream>
#include <fstream>
#include <filesystem>
#include <sstream>

#include <catch2/catch.hpp>
#include <structures/matrix.hpp>

#include <graphs/adjacency_matrix_graph.hpp>
#include <graphs/adjacency_list_graph.hpp>

#define DATA_DIR "../sp_data/"


const std::filesystem::path dataDirectoryPath{DATA_DIR};

int main(int argc, char* argv[])
{
    auto inputFile = dataDirectoryPath / "graph" / "graphV10D0.5.txt";
    std::ifstream inputStream{inputFile};

    std::cout << inputFile.c_str() << std::endl;
    auto graph = AdjacencyMatrixGraph::createGraph(inputStream);
    return 0;
}
