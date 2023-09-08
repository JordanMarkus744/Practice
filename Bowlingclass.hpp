#include <iostream>
#include <iomanip>
#pragma once
class PlayerInfo{
    int Rank;
    std::string Bowler;
    std::string Hometown;
    int Squad;
    int Games[4];
    int Total;
    float Average;
    std::string PlusMinus;

    public:

    void setRank(int Rank){
        this->Rank = Rank;
    }

    void setBowler(std::string Bowler){
        this->Bowler = Bowler;
    }

    void setHometown(std::string Hometown){
        this->Hometown = Hometown;
    }

    void setSquad(int Squad){
        this->Squad = Squad;
    }

    void setGames(int Games[4]){
        for (int i = 0; i < 4; i++){
            this->Games[i] = Games[i];
        }
    }

    void setTotal(int Total){
        this->Total = Total;
    }

    void setAverage(float Average){
        this->Average = Average;
    }

    void setPlusMinus(std::string PlusMinus){
        this->PlusMinus = PlusMinus;
    }

    void Print(){
        std::cout << std::setw(2) << Rank << std::setw(24) << Bowler << std::setw(27) << Hometown << std::setw(15) << Squad << std::setw(5);
        for (int i = 0; i < 4; i++){
            std::cout << Games[i] << std::setw(5);
        }
        std::cout << Total << std::setw(8) << Average << std::setw(5) << PlusMinus << std::endl << std::endl;
    }

    void Sqweak(){
        std::cout << "Sqweak!" << std::endl;
    }

    void Search(std::string name){
        if (this->Bowler == name){
            Print();
        }
    }
};