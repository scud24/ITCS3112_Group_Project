
/**
    ITSC 3112-001 Group Project
    VerticalMoveTile.h
    Purpose: Holds prototype declarations for VerticalMoveTile.cpp

    @author Nathan Holzworth, Abhinav Kasu, Johathan Walters
    @version 1.0 11/27/18
*/

#ifndef VERTICALMOVETILE_H_INCLUDED
#define VERTICALMOVETILE_H_INCLUDED

// Include required header files
#include "NumberTile.h"

using namespace std;

class VerticalMoveTile : public NumberTile
{
public:

    /**
        Constructor: Gives Tile the coordinates on grid and value to hold.

        @param x cordinate value on grid.
        @param y cordinate value on grid.
        @param value the number Tile should hold.
    */
    VerticalMoveTile(int x, int y, int value);



    /**
        Decide wether Tile can be moved Horizontally.

        @param none
        @return True or False for the move.
    */
    bool canMoveHorizontal() const;

    /**
        Decide wether Tile can be moved Vertically.

        @param none
        @return True or False for the move.
    */
    bool canMoveVertical() const;

    /**
        Gets the Tile type Vertical or Horizontal.

        @param t The Tile
        @return String denoting the Tile type.
    */
    string getCombinedTileType(NumberTile* t) const;

    /**
        Gets the Tile icons textual representation.

        @param none
        @return String denoting the Tile type.
    */
    string getConsoleIcon();
};

#endif // VERTICALMOVETILE_H_INCLUDED


