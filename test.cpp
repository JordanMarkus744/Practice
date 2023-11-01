#include <iostream>
#include <string>
template <typename T>
T sum(T first, T second){
    return first + second;
}

int main(){
    std::cout << sum(5,2) << std::endl;
    std::cout << sum(5.3,2.2) << std::endl;

    return 0;
}