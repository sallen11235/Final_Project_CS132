/*Joshua Lindquist & Sarah Allen
CS132 Winter 2022
Final Project: Simulation

Cpp file for the Deer class*/

#include <iostream>
#include "Deer.h"
#include <vector>
using namespace std;

Deer::Deer() {
    stepCount = 0;
    currentDir = CENTER;
    hasMated = false;
    flee = -1;
    rest = 0;
}

Direction Deer::getMove() {
    vector<Direction> dirs {NORTH, SOUTH, WEST, EAST};
    vector<Direction> opposite {SOUTH, NORTH, EAST, WEST};
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
    if (flee > 0) {
        flee--;
        return currentDir;
    } else if (flee == 0) {
        rest = 5;
        flee = -1;
        return CENTER;
    } else if (rest != 0) {
        rest--;
        return CENTER;
    } else {
        for (int i = 0; i < dirs.size(); i++) {
            if (getNeighbor(dirs[i]) == "Tiger" || getNeighbor(dirs[i]) == "Hunter" || getNeighbor(dirs[i]) == "Lumberjack") {
                flee = 5;
                currentDir = opposite[i];
                return currentDir;
            }
        }
        int random = rand() % 4;
        return dirs[random];
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

// Attack Deer::fight() const {
//     return FORFEIT;
// }