// CSCI 1300 Fall 2020
// Author: James Tran
// Recitation: 224 - Anuj Pasricha 
// Project 3

#include "ItemEvent.h"
#include <string>
#include <iostream>

using namespace std;

ItemEvent::ItemEvent()
{
    description = "";
    itemDamage = 0; 
}
ItemEvent::ItemEvent(string descriptionI, int damageI)
{
    description = descriptionI; 
    itemDamage = damageI; 
}

string ItemEvent::getDescription() const
{
    return description; 
}
void ItemEvent::setDescription(string descriptionI)
{
    description = descriptionI; 
}

int ItemEvent::getItemDamage() const
{
    return itemDamage; 
} 
void ItemEvent::setItemDamage(int damageI)
{
    itemDamage = damageI; 
}  