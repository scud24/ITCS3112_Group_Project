/**
    ITSC 3112-001 Group Project
    TileGrid.cpp
    Purpose:

    @author Nathan Holxworth
    @version 1.0 11/27/18
*/

#include <iostream>
#include <cstdlib>


using namespace std;

#include "TileGrid.h"

TileGrid::TileGrid(int w, int h)
    :width(w), height(h)
{
    tg = new NumberTile*[width*height];
}


void TileGrid::drawGrid()
{
    cout<< endl << "Dimensions: " << width << ", " << height <<  endl;
    for(int i = 0; i < activeTiles; i++)
    {
        cout << tg[i]->to_string() << endl;
    }
}


void TileGrid::clearTiles()
{
    activeTiles = 0;
}


void TileGrid::addTile(NumberTile* t)
{
    tg[activeTiles] = t;
    activeTiles++;
}


void TileGrid::moveTilesHorzontal(int dir)
{

}


void TileGrid::moveTilesVertical(int dir)
{

}

int TileGrid::getNumActiveTiles()
{
    return activeTiles;
}
