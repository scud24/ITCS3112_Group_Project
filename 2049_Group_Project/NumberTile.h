/**
    ITSC 3112-001 Group Project
    NumberTile.h
    Purpose: Holds prototype declarations for NumberTile.cpp

    @author Nathan Holzworth, Abhinav Kasu, Johathan Walters
    @version 1.0 11/27/18
*/

#ifndef NUMBERTILE_H_INCLUDED
#define NUMBERTILE_H_INCLUDED

using namespace std;

class NumberTile
{
// Declare fields
protected:
int value;
int x;
int y;
string type;

public:
    /**
        Constructor: Create empty tile.

    */
    NumberTile();


    /**
        Constructor: Creates number tile based on a value.
        
        @param xpos X coordinate on grid.
        @param ypos Y coordinate on grid.
        @ param tileValue Value of the tile

    */
    NumberTile(int xpos, int ypos, int tileValue);

    /**
        Sets the value of Tile.
        
        @param newValue Value to be assigned.

    */
    void setValue(int newValue);

    /**
        Gets the value of Tile.
        
        @param none 
        @return Value of the Tile
    */
    int getValue();

    /**
        Set X coordinate of tile.
        
        @param newX Value of coordinate. 
    */
    void setX(int newX);

    /**
        Get X coordinate of tile.
        
        @return x coordinate value. 
    */
    int getX();

    /**
        Set Y coordinate of tile.
        
        @param newY Value of coordinate. 
    */
    void setY(int newY);

    /**
        Get Y coordinate of tile.
        
        @return y coordinate value. 
    */
    int getY();

    /**
        Set Tile Type.
        
        @param newType The Tile type. 
    */
    void setTileType(string newType);

    /**
        Get Tile Type.
        
        @return The Tile type. 
    */
    string getTileType();

   /**
        Determine if tile can move horizontally. 
        
        @return Decide if move is possible.
    */
    virtual bool canMoveHorizontal() const = 0;
 /**
        Determine if tile can move vertically. 
        
        @return Decide if move is possible
    */
    virtual bool canMoveVertical() const = 0;

    /**
        Attempts to merge this tile into the given tile and return a bool indicating if this was successful.

        @params t The NumberTile to merge into.
        @returns mergeSuccessful Value indicating whether the merge was a success and the tile can be deleted, with a failure indicating that this tile should instead be places next to t.
    */
    bool canMergeWithTile(NumberTile* t);


    /**
        Gets the combined new Tile type Vertical or Horizontal.

        @param none
        @return String denoting the Tile type.
    */
    virtual string getCombinedTileType(NumberTile* t) const = 0;

    /**
        Textual representation of tile.
        
        @param none
        @return Textual representation of tile
    */
    string to_string();

    /**
        Gets the Tile icons textual representation.

        @param none
        @return String denoting the Tile type.
    */
    string getConsoleIcon();
};

#endif // NUMBERTILE_H_INCLUDED


