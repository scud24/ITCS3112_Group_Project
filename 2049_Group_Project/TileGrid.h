/**
    ITSC 3112-001 Group Project
    TileGrid.h
    Purpose: Holds prototype declarations for TileGrid.cpp

    @author Nathan Holzworth, Abhinav Kasu, Johathan Walters
    @version 1.0 11/27/18
*/

#ifndef TILEGRID_H_INCLUDED
#define TILEGRID_H_INCLUDED

// Include required header files
#include "NumberTile.h"
#include "FreeMoveTile.h"
#include "HorizontalMoveTile.h"
#include "VerticalMoveTile.h"



#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>

#include <FL/Fl_Image.H>
#include <FL/Fl_Shared_Image.H>
#include <FL/Fl_PNG_Image.H>
#include <FL/fl_draw.H>

using namespace std;

class TileGrid
{

// Declare Fields
protected:
int width;
int height;
int activeTiles;
NumberTile** tg;
Fl_PNG_Image* verticalTileImage;
Fl_PNG_Image* horizontalTileImage;
Fl_PNG_Image* freemoveTileImage;
Fl_PNG_Image* gridImage;



public:

    /**
        Constructor: Creates grid based on the dimensions.

        @param w Width of the grid.
        @param h Height of the grid.
    */
    TileGrid(int w, int h);

    /**
        Prints a symbolic representation of the game board to the console.

        @param none
    */
    void drawGrid();

    /**
        Updates the GUI representation of the grid

        @param none
    */
    void drawGUI();

    /**
        Lists all active tiles in the console.

        @param none
    */
    void listActiveTiles();

    /**
        Clears the grid's list of current tile.

        @param none
    */
    void clearTiles();

    /**
        Adds Tile to the grid.

        @param t The new tile to be added.
    */
    void addTile(NumberTile* t);

    /**
        Moves Tile horizontally.

        @param dir The distance to move the Tile.
    */
    void moveTilesHorzontal(int dir);

    /**
        Moves Tile Vertically.

        @param dir The distance to move the Tile.
    */
    void moveTilesVertical(int dir);

    /**
        Gets the total number of active tiles on console.

        @param none
        @return The total number of Tiles.
    */
    int getNumActiveTiles();


    /**
        Gets Tile in grid.

        @param x The coordinate.
        @param y The coordinate.
        @return The requested Tile.
    */
    NumberTile* getTileAtLocation(int x, int y);


    /**
        Gets Tile's index in grid.

        @param x The coordinate.
        @param y The coordinate.
        @return The requested Tile index.
    */
    int getTileIndexByLocation(int x, int y);


    /**
        Combines Tiles together.

        @param a First tile.
        @param b Second tile.
    */
    NumberTile* combineTiles(NumberTile* a, NumberTile* b);


    /**
        Removes tile from grid

        @param index The tile's index on grid
    */
    void removeTileAtIndex(int index);


    /**
        Spawn a random tile of a random type at a random location

        @param
    */
    void spawnRandomTile();
};

#endif // TILEGRID_H_INCLUDED

