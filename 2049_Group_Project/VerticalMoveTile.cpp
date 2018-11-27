/**
    ITSC 3112-001 Group Project
    VerticalMoveTile.cpp
    Purpose:

    @author Nathan Holxworth
    @version 1.0 11/27/18
*/

#include <iostream>
#include <cstdlib>

#include "VerticalMoveTile.h"

using namespace std;


VerticalMoveTile::VerticalMoveTile(int x, int y, int value)
    :NumberTile(x, y, value)
{
    setTileType("VerticalMoveTile");
}

bool VerticalMoveTile::canMoveHorizontal() const
{

}


bool VerticalMoveTile::canMoveVertical() const
{

}


string VerticalMoveTile::getCombinedTileType(NumberTile* t) const
{

}
