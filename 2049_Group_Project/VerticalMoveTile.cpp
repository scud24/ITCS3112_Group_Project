/**
    ITSC 3112-001 Group Project
    VerticalMoveTile.cpp
    Purpose: This class creates and allows the tile to be moved Vertically.
    It decides wether the tile can be moved based on its type.

    @author Nathan Holzworth, Abhinav Kasu, Johathan Walters
    @version 1.0 11/27/18
*/

#include <iostream>
#include <cstdlib>

#include "VerticalMoveTile.h"

using namespace std;

/**
    Constructor: Gives Tile the coordinates on grid and value to hold.

    @param x cordinate value on grid.
    @param y cordinate value on grid.
    @param value the number Tile should hold.
*/
VerticalMoveTile::VerticalMoveTile(int x, int y, int value)
    :NumberTile(x, y, value)
{
    // Set value
    setTileType("VerticalMoveTile");
}

/**
    Decide wether Tile can be moved Horizontally.

    @param none
    @return True or False for the move.
*/
bool VerticalMoveTile::canMoveHorizontal() const
{
    return false;
}

/**
    Decide wether Tile can be moved Vertically.

    @param none
    @return True or False for the move.
*/
bool VerticalMoveTile::canMoveVertical() const
{
    return true;
}


/**
    Gets the Tile type Vertical or horizontal.

    @param t The Tile
    @return String denoting the Tile type.
*/
string VerticalMoveTile::getCombinedTileType(NumberTile* t) const
{
    // Decide Tile type
    if(t->getTileType() == "VerticalMoveTile")
    {
        return "VerticalMoveTile";
    }
    return "FreeMoveTile";
}

/**
    Gets the Tile icons textual representation.

    @param none
    @return String denoting the Tile type.
*/
string VerticalMoveTile::getConsoleIcon()
{
    // Return textual reprersentation
    return "^" + std::to_string(value) + "v ";
}
