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
    cout<< endl;

    for(int y = 0; y < height; y++)
    {
        string gridline = "";
        for(int x = 0; x < width; x++)
        {
           NumberTile* currentTile = getTileAtLocation(x,y);
           if(currentTile!=nullptr)
           {
                gridline+= " " + currentTile->getConsoleIcon();
           }
           else
           {
                gridline+= " |  |";
           }
        }
        cout << gridline << endl;
    }
}

void TileGrid::listActiveTiles()
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

    bool* tileMoved = new bool[activeTiles];

    if(dir == 1)//Move Right
    {
    cout << "Shifting tiles right" << endl;
        for(int x = width-2; x >= 0; x--)
        {
            for(int i = 0; i < activeTiles; i++)
            {
                if(tg[i]->getX() == x && !tileMoved[i])
                {
                    bool moveFinished = false;
                    while(tg[i]->getX() < width-1 && !moveFinished)
                    {
                        int testIndex = getTileIndexByLocation((tg[i]->getX()+dir),(tg[i]->getY()));
                        if(testIndex!=-1)
                        {
                            if(tg[i]->canMergeWithTile(tg[testIndex]))
                            {
                                cout << i<< " Tile val: " << tg[i]->getValue() << " at (" << tg[i]->getX() << ", " << tg[i]->getY() << ") merged to (" << tg[testIndex]->getX() << ", " << tg[testIndex]->getY() << ")" << endl;
                                    tg[testIndex] = combineTiles(tg[testIndex], tg[i]);
                                cout << i<< " Tile val: " << tg[i]->getValue() << " merged to (" << tg[testIndex]->getX() << ", " << tg[testIndex]->getY() << "), New val: " << tg[testIndex]->getValue() << endl;
                                    removeTileAtIndex(i);
                                cout << "Tile at index: " << i << " removed. Active tiles: " << activeTiles << endl;
                                moveFinished = true;
                            }
                            else
                            {
                                moveFinished = true;
                                cout << "Tile val: " << tg[i]->getValue() << " at (" << tg[i]->getX() << ", " << tg[i]->getY() << ")" <<
                                        " blocked by val: " << tg[testIndex]->getValue() << " at (" << tg[i]->getX() << ", " << tg[i]->getY() << ")" << endl;
                            }
                        }
                        else
                        {
                            tg[i]->setX(tg[i]->getX()+dir);
                            cout << "Tile val: " << tg[i]->getValue() << " moved to (" << tg[i]->getX() << ", " << tg[i]->getY() << ")" << endl;
                        }
                    }
                }
            }
        }
    }
    else//Move Left
    {
    cout << "Shifting tiles left" << endl;
        for(int x = 1; x < width; x++)
        {
            for(int i = 0; i < activeTiles; i++)
            {
                if(tg[i]->getX() == x && !tileMoved[i])
                {
                    bool moveFinished = false;
                    while(tg[i]->getX() > 0 && !moveFinished)
                    {
                        int testIndex = getTileIndexByLocation((tg[i]->getX()+dir),(tg[i]->getY()));
                        if(testIndex!=-1)
                        {
                            if(tg[i]->canMergeWithTile(tg[testIndex]))
                            {
                                cout << i<< " Tile val: " << tg[i]->getValue() << " at (" << tg[i]->getX() << ", " << tg[i]->getY() << ") merged to (" << tg[testIndex]->getX() << ", " << tg[testIndex]->getY() << ")" << endl;
                                    tg[testIndex] = combineTiles(tg[testIndex], tg[i]);
                                cout << i<< " Tile val: " << tg[i]->getValue() << " merged to (" << tg[testIndex]->getX() << ", " << tg[testIndex]->getY() << "), New val: " << tg[testIndex]->getValue() << endl;
                                    removeTileAtIndex(i);
                                cout << "Tile at index: " << i << " removed. Active tiles: " << activeTiles << endl;
                                moveFinished = true;
                            }
                            else
                            {
                                moveFinished = true;
                                cout << "Tile val: " << tg[i]->getValue() << " at (" << tg[i]->getX() << ", " << tg[i]->getY() << ")" <<
                                        " blocked by val: " << tg[testIndex]->getValue() << " at (" << tg[i]->getX() << ", " << tg[i]->getY() << ")" << endl;
                            }
                        }
                        else
                        {
                            tg[i]->setX(tg[i]->getX()+dir);
                            cout << "Tile val: " << tg[i]->getValue() << " moved to (" << tg[i]->getX() << ", " << tg[i]->getY() << ")" << endl;
                        }
                    }
                }
            }
        }
    }



}


void TileGrid::moveTilesVertical(int dir)
{
    bool* tileMoved = new bool[activeTiles];

    if(dir == 1)//Move down
    {
    cout << "Shifting tiles down" << endl;
        for(int y = height-2; y >= 0; y--)
        {
            for(int i = 0; i < activeTiles; i++)
            {
                if(tg[i]->getY() == y && !tileMoved[i])
                {
                    bool moveFinished = false;
                    while(tg[i]->getY() < height-1 && !moveFinished)
                    {
                        int testIndex = getTileIndexByLocation((tg[i]->getX()),(tg[i]->getY()+dir));
                        if(testIndex!=-1)
                        {
                            if(tg[i]->canMergeWithTile(tg[testIndex]))
                            {
                                cout << i<< " Tile val: " << tg[i]->getValue() << " at (" << tg[i]->getX() << ", " << tg[i]->getY() << ") merged to (" << tg[testIndex]->getX() << ", " << tg[testIndex]->getY() << ")" << endl;
                                    tg[testIndex] = combineTiles(tg[testIndex], tg[i]);
                                cout << i<< " Tile val: " << tg[i]->getValue() << " merged to (" << tg[testIndex]->getX() << ", " << tg[testIndex]->getY() << "), New val: " << tg[testIndex]->getValue() << endl;
                                    removeTileAtIndex(i);
                                cout << "Tile at index: " << i << " removed. Active tiles: " << activeTiles << endl;
                                moveFinished = true;
                            }
                            else
                            {
                                moveFinished = true;
                                cout << "Tile val: " << tg[i]->getValue() << " at (" << tg[i]->getX() << ", " << tg[i]->getY() << ")" <<
                                        " blocked by val: " << tg[testIndex]->getValue() << " at (" << tg[i]->getX() << ", " << tg[i]->getY() << ")" << endl;
                            }
                        }
                        else
                        {
                            tg[i]->setY(tg[i]->getY()+dir);
                            cout << "Tile val: " << tg[i]->getValue() << " moved to (" << tg[i]->getX() << ", " << tg[i]->getY() << ")" << endl;
                        }
                    }
                }
            }
        }
    }
    else//Move up
    {
    cout << "Shifting tiles up" << endl;
        for(int y = 0; y < height; y++)
        {
            for(int i = 0; i < activeTiles; i++)
            {
                if(tg[i]->getY() == y && !tileMoved[i])
                {
                    bool moveFinished = false;
                    while(tg[i]->getY() > 0 && !moveFinished)
                    {
                        //NumberTile* testTile = getTileAtLocation((tg[i]->getX()),(tg[i]->getY()+dir));
                        int testIndex = getTileIndexByLocation((tg[i]->getX()),(tg[i]->getY()+dir));
                        if(testIndex!=-1)
                        {
                            if(tg[i]->canMergeWithTile(tg[testIndex]))
                            {
                                cout << i<< " Tile val: " << tg[i]->getValue() << " at (" << tg[i]->getX() << ", " << tg[i]->getY() << ") merged to (" << tg[testIndex]->getX() << ", " << tg[testIndex]->getY() << ")" << endl;
                                    tg[testIndex] = combineTiles(tg[testIndex], tg[i]);
                                cout << i<< " Tile val: " << tg[i]->getValue() << " merged to (" << tg[testIndex]->getX() << ", " << tg[testIndex]->getY() << "), New val: " << tg[testIndex]->getValue() << endl;
                                    removeTileAtIndex(i);
                                cout << "Tile at index: " << i << " removed. Active tiles: " << activeTiles << endl;
                                moveFinished = true;
                            }
                            else
                            {
                                moveFinished = true;
                                cout << i<< " Tile val: " << tg[i]->getValue() << " at (" << tg[i]->getX() << ", " << tg[i]->getY() << ")" <<
                                            " blocked by val: " << tg[testIndex]->getValue() << " at (" << tg[i]->getX() << ", " << tg[i]->getY() << ")" << endl;
                            }
                        }
                        else
                        {
                            tg[i]->setY(tg[i]->getY()+dir);
                            cout << i<< " Tile val: " << tg[i]->getValue() << " moved to (" << tg[i]->getX() << ", " << tg[i]->getY() << ")" << endl;
                        }
                    }
                }
            }
        }
    }
}

int TileGrid::getNumActiveTiles()
{
    return activeTiles;
}

NumberTile* TileGrid::getTileAtLocation(int x, int y)
{
    for(int i = 0; i < activeTiles; i++)
    {
        if(x==tg[i]->getX() && y==tg[i]->getY()){
            return tg[i];
        }
    }
    return nullptr;
}

int TileGrid::getTileIndexByLocation(int x, int y)
{
    for(int i = 0; i < activeTiles; i++)
    {
        if(x==tg[i]->getX() && y==tg[i]->getY()){
            return i;
        }
    }
    return -1;
}

NumberTile* TileGrid::combineTiles(NumberTile* a, NumberTile* b)
{
    cout << "Combining Tiles A- val: " << a->getValue() << " from (" << a->getX() << ", " << a->getY() << ") and B- val: " << b->getValue() << " from (" << b->getX() << ", " << b->getY()
    << ") at pos (" << a->getX() << ", " << a->getY() << ")" << endl;
    NumberTile* outTile;
    string newType = a->getCombinedTileType(b);
    int newVal = a->getValue()+b->getValue();

    if(newType == "FreeMoveTile")
    {
        outTile = new FreeMoveTile(a->getX(), a->getY(), newVal);
    }
    else if(newType == "HorizontalMoveTile")
    {
        outTile = new HorizontalMoveTile(a->getX(), a->getY(), newVal);
    }
    else if(newType == "VerticalMoveTile")
    {
        outTile = new VerticalMoveTile(a->getX(), a->getY(), newVal);
    }
    else
    {
        cout<< "Error combining tiles"<< endl;
    }
    return outTile;
}

void TileGrid::removeTileAtIndex(int index)
{
    for(int i = index; i < activeTiles-1; i++)
    {
        tg[i] = tg[i+1];
    }
    activeTiles--;
}
