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
        Description

        @params
    */
    NumberTile();


    /**
        Description

        @params
    */
    NumberTile(int xpos, int ypos, int tileValue);

    /**
        Description

        @params
    */
    void setValue(int newValue);

    /**
        Description

        @params
    */
    int getValue();

    /**
        Description

        @params
    */
    void setX(int newX);

    /**
        Description

        @params
    */
    int getX();

    /**
        Description

        @params
    */
    void setY(int newY);

    /**
        Description

        @params
    */
    int getY();

    /**
        Description

        @params
    */
    void setTileType(string newType);

    /**
        Description

        @params
    */
    string getTileType();

    /**
        Description

        @params
    */
    virtual bool canMoveHorizontal() const = 0;

    /**
        Description

        @returns
    */
    virtual bool canMoveVertical() const = 0;

    /**
        Attempt to merge this tile into the given tile and return a bool indicating if this was successful

        @params t- The NumberTile to merge into
        @returns mergeSuccessful- value indicating whether the merge was a success and the tile can be deleted, with a failure indicating that this tile should instead be places next to t
    */
    bool canMergeWithTile(NumberTile* t);


    /**
        Description

        @params
    */
    virtual string getCombinedTileType(NumberTile* t) const = 0;


    /**
        Description

        @params
    */
    string to_string();

    /**
        Description

        @params
    */
    string getConsoleIcon();
};

#endif // NUMBERTILE_H_INCLUDED


