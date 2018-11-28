/**
    ITSC 3112-001 Group Project
    FreeMoveTile.h
    Purpose: Holds prototype declarations for FreeMoveTile.cpp

    @author Nathan Holzworth, Abhinav Kasu, Johathan Walters
    @version 1.0 11/27/18
*/
#include <iostream>


#include "NumberTile.h"
#include "TileGrid.h"
#include "FreeMoveTile.h"
#include "HorizontalMoveTile.h"
#include "VerticalMoveTile.h"

using namespace std;


int main()
{
    cout << "Hello world!" << endl;

    TileGrid* tg = new TileGrid(5, 5);

    FreeMoveTile* fmt1 = new FreeMoveTile(0,0,4);
    FreeMoveTile* fmt2 = new FreeMoveTile(2,4,2);
    HorizontalMoveTile* hmt1 = new HorizontalMoveTile(4,1,8);
    HorizontalMoveTile* hmt2 = new HorizontalMoveTile(2,1,4);
    VerticalMoveTile* vmt1 = new VerticalMoveTile(3,3,16);
    VerticalMoveTile* vmt2 = new VerticalMoveTile(0,4,4);

    tg->addTile(fmt1);
    tg->addTile(fmt2);
    tg->addTile(hmt1);
    tg->addTile(hmt2);
    tg->addTile(vmt1);
    tg->addTile(vmt2);


    tg->listActiveTiles();
    tg->drawGrid();

    string playerInput;

    while(playerInput!= "e")
    {
        cout << "Enter w, a, s, or d to move tiles up, left, down, or right, or Enter e to exit" << endl;
        cin>>playerInput;
        cout<< "Input was: " << playerInput << endl;
        if(playerInput == "w")
        {
            tg->moveTilesVertical(-1);
        }
        else if(playerInput == "a")
        {
            tg->moveTilesHorzontal(-1);
        }
        else if(playerInput == "s")
        {
            tg->moveTilesVertical(1);
        }
        else if(playerInput == "d")
        {
            tg->moveTilesHorzontal(1);
        }
        else if(playerInput != "e")
        {
            cout << "Invalid Input." << endl;
        }
        tg->drawGrid();
    }

    tg->clearTiles();

    tg->drawGrid();

    return 0;
}
