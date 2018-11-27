/**
    ITSC 3112-001 Group Project
    FreeMoveTile.h
    Purpose: Holds prototype declarations for FreeMoveTile.cpp

    @author Nathan Holxworth
    @version 1.0 11/27/18
*/

#ifndef FREEMOVETILE_H_INCLUDED
#define FREEMOVETILE_H_INCLUDED

using namespace std;

class FreeMoveTile
{
public:

    /**
        Description

        @params
    */
    FreeMoveTile(int x, int y, int value);

    /**
        Description

        @params
    */
    void setValue(int value);

    /**
        Description

        @params
    */
    int getValue();

    /**
        Description

        @params
    */
    void setX(int x);

    /**
        Description

        @params
    */
    int getX();

    /**
        Description

        @params
    */
    void setY(int y);

    /**
        Description

        @params
    */
    int getY();

    /**
        Description

        @params
    */
    string getTileType();

    /**
        Description

        @params
    */
    virtual bool canMoveHorizontal();

    /**
        Description

        @returns
    */
    virtual bool canMoveVertical();

    /**
        Attempt to merge this tile into the given tile and return a bool indicating if this was successful

        @params t- The NumberTile to merge into
        @returns mergeSuccessful- value indicating whether the merge was a success and the tile can be deleted, with a failure indicating that this tile should instead be places next to t
    */
    virtual bool mergeWithTile(NumberTile t);
};

#endif // FREEMOVETILE_H_INCLUDED


