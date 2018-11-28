
/**
    ITSC 3112-001 Group Project
    HorizontalMoveTile.cpp
    Purpose:

    @author Nathan Holxworth
    @version 1.0 11/27/18
*/

#include <iostream>
#include <cstdlib>

#include "HorizontalMoveTile.h"

using namespace std;

HorizontalMoveTile::HorizontalMoveTile(int x, int y, int value)
    :NumberTile(x, y, value)
{
    setTileType("HorizontalMoveTile");
}


bool HorizontalMoveTile::canMoveHorizontal() const
{
    return true;
}


bool HorizontalMoveTile::canMoveVertical() const
{
    return false;
}


string HorizontalMoveTile::getCombinedTileType(NumberTile* t) const
{
    if(t->getTileType() == "HorizontalMoveTile")
    {
        return "HorizontalMoveTile";
    }
    return "FreeMoveTile";
}

string HorizontalMoveTile::getConsoleIcon()
{
    return "<" + std::to_string(value) + ">";
}
