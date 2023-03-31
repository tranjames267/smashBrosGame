// CSCI 1300 Fall 2020
// Author: James Tran
// Recitation: 224 - Anuj Pasricha 
// Project 3

#ifndef GAME_H 
#define GAME_H
#include <string>
#include <fstream>
#include <iostream>
#include "Character.h"
#include "Moves.h"
#include "ItemEvent.h"

using namespace std;

class Game
{
    private:
    Character characters[4];
    Moves allMoves[24]; 
    ItemEvent events[5]; 
    Character player;
    Character computer; 
    bool gameWon; 

    public: 
    Game(); 
    // helper functions
    int split(string splitStr, char separator, string arr[], int size);
    void readAsciiArt(string fileName); 
    bool readCharacters(string fileName, Character allCharacters[]); 
    bool readMoves(string fileName, Moves everyMove[]);
    bool readEvents(string fileName, ItemEvent allEvents[]); 
    void viewByPower();
    void viewByProbHit();
    bool attackSuccess(int prob);
    void pressAnythingContinue();
    void opponentAttack(); 

    // main game flow functions
    void introductionAndDirections();
    void chooseCharacter(); 
    void chooseOpponent(); 
    void battle();
    void displayResults(); 

}; 

#endif