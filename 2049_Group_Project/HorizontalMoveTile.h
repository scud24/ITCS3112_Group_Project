
/**
    ITSC 3112-001 Group Project
    HorizontalMoveTile.h
    Purpose: Holds prototype declarations for HorizontalMoveTile.cpp

    @author Nathan Holxworth
    @version 1.0 11/27/18
*/

#ifndef HORIZONTALMOVETILE_H_INCLUDED
#define HORIZONTALMOVETILE_H_INCLUDED

using namespace std;

class HorizontalMoveTile
{
public:

    /**
        Description

        @params
    */
    HorizontalMoveTile(int x, int y, int value);

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

#endif // HORIZONTALMOVETILE_H_INCLUDED


