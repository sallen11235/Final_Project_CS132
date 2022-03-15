/*Sarah Allen & Joshua Lindquist
CS132 Winter 2022
Final Project: Simulation

Class main author: Sarah

Header file for the Building class. These will be constructed when a 
tree is cut down, and otherwise will not interact with other entities.*/

#ifndef _BUILDING_H
#define _BUILDING_H

#include "Entity.h"

class Building : public Entity {
public:
    //Constructor
    Building();
    
    //Returns "Building"
    virtual string getType();

    //Returns image of building using a UTC-8 hex code 
    virtual string toString();

    //Returns display color of building
    virtual string getColor();

    //Larger than humans, tigers, etc :)
    virtual int getFont() const;
    
private: 
};

#endif