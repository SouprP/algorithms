#ifndef MATRIX_HPP_
#define MATRIX_HPP_

#include <iostream>
#include <vector>

template<typename T>
class Matrix{
    //DynamicArray<DynamicArray<T>> matrix;
    std::vector<std::vector<T>> matrix;
    size_t size;

    public:
        Matrix(size_t size){
            this->size = size;
            matrix.resize(size);
            for(size_t row = 0; row < size; row++)
                matrix[row].resize(size);
        }

        ~Matrix(){
            // std::vector takes care of memory deallocation
        }

        void insert(T value, size_t row, size_t column){
            if(row >= size || column >= size)
                std::out_of_range("Row or column out of range");

            matrix[row][column] = value;
        }

        T get(size_t row, size_t column){
            if(row >= size || column >= size)
                std::out_of_range("Row or column out of range");

            return matrix[row][column];
        }

        std::vector<T> get_row(size_t row){
            return matrix[row];
        }

        std::vector<std::vector<T>> get_rows(){
            return matrix;
        }

        void remove_row(size_t index){
            matrix.erase(matrix.begin() + index);
        }

};

#endif