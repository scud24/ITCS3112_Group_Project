/**
    ITSC 3112-001 Group Project
    TileGrid.cpp
    Purpose: Create Grid for the Game.
    Add and delete tiles on the grid.
    Alter the tiles, get their location, change type and combine them to create 
    new tiles on the grid.

    @author Nathan Holzworth, Abhinav Kasu, Johathan Walters
    @version 1.0 11/27/18
*/

#include <iostream>
#include <cstdlib>


using namespace std;

// Include required header files
#include "TileGrid.h"

/**
    Constructor: Creates grid based on the dimensions.

    @param w Width of the grid.
    @param h Height of the grid.
*/
TileGrid::TileGrid(int w, int h)
    :width(w), height(h)
{
    // Create
    tg = new NumberTile*[width*height];
}

/**
    Prints a symbolic representation of the game board to the console.
        
    @param none
*/
void TileGrid::drawGrid()
{
    // Formatting
    cout<< endl;
    
    // Loop through the grid
    for(int y = 0; y < height; y++)
    {
        string gridline = "";
        for(int x = 0; x < width; x++)
        {
           // Get location
           NumberTile* currentTile = getTileAtLocation(x,y);
           // Check Tile
           if(currentTile!=nullptr)
           {
               // Create Tile icon
                gridline+= " " + currentTile->getConsoleIcon();
           }
           else
           {
               // Create Grid
                gridline+= " |  |";
           }
        }
        // Print
        cout << gridline << endl;
    }
}

/**
    Lists all active tiles in the console
    
    @param none
*/
void TileGrid::listActiveTiles()
{
    // Print dimensions of grid
    cout<< endl << "Dimensions: " << width << ", " << height <<  endl;
    
    // Loop through Tiles
    for(int i = 0; i < activeTiles; i++)
    {
        // Print Tiles
        cout << tg[i]->to_string() << endl;
    }
}

/**
    Clears the grid's list of current tile
    
    @param none
*/
void TileGrid::clearTiles()
{
    // Set Value
    activeTiles = 0;
}

/**
    Adds Tile to the grid.

    @param t The new tile to be added
*/
void TileGrid::addTile(NumberTile* t)
{
    // Add Tile
    tg[activeTiles] = t;
    activeTiles++;
}

/**
    Moves Tile horizontally.

    @param dir The distance to move the Tile.
*/
void TileGrid::moveTilesHorzontal(int dir)
{

    // Track Tile movement
    bool* tileMoved = new bool[activeTiles];

    // Move Right
    if(dir == 1)
    {
        // Information
    cout << "Shifting tiles right" << endl;
        // Loop through grid
        for(int x = width-2; x >= 0; x--)
        {
            for(int i = 0; i < activeTiles; i++)
            {
                // Check Values
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
                                //Display Tile movement and remove old data
                                cout << i<< " Tile val: " << tg[i]->getValue() << " at (" << tg[i]->getX() << ", " << tg[i]->getY() << ") merged to (" << tg[testIndex]->getX() << ", " << tg[testIndex]->getY() << ")" << endl;
                                    tg[testIndex] = combineTiles(tg[testIndex], tg[i]);
                                cout << i<< " Tile val: " << tg[i]->getValue() << " merged to (" << tg[testIndex]->getX() << ", " << tg[testIndex]->getY() << "), New val: " << tg[testIndex]->getValue() << endl;
                                    removeTileAtIndex(i);
                                cout << "Tile at index: " << i << " removed. Active tiles: " << activeTiles << endl;
                                moveFinished = true;
                            }
                            else
                            {
                                //Display Tile movement and remove old data
                                moveFinished = true;
                                cout << "Tile val: " << tg[i]->getValue() << " at (" << tg[i]->getX() << ", " << tg[i]->getY() << ")" <<
                                        " blocked by val: " << tg[testIndex]->getValue() << " at (" << tg[i]->getX() << ", " << tg[i]->getY() << ")" << endl;
                            }
                        }
                        else
                        {
                            //Display Tile movement and remove old data
                            tg[i]->setX(tg[i]->getX()+dir);
                            cout << "Tile val: " << tg[i]->getValue() << " moved to (" << tg[i]->getX() << ", " << tg[i]->getY() << ")" << endl;
                        }
                    }
                }
            }
        }
    }
    //Move Left
    else
    {
     // Information
    cout << "Shifting tiles left" << endl;
        // Loop through grid
        for(int x = 1; x < width; x++)
        {
            for(int i = 0; i < activeTiles; i++)
            {
                // Check Values
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
                                //Display Tile movement and remove old data
                                cout << i<< " Tile val: " << tg[i]->getValue() << " at (" << tg[i]->getX() << ", " << tg[i]->getY() << ") merged to (" << tg[testIndex]->getX() << ", " << tg[testIndex]->getY() << ")" << endl;
                                    tg[testIndex] = combineTiles(tg[testIndex], tg[i]);
                                cout << i<< " Tile val: " << tg[i]->getValue() << " merged to (" << tg[testIndex]->getX() << ", " << tg[testIndex]->getY() << "), New val: " << tg[testIndex]->getValue() << endl;
                                    removeTileAtIndex(i);
                                cout << "Tile at index: " << i << " removed. Active tiles: " << activeTiles << endl;
                                moveFinished = true;
                            }
                            else
                            {
                                //Display Tile movement and remove old data
                                moveFinished = true;
                                cout << "Tile val: " << tg[i]->getValue() << " at (" << tg[i]->getX() << ", " << tg[i]->getY() << ")" <<
                                        " blocked by val: " << tg[testIndex]->getValue() << " at (" << tg[i]->getX() << ", " << tg[i]->getY() << ")" << endl;
                            }
                        }
                        else
                        {
                            //Display Tile movement and remove old data
                            tg[i]->setX(tg[i]->getX()+dir);
                            cout << "Tile val: " << tg[i]->getValue() << " moved to (" << tg[i]->getX() << ", " << tg[i]->getY() << ")" << endl;
                        }
                    }
                }
            }
        }
    }



}

/**
    Moves Tile Vertically.

    @param dir The distance to move the Tile.
*/
void TileGrid::moveTilesVertical(int dir)
{
    // Track Tile movement
    bool* tileMoved = new bool[activeTiles];

    //Move Down
    if(dir == 1)
    {
        //Information
    cout << "Shifting tiles down" << endl;
    
        // Loop through grid
        for(int y = height-2; y >= 0; y--)
        {
            for(int i = 0; i < activeTiles; i++)
            {
                // Check values
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
                                //Display Tile movement and remove old data
                                cout << i<< " Tile val: " << tg[i]->getValue() << " at (" << tg[i]->getX() << ", " << tg[i]->getY() << ") merged to (" << tg[testIndex]->getX() << ", " << tg[testIndex]->getY() << ")" << endl;
                                    tg[testIndex] = combineTiles(tg[testIndex], tg[i]);
                                cout << i<< " Tile val: " << tg[i]->getValue() << " merged to (" << tg[testIndex]->getX() << ", " << tg[testIndex]->getY() << "), New val: " << tg[testIndex]->getValue() << endl;
                                    removeTileAtIndex(i);
                                cout << "Tile at index: " << i << " removed. Active tiles: " << activeTiles << endl;
                                moveFinished = true;
                            }
                            else
                            {
                                //Display Tile movement and remove old data
                                moveFinished = true;
                                cout << "Tile val: " << tg[i]->getValue() << " at (" << tg[i]->getX() << ", " << tg[i]->getY() << ")" <<
                                        " blocked by val: " << tg[testIndex]->getValue() << " at (" << tg[i]->getX() << ", " << tg[i]->getY() << ")" << endl;
                            }
                        }
                        else
                        {
                            //Display Tile movement and remove old data
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
        // Information
    cout << "Shifting tiles up" << endl;
        // Loop through grid
        for(int y = 0; y < height; y++)
        {
            for(int i = 0; i < activeTiles; i++)
            {
                // Check values
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
                                //Display Tile movement and remove old data
                                cout << i<< " Tile val: " << tg[i]->getValue() << " at (" << tg[i]->getX() << ", " << tg[i]->getY() << ") merged to (" << tg[testIndex]->getX() << ", " << tg[testIndex]->getY() << ")" << endl;
                                    tg[testIndex] = combineTiles(tg[testIndex], tg[i]);
                                cout << i<< " Tile val: " << tg[i]->getValue() << " merged to (" << tg[testIndex]->getX() << ", " << tg[testIndex]->getY() << "), New val: " << tg[testIndex]->getValue() << endl;
                                    removeTileAtIndex(i);
                                cout << "Tile at index: " << i << " removed. Active tiles: " << activeTiles << endl;
                                moveFinished = true;
                            }
                            else
                            {
                                //Display Tile movement and remove old data
                                moveFinished = true;
                                cout << i<< " Tile val: " << tg[i]->getValue() << " at (" << tg[i]->getX() << ", " << tg[i]->getY() << ")" <<
                                            " blocked by val: " << tg[testIndex]->getValue() << " at (" << tg[i]->getX() << ", " << tg[i]->getY() << ")" << endl;
                            }
                        }
                        else
                        {
                            //Display Tile movement and remove old data
                            tg[i]->setY(tg[i]->getY()+dir);
                            cout << i<< " Tile val: " << tg[i]->getValue() << " moved to (" << tg[i]->getX() << ", " << tg[i]->getY() << ")" << endl;
                        }
                    }
                }
            }
        }
    }
}

/**
    Gets the total number of active tiles on console.

    @param none
    @return The total number of Tiles.
*/
int TileGrid::getNumActiveTiles()
{
    return activeTiles;
}

/**
    Gets Tile in grid.

    @param x The coordinate.
    @param y The coordinate.
    @return The requested Tile.
*/
NumberTile* TileGrid::getTileAtLocation(int x, int y)
{
    // Loop 
    for(int i = 0; i < activeTiles; i++)
    {
        // Check location
        if(x==tg[i]->getX() && y==tg[i]->getY()){
            return tg[i];
        }
    }
    return nullptr;
}

/**
    Gets Tile's index in grid.

    @param x The coordinate.
    @param y The coordinate.
    @return The requested Tile index.
*/
int TileGrid::getTileIndexByLocation(int x, int y)
{
    // Loop
    for(int i = 0; i < activeTiles; i++)
    {
        // Check location
        if(x==tg[i]->getX() && y==tg[i]->getY()){
            return i;
        }
    }
    return -1;
}

/**
    Combines Tiles together.

    @param a First tile.
    @param b Second tile.
*/
NumberTile* TileGrid::combineTiles(NumberTile* a, NumberTile* b)
{
    // Information
    cout << "Combining Tiles A- val: " << a->getValue() << " from (" << a->getX() << ", " << a->getY() << ") and B- val: " << b->getValue() << " from (" << b->getX() << ", " << b->getY()
    << ") at pos (" << a->getX() << ", " << a->getY() << ")" << endl;
    // New Tile
    NumberTile* outTile;
    string newType = a->getCombinedTileType(b);
    int newVal = a->getValue()+b->getValue();

    // Decide based on Tile type
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

/**
    Removes tile from grid

    @param index The tile's index on grid
*/
void TileGrid::removeTileAtIndex(int index)
{
    for(int i = index; i < activeTiles-1; i++)
    {
        tg[i] = tg[i+1];
    }
    activeTiles--;
}
