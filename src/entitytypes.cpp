//Cpp for entitytypes enums


#include "entitytypes.h"

std::string to_string(Attack attack) {
    switch (attack) {
        case FORFEIT: return "FORFEIT";
        case CHOP:    return "CHOP";
        case STAB:  return "STAB";
        case BITE: return "BITE";
        default:      return "unknown";
    }
}
int ATTACK_COUNT = 4;

std::string to_string(Direction direction) {
    switch (direction) {
        case CENTER: return "CENTER";
        case NORTH:  return "NORTH";
        case EAST:   return "EAST";
        case SOUTH:  return "SOUTH";
        case WEST:   return "WEST";
        default:     return "unknown";
    }
}
int DIRECTION_COUNT = 5;
