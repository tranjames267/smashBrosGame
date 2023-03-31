// CSCI 1300 Fall 2020
// Author: James Tran
// Recitation: 224 - Anuj Pasricha 
// Project 3

#ifndef MOVES_H 
#define MOVES_H
#include <string>

using namespace std; 

class Moves
{
    private:
    string name; 
    int power;
    int probHit; 

    public:
    Moves();
    Moves(string moveName, int movePower, int moveProbHit);

    string getMoveName() const; 
    void setMoveName(string moveName);

    int getMovePower() const; 
    void setMovePower(int movePower);

    int getMoveProbHit() const; 
    void setMoveProbHit(int moveProbHit);

};

#endif