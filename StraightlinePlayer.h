#ifndef Striaghtline_Player
#define Straightline_Player

#include <iostream>
#include <iomanip>
using namespace std;

#include "RandomPlayer.h"
#include "Board.h"

//Straightline Player VS random Player
class StraightlinePlayer : public RandomPlayer{

    
    int rowTest =0;
    int colTest = 0;
public:
int straightRow, straightCol = 0;
int futureRow, futureCol;
Board board;
int getStraightMove(int, int);


void StraightVsRandom();
};

int StraightlinePlayer::getStraightMove(int straightRow, int straightCol){
    //First get the first cell which is 1, 1 and make sure its zero
    // Once this is placed then we head down the column 
    // If we are blocked we then head into the next column



        
        
        // - - - - -
        do {
            if (board.grid[straightRow][straightCol] = 0){ // First Cell
                straightRow = 0;
                straightCol = 0;
                // futureRow = straightRow;
                // futureCol = straightCol + 1;
            }

            
            
        } while (!isValidMove(straightRow , straightCol ));

        cout << "Straight line player entered: " << straightRow + 1 << " " << straightCol + 1 << endl;
}
    

    
    



void StraightlinePlayer::StraightVsRandom(){
    gameBoard.displayBoard();

        // do while loop 

        do {
            getStraightMove(0, 0);
            gameBoard.noOfMoves++;
            RandomPlayer::randomMove();
            gameBoard.noOfMoves++;
            addMove( straightRow, straightCol, randomX, randomY);

            straightRow + 1;
            
            gameBoard.displayBoard();
            gameBoard.gameStatus();
            
            Player::done = gameBoard.gameStatus();
                if (done == -1){
                    cout << "Eater Wins!\n";
                } else  if (done == 1){
                    cout << "Passer Wins!\n";
                }
                
                
        }
        while (gameBoard.gameWin == 0);

}


#endif