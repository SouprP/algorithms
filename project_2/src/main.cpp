#include <iostream>
#include <fstream>
#include <filesystem>
#include <sstream>
#include <chrono>

#include <catch2/catch.hpp>

#include <graphs/adjacency_matrix_graph.hpp>
#include <graphs/adjacency_list_graph.hpp>
#include <graphs/shortest_path_algorithms.hpp>

//#define DATA_DIR "../sp_data/"
#define DATA_DIR "./"
//#define DATA_DIR "../Debug/"
#define FILE_NAME "graph.txt"

typedef std::chrono::high_resolution_clock::time_point TimeVar;

#define duration(a) std::chrono::duration_cast<std::chrono::microseconds>(a).count()
#define timeNow() std::chrono::high_resolution_clock::now()

std::vector<int> GRAPH_SIZES = {10, 50, 100, 500, 1000};
std::vector<int> DENSITIES = {25, 50, 75, 100};

const std::filesystem::path dataDirectoryPath{DATA_DIR};

void time_test(){
    ShortestPathResult result, refResult;
    int sourceIndex = 5;
    for(auto density : DENSITIES){
        std::cout << std::endl << "=====================================" << std::endl;
        std::cout << "DENSITY: " << density << std::endl;
        //std::cout << "CURRENT SIZE: " << size << std::endl << std::endl;
        for(auto size : GRAPH_SIZES){
            std::cout << "CURRENT SIZE: " << size << std::endl << std::endl;
            //std::cout << "DENSITY: " << density << std::endl;
            TimeVar start;
            TimeVar end;

            size_t m_dijkstra_time = 0;
            size_t m_bellman_time = 0;
            size_t l_dijkstra_time = 0;
            size_t l_bellman_time = 0;


            for(int loop = 0; loop < 1; loop++){
                FileWriter writer = FileWriter();
                writer.write(size, density);
                std::fstream file(writer.get_file_name());

                
                auto m_graph = AdjacencyMatrixGraph::createGraph(file);

                // reset to begin of file
                file.clear();
                file.seekg(0);

                auto l_graph = AdjacencyListGraph::createGraph(file);

                // DIJKSTRA MATRIX
                start = timeNow();
                dijkstra(*m_graph, sourceIndex, result);
                end = timeNow();
                m_dijkstra_time += duration(end - start);

                // DIJKSTRA LIST
                start = timeNow();
                dijkstra(*l_graph, sourceIndex, result);
                end = timeNow();
                l_dijkstra_time += duration(end - start);

                // BELLMAN-FORD MATRIX
                start = timeNow();
                bellmanFord(*m_graph, sourceIndex, result);
                end = timeNow();
                m_bellman_time += duration(end - start);

                // BELLMAN-FORD LIST
                start = timeNow();
                bellmanFord(*l_graph, sourceIndex, result);
                end = timeNow();
                l_bellman_time += duration(end - start);
            }

            std::cout << "Matrix Djikstra:   " << m_dijkstra_time  << "us" << std::endl;
            std::cout << "Matrix Bellman:    " << m_bellman_time  << "us" << std::endl;
            std::cout << "List Djikstra:     " << l_dijkstra_time  << "us" << std::endl;
            std::cout << "List Bellman:      " << l_bellman_time  << "us" << std::endl;
            std::cout << std::endl;
        }
        
    }
}

int main(int argc, char* argv[])
{
    ShortestPathResult result, refResult;
    int sourceIndex = 5;

    FileWriter t_writer = FileWriter();
    t_writer.write(10, 50);
    std::fstream file(t_writer.get_file_name());

    time_test();

    // auto graph = AdjacencyListGraph::createGraph(file);
    // auto graph = AdjacencyMatrixGraph::createGraph(file);
    
    // Vertex* v = graph.get()->vertices().at(1);
    // Edge* e = graph.get()->edges().at(1);


    // std::cout << "Vertex: " << v->index << std::endl;
    // std::cout << "Edge: " << e->v1->index << ", " 
    //     << e->v2->index <<std::endl;
    // std::cout << "-------------------" << std::endl;
    // graph.get()->visualise();
    // std::cout << "-------------------" << std::endl;

    // auto G = graph.get();

    // // insertVertex and insertEdge work
    // // because the correct graph is created

    // //graph.get()->removeEdge(e); 
    // //graph.get()->removeVertex(v);
    
    //  for(auto obj : graph.get()->incidentEdges(v))
    //      std::cout << "Incident edge go to V: " << obj->v2->index << std::endl;
    // return 1;
    // //for(auto obj : G->edges())
    //     //std::cout << "Edge: " << obj->weight << std::endl;

    // //std::cout << "Opposite: " << G->opposite(v, e)->index << std::endl;

    // for(auto obj : G->vertices())
    //     std::cout << "Vertex: " << obj->label << std::endl;

    // for(auto obj : G->endVertices(e))
    //    std::cout << "Vertex: " << obj->label << std::endl;

    // // 0 = false
    // // 1 = true
    // // V1 and V2 are adjacent
    // //std::cout << G->areAdjacent(G->vertices()[0], G->vertices()[1]) << std::endl;

    // // V1 and V4 are not adjacent
    // //std::cout << G->areAdjacent(G->vertices()[0], G->vertices()[3]) << std::endl;

    return 0;
}
