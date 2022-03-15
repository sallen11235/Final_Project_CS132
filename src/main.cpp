/*Sarah Allen & Joshua Lindquist
CS132 Winter 2022
Final Project: Simulation 

For our final project we decided to simulate a village. The villagers consist of hunters and
lumberjacks. The hunters will hunt deer for food, the lumberjacks will cut down trees, and once 
a tree is cut down they will build a house. There are also tigers roaming about, which only 
hunters can stand a chance against.

As for this main() file, it simply creates the GUI.*/

#include "Gui.h"

int main() {
    //Changable Parameters:
    int MODEL_SIZE = 200;
    int SQUARE_SIZE = 20;
    int TIGER_NUM = 0;
    int HUNTER_NUM = 0;
    int LUMBER_NUM = 0;
    int TREE_NUM = 0;
    int DEER_NUM =5;
   
    new Gui(MODEL_SIZE, SQUARE_SIZE, TIGER_NUM, HUNTER_NUM, LUMBER_NUM, TREE_NUM, DEER_NUM);
    return 0;
}