/*Sarah Allen & Joshua Lindquist
CS132 Winter 2022
Final Project: Simulation

Class main author: Sarah

Header file for the Deer class. Deer want to mind their business, but can be hunted and killed. 
They will try to run from all threats, but need to rest after their burst of speed.*/

#ifndef _DEER_H
#define _DEER_H

#include "Creature.h"
using namespace std;

class Deer : public Creature {
public:
    //Constructor
    Deer();

    //Prefers to stay near trees and away from buildings/predators
    virtual Direction getMove();
    
    //Returns "Deer"
    virtual string getType();

    //Returns image of deer using a UTC-8 hex code 
    virtual string toString();

    //Returns display color of the deer
    virtual string getColor();

    // virtual Attack fight() const;

private: 
    int stepCount;
    Direction currentDir;
    bool hasMated;
    int flee;
    int rest;
};

#endif