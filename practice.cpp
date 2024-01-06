#include <iostream>
#include <random>
#include <time.h>
using namespace std;

int main(){
    srand(time(NULL));
    string name = "";
    int iterations = 0;
    while(name != "Jayson"){
        name = "";
        int randnum = rand() % 26;
        char c = 65 + randnum;
        name += c;
        for (int i = 0; i < 5; i++){
            int randnum = rand() % 26;
            c = 97 + randnum;
            name += c;
        }
        cout << iterations++ << endl;
        cout << name << endl;
    }
    cout << name << endl;
}