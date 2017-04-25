#ifndef BOARD_H
#define BOARD_H
#include "Node.h"
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Board {

public:

	Board();
	Board(map<int, Node> board, int lastPosP1, int lastPosP2);
	void displayBoard();
	void setBoard(int location, int player);	//set status of board
	int getBoard(int position);		//returns 0,1,2 (0 means empty, 1 means player 1, 2 means player 2)
	bool adjacentPositions(int token, int position);	//returns true if adjacent position
	int evaluateBoard(int Player, int phase);		//returns a score, used by alpha beta
	vector<Board> generateBoard(int Player, int phase);	//generates a board for alphabeta
	int getPosLastPlaced(int player);
	void setPositionLastPlaced(int position, int player);
	int tokenRemove;    //used we would know if token is going to be removed for mill

private:

	int positionLastPlacedP1; //used to find token that was last placed, used for evaluation function
	int positionLastPlacedP2;
	map <int, Node> gamePositions;
};

#endif
