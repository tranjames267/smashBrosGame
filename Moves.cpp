// CSCI 1300 Fall 2020
// Author: James Tran
// Recitation: 224 - Anuj Pasricha 
// Project 3

#include "Moves.h"
#include <string>
#include <iostream>

using namespace std;

Moves::Moves()
{
    name = "";
    power = 0;
    probHit = 0; 
}
Moves::Moves(string moveName, int movePower, int moveProbHit)
{
    name = moveName; 
    power = movePower;
    probHit = moveProbHit; 
}

string Moves::getMoveName() const
{
    return name; 
} 
void Moves::setMoveName(string moveName)
{
    name = moveName; 
}

int Moves::getMovePower() const
{
    return power; 
} 
void Moves::setMovePower(int movePower)
{
    power = movePower; 
}

int Moves::getMoveProbHit() const
{
    return probHit; 
} 
void Moves::setMoveProbHit(int moveProbHit)
{
    probHit = moveProbHit; 
}