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

    TileGrid* tg = new TileGrid(3, 3);

    FreeMoveTile* fmt1 = new FreeMoveTile(0,0,4);
    FreeMoveTile* fmt2 = new FreeMoveTile(2,4,2);
    HorizontalMoveTile* hmt1 = new HorizontalMoveTile(4,1,8);
    HorizontalMoveTile* hmt2 = new HorizontalMoveTile(2,1,4);
    VerticalMoveTile* vmt1 = new VerticalMoveTile(3,3,16);
    VerticalMoveTile* vmt2 = new VerticalMoveTile(0,4,64);

    tg->addTile(fmt1);
    tg->addTile(fmt2);
    tg->addTile(hmt1);
    tg->addTile(hmt2);
    tg->addTile(vmt1);
    tg->addTile(vmt2);

    tg->drawGrid();


    tg->clearTiles();

    tg->drawGrid();

    return 0;
}
