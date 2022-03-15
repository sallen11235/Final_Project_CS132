/*Sarah Allen & Joshua Lindquist
CS132 Winter 2022
Final Project: Simulation

Class main author: Sarah

Gui class header. The GUI will draw and redraw the grid that the model 
class feeds it, and can also load to/save from separate files.*/

#ifndef _GUI_H
#define _GUI_H

#include "Model.h"
#include "gwindow.h"
#include "gbutton.h"
#include "gcontainer.h"
#include "gtypes.h"
#include "gobjects.h"
using namespace sgl;

class Gui {
private:    
    //Member variables:
    GWindow* window;
    Model* model;
    int windowSize;
    int squareSize;
    GButton* saveB;
    GButton* loadB;

    //Helper function to obtain and return a file name from the user.
    string getFileName();
public:
    //Constructor, opens the GUI window and formats according to desired window size 
    //and square size. Calls the GUI update function every set number of milliseconds.
    Gui(int windowSize, int squareSize, int tigerNum, int huntNum, int lumbNum, int treeNum, int deerNum);

    //Draws the vector of vectors of Entities from the Model object
    void draw();

    //Calls for the Model object to update itself, then redraws the changes
    void update();

    //Save the state of the model and its parameters to a separate file for later use.
    void save();

    //Loads a saved file to restore simulation to a desired state.
    void load();
};

#endif