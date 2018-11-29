/**
    ITSC 3112-001 Group Project
    FreeMoveTile.h
    Purpose: This class creates and allows the tile to be moved freely.
    It decides wether the tile can be moved based on its type.

    @author Nathan Holzworth, Abhinav Kasu, Johathan Walters
    @version 1.0 11/27/18
*/
#include <iostream>
#include <cstdlib>
#include "FreeMoveTile.h"
using namespace std;

/**
    Constructor: Create tile that can only move freely.

    @param x cordinate value on grid.
    @param y cordinate value on grid.
    @param value the number Tile should hold. 
*/
FreeMoveTile::FreeMoveTile(int x, int y, int value)
    :NumberTile(x, y, value)
{
    // Set Type
    setTileType("FreeMoveTile");
}

/**
    Determine if tile can move horizontally.
        
    @param none
    @return True or False for the move.
*/
bool FreeMoveTile::canMoveHorizontal() const
{
    return true;
}

/**
    Determine if tile can move vertically.

    @param none
    @return True or False for the move.
*/
bool FreeMoveTile::canMoveVertical() const
{
    return true;
}

/**
    Gets the Tile type Vertical or Horizontal.

    @param t The Tile
    @return String denoting the Tile type.
*/
string FreeMoveTile::getCombinedTileType(NumberTile* t) const
{
    return "FreeMoveTile";
}

/**
    Gets the Tile icons textual representation.

    @param none
    @return String denoting the Tile type.
*/
string FreeMoveTile::getConsoleIcon()
{
    return "[" + std::to_string(value) + "]";
}