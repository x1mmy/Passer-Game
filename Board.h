#ifndef Board_file
#define Board_file


#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;



class Board {
private:

public:
    int row, col;
    int tempRow, tempCol;
    int noOfMoves;
    int gameWin = 0;

    bool LEFTbackTrace = false;
    bool RIGHTbackTrace = false;

    // int done;
    int x, y;
    int** grid; 

    Board();
    ~Board();
    void displayBoard();


    
    bool isValidSize(int, int);

    int gameStatus();

    int recursiveFunction(int& , int, int, bool&, bool&);


};

bool Board::isValidSize(int tempRow, int tempCol){
    if((tempRow >=3 && tempCol >=3)&&(tempRow <= 9 && tempCol <= 9 )){
        return true;
    }
    else{
        cout << "Invalid Size, Please input again:  \n";
        return false;
    }

}

void Board::displayBoard() {
	
    cout << " ";
    for (int i = 0; i < col; i++) {
		cout << "  " << i + 1 << " "; 
    }
    cout << endl;

    cout << "  ";
    for(int k = 0; k < col; k++){
        cout << "___|";
    }

    cout << endl;
	for (int i = 0; i < row; i++) {
		cout << i + 1 << "|";
		for (int j = 0; j < col; j++) {
			char playerSymbol = ' ';
			if (grid[i][j] == 1)
				playerSymbol = 'P';
			else if (grid[i][j] == -1)
				playerSymbol = 'E';
			cout << setw(3) << playerSymbol;
			if (j != col)
				cout << "|"; 
        }
        cout << endl;
        cout << "  ";
        // for(int k = 0; k < col; k++){
        //     cout << "___|";
        // }
        cout << endl;
    }
}

int Board::recursiveFunction(int& gameWin, int x, int y, bool& LEFTbackTrace, bool& RIGHTbackTrace){
    if(x == row -1){ // END OF THE BOARD INDICATING A WIN
        
        gameWin = 1;
        return gameWin;

    //DOWN FOR P
    } else if(grid[x + 1][y] == 1){     
        //cout << "There is " << i + 1 << " connections in path DOWN" << endl;
        LEFTbackTrace = false;
        RIGHTbackTrace = false;
        recursiveFunction(gameWin, x +1, y, LEFTbackTrace, RIGHTbackTrace);
    } 

    //DOWN-RIGHT FOR P
    else if(grid[x + 1][y + 1] == 1 && y < col){
        //cout << "There is " << i + 1 << " connections in pathDOWNRIGHT" << endl;
        LEFTbackTrace = false;
        RIGHTbackTrace = false;
        recursiveFunction(gameWin, x + 1, y +1, LEFTbackTrace, RIGHTbackTrace);
    }
    
    //DOWN-LEFT
    else if(grid[x + 1][y - 1] == 1 && x >= 0){
        //cout << "There is " << i + 1 << " connections in path DOWNLEFT" << endl;
        LEFTbackTrace = false;
        RIGHTbackTrace = false;
        recursiveFunction(gameWin, x + 1, y -1, LEFTbackTrace, RIGHTbackTrace);
    }

    //LEFT
    else if(grid[x][y - 1] == 1 && y >= 0){
        
        if(!LEFTbackTrace){
            RIGHTbackTrace = true;
            recursiveFunction(gameWin, x , y -1,LEFTbackTrace, RIGHTbackTrace) ;
        }
    }

     //RIGHT
    else if(grid[x][y + 1 ] == 1 && y < col){
        //cout << "There is " << j + 1 << " connections in path RIHT" << endl;
        if(!RIGHTbackTrace){
            LEFTbackTrace = true;
            recursiveFunction(gameWin, x, y +1,LEFTbackTrace, RIGHTbackTrace);
        }
        
    }

}


int Board::gameStatus(){
    

    // THIS IS PART OF THE WIN CHECK CODE - COME BACk TO THIS

    for ( int i = 0; i <= tempCol; i++){ // Finding the P in the first row 
        if (grid[0][i] == 1){
            recursiveFunction(gameWin, 0, i,LEFTbackTrace,RIGHTbackTrace);
        }
    }
    if (gameWin == 1){
        return 1;
    }

    if (noOfMoves >= tempRow * tempCol){
        // cout << "Eater wins!\n";
        return -1; // -1 is Eater
    } 

    return 0;


    

}



Board::Board(){ //Constructor 
    cout << "Enter the row and column dimensions of the array(between 3-9):\n";
    
    do {
        cin >> tempRow >> tempCol;
		cout << endl;
	} while (!isValidSize(tempRow, tempCol));
        row = tempRow;
        col = tempCol;

	grid = new int*[row];
    noOfMoves = 0;
	for (int i = 0; i < row; i++)
		grid[i] = new int[col];

}

Board::~Board()
{
    for (int i = 0; i < row; i++)
		delete[] grid[i];

	delete[] grid;
}



#endif