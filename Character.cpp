// CSCI 1300 Fall 2020
// Author: James Tran
// Recitation: 224 - Anuj Pasricha 
// Project 3

#include "Character.h"
#include <string>
#include <iostream>

using namespace std;

Character::Character()
{
    charName = "";
    damage = 0; 
    lives = 0;
    movesMade = 0; 

    for(int i=0; i<6; i++) // set all indexes to 0
    {
        movesIdx[i] = 0; 
    }
}
Character::Character(string nameC, int damageC, int livesC, int movesMadeC, int movesIdxC[])
{
    charName = nameC; 
    damage = damageC;
    lives = livesC;
    movesMade = movesMadeC; 

    for(int i=0; i<6; i++) // copy indexes from the given array
    {
        movesIdx[i] = movesIdxC[i]; 
    }
}

string Character::getCharName() const
{
    return charName; 
} 
void Character::setCharName(string nameC)
{
    charName = nameC; 
}

int Character::getDamage() const
{
    return damage; 
}
void Character::setDamage(int damageC)
{
    damage = damageC; 
}

int Character::getLives() const
{
    return lives; 
} 
void Character::setLives(int livesC)
{
    lives = livesC; 
}

int Character::getMovesMade() const
{
    return movesMade; 
} 
void Character::setMovesMade(int movesMadeC)
{
    movesMade = movesMadeC;
}

int Character::getMovesIdxAt(int index) const
{
    return movesIdx[index];
}
void Character::setMovesIdxAt(int index, int value)
{
    movesIdx[index] = value; 
} 