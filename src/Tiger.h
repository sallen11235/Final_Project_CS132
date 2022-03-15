/*Sarah Allen & Joshua Lindquist
CS132 Winter 2022
Final Project: Simulation

Class main author: Sarah
Debugging: Josh

Header file for the Tiger class. Tigers have the ability 
to hunt villagers and deer by using a bite attack.*/

#ifndef _TIGER_H
#define _TIGER_H

#include "Creature.h"

class Tiger : public Creature {
public:
    //Constructor
    Tiger();

    //Searches for prey (Deer and villagers), can't enter buildings
    virtual Direction getMove();

    //Always returns BITE
    virtual Attack fight() const;

    //Returns "Tiger"
    virtual string getType();

    //Returns image of a tiger using a UTC-8 hex code
    virtual string toString();

    //Returns display color of the tiger
    virtual string getColor();
private:
    int stepCount;
    int currentDir;
    bool hasMated;
};

#endif