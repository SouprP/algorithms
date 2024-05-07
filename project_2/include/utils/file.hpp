#ifndef FILE_HPP
#define FILE_HPP

#include <iostream>
#include <vector>
#include <istream>
#include <sstream>

class FileReader{
    private:
        std::vector<std::string> data;

        void read_file();
    public:
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

template <typename T>
class FileWriter{
    private:
        size_t size;

    public:
        void write();
};

#endif