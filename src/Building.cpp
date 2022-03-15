/*Joshua Lindquist & Sarah Allen
CS132 Winter 2022
Final Project: Simulation

Cpp file for the Building class*/

#include "Building.h"

Building::Building() {}

string Building::getType() {
    return "Building";
}

string Building::toString() {
    //return "H";
    return "\xF0\x9F\x8F\xA0";
}

string Building::getColor() {
    return "red";
}

int Building::getFont() const {
    return Entity::getFont()*2;
}