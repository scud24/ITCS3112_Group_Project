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

static void redrawWindow()
{
    Fl::redraw();

}

/**
 Handles input from the play button

 @param obj object callback originated from
 @param other target of callback event
 */
static void playButton_callback(Fl_Widget* obj, void* w)
{
    bool exitGame = false;
    while(!exitGame)
    {
        cout << "Attempt set tg" << endl;
        // Create Grid
        TileGrid* tg = new TileGrid(5, 5);

        for (int i = 0; i < 5; i++)
        {
            tg->spawnRandomTile();
        }

        cout << "Attempt run tg" << endl;
        exitGame = !tg->runGUI();
        cout << "gui returned to main- " << exitGame << endl;

        /*cout << "Game finished check" << endl;
        if(tg->checkForWinner())
        {
            exitGame =!fl_ask("You won!!! Play again?");
        }
        else
        {
            exitGame =!fl_ask("You lost! Play again?");
        }*/

    }

        cout << "Finished playing" <<endl;
        redrawWindow();

}
/**
Handles input from the exit button

@param obj object callback originated from
@param other target of callback event
*/
static void exitButton_callback(Fl_Widget* obj, void* w)
{

    cout << "Exit button- "  << endl;
    Fl_Window* window = (Fl_Window*) w;
    window->hide();
}

int main()
{
    bool runInGUIMode = true;

    cout << "Welcome to 4096 Game" << endl;



    // Store user input
    string playerInput;

    if(runInGUIMode)
    {
        cout << "Run GUI start" << endl;
        Fl_Window *replayWindow;
        Fl_Box *promptBox;

        Fl_Button *playButton;
        Fl_Button *exitButton;

        replayWindow = new Fl_Window (300, 200);
        //replayWindow->callback(( Fl_Callback* ) , replayWindow);
        promptBox = new Fl_Box (50, 50, 200, 100, "2049");
        promptBox->box (FL_UP_BOX);
        promptBox->align(FL_ALIGN_TOP);
        promptBox->labelsize (36);
        promptBox->labelfont (FL_BOLD+FL_ITALIC);
        promptBox->labeltype (FL_SHADOW_LABEL);

        playButton = new Fl_Button( 50, 55, 200, 40, "Play Game" );
        playButton->callback(( Fl_Callback* ) playButton_callback, replayWindow);
        exitButton = new Fl_Button( 50, 100, 200, 40, "Exit" );
        exitButton->callback(( Fl_Callback* ) exitButton_callback, replayWindow);
        //tg->drawGUI();



        replayWindow->end ();
        replayWindow->show ();
        cout << "Run GUI end" << endl;
        Fl::run();
        cout << "past fl run" << endl;
        Fl::wait();
    }
    else
    {


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
    }







    cout << endl << "Thanks for playing!" << endl;


}


