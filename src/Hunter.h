/*Sarah Allen & Joshua Lindquist
CS132 Winter 2022
Final Project: Simulation

Class main author: Sarah

Header file for Hunter class. Hunters have the ability
to fight the animals in order to gain food.*/

#ifndef _HUNTER_H
#define _HUNTER_H

#include "Creature.h"

class Hunter : public Creature {
public:
    //Constructor
    Hunter();

    virtual void onWin();

    //Searches for prey (Animals), returns to building to sleep
    virtual Direction getMove();

    //Always returns STAB, to kill Tigers
    virtual Attack fight() const;

    //Returns "Hunter"
    virtual string getType();

    //Returns image of bow using a UTC-8 hex code, to represent the concept of hunting
    virtual string toString();

    //Returns display color of the hunter
    virtual string getColor();
private: 
    int currentDir;
    int foodCount;
};

#endif

