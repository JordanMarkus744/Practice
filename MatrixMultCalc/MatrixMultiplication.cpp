#include <iostream>
#include "Matrix.hpp"

int main(){
    Matrix<int> matrix1(2); // 3x3 matrix
    Matrix<int> matrix2(2); 
    matrix1.MatrixInput();
    matrix2.MatrixInput();
    std::cout << "\n";
    matrix1.PrintMatrix();
    std::cout << "\n";
    matrix2.PrintMatrix();

    std::cout << "\n";
    Matrix<int> result = matrix1.Multiplication(matrix2);
    result.PrintMatrix();
    return 0;
}