#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <vector>

using namespace std;

class Board {
    
public:
    
    Board(int arr[] = NULL);
    void displayBoard();
    void setBoard(int location, int player);	//set status of board
    int getBoard(int position);		//returns 0,1,2 (0 means empty, 1 means player 1, 2 means player 2)
    bool adjacentPositions(int token, int position);	//returns true if adjacent position
    int evaluateBoard(int maximizingPlayer, int phase);		//returns a score, used by alpha beta
    vector<Board> generateBoard(bool maximizingPlayer, int phase);	//generates a board for alphabeta
    
private:
    
    int gameboard[24];
    
};

#endif
