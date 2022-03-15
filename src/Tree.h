/*Sarah Allen & Joshua Lindquist
CS132 Winter 2022
Final Project: Simulation

Class main author: Sarah

Header file for the Tree class. Trees do not move, sleep, or fight, 
but they can be cut down for wood by hunters.*/

#ifndef _TREE_H
#define _TREE_H

#include "Entity.h"

class Tree : public Entity {
public:
    //Constructor
    Tree(); 
        
    //Returns "Tree"
    virtual string getType();

    //Returns image of a tree using a UTC-8 hex code
    virtual string toString();

    //Returns display color of the tree
    virtual string getColor();
};

#endif