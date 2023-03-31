// CSCI 1300 Fall 2020
// Author: James Tran
// Recitation: 224 - Anuj Pasricha 
// Project 3

#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Game.h"
#include "Character.h"
#include "Moves.h"
#include "ItemEvent.h"

using namespace std; 

int main()
{
    srand(time(0)); // set random seed
    Game smashBros; // make a game object

    string keepPlaying = "";

    smashBros.introductionAndDirections();
    
    do
    {
        smashBros.chooseCharacter();
        smashBros.chooseOpponent(); 
        smashBros.battle();
        smashBros.displayResults();
        
        // check if the user wants to play multiple rounds
        cout << "Do you want to play again?" <<endl;
        cout <<endl; 
        cout << "Enter y or Y for yes" <<endl;
        cout << "Enter anything else for no" <<endl;
        getline(cin,keepPlaying); 
    } while (keepPlaying == "y" || keepPlaying == "Y");
    
    
}