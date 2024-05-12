#ifndef FILE_HPP
#define FILE_HPP

#include <iostream>
#include <vector>
#include <sstream>
#include <random>
#include <fstream>

#include <utils/node.hpp>

#define FILE_NAME "graph.txt"
#define MIN_WEIGHT 1
#define MAX_WEIGHT std::pow(2, 12) // 4096

class FileReader{
    private:
        std::vector<std::string> data;

    public:
        FileReader();
        
        FileReader(std::istream& is){
            std::string output;

            while(std::getline(is, output))
                data.push_back(output);
            
        }

        std::vector<std::string> get_lines(){
            return data;
        }

        size_t get_size(){
            return data.size();
        }
        
    std::vector<size_t> parse(std::string line){
        std::vector<size_t> values;
        size_t value;

        std::istringstream stream(line);
        while(stream >> value)
            values.push_back(value);

        return values;

    }

    size_t get_graph_size(){
        return parse(data.front())[0];
    }

    size_t get_edges_count(){
        return parse(data.front())[1];
    }

    size_t get_starting_vertex(){
        return parse(data.back())[0];
    }

};

class FileWriter{
    public:
        FileWriter(){
            // init srand at current time
            srand(time(NULL));
        }

        void write(size_t size, uint8_t density){
            if(density > 100)
                return;

            std::stringstream buffer;

            // max edges in a graph = V * (V-1) / 2
            size_t max_edges = size * (size - 1) / 2;
            float_t perc = (float_t) density / 100;
            size_t edge_per_v = (size - 1) * perc;

            std::vector<Edge*> e_vector;
            buffer << size << " " << edge_per_v * size << "\n";
            
            // go through all verteces
            // in order to create edges for them
            for(size_t vertex = 0; vertex < size; vertex++){
                std::vector<size_t> used_verteces;

                // for each vertex create edge_per_v edges
                for(size_t edge = 0; edge < edge_per_v; edge++){
                    // index of the vertex to connect to
                    while(true){
                        // random vertex
                        size_t temp = random(0, size);

                        // if not contained inside our vector
                        // and if its not the same
                        // as our vertex then add it as an edge
                        if(!contains(used_verteces, temp))
                            if(vertex != temp){
                                used_verteces.push_back(temp);
                                break;
                            }
                    }
                }

                // write all edges for a vertex to a file
                // and generate a random weight for them
                for(auto obj : used_verteces)
                    buffer << vertex << " " << obj 
                        << " " << random(MIN_WEIGHT, MAX_WEIGHT) << "\n";
            }

            // generate a starting vertex
            buffer << random(0, size) << "\n";

            // remove the file
            // if exists
            std::remove(FILE_NAME);
            std::ofstream file;
            file.open(FILE_NAME);

            // if file is opened
            // write to it
            if(file){
                file << buffer.str();
                file.close();
            }
        }

        bool contains(std::vector<size_t> v, size_t number_to_check){
            // vector is empty
            // so it does not contain our number
            if(v.empty())
                return false;

            // look for the number
            // if found return true
            for(auto obj : v)
                if(obj == number_to_check)
                    return true;

            // not found
            return false;
        }

        size_t random(size_t low, size_t high){
            return rand() % high + low;
        }

        std::string get_file_name(){
            return FILE_NAME;
        }
};

#endif