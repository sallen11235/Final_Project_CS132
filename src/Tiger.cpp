/*Joshua Lindquist & Sarah Allen
CS132 Winter 2022
Final Project: Simulation

Cpp file for the Tiger class*/

#include "Tiger.h"

Tiger::Tiger() {
    stepCount = 0;
    currentDir = 'n';
    hasMated = false;
}
Direction Tiger::getMove() {
    vector<Direction> look {NORTH,EAST,SOUTH,WEST}; 
    //Don't hit trees or houses
    for (int i = 0; i < look.size(); i++) {
        if (getNeighbor(look[i]) == "Tree" || getNeighbor(look[i]) == "Building") {
            int chance = rand() % 2;
            if (chance == 0) {
                return look[(i+1) % 4];
            } else {
                return look[(i-1) % 4];
            }
        }
    }
   //Check for anything nearby and exclude other Cats if the Cat has mated.
   for (int i = 0; i < 4; i++) {
        if ((getNeighbor(look[i]) == "\xF0\x9F\x90\x85" && !hasMated) || (getNeighbor(look[i]) != "" && getNeighbor(look[i]) != "\xF0\x9F\x90\x86")) {
            //cout << "getNeighbor: " << look[i] << endl;
            return look[i];
        }
   }
   //if after checking each direction it finds nothing then move randomly up to 5 spaces in a random direction
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

Attack Tiger::fight() const{
    return BITE;
}

string Tiger::getType() {
    return "Tiger";
}

string Tiger::toString() {
   return "\xF0\x9F\x90\x85";
}

string Tiger::getColor() {
    return "blue";
}