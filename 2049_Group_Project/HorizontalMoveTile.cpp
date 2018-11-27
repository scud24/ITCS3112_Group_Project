
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

}


bool HorizontalMoveTile::canMoveVertical() const
{

}


string HorizontalMoveTile::getCombinedTileType(NumberTile* t) const
{

}
