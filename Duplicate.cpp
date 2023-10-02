#include <map>
#include <iostream>
#include <vector>

class Duplicate{

public:

    bool hasDuplicate(std::vector<int> vec){
        std::map<char,int> Duplicate;
        int length = vec.size();
        for (int i = 0; i < length; i++){
            if (Duplicate[vec[i]]){
                std::cout << "Duplicate is: " << vec[i] << std::endl;
                return true;
            }
            Duplicate[vec[i]]++;
            std::cout << vec[i] << ": " << Duplicate[vec[i]] << std::endl;
        }
        return false;
    }
};

int main(){
    Duplicate dupe;
    int len = 50;
    std::vector<int> vec;
    vec.resize(len);
    for (int i = 0; i < len; i++){
        vec.push_back(i);
    }
    vec.push_back(3);
    
    bool hasDuplicate = dupe.hasDuplicate(vec);
    std::cout << hasDuplicate << std::endl;
}