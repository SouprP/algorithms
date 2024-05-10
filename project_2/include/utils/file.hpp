#ifndef FILE_HPP
#define FILE_HPP

#include <iostream>
#include <vector>
#include <istream>
#include <sstream>
#include <random>

#include <utils/node.hpp>

#define FILE_NAME "graph.txt"
#define MIN_WEIGHT 1
#define MAX_WEIGHT 100

class FileReader{
    private:
        std::vector<std::string> data;

    public:
        FileReader();
        
        FileReader(std::istream& is){
            std::string output;

            while(std::getline(is, output)){
                //std::istringstream stream(output);
                //stream >> value;
                data.push_back(output);
            }
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
            size_t edge_per_v = max_edges * perc;

            std::vector<Edge*> e_vector;
            buffer << size << " " << edge_per_v << "\n";
            //for()
        }

        std::string get_file_name(){
            return FILE_NAME;
        }
};

#endif