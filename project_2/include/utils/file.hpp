#ifndef FILE_HPP
#define FILE_HPP

#include <iostream>
#include <vector>
#include <istream>
#include <sstream>

template <typename T>
class FileReader{
    private:
        std::vector<T> data;

        void read_file();
    public:
        FileReader(std::istream& is){
            T value;
            std::string output;

            while(getline(is, output)){
                std::istringstream stream(output);
                stream >> value;
                data.push_back(value);
            }
        }

        std::vector<T> get_lines(){
            return data;
        }

        size_t get_size(){
            return data.size();
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