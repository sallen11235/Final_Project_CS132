/*Sarah Allen & Joshua Lindquist
CS132 Winter 2022
Final Project: Simulation

Class main author: 

Header file for the Deer class. Deer want to mind their business, but can be hunted and killed.*/

#ifndef _DEER_H
#define _DEER_H

#include "Creature.h"

class Deer : public Creature {
public:
    //Constructor
    Deer();

    //Prefers to stay near trees and away from buildings/predators
    virtual Direction getMove();
    
    //Returns "Deer"
    virtual string getType();

    //Returns                                                <- Deer symbol?
    virtual string toString();

    //Returns display color of the deer
    virtual string getColor();

private: 
    int stepCount;
    int currentDir;
    bool hasMated;
};

#endif