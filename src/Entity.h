/*Sarah Allen & Joshua Lindquist
CS132 Winter 2022
Final Project: Simulation

Class main author: Josh

Header file for base class of Entity. It is what will fill the vector of 
vectors in model, and allows the model to interact with all of its data.*/

#ifndef _ENTITY_H
#define _ENTITY_H

#include <iostream>
#include <vector>

#include "entitytypes.h"
using namespace std;

class Entity {
public:
    //Constructor
    Entity();

    //Returns object's height
    virtual int getHeight();

    // //Returns object string in the designated direction
    virtual string getNeighbor(Direction dir) const;

    //Returns object's width
    virtual int getWidth();

    //Returns object's X position
    virtual int getX();

    //Returns object's Y position
    virtual int getY();

    //Determines if object is a child/sappling/building-in-progress
    virtual bool isChild();

    //Returns the name of what type of entity the object is
    virtual string getType();

    //Returns the visual representation of the entity
    virtual string toString();

    //Returns display color of the entity
    virtual string getColor();

    //Default move of CENTER
    virtual Direction getMove();

    //Function that allows Model class to feed the Entity what its neighbor is
    virtual void setNeighbor(Direction dir, const string& neighbor);

    //Gets neighbor
    //virtual string getNeighbor(Direction dir/* , int x, int y */) const;

    virtual void setPos(int x, int y);

    //Gets object's display font size
    virtual int getFont() const;

    //Allows the entities to use a fight function when cast as Entity
    virtual Attack fight() const;

    //Allows the entities to use on-win behavior when cast as Entity
    virtual void onWin() const;

    //Allows entities to use a specific behavior after mating when cast as Entity
    virtual void onMate() const;

private:
    int height;
    int width;
    int x;
    int y;
    bool child;
    string neighbors[5];
    int fontSize;
};

#endif
