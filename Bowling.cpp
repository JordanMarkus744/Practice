#include <iostream>
#include <fstream>
#include <vector>
#include "Bowlingclass.hpp"


// This program takes input from a txt file of the leaderboard of a youth bowling tournament
int main(){

    PlayerInfo Player[284];
    int player = 0;
    std::fstream myfile;
    myfile.open("BowlingStats.txt");


    while(!myfile.eof()){
        int line;
        myfile >> line;
        std::string name = "";
        std::string temp = "";
        bool hasComma = false;
        myfile >> line;

        Player[player].setRank(line);
        myfile >> temp;
        name = temp;
        myfile >> temp;
        name += ' ' + temp; // name is done
        Player[player].setBowler(name);


        std::string Hometown;
        myfile >> temp;
        Hometown = temp;
        while(temp[temp.size()-1] != ','){
            
            for (int i = 0; i < temp.size(); i++){
                if (temp[i] == ','){
                    hasComma = true;
                    break;
                }
            }
            if (!hasComma){
                myfile >> temp;
                Hometown += ' ' + temp;
            }
            else{
                break;
            }
        }
        if (!hasComma){
            myfile >> temp;
            Hometown += temp;
        } // Hometown end

        

        Player[player].setHometown(Hometown);

        myfile >> line;
        Player[player].setSquad(line);
        int games[4];
        for (int i = 0; i < 4; i++){
            myfile >> games[i];
        }
        Player[player].setGames(games);

        myfile >> line;
        Player[player].setTotal(line);


        float myline;
        myfile >> myline;
        Player[player].setAverage(myline);

        myfile >> temp;
        if (temp[temp.size()-1] == '+' || temp[temp.size()-1] == '-'){
            myfile >> temp;
        }
        Player[player].setPlusMinus(temp);
        
        //Player[player].Print();
        Player[player].Search("Peyton Abel");

        player++;
    }
    

    myfile.close();
    return 0;
}