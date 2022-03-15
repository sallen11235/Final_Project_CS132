/*Joshua Lindquist & Sarah Allen
CS132 Winter 2022
Final Project: Simulation

Cpp file for Entity class*/

 #include "Entity.h"

Entity::Entity() {
    fontSize = 9;
}

int Entity::getHeight() {
    return height;
}

int Entity::getWidth() {
    return width;
}

int Entity::getX() {
    return x;
}

int Entity::getY() {
    return y;
}

void Entity::setPos(int x, int y) {
    this->x = x;
    this->y = y;
}

bool Entity::isChild() {
    return child;
}

string Entity::getType() {
    //default:
    return "Entity";
}

string Entity::toString() {
    //default:
    return "?";
}

string Entity::getColor() {
    //default:
    return "black";
}

Direction Entity::getMove() {
    return CENTER;
}

void Entity::setNeighbor(Direction dir, const string& neighbor) {
    if (dir < 0 || dir >= DIRECTION_COUNT) {
        return;
    }
    neighbors[dir] = neighbor;
}

string Entity::getNeighbor(Direction dir) const{
    if (dir < 0 || dir >= DIRECTION_COUNT) {
        return "";
    }
    return neighbors[dir];
}

int Entity::getFont() const {
    //default:
    return fontSize;
}

Attack Entity::fight() const {
    return FORFEIT;
}

void Entity::onWin() const {}

void Entity::onMate() const {}

