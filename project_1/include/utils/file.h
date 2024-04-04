#ifndef FILE_H
#define FILE_H

#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <utils/generator.h>

template <typename T>
class FileIO{
    public:
        void write(std::string file_name, std::vector<T> items){
            std::fstream file(file_name, std::ios::out);

            if(!file.is_open())
                return;

            for(T item : items)
                file << item << "\n";

            file.close();
        };
    
        
        std::vector<T> read(std::string file_name){
            std::fstream file(file_name, std::ios::in);
            std::vector<T> buffer;

            if(!file.is_open())
                return buffer;


            T value;
            std::string output;

            while(getline(file, output)){
                std::istringstream stream(output);
                stream >> value;
                buffer.push_back(value);
            }

            file.close();
            return buffer;
        };
};


#endif