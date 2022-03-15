/*Joshua Lindquist & Sarah Allen
CS132 Winter 2022
Final Project: Simulation

Cpp file for the Lumberjack class*/

#include "Lumberjack.h"

Lumberjack::Lumberjack() {
    woodCount = 0;
}

Direction Lumberjack::getMove() {
    vector<Direction> dirs {NORTH, SOUTH, WEST, EAST};

    //Get! Those! Trees! but not the houses
    for (int i = 0; i < dirs.size(); i++) {
        if (getNeighbor(dirs[i]) == "Tree") {
            woodCount++;
            return dirs[i];
        } else if (getNeighbor(dirs[i]) == "Building") {
            int chance = rand() % 2;
            if (chance == 0) {
                return dirs[(i+1) % 4];
            } else {
                return dirs[(i-1) % 4];
            }
        }
    }
    //potentially add home zone with ifs:
    //if (getX() > HOME_BOUND && getX() < HOME_BOUND2 && getY() < BLAH && getY() > BLAB) {
    int random = rand() % 4;
    //int currentDir = random;
    return dirs[random];
    //} else {
        //return opposite[currentDir];
    //}
}

Attack Lumberjack::fight() const{
    return CHOP;
}

string Lumberjack::getType() {
    return "Lumberjack";
}

string Lumberjack::toString() {
  //return "\xF0\x9F\xA7\x8D"; //humanoid
  return "\xF0\x9F\xAA\x93"; //axe
}

string Lumberjack::getColor() {
    return "blue";
}