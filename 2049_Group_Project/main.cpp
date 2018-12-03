/**
    ITSC 3112-001 Group Project
    main.cpp
    Purpose: The driver class for game.
    Sets up the game, calls functions and runs everything.

    @author Nathan Holzworth, Abhinav Kasu, Johathan Walters
    @version 1.0 11/27/18
*/
#include <iostream>

// Include required header files
#include "NumberTile.h"
#include "TileGrid.h"
#include "FreeMoveTile.h"
#include "HorizontalMoveTile.h"
#include "VerticalMoveTile.h"

using namespace std;


int main()
{
    cout << "Welcome to 4096 Game" << endl;

    // Create Grid
    TileGrid* tg = new TileGrid(5, 5);

    // Create Tiles
    FreeMoveTile* fmt1 = new FreeMoveTile(0,0,4);
    FreeMoveTile* fmt2 = new FreeMoveTile(2,4,2);
    HorizontalMoveTile* hmt1 = new HorizontalMoveTile(4,1,8);
    HorizontalMoveTile* hmt2 = new HorizontalMoveTile(2,1,4);
    VerticalMoveTile* vmt1 = new VerticalMoveTile(3,3,16);
    VerticalMoveTile* vmt2 = new VerticalMoveTile(0,4,4);

    // Add Tiles to grid
    tg->addTile(fmt1);
    tg->addTile(fmt2);
    tg->addTile(hmt1);
    tg->addTile(hmt2);
    tg->addTile(vmt1);
    tg->addTile(vmt2);

    // Set grid and display
    tg->listActiveTiles();
    tg->drawGrid();
    tg->drawGUI();

    // Store user input
    string playerInput;

    // Loop for game
    while(playerInput!= "e")
    {
        // get use imput and display prompt
        cout << "Enter w, a, s, or d to move tiles up, left, down, or right, or Enter e to exit" << endl;
        cin>>playerInput;
        cout<< "Input was: " << playerInput << endl;

        // Evaluate user input and move tiles
        if(playerInput == "w")
        {
            tg->moveTilesVertical(-1);
        }
        else if(playerInput == "a")
        {
            tg->moveTilesHorzontal(-1);
        }
        else if(playerInput == "s")
        {
            tg->moveTilesVertical(1);
        }
        else if(playerInput == "d")
        {
            tg->moveTilesHorzontal(1);
        }
        else if(playerInput != "e")
        {
            cout << "Exitting Game.... GoodBye!" << endl;
        }
        tg->drawGrid();
        tg->drawGUI();
    }

    // Clear tiles and drid before exitting
    //tg->clearTiles();

    //tg->drawGrid();



}
