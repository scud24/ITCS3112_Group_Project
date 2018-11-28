/**
    ITSC 3112-001 Group Project
    FreeMoveTile.cpp
    Purpose:

    @author Nathan Holxworth
    @version 1.0 11/27/18
*/

#include <iostream>
#include <cstdlib>

#include "FreeMoveTile.h"

using namespace std;


FreeMoveTile::FreeMoveTile(int x, int y, int value)
    :NumberTile(x, y, value)
{
    setTileType("FreeMoveTile");
}


bool FreeMoveTile::canMoveHorizontal() const
{
    return true;
}


bool FreeMoveTile::canMoveVertical() const
{
    return true;
}

string FreeMoveTile::getCombinedTileType(NumberTile* t) const
{
    return "FreeMoveTile";
}

string FreeMoveTile::getConsoleIcon()
{
    return "[" + std::to_string(value) + "]";
}
