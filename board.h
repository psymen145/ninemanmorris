#ifndef BOARD_H
#define BOARD_H
#include "Node.h"
#include <iostream>
#include <vector>

using namespace std;

class Board {
    
public:
    
    Board(Node board[24] = NULL);
    void displayBoard();
    void setBoard(int location, int player);	//set status of board
    int getBoard(int position);		//returns 0,1,2 (0 means empty, 1 means player 1, 2 means player 2)
    bool adjacentPositions(int token, int position);	//returns true if adjacent position
    int evaluateBoard(bool maximizingPlayer, int phase, int move);		//returns a score, used by alpha beta
    vector<Board> generateBoard(bool maximizingPlayer, int phase);	//generates a board for alphabeta
    int getPosLastPlaced();
    void setPositionLastPlaced(int position);
    
private:
    
    int positionLastPlaced; //used to find token that was last placed, used for evaluation function
    Node gamePositions[24];
    
};

#endif
