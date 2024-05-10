#include <iostream>
#include <fstream>
#include <filesystem>
#include <sstream>

#include <catch2/catch.hpp>
#include <structures/matrix.hpp>

#include <graphs/adjacency_matrix_graph.hpp>
#include <graphs/adjacency_list_graph.hpp>
#include <graphs/shortest_path_algorithms.hpp>

//#define DATA_DIR "../sp_data/"
#define DATA_DIR "./"
#define FILE_NAME "graph.txt"

const std::filesystem::path dataDirectoryPath{DATA_DIR};

int main(int argc, char* argv[])
{
    //auto inputFile = dataDirectoryPath / "graph" / "graphV10D0.5.txt";
    auto inputFile = dataDirectoryPath / "graph_test.txt";
    std::ifstream inputStream{inputFile};

    FileWriter writer = FileWriter();
    writer.write(10, 10);
    std::fstream file(FILE_NAME);

    //if(is){
    //    std::string line;
    //    while(std::getline(*is, line))
    //        std::cout << line;
    //}
        
    
    //return 1;
    //std::string line;
    //while(std::getline(*stream.get(), line))
    //    std::cout << line;
    //return 0;
    
    //std::cout << inputFile.c_str() << std::endl;

    //auto graph = AdjacencyMatrixGraph::createGraph(inputStream);
    //auto graph = AdjacencyListGraph::createGraph(inputStream);
    auto graph = AdjacencyListGraph::createGraph(file);
    
    Vertex* v = graph.get()->vertices().at(1);
    Edge* e = graph.get()->edges().at(1);


    std::cout << "Vertex: " << v->index << std::endl;
    std::cout << "Edge: " << e->v1->index << ", " 
        << e->v2->index <<std::endl;
    std::cout << "-------------------" << std::endl;
    graph.get()->visualise();
    std::cout << "-------------------" << std::endl;

    auto G = graph.get();



    /**
     * 
     *          THESE WORK
     * 
    */

    
    // insertVertex and insertEdge work
    // because the correct graph is created

    //graph.get()->removeEdge(e); 
    //graph.get()->removeVertex(v);

    //for(auto obj : graph.get()->incidentEdges(v))
        //std::cout << "Incident edge: " << obj->weight << std::endl;

    //for(auto obj : G->edges())
        //std::cout << "Edge: " << obj->weight << std::endl;

    //for(auto obj : G->vertices())
    //    std::cout << "Vertex: " << obj->label << std::endl;

    //for(auto obj : G->endVertices(e))
    //    std::cout << "Vertex: " << obj->label << std::endl;

    // 0 = false
    // 1 = true
    // V1 and V2 are adjacent
    //std::cout << G->areAdjacent(G->vertices()[0], G->vertices()[1]) << std::endl;

    // V1 and V4 are not adjacent
    //std::cout << G->areAdjacent(G->vertices()[0], G->vertices()[3]) << std::endl;

    /**
     * 
     *          THESE DONT WORK
     * 
    */
    
    // everything works! yay!

    std::cout << "-------------------" << std::endl;
    graph.get()->visualise();

    //auto graph = AdjacencyMatrixGraph::createGraph(inputStream);

    //ShortestPathResult result, refResult;

    //int sourceIndex = 2;

    //dijkstra(*graph, sourceIndex, result);
    //dijkstra(*graph, sourceIndex, result);
    return 0;
}
