/**
    ITSC 3112-001 Group Project
    NumberTile.cpp
    Purpose:

    @author Nathan Holxworth
    @version 1.0 11/27/18
*/

#include <iostream>
#include <cstdlib>

#include "NumberTile.h"

using namespace std;

NumberTile::NumberTile()
    :value(0), x(-1), y(-1)
{
    setTileType("Empty");
}

NumberTile::NumberTile(int xpos, int ypos, int tileValue)
    :value(tileValue), x(xpos), y(ypos)
{
    setTileType("NumberTile");
}


void NumberTile::setValue(int newValue)
{
    value = newValue;
}


int NumberTile::getValue()
{
    return value;
}


void NumberTile::setX(int newX)
{
 x = newX;
}


int NumberTile::getX()
{
    return x;
}


void NumberTile::setY(int newY)
{
    y = newY;
}


int NumberTile::getY()
{
    return y;
}

void NumberTile::setTileType(string newType)
{
    type = newType;
}

string NumberTile::getTileType()
{
    return type;
}

bool NumberTile::canMergeWithTile(NumberTile* t)
{
    return t->getValue() == value;
}

string NumberTile::to_string()
{
    return type + "(" + std::to_string(x) + "," + std::to_string(y) + "): " + std::to_string(value);
}
