#include <vector>
#include <iostream>
using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {
    vector<int> result;
    int* ptr1 = &numbers[0];
    int* ptr2 = &numbers[numbers.size()-1];

    int index1 = 0;
    int index2 = numbers.size() - 1;

    for (int i = 0; i < numbers.size(); i++){
        if (ptr1 == ptr2){
            break;
        }
        else if (*ptr1 + *ptr2 != target){
            std::cout << "Pointer 1: " << *ptr1 << std::endl;
            std::cout << "Pointer 2: " << *ptr2 << std::endl;
            if (*ptr1 + *ptr2 > target){
                ptr2--;
                index2--;
            }
            else{
                ptr1++;
                index1++;
            }
        }
        else{
            result.push_back(++index1);
            result.push_back(++index2);
            return result;
        }
    }
    return result;
}

int main(){
    vector<int> numbers;
    vector<int> result;
    int target = 9;
    numbers.push_back(2);
    numbers.push_back(7);
    numbers.push_back(11);
    numbers.push_back(13);
    result = twoSum(numbers, target);
    for (unsigned int i = 0; i < result.size(); i++){
        std::cout << result[i] << ", ";
    }
    return 0;
}