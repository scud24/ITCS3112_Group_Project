/**
    ITSC 3112-001 Group Project
    NumberTile.cpp
    Purpose: Creates the Tiles that will be used in game.
    Sets the tile type, value and location in grid.
    Decides what type of tiles can be combined and where they will be used.
    Alters tiles as need and informs user of errors.

    @author Nathan Holzworth, Abhinav Kasu, Johathan Walters
    @version 1.0 11/27/18
*/

#include <iostream>
#include <cstdlib>

// Include required header files
#include "NumberTile.h"

using namespace std;

/**
    Constructor: Create empty tile.

*/
NumberTile::NumberTile()
    :value(0), x(-1), y(-1)
{
    // Set type
    setTileType("Empty");
}

/**
    Constructor: Creates number tile based on a value.

    @param xpos X coordinate on grid.
    @param ypos Y coordinate on grid.
    @ param tileValue Value of the tile
*/
NumberTile::NumberTile(int xpos, int ypos, int tileValue)
    :value(tileValue), x(xpos), y(ypos)
{
    // Set Type
    setTileType("NumberTile");
}

/**
    Sets the value of Tile.

    @param newValue Value to be assigned.

*/
void NumberTile::setValue(int newValue)
{
    // Set Value
    value = newValue;
}

/**
    Gets the value of Tile.

    @param none
    @return Value of the Tile
*/
int NumberTile::getValue()
{
    return value;
}

/**
    Set X coordinate of tile.

    @param newX Value of coordinate.
*/
void NumberTile::setX(int newX)
{
    // Set Value
    x = newX;
}

/**
    Get X coordinate of tile.

    @return x coordinate value.
*/
int NumberTile::getX()
{
    return x;
}

/**
    Set Y coordinate of tile.

    @param newY Value of coordinate.
*/
void NumberTile::setY(int newY)
{
    // Set Value
    y = newY;
}

/**
    Get Y coordinate of tile.

    @return y coordinate value.
*/
int NumberTile::getY()
{
    return y;
}

/**
    Set Tile Type.

    @param newType The Tile type.
*/
void NumberTile::setTileType(string newType)
{
    // Set Type
    type = newType;
}

/**
    Get Tile Type.

    @return The Tile type.
*/
string NumberTile::getTileType()
{
    return type;
}

/**
    Attempts to merge this tile into the given tile and return a bool indicating if this was successful.

    @params t The NumberTile to merge into.
    @returns mergeSuccessful Value indicating whether the merge was a success and the tile can be deleted, with a failure indicating that this tile should instead be places next to t.
*/
bool NumberTile::canMergeWithTile(NumberTile* t)
{
    // Get Value
    return t->getValue() == value;
}

/**
    Textual representation of tile.

    @param none
    @return Textual representation of tile
*/
string NumberTile::to_string()
{
    // Return textual representation
    return type + "(" + std::to_string(x) + "," + std::to_string(y) + "): " + std::to_string(value);
}

/**
    Gets the Tile icons textual representation.

    @param none
    @return String denoting the Tile type.
*/
string NumberTile::getConsoleIcon()
{
    // Return textual representation
    return " #" + std::to_string(value) + "#";
}
