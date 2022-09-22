#ifndef Random_Player
#define Random_Player

#include <iostream>
using namespace std;

// #include "Board.h"
#include "Player.h"


class RandomPlayer : public Player {

    
    public:
    int randomX, randomY;
    // Board gameBoard;
    bool randomMove();

    void randomPlay();
    int random();
};


bool RandomPlayer::randomMove(){
    
    do {
        randomX = rand() % gameBoard.row ; 
        randomY = rand() % gameBoard.col ; // Numb between 0 & row (0)
        cout << "Random Player entered move " << randomX + 1 << " " << randomY + 1 << endl;
        cout << endl;
    } while (!isValidMove(randomX , randomY ));

}

void RandomPlayer::randomPlay(){
        int playerP = 1;
        int playerE = -1;
	    int win = 0;
        gameBoard.displayBoard();

        do {
            getPasserMove();
            gameBoard.noOfMoves++;
            randomMove();
            gameBoard.noOfMoves++;
            addMove( x1, y1, randomX, randomY);
            gameBoard.displayBoard();
            gameBoard.gameStatus();

            done = gameBoard.gameStatus();
                if (done == -1){
                    cout << "Eater Wins!\n";
                } else  if (done == 1){
                    cout << "Passer Wins!\n";
                }
                
                
        }
        while (gameBoard.gameWin == 0);


}




#endif