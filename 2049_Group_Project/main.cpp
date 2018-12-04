/**
    ITSC 3112-001 Group Project
    main.cpp
    Purpose: The driver class for game.
    Sets up the game, calls functions and runs everything.

    @author Nathan Holzworth, Abhinav Kasu, Johathan Walters
    @version 1.0 11/27/18
*/
#include <iostream>

// Include required header files
#include "NumberTile.h"
#include "TileGrid.h"
#include "FreeMoveTile.h"
#include "HorizontalMoveTile.h"
#include "VerticalMoveTile.h"



using namespace std;


int main()
{
    bool runInGUIMode = true;

    cout << "Welcome to 4096 Game" << endl;



    // Store user input
    string playerInput;

    //Replay loop
    bool exitGame = false;
    while(!exitGame)
    {
        // Create Grid
        TileGrid* tg = new TileGrid(5, 5);

        for (int i = 0; i < 5; i++)
        {
            tg->spawnRandomTile();
        }

        cout << "List tiles start" << endl;
        // Set grid and display
        tg->listActiveTiles();
        tg->drawGrid();
        if(runInGUIMode)
        {
            tg->drawGUI();
        }
        else
        {
            // Loop for game
            bool gameOver = false;
            while(playerInput!= "e" && !gameOver)
            {
                // get use imput and display prompt
                cout << "Enter w, a, s, or d to move tiles up, left, down, or right, or Enter e to exit" << endl;
                cin>>playerInput;
                cout<< "Input was: " << playerInput << endl;

                // Evaluate user input and move tiles
                if(playerInput == "w"||playerInput == "W")
                {
                    tg->moveTilesVertical(-1);
                }
                else if(playerInput == "a"||playerInput == "A")
                {
                    tg->moveTilesHorizontal(-1);
                }
                else if(playerInput == "s"||playerInput == "S")
                {
                    tg->moveTilesVertical(1);
                }
                else if(playerInput == "d"||playerInput == "D")
                {
                    tg->moveTilesHorizontal(1);
                }
                else if(playerInput != "e"||playerInput == "E")
                {
                    cout << "Exitting Game.... GoodBye!" << endl;
                }
                tg->drawGrid();
                if(tg->checkForWinner())
                {
                    cout<<"You Win!!!" << endl;
                    gameOver=true;
                }
                else if(tg->checkIfGameOver())
                {
                    cout<<"All tiles filled. Game Over!" << endl;
                    gameOver=true;
                }
            }
        }


        cout<<"Play again? [y/n]" << endl;
        cin >> playerInput;
        if(playerInput == "y"||playerInput == "Y")
        {
            exitGame = false;
        }
        else
        {
            exitGame = true;
        }

    }

    cout << endl << "Thanks for playing!" << endl;


}

