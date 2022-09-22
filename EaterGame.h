#ifndef Eater_Game
#define Eater_Game

#include "IntroMenu.h"
#include "Board.h"
#include "Player.h"
#include "RandomPlayer.h"
#include "StraightlinePlayer.h"


#include <iostream>
using namespace std;

//This is the main sorting file that will send the code to whichever file it needs
class EaterGame {
    private:
        // Board gameBoard;
    public:
    IntroMenu introMenu;
    int startGame();
};


int EaterGame::startGame(){
    introMenu.enterGameMode();
    int answer;
    cin >> answer;

    if (answer == 1){ // Player VS Player
        
        Player pvp;
        pvp.play();
        

    } 
    
    else if (answer == 2){ // Human Vs Random Player
        
        RandomPlayer randomPlayer;
        randomPlayer.randomPlay();

    } else if (answer == 3){ // straight line VS random
        
        StraightlinePlayer playerS;
        playerS.StraightVsRandom();

    } else if (answer == 4){ // SmarterAI Vs random player
        cout << "This game mode is still in development. Please choose another mode. :)\n\n";
        EaterGame::startGame();
        
    } else if (answer == 5){ // MonteCarlo vs human
        cout << "This game mode is still in development. Please choose another mode. :)\n\n";
        EaterGame::startGame();
    };
}
#endif