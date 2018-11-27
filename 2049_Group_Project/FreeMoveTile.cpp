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

}


bool FreeMoveTile::canMoveVertical() const
{

}

string FreeMoveTile::getCombinedTileType(NumberTile* t) const
{

}
