/**
    ITSC 3112-001 Group Project
    FreeMoveTile.h
    Purpose: Holds prototype declarations for FreeMoveTile.cpp

    @author Nathan Holzworth, Abhinav Kasu, Johathan Walters
    @version 1.0 11/27/18
*/

#ifndef FREEMOVETILE_H_INCLUDED
#define FREEMOVETILE_H_INCLUDED

#include "NumberTile.h"

using namespace std;

class FreeMoveTile : public NumberTile
{
public:

    /**
    
    * Create a tile that can move freely
    *
    * @param x, y, value
    
    * @return none
    */
    FreeMoveTile(int x, int y, int value);

    /**
    
    * Determine if tile can move horizontally
    *
    * @param 
    
    * @return true
    */
    bool canMoveHorizontal() const;

    /**
    
    * Determine if tile can move vertically
    *
    * @param 
    
    * @return true
    */
    bool canMoveVertical() const;

     /**
    
    * Get tile type
    *
    * @param 
    
    * @return FreeMoveTile
    */
    string getCombinedTileType(NumberTile* t) const;

    /**
    
    * Get output icon
    *
    * @param 
    
    * @return value
    */
    string getConsoleIcon();
};

#endif // FREEMOVETILE_H_INCLUDED


