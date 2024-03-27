#ifndef FILE_H
#define FILE_H

#include <fstream>
#include <string>
#include <vector>
#include <utils/generator.h>

template <typename T>
class FileIO{
    public:
        void write(std::string file_name, std::vector<T> items){
            std::fstream file(file_name, std::fstream::in);

            for(T item : items)
                file << item << std::endl;

            file.close();
        };
    
        
        std::vector<T> read(std::string file_name){
            std::fstream file(file_name, std::fstream::out);
            std::string output;

            while(getline(file, output))
                std::cout << output << std::endl;

            file.close();
            return std::vector<T>(5);
        };
};


#endif