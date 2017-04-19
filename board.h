#ifndef board_h
#define board_h
#include <iostream>
#include <vector>

using namespace std;

class board{
    
public:
    
    board();
    void displayBoard();
    
    //set status of board
    void setBoard(int location, int player);
    //gets 0,1,2 (0 means empty, 1 means player 1, 2 means player 2)
    int getBoard(int position);
    bool adjacentPositions(int token, int position);
    int getTokensPlacedP1();
    int getTokensPlacedP2();
    
private:
    
    int gameboard[24];
    
};

#endif
