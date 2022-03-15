/*Joshua Lindquist & Sarah Allen
CS132 Winter 2022
Final Project: Simulation

Cpp file for the Gui class*/

#include <iostream>
#include <fstream>
#include "Gui.h"


using namespace std;

Gui::Gui(int windowSize, int squareSize, int tigerNum, int huntNum, int lumbNum, int treeNum, int deerNum) {
    this->windowSize = windowSize;
    this->squareSize = squareSize;

    // creates the initial version of our model
    model = new Model(windowSize / squareSize, tigerNum, huntNum, lumbNum, treeNum, deerNum);

    window = new GWindow(windowSize, windowSize+25);
    window->setExitOnClose(true);
    window->setBackground("white");
    window->setColor("black");
    window->setFillColor("#00DDAA");
    window->setFont("Arial-9-bold");
    //Save button:
    saveB = new GButton("Save");
    saveB->setActionListener([this]() {
        this->save();
    });
    window->addToRegion(saveB, GWindow::Region::REGION_SOUTH);
    //Load button:
    loadB = new GButton("Load");
    loadB->setActionListener([this]() {
    this->load();
    });
    window->addToRegion(loadB, GWindow::Region::REGION_SOUTH);
    
    // draw the critters at their initial positions
    draw();

    // sets it so the redraw function will be called every 2 seconds. 
     window->setTimerListener(2000, [this] {
        this->update();
    });
}

void Gui::draw() {
    // clear off the screen and draw the updated contents of the model
    window->clearCanvasPixels();
    window->setFillColor("#00DDAA");
    window->drawRect(0, 0, windowSize, windowSize);
    window->fillRect(0, 0, windowSize, windowSize);
    for(int row = 0; row < model->getSize(); row++) {
        for(int col = 0; col < model->getSize(); col++) {
            Entity* thing = model->getEntity(row, col);
            //Ignore nullptr non-entities
            if(thing != nullptr) {
               string name = thing->toString();
               int fontSize = thing->getFont();
               string font = "Arial-" + to_string(fontSize) + "-bold";
               window->setColor(thing->getColor());
               window->setFont(font);
               window->drawString(name, row * squareSize, col * squareSize);
            }
        }
    }
}

void Gui::update() {
    //Call the model to update the grid
    model->update();
    draw();
}

string Gui::getFileName() {
    string save;
    cout << "Please enter file name in format \"file.txt\": ";
    cin >> save;
    return save;
}

void Gui::save() {
    string save = getFileName();
    ofstream saveFile;
    saveFile.open(save);
    if(saveFile.good()) { //Check for existing file
        bool approved = false;
        while (!approved) { //Keep asking until user agrees to overwrite
            cout << "Overwrite file? y/n ";
            string input;
            getline(cin, input);
            if (input == "Y" || input == "y") { //Leave while loop
                cout << "File overwritten." << endl;
                approved = true;
            } else if (input == "N" || input == "n") { //Get new file
                saveFile.close();
                save = getFileName();
                saveFile.open(save);
                if (!saveFile.good()) {
                    approved = true;
                }
            } else { //Reprompt for Y/N
                cout << "Invalid response. ";
            }
        }
    }
    saveFile << windowSize << endl << squareSize << endl;
    saveFile << model;
    saveFile.close();
}

void Gui::load() {
    ifstream loadFile;
    string load = getFileName();
    loadFile.open(load);
    bool goodFile = loadFile.good(); //Check for existing file
    while (!goodFile) {
        cout << "Sorry, that file does not exist. Please try again." << endl;
        loadFile.close();
        load = getFileName(); //Get a new file name
        loadFile.open(load);
        goodFile = loadFile.good();
    }
    //Use file info to create new model grid
    loadFile >> windowSize;
    loadFile >> squareSize;

    //Create new (empty) Model
    model = new Model(windowSize / squareSize, 0, 0, 0, 0, 0);
    //Fill the Model:
    for (int i = 0; i < windowSize / squareSize; i++) {
        for (int j = 0; j < windowSize / squareSize; j++) {
            string next;
            loadFile >> next;

            //Depending on next input, create an entity to place in (*map)[i][j]
            if (next == ".," || next == "{.," || next == ".}") {
                model->placeEntity(i, j, nullptr);
            } else if (next == "Building," || next == "{Building," || next == "Building}") {
                Entity* added = new Building;
                model->placeEntity(i, j, added);
            } else if (next == "Deer," || next == "{Deer," || next == "Deer}") {
                Entity* added = new Deer;
                model->placeEntity(i, j, added);
            } else if (next == "Hunter," || next == "{Hunter," || next == "Hunter}") {
                Entity* added = new Hunter;
                model->placeEntity(i, j, added);
            } else if (next == "Lumberjack," || next == "{Lumberjack," || next == "Lumberjack}") {
                Entity* added = new Lumberjack;
                model->placeEntity(i, j, added);
            } else if (next == "Tiger," || next == "{Tiger," || next == "Tiger}") {
                Entity* added = new Tiger;
                model->placeEntity(i, j, added);
            } else if (next == "Tree," || next == "{Tree," || next == "Tree}") {
                Entity* added = new Tree;
                model->placeEntity(i, j, added);
            }
        }
    }
    loadFile.close();
    draw();
}