// CSCI 1300 Fall 2020
// Author: James Tran
// Recitation: 224 - Anuj Pasricha 
// Project 3

#ifndef ITEMEVENT_H 
#define ITEMEVENT_H
#include <string>

using namespace std; 

class ItemEvent
{
    private:
    string description; 
    int itemDamage; 

    public: 
    ItemEvent();
    ItemEvent(string descriptionI, int damageI);

    string getDescription() const;
    void setDescription(string descriptionI);

    int getItemDamage() const; 
    void setItemDamage(int damageI);  
};

#endif