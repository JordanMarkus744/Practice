#include <iostream>
#include <vector>
#pragma once

template<typename T>
class Matrix{
    int NumRows;
    int NumCols;
    
    public:
    std::vector<std::vector<T>> matrix;

    Matrix(){
        NumRows = 0;
        NumCols = 0;
        matrix.resize(NumRows, std::vector<T>(NumCols));
    }

    Matrix(int num){ // Square Matrix
        NumRows = num;
        NumCols = num;
        matrix.resize(NumRows, std::vector<T>(NumCols));
    }

    Matrix(int row, int col){
        NumRows = row;
        NumCols = col;
        matrix.resize(NumRows, std::vector<T>(NumCols));
    }

    int getRows(){
        return this->NumRows;
    }

    int getCols(){
        return this->NumCols;
    }

    void MatrixInput(){
        for (int i = 0; i < NumRows; i++){
            for (int j = 0; j < NumCols; j++){
                T value;
                std::cout << "What is the value for row " << i << " column " << j << "?" << std::endl;
                std::cin >> value;
                this->matrix[i][j] = value;
            }
        }
    }

    Matrix<T> Multiplication(Matrix<T>& Secondmatrix){
        if (this->NumRows == Secondmatrix.getCols()){ // If this is true, then we can multiply them  
            Matrix<T> result(this->NumRows, Secondmatrix.getCols());

            for (int i = 0; i < NumRows; i++){
                for (int j = 0; j < Secondmatrix.getCols(); j++){
                    T newElement = NULL;
                    for (int k = 0; k < Secondmatrix.getRows(); k++){
                        newElement += this->matrix[i][k] * Secondmatrix.matrix[k][j];
                        std::cout << "\n" << this->matrix[i][k] << " * " << Secondmatrix.matrix[k][j] << " = " << newElement << std::endl;
                    }
                    result.matrix[i][j] = newElement;
                }
            }
            return result;
        }
        else{
            Matrix<T> result;
            std::cout << "The row length of the first matrix has to be equal to the col length of the second matrix!" << std::endl;
            std::cout << "Row length of first is: " << this->getRows() << "\t Col length of second is: " << Secondmatrix.getCols() << std::endl;
            return result;
        }
    }

    void PrintMatrix(){
        for (int i = 0; i < NumRows; i++){
            for (int j = 0; j < NumCols; j++){
                std::cout << this->matrix[i][j] << ", ";
            }
            std::cout << "\n";
        }
    }
};