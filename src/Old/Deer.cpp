/*Joshua Lindquist & Sarah Allen
CS132 Winter 2022
Final Project: Simulation

Class main author:

Cpp file for the Deer class*/

#include "Deer.h"

Deer::Deer() {
    stepCount = 0;
    currentDir = 'n';
    hasMated = false;
}

Direction Deer::getMove() {
    if (stepCount == 0) {
       stepCount = 5;
       currentDir = rand() % 4;
   }
    stepCount--;
   if (currentDir == 0) {
       return NORTH;
   } else if (currentDir == 1) {
       return EAST;
   } else if (currentDir == 2) {
       return SOUTH;
   } else {
       return WEST;
   }
}

string Deer::getType() {
    return "Deer";
}

string Deer::toString() {
    return "\xF0\x9F\xA6\x8C";
}

string Deer::getColor() {
    return "brown";
}