#ifndef Player_Class
#define Player_Class

#include <iostream>
using namespace std;


#include "Board.h"

class Player{
    

    int playerSymbol;
    int PasserRow, PasserCol;
    int EaterRow, EaterCol;
    
    int pRow, pCol;
    int player;
    
    
    public:

    Board gameBoard;
    int done;
    int x1, y1 , x2, y2;
    
    
    

    Player();
    ~Player();
    
    bool isValidMove(int, int);

    bool isValidSize(int, int);
    
    
    bool getPasserMove();
    bool getEaterMove();
    


    void play();
    void addMove(int&, int&, int&, int&);
    int searchFirstRow();
    int gameStatus(int, int);
    
    //testing gameboard full from task 1
    int boardFull();
};

Player::Player(){

}

Player::~Player(){
    
}

bool Player::getPasserMove(){
        
    // if (MaxNumberMoves)
	// 	return false;

	do {
        cout << "Player P enter move:";
		cin >> pRow >> pCol;
		cout << endl;
	} while (!isValidMove( pRow-1, pCol-1));
        x1 = pRow -1;
        y1 = pCol -1;
        return true;
        return x1,y1;

        

	return true;
    } 

bool Player::getEaterMove(){
    
	do {
        cout << "Player E enter move:";
		cin >> pRow >> pCol;
		cout << endl;
	} while (!isValidMove( pRow-1, pCol-1));
        x2 = pRow -1;
        y2 = pCol -1;
        return true;
        return x2,y2;

        

	return true;
    } 

void Player::addMove( int& x1, int& y1, int& x2, int& y2) {
        
        if ((x2 == x1) && (y2 == y1)){ // Eater eats the Passer
            gameBoard.grid[x2][y2] = -1;
        } else {
            gameBoard.grid[x1][y1] = 1;
            gameBoard.grid[x2][y2] = -1;
        }
        
}

bool Player::isValidMove(int r, int c) {


        if (gameBoard.grid[r][c] == 0 && (r < gameBoard.row && c < gameBoard.col) && (r >= 0  && c >= 0  )) //Less than row num or greater than 0 (row-row)
                {
                        return true;
                }
                else{
                    cout << "Invalid move try again:  \n";
                    return false;
                    
                }    
                        
        
                        
    }


void Player::play(){
        int playerP = 1;
        int playerE = -1;
	    int win = 0;
        gameBoard.displayBoard();

        // do while loop 

        do {
            getPasserMove();
            gameBoard.noOfMoves++;
            getEaterMove();
            gameBoard.noOfMoves++;
            addMove( x1, y1, x2, y2);
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

        // while (done == 0) {
        //     getPasserMove();
        //     gameBoard.noOfMoves++;
        //     getEaterMove();
        //     gameBoard.noOfMoves++;
        //     addMove( x1, y1, x2, y2);
        //     gameBoard.displayBoard();


            // done = gameBoard.gameStatus();
            //     if (done = -1){
            //         cout << "Eater wins!\n";
            //     }

        
		
        // }
}  
#endif