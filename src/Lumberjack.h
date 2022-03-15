/*Sarah Allen & Joshua Lindquist
CS132 Winter 2022
Final Project: Simulation

Class main author: Sarah

Header file for Lumberjack class. Lumberjacks have the ability to harvest wood and build houses*/

#ifndef _LUMBERJACK_H
#define _LUMBERJACK_H

#include "Creature.h"

class Lumberjack : public Creature {
public:    
    //Constructor
    Lumberjack();

    //virtual void getWood();

    //Searches for trees, returns to a building to sleep
    virtual Direction getMove();

    //Always returns CHOP, to cut down trees
    virtual Attack fight() const;

    //Returns "Lumberjack"
    virtual string getType();

    //Returns image of axe using a UTC-8 hex code, to represent the concept of woodcutting
    virtual string toString();

    //Returns display color of the lumberjack
    virtual string getColor();

    //This is how the Lumberjack builds houses.
    //virtual Entity* buildHouse();

private:
    int woodCount;
};

#endif

