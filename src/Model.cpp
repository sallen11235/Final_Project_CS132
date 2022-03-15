/*Joshua Lindquist & Sarah Allen
CS132 Winter 2022
Final Project: Simulation

Class main author: 

*/

#include "Model.h"

using namespace std;

vector<vector<Entity*>>* Model::createNewVillage(int modelSize) {
    vector<vector<Entity*>>* EntityMap = new vector<vector<Entity*>>();
 
    // adding size inner vectors to the outer vector
    for(int i = 0; i < modelSize; i++) {
        vector<Entity*> row;
        // adding nullptr to every spot so it is the right size
        for(int j = 0; j < modelSize; j++) {
            row.push_back(nullptr);
        }
        EntityMap->push_back(row); 
    }
    return EntityMap;
}

Model::Model(int modelSize, int tigerNum, int huntNum, int lumbNum, int treeNum, int deerNum) {
    this->size = modelSize;
    this->tigerNum = tigerNum;
    this->huntNum = huntNum;
    this->treeNum = treeNum;
    this->deerNum = deerNum;
    this->lumbNum = lumbNum;
    map = createNewVillage(modelSize);
    
    //Randomly place each class, depending on how many (determined by initializer)
    for (int i = 0; i < tigerNum; i++) {
        int x = rand() % modelSize;
        int y = rand() % modelSize;
        Entity* tiger = new Tiger;
        tiger->setPos(x,y);
        (*map)[x][y] = tiger;
    }
    for (int i = 0; i < huntNum; i++) {
        int x = rand() % modelSize;
        int y = rand() % modelSize;
        Entity* hunt = new Hunter;
        hunt->setPos(x,y);
        (*map)[x][y] = hunt;
    }
    for (int i = 0; i < treeNum; i++) {
        int x = rand() % modelSize;
        int y = rand() % modelSize;
        Entity* tree = new Tree;
        tree->setPos(x,y);
        (*map)[x][y] = tree;
    }
    for (int i = 0; i < deerNum; i++) {
        int x = rand() % modelSize;
        int y = rand() % modelSize;
        Entity* deer = new Deer;
        deer->setPos(x,y);
        (*map)[x][y] = deer;
    }
    for (int i = 0; i < lumbNum; i++) {
        int x = rand() % modelSize;
        int y = rand() % modelSize;
        Entity* lumb = new Lumberjack;
        lumb->setPos(x,y);
        (*map)[x][y] = lumb;
    }
}

int Model::getSize() {
    return size;
}

//Entity* Model::typeTranslator(string type){}

void Model::mate(Entity* creature1) {
    cout << "Reached mate!" << endl;
    //We need to add a new baby
    //For humans, baby will always take after creature1
    string creature1Type = creature1->getType();
    cout << "Got type: " << creature1Type << endl;
    Entity* baby = new Creature; //Not null? Please don't break?
    cout << "Got baby" << endl;

    //Get baby's class
    if (creature1Type == "Deer") {
        baby = new Deer();
    } else if (creature1Type == "Hunter") {
        baby = new Hunter();
    } else if (creature1Type == "Lumberjack") {
        baby = new Lumberjack();
    } else if (creature1Type == "Tiger") {
        baby = new Tiger();
    }

cout << "Got baby type: " << baby->getType() << endl;
    //Place baby in available empty spot.
    int x = creature1->getX();
    int y = creature1->getY();
    if (modelNeighbor(x, y, NORTH) == nullptr) {
        (*map)[x][y] = baby;
        baby->setPos(x, y);
    } else if (modelNeighbor(x, y, SOUTH) == nullptr) {
        (*map)[x][y] = baby;
        baby->setPos(x, y);
    } else if (modelNeighbor(x, y, WEST) == nullptr) {
        (*map)[x][y] = baby;
        baby->setPos(x, y);
    } else if (modelNeighbor(x, y, EAST) == nullptr) {
        (*map)[x][y] = baby;
        baby->setPos(x, y);
    } //If none available the baby died from childbirth complications :'(
        cout << "Got to end of mate" << endl;
}

Entity* Model::fight(Entity* creature1, Entity* creature2) {
    //get the weapons for each creature
    cout << "Reached fight function!" << endl;
    Attack weapon1 = creature1->fight();
    cout << "Got first weapon: " << creature1->getType() << weapon1 << endl;
    Attack weapon2 = creature2->fight();
    cout << "Got second weapon: " << weapon2 << endl;

    Entity* winner;
    cout << "Weapons: " << weapon1 << " " << weapon2 << endl;
    if ((weapon2 == FORFEIT) || (weapon1 == BITE && weapon2 == CHOP)) {
        winner = creature1;
    } else if ((weapon1 == STAB && weapon2 == BITE) || (weapon1 == BITE && weapon2 == STAB)) {
        winner = rand() % 2 == 0 ? creature1 : creature2;
    } else {
        winner = creature2;
    }

    return winner;
}

Entity* Model::getEntity(int row, int col) {
    return (*map)[row][col];
}

Entity* Model::modelNeighbor(int row, int col, Direction dir) {
    int newRow;
    int newCol;
    Entity* neighbor;
    if(dir == WEST) {
        newRow = row - 1 < 0? map->size() - 1 : row - 1;
        return neighbor = (*map)[newRow][col];
    } else if (dir == EAST) {
       newRow = (row + 1) % map->size();
       return neighbor = (*map)[newRow][col];
    } else if (dir == SOUTH) {
        newCol = (col + 1) % map->size();
        return neighbor = (*map)[row][newCol];
    } else if (dir == NORTH) {
        newCol = col - 1 < 0? map->size() - 1 : col - 1;
        return neighbor = (*map)[row][newCol];
    }else {
        return neighbor = nullptr;
    }
}

void Model::addEntity(int row, int col, Entity* thing, vector<vector<Entity*>>* oldMap) {
    cout << thing->getType();                                                                   //ERASE THIS
        Direction dir = thing->getMove();
        string neighbor = "";
    if (dir != CENTER) { //Entity can't be its own neighbor
        Entity* neighborEnt = modelNeighbor(row, col, dir);
        if (neighborEnt != nullptr) { //if the neighbor exists
            neighbor = neighborEnt->getType();
        }
        thing->setNeighbor(dir, neighbor);
    }
    int newRow = row;
    int newCol = col;

    //gets new row and new col for the rest of this function to work
    if(dir == WEST) {
        newRow = row - 1 < 0? map->size() - 1 : row - 1;
    } else if (dir == EAST) {
       newRow = (row + 1) % map->size();
    } else if (dir == SOUTH) {
        newCol = (col + 1) % map->size();
    } else if (dir == NORTH) {
        newCol = col - 1 < 0? map->size() - 1 : col - 1;
    }else {
        (*map)[row][col] = thing;
    }

    cout << " Neighbor: " << neighbor << endl;
    if(neighbor != "") {
        //Entity* otherThing = (*oldMap)[newRow][newCol];
        //Entity* otherThing = modelNeighbor(row, col, dir);
        Entity* otherThing = modelNeighbor(newRow, newCol, dir);
        
        if (neighbor == thing->getType() //If matching Entities or both humans
        || (neighbor == "Hunter" && thing->getType() == "Lumberjack") 
        || (neighbor == "Lumberjack" && thing->getType() == "Hunter")) {
            mate(thing);
            thing->onMate();
            otherThing->onMate();
        } else {
            Entity* winner = fight(thing, otherThing);
            winner->onWin();

            //Build house with lumber
            if (otherThing->getType() == "Tree") { 
            (*map)[newRow][newCol] = new Building;
            (*map)[row][col] = winner;
            } else {
            //Winner takes the spot:
            (*map)[newRow][newCol] = winner;
            }
        }
    } else {
        (*map)[newRow][newCol] = thing;
    }
}

void Model::update() {
    // create a new map 
    vector<vector<Entity*>>* newMap = createNewVillage(map->size());
    // creates a temporary pointer to point at the old state of the map
    // and points the member variable at the empty new map
    vector<vector<Entity*>>* oldMap = map;
    map = newMap;

    //
    for(int row = 0; row < map->size(); row++) {
        for(int col = 0; col < map->size(); col++) {
            Entity* thing = (*oldMap)[row][col];
           
            // when you come accross a Entity....
            if(thing != nullptr) {
               
                //Ensures each thing knows where it is
                thing->setPos(row, col);
                cout << "Thing pos: "<< thing->getX() << ", " << thing->getY() << endl;
                
                //Checks each direction for neighbors, would be good to make this a new function.
                for (Direction dir : {CENTER, NORTH, EAST, SOUTH, WEST}) {
                    Entity* neighbor;
                    int newRow = row;
                    int newCol = col;
                    if(dir == WEST) {
                        newRow = row - 1 < 0? map->size() - 1 : row - 1;
                    } else if (dir == EAST) {
                        newRow = (row + 1) % map->size();
                    } else if (dir == SOUTH) {
                        newCol = (col + 1) % map->size();
                    } else if (dir == NORTH) {
                        newCol = col - 1 < 0? map->size() - 1 : col - 1;
                    }else {
                        neighbor = (*oldMap)[row][col];
                    }
                    
                    neighbor = (*oldMap)[newRow][newCol]; 
                    
                    if (neighbor != nullptr) {
                        string neighborName = neighbor->getType();
                        thing->setNeighbor(dir, neighborName);
                    } else {
                        thing->setNeighbor(dir, "");
                    }
                }
                //Adds everything onto the map, this needs to be the last thing that happens here
                addEntity(row, col, thing, oldMap);
            }
        }
    }
}


void Model::placeEntity(int i, int j, Entity* e) {
    (*map)[i][j] = e;
}

ostream& operator<< (ostream& out, Entity* e) {
    if (e !=nullptr) {
        out << e->getType();
    } else {
        out << ".";
    }
    return out;
}