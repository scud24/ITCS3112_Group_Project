
/**
    ITSC 3112-001 Group Project
    HorizontalMoveTile.cpp
    Purpose: This class creates and allows the tile to be moved Horizontally.
    It decides wether the tile can be moved based on its type.

    @author Nathan Holzworth, Abhinav Kasu, Johathan Walters
    @version 1.0 11/27/18
*/

#include <iostream>
#include <cstdlib>

// Include required header files.
#include "HorizontalMoveTile.h"

using namespace std;

/**
    Constructor: Create tile that can only move horizontally.

    @param x cordinate value on grid.
    @param y cordinate value on grid.
    @param value the number Tile should hold.
*/
HorizontalMoveTile::HorizontalMoveTile(int x, int y, int value)
    :NumberTile(x, y, value)
{
    // Set Type
    setTileType("HorizontalMoveTile");
}

/**
    Determine if tile can move horizontally.

    @param none
    @return True or False for the move.
*/
bool HorizontalMoveTile::canMoveHorizontal() const
{
    return true;
}

/**
    Determine if tile can move vertically.

    @param none
    @return True or False for the move.
*/

bool HorizontalMoveTile::canMoveVertical() const
{
    return false;
}

/**
    Gets the Tile type Vertical or Horizontal.

    @param t The Tile
    @return String denoting the Tile type.
*/
string HorizontalMoveTile::getCombinedTileType(NumberTile* t) const
{
    // Decide Tile type
    if(t->getTileType() == "HorizontalMoveTile")
    {
        return "HorizontalMoveTile";
    }
    return "FreeMoveTile";
}
/**
    Gets the Tile icons textual representation.

    @param none
    @return String denoting the Tile type.
*/
string HorizontalMoveTile::getConsoleIcon()
{
    // Return textual reprersentation
    return " <" + std::to_string(value) + ">";
}
