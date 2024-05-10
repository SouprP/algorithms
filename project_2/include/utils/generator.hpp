#ifndef GENERATOR_HPP_
#define GENERATOR_HPP_

#include <cstddef>
#include <vector>
#include <random>
#include <sstream>
#include <iostream>
#include <memory>

#include <utils/node.hpp>

#define FILE_NAME "graph.txt"
#define MIN_WEIGHT 1
#define MAX_WEIGHT 100

enum DENSITY{
    D_25,
    D_50,
    D_75,
    D_100
};

class Generator{
    public:
        Generator(){
            srand(time(NULL));
        }

        void generate_graph(size_t size, uint8_t density){
            // create all vertex
            // get max edge count for a single vertex = vertex/density?
            if(density > 100)
                return;

            std::stringstream buffer;
            
            // max edges in a graph = V * (V - 1) / 2
            size_t max_edges = size * (size - 1) / 2;
            float_t perc = (float_t) density / 100;
            size_t edges_per_v = max_edges * perc;

            std::vector<Edge*> edges_vector;

            // header of graph file
            // vertex_count and edges_count
            // edges_per_v * size
            buffer << size << " " << edges_per_v << "\n";

            for(size_t vertex = 0; vertex < size; vertex++){
                std::vector<size_t> used_verteces;
                Vertex* v1 = new Vertex(vertex, false);

                // create edge_per_v edges for every vertex
                std::cout << std::endl << vertex << ":  [";
                for(size_t edge = 0; edge < size - 1; edge++){
                    // index of the vertex to connect to
                    size_t edge_v;
                    do
                    {
                        // get a random vertex
                        edge_v = random(0, size);
                        //Vertex* v2 = new Vertex(edge_v, false);
                        //Edge* temp = new Edge(v1, v2, 0);

                        // loop till the randomized vertex
                        // is not already in the std::vector
                        // and it's not the vertex we are currently creating
                        // edges for
                        
                    } while (contains(used_verteces, edge_v) && vertex == edge_v);

                    //std::cout << "done for vertex: " << vertex;
                    std::cout << " " << edge_v;
                    used_verteces.push_back(edge_v);
                }

                // write to file
                for(auto obj : used_verteces){
                    for(auto used_edge : edges_vector)
                        if(used_edge->v1->index != obj && used_edge->v2->index != vertex)
                            if(used_edge->v2->index != obj && used_edge->v1->index != vertex);
                                edges_vector.push_back(new Edge(v1, new Vertex(obj, false), random(MIN_WEIGHT, MAX_WEIGHT)));
                                buffer << vertex << " " << obj << " " << random(MIN_WEIGHT, MAX_WEIGHT) << "\n";
                            }
                
                    

            }

            buffer << random(0, size) << "\n";


            //std::string data   = "3 2\n";
            //std::string data_1 = "0 1 5\n";
            //std::string data_2 = "0 2 3\n";
            //std::string data_3 = "1\n";

            //buffer << data << data_1 << data_2 << data_3;

            std::remove(FILE_NAME);
            std::ofstream file(FILE_NAME);

            if(file){
                file << buffer.str();
                file.close();
            }
            
        }

        size_t random(size_t low, size_t high){
            return rand() % high + low;
        }

        bool contains(std::vector<size_t> v, size_t item){
            // vector empty so it doesnt contain it
            if(v.empty())
                return false;

            // look for it, return true if found
            for(auto obj : v)
                if(obj == item)
                    return true;

            // nothing found
            return false;
        }
};

#endif