// CSCI 1300 Fall 2020
// Author: James Tran
// Recitation: 224 - Anuj Pasricha 
// Project 3

#ifndef CHARACTER_H 
#define CHARACTER_H
#include <string>

using namespace std; 

class Character
{
    private:
    string charName;
    int damage; 
    int lives;
    int movesMade;   
    int movesIdx[6];

    public:
    Character();
    Character(string nameC, int damageC, int livesC, int movesMadeC, int movesIdxC[]);

    string getCharName() const; 
    void setCharName(string nameC);

    int getDamage() const; 
    void setDamage(int damageC);

    int getLives() const; 
    void setLives(int livesC);

    int getMovesMade() const; 
    void setMovesMade(int movesMadeC);

    int getMovesIdxAt(int index) const;
    void setMovesIdxAt(int index, int value); 
};

#endif