/*Sarah Allen & Joshua Lindquist
CS132 Winter 2022
Final Project: Simulation

Class main author: Both

Header class for modeling the entities inside the village simulation by 
maintaining a grid of Entities and determining the outcome of their actions.*/

#ifndef _MODEL_H
#define _MODEL_H

#include <vector>
#include "Entity.h"
#include "Tiger.h"
#include "Hunter.h"
#include "Tree.h"
#include "Deer.h"
#include "Lumberjack.h"
#include "Building.h"
#include "entitytypes.h"
#include "Creature.h"

class Model {
public:
    //Constructor, populates vector of vectors with entities
    Model(int modelSize, int tigerNum, int huntNum, int lumbNum, int treeNum, int deerNum);   

    //Calls the Entity's getMove() return, then moves it to its new spot on the map. If the move
    //would place the Entity out of bounds, it will wrap around to the opposite side of the map.
    void addEntity(int row, int col, Entity* animal);
        
    //Returns a pointer to the Entity stored in the specified spot in the map
    Entity* getEntity(int row, int col);

    // returns the number of columns wide / rows tall of the world
    int getSize();

    //Calls for every Entity's move, and determines the outcome of every move and interaction
    void update();

    //Determines the outcome of two creatures fighting, using the creatures' Attack returns
    Entity* fight(Entity* creature1, Entity* creature2);
   
    //Calls for mating behavior between the two entities
    void mate(Entity* creature1);

    //Function for the load/save feature, to place a creature in a specific spot on the map
    void placeEntity(int i, int j, Entity* e);

    Entity* modelNeighbor(int row, int col, Direction dir);

    Entity* typeTranslator(string type);

private:
    //Helper function to fill vector of vector with nullptrs, sets the vectors to the correct size
    vector<vector<Entity*>>* createNewVillage(int modelSize);

    //Member variables:
    vector<vector<Entity*>>* map;
    vector<vector<Entity*>>* oldMap;
    const int row = 100;
    const int col = 100;
    const int startEntNum = 25; //Starting number of entities
    int size;
    const int centerX = row/2;
    const int centerY = col/2;
    int tigerNum;
    int huntNum;
    int lumbNum;
    int treeNum;
    int deerNum;
};

//Overrides the << operator to print Entities as either their getType() return or as nullptr
ostream& operator<< (ostream& out, const Entity* e);

//Overrides the << operator to print any vector, including vectors of vectors
template<typename T>
std::ostream& operator <<(std::ostream& out, const vector<T>& list) {
    if(list.size() == 0) {
        out << "{}";
    } else {
        out << "{";
        for(int i = 0; i < list.size() - 1; i++) {
            T val = list[i];
            out << val << ", ";
        }
        T val = list[list.size() - 1];
        out << val << "}";
    }
    return out;
}

#endif