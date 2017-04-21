#pragma once

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
	int evaluateBoard(bool maximizingPlayer, int phase);		//returns a score, used by alpha beta
	vector<Board> generateBoard(bool maximizingPlayer, int phase);	//generates a board for alphabeta
	int getPosLastPlaced(int player);
	void setPositionLastPlaced(int position, int player);

private:

	int positionLastPlacedP1; //used to find token that was last placed, used for evaluation function
	int positionLastPlacedP2;
	Node gamePositions[24];

};

#endif
