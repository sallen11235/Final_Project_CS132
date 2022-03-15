/*Joshua Lindquist & Sarah Allen
CS132 Winter 2022
Final Project: Simulation

Class main author:

Cpp file for the Hunter class*/

#include "Hunter.h"

Hunter::Hunter() {
    currentDir = 0;
    foodCount = 0;
}

void Hunter::onWin() {
    foodCount++;
}

Attack Hunter::fight() const{
    return STAB;
}

string Hunter::getType() {
    return "Hunter";
}

string Hunter::toString() {
   
    //return "\xF0\x9F\xA7\x98"; //humanoid
    return "\xF0\x9F\x8F\xB9"; //bow
    //return "\xF0\x9F\x97\xA1"; //dagger
}

string Hunter::getColor() {
    return "blue";
}

Direction Hunter::getMove() {
    vector<Direction> dirs {NORTH, SOUTH, WEST, EAST};
    vector<Direction> opposite {SOUTH, NORTH, EAST, WEST};
    //Persistance hunt deer
    for (int i = 0; i < dirs.size(); i++) {
        if (getNeighbor(dirs[i]) == "Deer") {
            return dirs[i];
        }
    }
    //Don't hit trees or houses
    for (int i = 0; i < dirs.size(); i++) {
        if (getNeighbor(dirs[i]) == "Tree" || getNeighbor(dirs[i]) == "Building") {
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
    currentDir = random;
    return dirs[random];
    //} else {
        //return opposite[currentDir];
    //}

}
