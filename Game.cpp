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

Game::Game()
{
    Character characters[4];
    Moves allMoves[24]; 
    ItemEvent events[5]; 
    Character player;
    Character computer;   
} 
// helper functions
int Game::split(string splitStr, char separator, string arr[], int size)
{
    // check for the number of separators
    int numSeparator = 0;
    for(int i=0; i<splitStr.length(); i++)
    {
        if(splitStr[i] == separator)
        {
            numSeparator ++; 
        }
    }
    if(splitStr.length() == 0) // no smaller strings possible if splitStr is empty
    {
        return 0; 
    }
    else if(numSeparator == 0) // assign first element in the array to splitStr if no delimiter is found. Always 1 string
    {
        arr[0] = splitStr; 
        return 1;
    }
    else if(numSeparator >= size) // if there are more smaller strings than space in the array, fill up array but return -1
    {
        int arrayPos = 0; // accounts for the index in the array
        string strToArray = ""; 
     
        for(int i=0; i<splitStr.length(); i++)
        {
            if(splitStr[i] != separator)
            {
                strToArray += splitStr[i]; // add the character to the smaller string
            }
            if(splitStr[i] == separator)
            {
                arr[arrayPos] = strToArray; // add the smaller string to the array
                strToArray = ""; // reset the smaller string
                arrayPos ++; 
                
                if(arrayPos == size) // stop if the array is all filled
                break;
            }
        }
        return -1;
    }
    
    else // fill up an array that can fit all smaller strings and return the number of smaller strings
    { 
        int numItems = 1; // 1 accounts for the last smaller string 
        int arrayPos = 0; 
         
        string strToArray = ""; 
     
        for(int i=0; i<splitStr.length(); i++)
        {
            if(splitStr[i] != separator)
            {
                strToArray += splitStr[i]; 
            }
            if(splitStr[i] == separator)
            {
                arr[arrayPos] = strToArray; 
                strToArray = "";
                numItems ++; // keep count of the number of smaller strings
                arrayPos ++; // move to the next index of the array
            }
        }
        arr[arrayPos] = strToArray; // add the last string to the array
        
        return numItems;  
    }
}
void Game::readAsciiArt(string fileName)
{
    string line; // will be the line variable for getline()
    ifstream inFile; // input from a plain txt file 

    inFile.open(fileName);

    // check if the file is opened
    if(inFile.fail())
    {
        cout << "Could not open file." <<endl;
    } 
    else
    {
        while(getline(inFile, line))
        {
            if(line.length() > 0) // ensures that we don't process empty lines
            {
                cout << line <<endl;  
            }
        }
    }
} 
bool Game::readCharacters(string fileName, Character allCharacters[])
{
    // this will fill up the array of all characters by reading in characters.txt
    // I will use a storage array of type string to contain all the information (will most likely need .stoi())

    string line; // will be the line variable for getline()
    ifstream inFile; // input from a plain txt file 
    int arrCount = 0; 

    inFile.open(fileName);

    // check if the file is opened
    if(inFile.fail())
    {
        cout << "Could not open file." <<endl;
        return false; 
    } 
    else
    {
        while(getline(inFile, line))
        {
            if(line.length() > 0) // ensures that we don't process empty lines
            {
                string storage[10];
                int moveIndexes[6]; 
                split(line, ',', storage, 10);  

                for(int i=0; i<6; i++)
                {
                    moveIndexes[i] = stoi(storage[i+4]); 
                }

                allCharacters[arrCount] = Character(storage[0], stoi(storage[1]), stoi(storage[2]), stoi(storage[3]), moveIndexes);
                arrCount ++; 
            }
        }
        return true; 
    }
} 
bool Game::readMoves(string fileName, Moves everyMove[])
{
    // this will fill up the array of all the moves by reading in moves.txt
    // a storage array of type string will contain the information (will most likely need .stoi())

    string line; // will be the line variable for getline()
    ifstream inFile; // input from a plain txt file 
    int arrCount = 0; 

    inFile.open(fileName);

    // check if the file is opened
    if(inFile.fail())
    {
        cout << "Could not open file." <<endl;
        return false; 
    } 
    else
    {
        while(getline(inFile, line))
        {
            if(line.length() > 0) // ensures that we don't process empty lines
            {
                string storage[3];
                split(line, ',', storage, 3);  
                everyMove[arrCount] = Moves(storage[0], stoi(storage[1]), stoi(storage[2]));
                arrCount ++; 
            }
        }
        return true; 
    }
}
bool Game::readEvents(string fileName, ItemEvent allEvents[])
{
    // this will fill up the array of all the item events by reading in items.txt
    // a storage array of type string will contain the information (will most likely need .stoi())

    string line; // will be the line variable for getline()
    ifstream inFile; // input from a plain txt file 
    int arrCount = 0; 

    inFile.open(fileName);

    // check if the file is opened
    if(inFile.fail())
    {
        cout << "Could not open file." <<endl;
        return false; 
    } 
    else
    {
        while(getline(inFile, line))
        {
            if(line.length() > 0) // ensures that we don't process empty lines
            {
                string storage[2];
                split(line, ',', storage, 2);  
                allEvents[arrCount] = ItemEvent(storage[0], stoi(storage[1]));
                arrCount ++; 
            }
        }
        return true; 
    }
}
void Game::viewByPower()
{
    // print the moves of a character and their power levels  
    cout << endl; 
    cout << "Here are the names and power levels of your character's moves:" <<endl; 
    for(int i=0; i<6; i++)
    {
        cout << allMoves[player.getMovesIdxAt(i)].getMoveName() << ": Power = " << allMoves[player.getMovesIdxAt(i)].getMovePower() <<endl;
    }
    pressAnythingContinue(); 
}
void Game::viewByProbHit()
{
    // print the moves of a character based on probability of hitting
    cout << endl; 
    cout << "Here are the probability levels that your character's moves will hit:" <<endl;
    for(int i=0; i<6; i++)
    {
        cout << allMoves[player.getMovesIdxAt(i)].getMoveName() << ": Probability = " << allMoves[player.getMovesIdxAt(i)].getMoveProbHit() <<endl;
    }
    pressAnythingContinue(); 
     
}
bool Game::attackSuccess(int prob)
{
    // generate a random number from 1 to 100
    int determine = rand() % 100 + 1; 
    // if the number is less than or equal to the probHit of the move, return true
    if(determine <= prob)
    {
        return true; 
    }
    else // otherwise, return false
    {
        return false; 
    }  
}
void Game::pressAnythingContinue()
{
    // this is supposed to help pace the game by taking input and doing nothing with it
    cout <<endl; 
    cout << "---- Press anything to continue ---- "; 
    string choice; 
    getline(cin,choice); 
    cout <<endl; 
}
void Game::opponentAttack()
{
    int chooseMove = rand() % 6; // randomly choose one of the 6 moves for the opponent 
    Moves compMove = allMoves[computer.getMovesIdxAt(chooseMove)]; 
    // opponent attacks if they have at least one life and attackSuccess() returns true
    if(computer.getLives() > 0)
    {
        if(attackSuccess(compMove.getMoveProbHit()))
        {
            player.setDamage(player.getDamage() + compMove.getMovePower()); // increase damage on player
            cout << endl;
            cout << "Your opponent damaged you by " << compMove.getMovePower() << " with the move: " << compMove.getMoveName() <<endl;
            
            if(player.getDamage() >= 100) // check if player should lose a life
            {
                player.setDamage(0);
                player.setLives(player.getLives() - 1);
                cout <<endl; 
                cout << "You lost a life since your opponent knocked you out" <<endl;
            }
            pressAnythingContinue(); 
        }
        else
        {
            cout <<endl; 
            cout << "Your opponent tried to attack but you were able to dodge" <<endl;
            pressAnythingContinue();
        }
    }
    else
    {
        pressAnythingContinue(); 
    }
    
}

// Main game flow functions
void Game::introductionAndDirections()
{
    readAsciiArt("smashBrosArt.txt"); // read out title ascii art
    pressAnythingContinue(); 
    // print out directions
    cout << "Directions:" <<endl;
    cout << "Welcome to the text-based version of Super Smash Bros, a back and forth fighting game." <<endl; 
    cout << "The objective is simple: defeat your opponent by attacking them and taking three of their lives." <<endl;
    cout << "If your character has 100 or more damage, you will lose a life. Same goes for your opponent." <<endl;
    cout << "After choosing your character and opponent, you will be presented with 5 main battle options." <<endl;
    pressAnythingContinue();
    cout << "View Moves: view your character's moves by power or probability of hitting" <<endl;
    cout << "Fight: choose one of the six moves for your character to attack" <<endl;
    cout << "Heal: your character will heal by -10 damage" <<endl;
    cout << "Attack and Block: guarenteed to damage your opponent by 10 and take half damage of an opponent's attack" <<endl;
    cout << "Grab and Use Item: generate a random item to attack your opponent with" <<endl;
    cout <<endl;
    cout << "Remember: you must defeat your opponent using at most 60 moves." <<endl;  
    cout << "Your opponent will always attack after your choice except viewing your moves." <<endl;
    cout << "GO GET EM!" <<endl;
    pressAnythingContinue(); 
}
void Game::chooseCharacter()
{
    // display a menu with the four character options 
    // depending on the user's choice, read out the character ascii art txt file
    // modify the character object named player to have the attributes of the certain character 
    // assign the name, damage, lives, number of moves made, and moves indexes based on the master array characters[] 

    readMoves("moves.txt", allMoves); 
    readCharacters("characters.txt", characters); 

    int choice = 0;  
    cout <<endl; 
    cout << "=== Choose Your Character ===" <<endl;
    cout << "1. Mario" <<endl;
    cout << "2. Link" <<endl;
    cout << "3. Pikachu" <<endl;
    cout << "4. Kirby" <<endl;
    cout << "Enter an Integer from the menu" <<endl;   

    string choiceStr; 
    getline(cin, choiceStr);
    if(choiceStr.length() == 1 && choiceStr[0] >= '0' && choiceStr[0] <= '9')
    choice = stoi(choiceStr);
    
    while(choice < 1 || choice > 4) // make sure input is valid
    {
        cout << endl; 
        cout << "Please pick a valid integer" <<endl;
        cout << endl; 
        cout << "=== Choose Your Character ===" <<endl;
        cout << "1. Mario" <<endl;
        cout << "2. Link" <<endl;
        cout << "3. Pikachu" <<endl;
        cout << "4. Kirby" <<endl;
        cout << "Enter an Integer from the menu" <<endl; 
        getline(cin, choiceStr);
        if(choiceStr.length() == 1 && choiceStr[0] >= '0' && choiceStr[0] <= '9')
        choice = stoi(choiceStr);
    }
    switch(choice)
    {
        case 1:
        cout << "You have chosen: " <<endl; 
        cout <<endl; 
        readAsciiArt("marioArt.txt");
        player = characters[0]; 
        break; 

        case 2:
        cout << "You have chosen: " <<endl; 
        cout <<endl; 
        readAsciiArt("linkArt.txt");
        player = characters[1];  
        break; 

        case 3:
        cout << "You have chosen: " <<endl; 
        cout <<endl; 
        readAsciiArt("pikachuArt.txt");
        player = characters[2]; 
        break; 

        case 4:
        cout << "You have chosen: " <<endl; 
        cout <<endl; 
        readAsciiArt("kirbyArt.txt");
        player = characters[3];  
        break; 

        default: break; 
    }  

    /* For testing purposes
    cout << player.getCharName() <<endl;
    cout << player.getDamage() <<endl;
    cout << player.getLives() <<endl;
    cout << player.getMovesMade() <<endl;
    cout << player.getMovesIdxAt(0) <<endl;
    cout << player.getMovesIdxAt(1) <<endl;
    cout << player.getMovesIdxAt(2) <<endl;
    cout << player.getMovesIdxAt(3) <<endl;
    cout << player.getMovesIdxAt(4) <<endl;
    cout << player.getMovesIdxAt(5) <<endl;
    */

    pressAnythingContinue(); 
} 
void Game::chooseOpponent()
{
    // display a menu with the four character options 
    // depending on the user's choice, read out the character ascii art txt file
    // modify the character object named computer to have the attributes of the certain character 
    // assign the name, damage, lives, number of moves made, and moves indexes based on the master array characters[]

    int choice = 0; 
     
    cout << "=== Choose Your Opponent ===" <<endl;
    cout << "1. Mario" <<endl;
    cout << "2. Link" <<endl;
    cout << "3. Pikachu" <<endl;
    cout << "4. Kirby" <<endl;
    cout << "Enter an Integer from the menu" <<endl;   

    string choiceStr; 
    getline(cin, choiceStr);

    if(choiceStr.length() == 1 && choiceStr[0] >= '0' && choiceStr[0] <= '9')
    choice = stoi(choiceStr);
    
    while(choice < 1 || choice > 4) // make sure input is valid
    {
        cout << endl; 
        cout << "Please pick a valid integer" <<endl;
        cout << endl; 
        cout << "=== Choose Your Opponent ===" <<endl;
        cout << "1. Mario" <<endl;
        cout << "2. Link" <<endl;
        cout << "3. Pikachu" <<endl;
        cout << "4. Kirby" <<endl;
        cout << "Enter an Integer from the menu" <<endl; 
        getline(cin, choiceStr);
        if(choiceStr.length() == 1 && choiceStr[0] >= '0' && choiceStr[0] <= '9')
        choice = stoi(choiceStr);
    }
    switch(choice)
    {
        case 1:
        cout << "Your Opponent is: " <<endl; 
        cout <<endl; 
        readAsciiArt("marioArt.txt");
        computer = characters[0]; 
        break; 

        case 2:
        cout << "Your Opponent is: " <<endl; 
        cout <<endl; 
        readAsciiArt("linkArt.txt");
        computer = characters[1];  
        break; 

        case 3:
        cout << "Your Opponent is: " <<endl; 
        cout <<endl; 
        readAsciiArt("pikachuArt.txt");
        computer = characters[2]; 
        break; 

        case 4:
        cout << "Your Opponent is: " <<endl; 
        cout <<endl; 
        readAsciiArt("kirbyArt.txt");
        computer = characters[3]; 
        break; 

        default: break; 
    }  

    /* //For testing purposes
    cout << computer.getCharName() <<endl;
    cout << computer.getDamage() <<endl;
    cout << computer.getLives() <<endl;
    cout << computer.getMovesMade() <<endl;
    cout << computer.getMovesIdxAt(0) <<endl;
    cout << computer.getMovesIdxAt(1) <<endl;
    cout << computer.getMovesIdxAt(2) <<endl;
    cout << computer.getMovesIdxAt(3) <<endl;
    cout << computer.getMovesIdxAt(4) <<endl;
    cout << computer.getMovesIdxAt(5) <<endl;
    */

    pressAnythingContinue(); 
} 
void Game::battle()
{
    cout << "ARE YOU READY TO BATTLE?" <<endl; 
    cout <<endl;
    cout << "3" <<endl;
    cout << "2" <<endl;
    cout << "1" <<endl;
    cout << "GO!!" <<endl;
    cout <<endl; 

    do
    { 
        int choice = 0; 
     
        // Player and Opponent Stats 
        cout << "-----------------------------------------------------------------------------------" <<endl;
        cout << "Player Stats: " << "Character: " << player.getCharName() << " | Damage: " << player.getDamage() << " | Lives: " << player.getLives() << " | Moves Made: " << player.getMovesMade() <<endl;
        cout <<endl; 
        cout << "Opponent Stats: " << "Character: " << computer.getCharName() << " | Damage: " << computer.getDamage() << " | Lives: " << computer.getLives() << " | Moves Made: " << computer.getMovesMade() <<endl;
        cout << "-----------------------------------------------------------------------------------" <<endl;
        // main menu of battle options 
        cout <<endl; 
        cout << "=== Pick a Battle Option ===" <<endl;
        cout << "1. View Moves" <<endl;
        cout << "2. Fight" <<endl;
        cout << "3. Heal" <<endl;
        cout << "4. Attack and Block" <<endl;
        cout << "5. Grab and Use Item" <<endl;
        cout << "6. Quit" <<endl;
        cout << "Enter an Integer from the menu" <<endl;   

        string choiceStr; 
        getline(cin, choiceStr);
        if(choiceStr.length() == 1 && choiceStr[0] >= '0' && choiceStr[0] <= '9')
        choice = stoi(choiceStr);
        
        switch(choice)
        {
            case 1: // View Moves of player
            {
                // view power or probability of a character's moves
                // computer character won't make a move after this choice
                int viewType = 0;
                cout << endl; 
                cout << "=== What would you like to view? ===" <<endl;
                cout << "1. View moves by power" <<endl;
                cout << "2. View moves by probability" <<endl;
                cout << "Enter an Integer from the menu" <<endl;       
                
                string viewTypeStr; 
                getline(cin,viewTypeStr);
                if(viewTypeStr.length() == 1 && viewTypeStr[0] >= '0' && viewTypeStr[0] <= '9')
                viewType = stoi(viewTypeStr);

                if(viewType == 1)
                {
                    viewByPower();
                    player.setMovesMade(player.getMovesMade() + 1);
                }
                else if(viewType == 2)
                {
                    viewByProbHit(); 
                    player.setMovesMade(player.getMovesMade() + 1);
                }
                else
                {
                    cout <<endl;
                    cout << "Invalid Response" <<endl;
                    cout <<endl; 
                    player.setMovesMade(player.getMovesMade() + 1);
                }
                

                break; 
            }
            
            case 2: // Fight
            {
                // will be given a list of moves of the character to choose from
                int attackChoice = 0; 
                
                cout <<endl; 
                cout << "=== Choose a Move ===" <<endl; 
                for(int i=0; i<6; i++)
                {
                    cout << i+1 << ". " << allMoves[player.getMovesIdxAt(i)].getMoveName() <<endl;
                }
                cout << "Pick an Integer from the menu" <<endl;
                
                string attackChoiceStr;
                getline(cin, attackChoiceStr);
                if(attackChoiceStr.length() == 1 && attackChoiceStr[0] >= '0' && attackChoiceStr[0] <= '9')
                attackChoice = stoi(attackChoiceStr);

                if(attackChoice < 1 || attackChoice > 6)
                {
                    cout <<endl;
                    cout << "You decided to stand still, which leaves you vulnerable" <<endl;
                }
                else
                {
                    Moves playerMove = allMoves[player.getMovesIdxAt(attackChoice - 1)]; 

                    if(attackSuccess(playerMove.getMoveProbHit())) // call on attackSuccess() to see if the move will execute 
                    {
                        // the attack will change the damage of the computer character
                        computer.setDamage(computer.getDamage() + playerMove.getMovePower());
                        cout << endl;
                        cout << "You used " << playerMove.getMoveName() << " and damaged your opponent by " << playerMove.getMovePower() <<endl;
                        
                        if(computer.getDamage() >= 100)
                        {
                            computer.setDamage(0);
                            computer.setLives(computer.getLives() - 1);
                            cout <<endl; 
                            cout << "You knocked out your opponent, and they lost a life" <<endl;
                        } 
                    }
                    else
                    {
                        cout <<endl; 
                        cout << "You tried to attack your opponent but you missed" <<endl;
                    }
                }
                
                opponentAttack(); // the computer character will attack after this choice 
                player.setMovesMade(player.getMovesMade() + 1);
                if(computer.getLives() > 0)
                computer.setMovesMade(computer.getMovesMade() + 1);

                break;
            }

            case 3: // Heal
            {
                cout <<endl;
                cout << "You healed by -10" <<endl;
                if(player.getDamage() <= 10) // make sure there is no negative damage
                {
                    player.setDamage(0); 
                }
                else // will lower the player character damage by 10
                {
                    player.setDamage(player.getDamage() - 10);
                }

                opponentAttack(); // computer character will attack after this choice 
                player.setMovesMade(player.getMovesMade() + 1);
                if(computer.getLives() > 0)
                computer.setMovesMade(computer.getMovesMade() + 1);
                
                break;
            }

            case 4: // Attack and Block
            {
                // player has a guarenteed attack with 10 damage 
                computer.setDamage(computer.getDamage() + 10);
                cout << "You landed a blow on your opponent worth 10 damage" <<endl;
                if(computer.getDamage() >= 100)
                {
                    computer.setDamage(0);
                    computer.setLives(computer.getLives() - 1);
                    cout <<endl; 
                    cout << "You knocked out your opponent, and they lost a life" <<endl;
                } 

                // guarenteed opponent attack
                int compMoveChoice = rand() % 6; 
                Moves blockMove = allMoves[computer.getMovesIdxAt(compMoveChoice)]; 
                if(computer.getLives() > 0)
                {
                    player.setDamage(player.getDamage() + blockMove.getMovePower()/2); // you only take half damage
                    cout << endl;
                    cout << "You took damage of " << blockMove.getMovePower()/2 << " after blocking your opponent's move: " << blockMove.getMoveName() <<endl;
            
                    if(player.getDamage() >= 100)
                    {
                        player.setDamage(0);
                        player.setLives(player.getLives() - 1);
                        cout <<endl; 
                        cout << "You lost a life since your opponent knocked you out" <<endl;
                    }
                }
                
                pressAnythingContinue(); 
                player.setMovesMade(player.getMovesMade() + 1);
                if(computer.getLives() > 0)
                computer.setMovesMade(computer.getMovesMade() + 1);
                
                break;
            }

            case 5: // Grab and use an item
            {
                readEvents("items.txt", events);
                // generate a random item (probability out of 8)
                int itemChoice = rand() % 8;

                if(itemChoice > 4)
                {
                    cout <<endl; 
                    cout << "There are no items around to use" <<endl; 
                } 
                else
                {
                    cout <<endl; 
                    cout << events[itemChoice].getDescription() <<endl;
                    computer.setDamage(computer.getDamage() + events[itemChoice].getItemDamage()); 

                    if(computer.getDamage() >= 100)
                    {
                        computer.setDamage(0);
                        computer.setLives(computer.getLives() - 1);
                        cout <<endl; 
                        cout << "You knocked out your opponent, and they lost a life" <<endl;
                    } 
                }
                
                opponentAttack(); // computer character will attack after this choice 
                player.setMovesMade(player.getMovesMade() + 1);
                if(computer.getLives() > 0)
                computer.setMovesMade(computer.getMovesMade() + 1);
                
                break;
            }

            case 6: // Quit: will end the loop
            {
                player.setLives(0);
                computer.setLives(0); 
                break;
            }

            default:
            {
                cout <<endl; 
                cout << "Please pick a valid integer. You are wide open for attack" <<endl;
                opponentAttack(); 
                player.setMovesMade(player.getMovesMade() + 1);
                computer.setMovesMade(computer.getMovesMade() + 1);
                break;
            }
        }
        
        if(player.getMovesMade() > 60) // end game if player makes more than 60 moves
        {
            cout <<endl; 
            cout << "Sudden Death: You have taken too many moves" <<endl;
            player.setLives(0); 
            pressAnythingContinue(); 
        }

    } while (player.getLives() > 0 && computer.getLives() > 0);
}
void Game::displayResults()
{
    // display if the player or computer won 
    // read out a character ascii file if the player won by calling readAsciiArt() 

    if(player.getLives() == 0 && computer.getLives() == 0)
    {
        cout <<endl;
        cout << "No Contest" <<endl; 
        pressAnythingContinue(); 
    }
    else if(player.getLives() == 0)
    {
        cout <<endl; 
        readAsciiArt("defeat.txt");
        pressAnythingContinue();
    }
    else
    {
        cout <<endl; 
        readAsciiArt("victory.txt");
        cout <<endl; 

        if(player.getCharName() == "Mario")
        {
            readAsciiArt("marioArt.txt");
        }
        if(player.getCharName() == "Link")
        {
            readAsciiArt("linkArt.txt");
        }
        if(player.getCharName() == "Pikachu")
        {
            readAsciiArt("pikachuArt.txt");
        }
        if(player.getCharName() == "Kirby")
        {
            readAsciiArt("kirbyArt.txt");
        }

        // will write out the user stats to a file if they won 
        ofstream outFile; 
        outFile.open("gameResults.txt");
        outFile << "-----------------------------------" <<endl;
        outFile << "Winning Character: " << player.getCharName() <<endl;
        outFile << "Damage: " << player.getDamage() <<endl;
        outFile << "Lives: " << player.getLives() <<endl;
        outFile << "Moves Made: " << player.getMovesMade() <<endl;
        outFile << "-----------------------------------" <<endl; 
        pressAnythingContinue();
    }
    
} 
