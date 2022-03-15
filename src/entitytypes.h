//Enum files. Although they're slightly altered, we will not take credit 
//for writing these, as they were originally ripped straight from Critters

#ifndef _ENTITYTYPES_H
#define _ENTITYTYPES_H

#include <string>

enum Attack {
    FORFEIT,
    CHOP,
    STAB,
    BITE,
};
std::string to_string(Attack attack);
extern int ATTACK_COUNT;

enum Direction {
    CENTER,
    NORTH,
    EAST,
    SOUTH,
    WEST
};
std::string to_string(Direction direction);
extern int DIRECTION_COUNT;

#endif // _ENTITYTYPES_H
