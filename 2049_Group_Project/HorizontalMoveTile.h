
/**
    ITSC 3112-001 Group Project
    HorizontalMoveTile.h
    Purpose: Holds prototype declarations for HorizontalMoveTile.cpp

    @author Nathan Holxworth
    @version 1.0 11/27/18
*/

#ifndef HORIZONTALMOVETILE_H_INCLUDED
#define HORIZONTALMOVETILE_H_INCLUDED

#include "NumberTile.h"

using namespace std;

class HorizontalMoveTile : public NumberTile
{
public:

    /**
       Create tile that can only move horizontally

        @params x, y, value
        
        @return 
    */
    HorizontalMoveTile(int x, int y, int value);

    /**
        Determine if tile can move horizontally 
        
        @params 
        
        @return true
    */
    bool canMoveHorizontal() const;

    /**
        Determine if tile can move vertically

        @return true
    */
    bool canMoveVertical() const;

    /**
    
    * Get the tile type
    *
    * @param Numbertile
    
    * @return tile type
    * 
    * */
    
    string getCombinedTileType(NumberTile* t) const;

    /**
        Get output icon
        
        @params 
        
        @return value
    */
    string getConsoleIcon();
};

#endif // HORIZONTALMOVETILE_H_INCLUDED


