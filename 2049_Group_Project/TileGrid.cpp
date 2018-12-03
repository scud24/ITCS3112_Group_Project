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
#include <Fl/Fl_JPEG_Image.H>

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

    gridImage = new Fl_PNG_Image("grid320.png");
    verticalTileImage = new Fl_PNG_Image("vertical.png");
    horizontalTileImage = new Fl_PNG_Image("horizontal.png");
    freemoveTileImage = new Fl_PNG_Image("freemove.png");
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

void TileGrid::drawGUI()
{
    Fl_Window *window;
    Fl_Box *titleBox;
    Fl_Box *gridBox;

    window = new Fl_Window (600, 400);
    titleBox = new Fl_Box (50, 50, 300, 300, "2049");
    titleBox->box (FL_UP_BOX);
    titleBox->align(FL_ALIGN_TOP);
    titleBox->labelsize (36);
    titleBox->labelfont (FL_BOLD+FL_ITALIC);
    titleBox->labeltype (FL_SHADOW_LABEL);

    gridBox = new Fl_Box (50, 50, gridImage->w(), gridImage->h(), "");
    gridBox->image(gridImage);


    /*Fl_Box *vt = new Fl_Box (50, 45, verticalTileImage->w(), verticalTileImage->h(), "2");
    vt->image(verticalTileImage);
    vt->align(FL_ALIGN_IMAGE_BACKDROP);


    Fl_Box *ht = new Fl_Box (114, 45, horizontalTileImage->w(), horizontalTileImage->h(), "4");
    ht->image(horizontalTileImage);
    ht->align(FL_ALIGN_IMAGE_BACKDROP);

    Fl_Box *fmt = new Fl_Box (178, 45, freemoveTileImage->w(), freemoveTileImage->h(), "8");
    fmt->image(freemoveTileImage);
    fmt->align(FL_ALIGN_IMAGE_BACKDROP);
*/
    Fl_Box **drawTiles = new Fl_Box*[width*height];


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
                string testString = std::to_string(currentTile->getValue()).c_str();
                drawTiles[y*width+x] = new Fl_Box (64*x+50, 64*y+45, freemoveTileImage->w(), freemoveTileImage->h(), "8");
                drawTiles[y*width+x]->copy_label(testString.c_str());
                cout<< std::to_string(currentTile->getValue()).c_str()<<endl;
                drawTiles[y*width+x]->align(FL_ALIGN_IMAGE_BACKDROP);

                if(currentTile->getTileType() == "VerticalMoveTile")
                {
                    drawTiles[y*width+x]->image(verticalTileImage);
                }
                else if(currentTile->getTileType() == "HorizontalMoveTile")
                {
                    drawTiles[y*width+x]->image(horizontalTileImage);
                }
                else
                {
                    drawTiles[y*width+x]->image(freemoveTileImage);
                }
            }
            else
            {

            }
        }
    }

    window->end ();
    window->show ();

    Fl::run();
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
                    if(!tg[i]->canMoveHorizontal()) moveFinished = true;
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
                    if(!tg[i]->canMoveHorizontal()) moveFinished = true;
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
                    if(!tg[i]->canMoveVertical()) moveFinished = true;
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
                    if(!tg[i]->canMoveVertical()) moveFinished = true;
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
        if(x==tg[i]->getX() && y==tg[i]->getY())
        {
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
        if(x==tg[i]->getX() && y==tg[i]->getY())
        {
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
