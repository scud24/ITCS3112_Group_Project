/**
    ITSC 3112-001 Group Project
    NumberTile.h
    Purpose: Holds prototype declarations for NumberTile.cpp

    @author Nathan Holxworth
    @version 1.0 11/27/18
*/

#ifndef NUMBERTILE_H_INCLUDED
#define NUMBERTILE_H_INCLUDED

using namespace std;

class NumberTile
{
protected:
int value;
int x;
int y;
string type;

public:
    /**
        Create empty tile
        
        @params 
        
        @return 
    */
    NumberTile();


    /**
        Create number tile
        
        @params xpos, ypos, tileValue
        
        @return true
    */
    NumberTile(int xpos, int ypos, int tileValue);

    /**
        Determine if tile can move horizontally 
        
        @params 
        
        @return true
    */
    void setValue(int newValue);

    /**
        Determine if tile can move horizontally 
        
        @params 
        
        @return true
    */
    int getValue();

    /**
        Determine if tile can move horizontally 
        
        @params 
        
        @return true
    */
    void setX(int newX);

    /**
        Determine if tile can move horizontally 
        
        @params 
        
        @return true
    */
    int getX();

    /**
        Determine if tile can move horizontally 
        
        @params 
        
        @return true
    */
    void setY(int newY);

     /**
        Determine if tile can move horizontally 
        
        @params 
        
        @return true
    */
    int getY();

     /**
        Determine if tile can move horizontally 
        
        @params 
        
        @return true
    */
    void setTileType(string newType);

    /**
        Determine if tile can move horizontally 
        
        @params 
        
        @return true
    */
    string getTileType();

   /**
        Determine if tile can move horizontally 
        
        @params 
        
        @return true
    */
    virtual bool canMoveHorizontal() const = 0;
 /**
        Determine if tile can move horizontally 
        
        @params 
        
        @return true
    */
    virtual bool canMoveVertical() const = 0;

    /**
        Attempt to merge this tile into the given tile and return a bool indicating if this was successful

        @params t- The NumberTile to merge into
        @returns mergeSuccessful- value indicating whether the merge was a success and the tile can be deleted, with a failure indicating that this tile should instead be places next to t
    */
    bool canMergeWithTile(NumberTile* t);


     /**
        Determine if tile can move horizontally 
        
        @params 
        
        @return true
    */
    virtual string getCombinedTileType(NumberTile* t) const = 0;

     /**
        Determine if tile can move horizontally 
        
        @params 
        
        @return true
    */
    string to_string();

    /**
        Determine if tile can move horizontally 
        
        @params 
        
        @return true
    */
    string getConsoleIcon();
};

#endif // NUMBERTILE_H_INCLUDED


