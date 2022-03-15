/*Joshua Lindquist & Sarah Allen
CS132 Winter 2022
Final Project: Simulation

Cpp file for Creature class */

#include "Creature.h"

Creature::Creature() {}

bool Creature::isAlive() {
    return alive;
}

bool Creature::isAwake() {
    return awake;
}

void Creature::onLose() {
    alive = false;
}

void Creature::onMate() {}
void Creature::onMateEnd() {}

void Creature::onSleep() {
    awake = false;
}

void Creature::onWakeUp() {
    awake = true;
}

void Creature::onWin() {}



Attack Creature::fight(string) {
    return FORFEIT;
}