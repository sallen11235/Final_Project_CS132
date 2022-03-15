/*Sarah Allen & Joshua Lindquist
CS132 Winter 2022
Final Project: Simulation

Class main author: Josh

Header for Creature class, an abstract class for all living Entity objects (so not buildings).
Sets default behaviors for its subclasses, mostly opting for passivity.*/

#ifndef _Creature_H
#define _Creature_H

#include "Entity.h"

class Creature : public Entity {
public:

    Creature();
    //Returns true until Creature loses a fight, destructing the Creature
    virtual bool isAlive();

    //Returns true until onSleep() sets to false
    virtual bool isAwake();

    //Sets isAlive() to return false
    virtual void onLose();

    //                                                           NGL idk how to describe these
    virtual void onMate();
    virtual void onMateEnd();
    virtual void onSleep();
    virtual void onWakeUp();
    virtual void onWin();

    

    //Default attack of FORFEIT
    virtual Attack fight(string);


private:
bool alive;
bool awake;
int woodCount;
int foodCount;
};

#endif