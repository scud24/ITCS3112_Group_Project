/**
    ITSC 3112-001 Group Project
    TileGrid.h
    Purpose: Holds prototype declarations for TileGrid.cpp

    @author Nathan Holxworth
    @version 1.0 11/27/18
*/

#ifndef TILEGRID_H_INCLUDED
#define TILEGRID_H_INCLUDED

#include "NumberTile.h"
#include "FreeMoveTile.h"
#include "HorizontalMoveTile.h"
#include "VerticalMoveTile.h"

using namespace std;

class TileGrid
{
protected:
int width;
int height;
int activeTiles;
NumberTile** tg;

public:

    /**
        Description

        @params
    */
    TileGrid(int w, int h);

    /**
        Prints a symbolic representation of the game board to the console
    */
    void drawGrid();

    /**
        Lists all active tiles in the console
    */
    void listActiveTiles();

    /**
        Clears the grid's list of current tile
    */
    void clearTiles();

    /**
        Description

        @params
    */
    void addTile(NumberTile* t);

    /**
        Description

        @params
    */
    void moveTilesHorzontal(int dir);

    /**
        Description

        @params
    */
    void moveTilesVertical(int dir);

    /**
        Description

        @params
    */
    int getNumActiveTiles();


    /**
        Description

        @params
    */
    NumberTile* getTileAtLocation(int x, int y);


    /**
        Description

        @params
    */
    int getTileIndexByLocation(int x, int y);


    /**
        Description

        @params
    */
    NumberTile* combineTiles(NumberTile* a, NumberTile* b);


    /**
        Description

        @params
    */
    void removeTileAtIndex(int index);
};

#endif // TILEGRID_H_INCLUDED

