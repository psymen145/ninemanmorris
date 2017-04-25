#include "stdafx.h"
#include "nineman.h"
#include <iostream>

using namespace std;

NineManMorris::NineManMorris() :phase(1), numOfTokensInHandP1(9), numOfTokensInHandP2(9) {

}

void NineManMorris::display() {

	gameboard.displayBoard();

}

bool NineManMorris::isGameOver() {

	bool flag = false;	//check if player is trapped
	int currentplayer = 1;
	int opposingplayer = 2;

	//check if game is over by seeing if theres less than 3 pieces on the board
	//it also has to be in phase 3, or else this will read as game over in phase 1
	if (getTokensPlaced(1) < 3 && phase == 3) {
		return true;
	}
	else if (getTokensPlaced(2) < 3 && phase == 3) {
		return true;
	}

	//if a player gets trapped in phase 2 where a player slides pieces around
	if (phase == 2) {
		for (int j = 0; j < 2; j++) {	//we have to loop twice in order to check player 1 the 2
			for (int i = 0; i < 24; i++) {
				if (gameboard.getBoard(i) == currentplayer) {	//pulls in all of player 1's tokens
					if (i == 0) {
						if (gameboard.getBoard(1) == opposingplayer && gameboard.getBoard(9) == opposingplayer) {
							flag = true;
						}
						else {
							flag = false;
							break;
						}
					}
					else if (i == 1) {
						if (gameboard.getBoard(0) == opposingplayer && gameboard.getBoard(4) == opposingplayer && gameboard.getBoard(2) == opposingplayer) {
							flag = true;
						}
						else {
							flag = false;
							break;
						}
					}
					else if (i == 2) {
						if (gameboard.getBoard(1) == opposingplayer && gameboard.getBoard(4) == opposingplayer) {
							flag = true;
						}
						else {
							flag = false;
							break;
						}
					}
					else if (i == 3) {
						if (gameboard.getBoard(4) == opposingplayer && gameboard.getBoard(10) == opposingplayer) {
							flag = true;
						}
						else {
							flag = false;
							break;
						}
					}
					else if (i == 4) {
						if (gameboard.getBoard(1) == opposingplayer && gameboard.getBoard(3) == opposingplayer && gameboard.getBoard(5) == opposingplayer && gameboard.getBoard(7) == opposingplayer) {
							flag = true;
						}
						else {
							flag = false;
							break;
						}
					}
					else if (i == 5) {
						if (gameboard.getBoard(4) == opposingplayer && gameboard.getBoard(13) == opposingplayer) {
							flag = true;
						}
						else {
							flag = false;
							break;
						}
					}
					else if (i == 6) {
						if (gameboard.getBoard(7) == opposingplayer && gameboard.getBoard(11) == opposingplayer) {
							flag = true;
						}
						else {
							flag = false;
							break;
						}
					}
					else if (i == 7) {
						if (gameboard.getBoard(6) == opposingplayer && gameboard.getBoard(4) == opposingplayer && gameboard.getBoard(8) == opposingplayer) {
							flag = true;
						}
						else {
							flag = false;
							break;
						}
					}
					else if (i == 8) {
						if (gameboard.getBoard(7) == opposingplayer && gameboard.getBoard(12) == opposingplayer) {
							flag = true;
						}
						else {
							flag = false;
							break;
						}
					}
					else if (i == 9) {
						if (gameboard.getBoard(0) == opposingplayer && gameboard.getBoard(10) == opposingplayer && gameboard.getBoard(21) == opposingplayer) {
							flag = true;
						}
						else {
							flag = false;
							break;
						}
					}
					else if (i == 10) {
						if (gameboard.getBoard(3) == opposingplayer && gameboard.getBoard(9) == opposingplayer && gameboard.getBoard(11) == opposingplayer && gameboard.getBoard(18) == opposingplayer) {
							flag = true;
						}
						else {
							flag = false;
							break;
						}
					}
					else if (i == 11) {
						if (gameboard.getBoard(6) == opposingplayer && gameboard.getBoard(10) == opposingplayer && gameboard.getBoard(15) == opposingplayer) {
							flag = true;
						}
						else {
							flag = false;
							break;
						}
					}
					else if (i == 12) {
						if (gameboard.getBoard(8) == opposingplayer && gameboard.getBoard(13) == opposingplayer && gameboard.getBoard(17) == opposingplayer) {
							flag = true;
						}
						else {
							flag = false;
							break;
						}
					}
					else if (i == 13) {
						if (gameboard.getBoard(12) == opposingplayer && gameboard.getBoard(5) == opposingplayer && gameboard.getBoard(14) == opposingplayer && gameboard.getBoard(20) == opposingplayer) {
							flag = true;
						}
						else {
							flag = false;
							break;
						}
					}
					else if (i == 14) {
						if (gameboard.getBoard(2) == opposingplayer && gameboard.getBoard(13) == opposingplayer && gameboard.getBoard(23) == opposingplayer) {
							flag = true;
						}
						else {
							flag = false;
							break;
						}
					}
					else if (i == 15) {
						if (gameboard.getBoard(11) == opposingplayer && gameboard.getBoard(16) == opposingplayer) {
							flag = true;
						}
						else {
							flag = false;
							break;
						}
					}
					else if (i == 16) {
						if (gameboard.getBoard(15) == opposingplayer && gameboard.getBoard(17) == opposingplayer && gameboard.getBoard(19) == opposingplayer) {
							flag = true;
						}
						else {
							flag = false;
							break;
						}
					}
					else if (i == 17) {
						if (gameboard.getBoard(16) == opposingplayer && gameboard.getBoard(12) == opposingplayer) {
							flag = true;
						}
						else {
							flag = false;
							break;
						}
					}
					else if (i == 18) {
						if (gameboard.getBoard(10) == opposingplayer && gameboard.getBoard(19) == opposingplayer) {
							flag = true;
						}
						else {
							flag = false;
							break;
						}
					}
					else if (i == 19) {
						if (gameboard.getBoard(16) == opposingplayer && gameboard.getBoard(18) == opposingplayer && gameboard.getBoard(20) == opposingplayer && gameboard.getBoard(22) == opposingplayer) {
							flag = true;
						}
						else {
							flag = false;
							break;
						}
					}
					else if (i == 20) {
						if (gameboard.getBoard(19) == opposingplayer && gameboard.getBoard(13) == opposingplayer) {
							flag = true;
						}
						else {
							flag = false;
							break;
						}
					}
					else if (i == 21) {
						if (gameboard.getBoard(9) == opposingplayer && gameboard.getBoard(22) == opposingplayer) {
							flag = true;
						}
						else {
							flag = false;
							break;
						}
					}
					else if (i == 22) {
						if (gameboard.getBoard(19) == opposingplayer && gameboard.getBoard(21) == opposingplayer && gameboard.getBoard(23) == opposingplayer) {
							flag = true;
						}
						else {
							flag = false;
							break;
						}
					}
					else if (i == 23) {
						if (gameboard.getBoard(22) == opposingplayer && gameboard.getBoard(14) == opposingplayer) {
							flag = true;
						}
						else {
							flag = false;
							break;
						}
					}
				}
			}
			if (flag == true) {		//if we discover one player is already stuck we already know game is over
				return true;
			}
			else {
				currentplayer = 2;
				opposingplayer = 1;
			}
		}
	}

	return false;
}

//first checks if it is time to change phases
bool NineManMorris::play(int player, int token, int MoveTo, int playType) {

	//placing stage
	if (phase == 1 && playType == 0) {
		gameboard.setBoard(MoveTo, player);
		if (player == 1) {
			numOfTokensInHandP1--;
		}
		if (player == 2) {
			numOfTokensInHandP2--;
		}
		gameboard.setPositionLastPlaced(MoveTo, player);
	}
	//moving phase
	else if (phase == 2 && playType == 0) {
		//change the spot where the player wants to move to
		gameboard.setBoard(MoveTo, player);
		//remove the spot where the player's token originally was. This gives the image that the token is moving
		gameboard.setBoard(token, 0);
		gameboard.setPositionLastPlaced(MoveTo, player);
	}
	else if (phase == 3 && playType == 0) {
		//change the spot where the player wants to move to
		gameboard.setBoard(MoveTo, player);
		//remove the spot where the player's token originally was. This gives the image that the token is moving
		gameboard.setBoard(token, 0);
		gameboard.setPositionLastPlaced(MoveTo, player);
	}

	if (playType) {    //means we are removing a piece because a mill was formed
		if (gameboard.getBoard(token) == 0 || gameboard.getBoard(token) == player) {
			return false;
		}
		else {
			gameboard.tokenRemove = 0;  //used for AI to know that it is turn to remove a token or not
			gameboard.setBoard(token, 0);
			return true;
		}
	}

	return true;
}

//will check if move is valid first. If it is, then the board's function to actually complete the action is called
bool NineManMorris::isValid(int player, int token, int position) {

	//regardless of phase, the position that the token wants to go to has to be empty
	if (gameboard.getBoard(position) != 0) {
		return false;
	}
	//phase 1 set of rules:
	//1. player must still have token
	else if (phase == 1) {
		//determine which player we are getting info for
		if (player == 1) {
			if (getNumTokensP1() == 0) {
				return false;
			}
		}
		if (player == 2) {
			if (getNumTokensP2() == 0) {
				return false;
			}
		}
		return true;
	}

	//phase 2 set of rules:
	//1. their desired token to move must have their token
	//2. the spot they want to go to must be adjacent
	else if (phase == 2) {
		if (player == 1) {
			if (gameboard.getBoard(token) != 1) {
				return false;
			}
			else {
				//returns true or false
				return gameboard.adjacentPositions(token, position);
			}
		}
		else {		//player 2
			if (gameboard.getBoard(token) != 2) {
				return false;
			}
			else {
				return gameboard.adjacentPositions(token, position);
			}
		}
	}

	//phase 3 set of rules:
	//1. the spot they choose to get the token from has to be their token
	else if (phase == 3) {
		if (player == 1) {    //if player 1, we have to check the token they want to move is actually their token
			if (gameboard.getBoard(token) == 1) {
				return true;
			}
		}
		if (player == 2) {    //same as player 1
			if (gameboard.getBoard(token) == 2) {
				return true;
			}
		}
	}

	return false;
}

int NineManMorris::getPhase() {

	return phase;
}

void NineManMorris::setPhase(int p) {

	phase = p;
}

int NineManMorris::getNumTokensP1() {

	return numOfTokensInHandP1;
}

int NineManMorris::getNumTokensP2() {

	return numOfTokensInHandP2;
}

bool NineManMorris::checkTriple(int currentplayer, int spot) {
	//given a spot, see if the two possible lines (horizontal/vertical) have 3 in a row
	if (spot == 0) {

		if ((gameboard.getBoard(1) == currentplayer && gameboard.getBoard(2) == currentplayer) || (gameboard.getBoard(9) == currentplayer && gameboard.getBoard(21) == currentplayer)) {
			gameboard.tokenRemove = 1;
			return true;
		}
	}
	else if (spot == 1) {

		if ((gameboard.getBoard(0) == currentplayer && gameboard.getBoard(2) == currentplayer) || (gameboard.getBoard(4) == currentplayer && gameboard.getBoard(7) == currentplayer)) {
			gameboard.tokenRemove = 1;
			return true;
		}
	}
	else if (spot == 2) {

		if ((gameboard.getBoard(0) == currentplayer && gameboard.getBoard(1) == currentplayer) || (gameboard.getBoard(23) == currentplayer && gameboard.getBoard(14) == currentplayer)) {
			gameboard.tokenRemove = 1;
			return true;
		}
	}
	else if (spot == 3) {

		if ((gameboard.getBoard(4) == currentplayer && gameboard.getBoard(5) == currentplayer) || (gameboard.getBoard(10) == currentplayer && gameboard.getBoard(18) == currentplayer)) {
			gameboard.tokenRemove = 1;
			return true;
		}
	}
	else if (spot == 4) {

		if ((gameboard.getBoard(3) == currentplayer && gameboard.getBoard(5) == currentplayer) || (gameboard.getBoard(2) == currentplayer && gameboard.getBoard(7) == currentplayer)) {
			gameboard.tokenRemove = 1;
			return true;
		}
	}
	else if (spot == 5) {

		if ((gameboard.getBoard(3) == currentplayer && gameboard.getBoard(4) == currentplayer) || (gameboard.getBoard(13) == currentplayer && gameboard.getBoard(20) == currentplayer)) {
			gameboard.tokenRemove = 1;
			return true;
		}
	}
	else if (spot == 6) {

		if ((gameboard.getBoard(7) == currentplayer && gameboard.getBoard(8) == currentplayer) || (gameboard.getBoard(11) == currentplayer && gameboard.getBoard(15) == currentplayer)) {
			gameboard.tokenRemove = 1;
			return true;
		}
	}
	else if (spot == 7) {

		if ((gameboard.getBoard(6) == currentplayer && gameboard.getBoard(8) == currentplayer) || (gameboard.getBoard(1) == currentplayer && gameboard.getBoard(4) == currentplayer)) {
			gameboard.tokenRemove = 1;
			return true;
		}
	}
	else if (spot == 8) {

		if ((gameboard.getBoard(6) == currentplayer && gameboard.getBoard(7) == currentplayer) || (gameboard.getBoard(12) == currentplayer && gameboard.getBoard(16) == currentplayer)) {
			gameboard.tokenRemove = 1;
			return true;
		}
	}
	else if (spot == 9) {

		if ((gameboard.getBoard(10) == currentplayer && gameboard.getBoard(11) == currentplayer) || (gameboard.getBoard(0) == currentplayer && gameboard.getBoard(21) == currentplayer)) {
			gameboard.tokenRemove = 1;
			return true;
		}
	}
	else if (spot == 10) {

		if ((gameboard.getBoard(9) == currentplayer && gameboard.getBoard(11) == currentplayer) || (gameboard.getBoard(3) == currentplayer && gameboard.getBoard(18) == currentplayer)) {
			gameboard.tokenRemove = 1;
			return true;
		}
	}
	else if (spot == 11) {

		if ((gameboard.getBoard(15) == currentplayer && gameboard.getBoard(6) == currentplayer) || (gameboard.getBoard(9) == currentplayer && gameboard.getBoard(10) == currentplayer)) {
			gameboard.tokenRemove = 1;
			return true;
		}
	}
	else if (spot == 12) {

		if ((gameboard.getBoard(13) == currentplayer && gameboard.getBoard(14) == currentplayer) || (gameboard.getBoard(8) == currentplayer && gameboard.getBoard(17) == currentplayer)) {
			gameboard.tokenRemove = 1;
			return true;
		}
	}
	else if (spot == 13) {

		if ((gameboard.getBoard(12) == currentplayer && gameboard.getBoard(14) == currentplayer) || (gameboard.getBoard(20) == currentplayer && gameboard.getBoard(5) == currentplayer)) {
			gameboard.tokenRemove = 1;
			return true;
		}
	}
	else if (spot == 14) {

		if ((gameboard.getBoard(12) == currentplayer && gameboard.getBoard(13) == currentplayer) || (gameboard.getBoard(2) == currentplayer && gameboard.getBoard(23) == currentplayer)) {
			gameboard.tokenRemove = 1;
			return true;
		}
	}
	else if (spot == 15) {

		if ((gameboard.getBoard(6) == currentplayer && gameboard.getBoard(11) == currentplayer) || (gameboard.getBoard(16) == currentplayer && gameboard.getBoard(17) == currentplayer)) {
			gameboard.tokenRemove = 1;
			return true;
		}
	}
	else if (spot == 16) {

		if ((gameboard.getBoard(15) == currentplayer && gameboard.getBoard(17) == currentplayer) || (gameboard.getBoard(19) == currentplayer && gameboard.getBoard(22) == currentplayer)) {
			gameboard.tokenRemove = 1;
			return true;
		}
	}
	else if (spot == 17) {

		if ((gameboard.getBoard(15) == currentplayer && gameboard.getBoard(16) == currentplayer) || (gameboard.getBoard(8) == currentplayer && gameboard.getBoard(12) == currentplayer)) {
			gameboard.tokenRemove = 1;
			return true;
		}
	}
	else if (spot == 18) {

		if ((gameboard.getBoard(3) == currentplayer && gameboard.getBoard(10) == currentplayer) || (gameboard.getBoard(19) == currentplayer && gameboard.getBoard(20) == currentplayer)) {
			gameboard.tokenRemove = 1;
			return true;
		}
	}
	else if (spot == 19) {

		if ((gameboard.getBoard(18) == currentplayer && gameboard.getBoard(20) == currentplayer) || (gameboard.getBoard(22) == currentplayer && gameboard.getBoard(16) == currentplayer)) {
			gameboard.tokenRemove = 1;
			return true;
		}
	}
	else if (spot == 20) {

		if ((gameboard.getBoard(18) == currentplayer && gameboard.getBoard(19) == currentplayer) || (gameboard.getBoard(5) == currentplayer && gameboard.getBoard(13) == currentplayer)) {
			gameboard.tokenRemove = 1;
			return true;
		}
	}
	else if (spot == 21) {

		if ((gameboard.getBoard(0) == currentplayer && gameboard.getBoard(9) == currentplayer) || (gameboard.getBoard(22) == currentplayer && gameboard.getBoard(23) == currentplayer)) {
			gameboard.tokenRemove = 1;
			return true;
		}
	}
	else if (spot == 22) {

		if ((gameboard.getBoard(21) == currentplayer && gameboard.getBoard(23) == currentplayer) || (gameboard.getBoard(16) == currentplayer && gameboard.getBoard(19) == currentplayer)) {
			gameboard.tokenRemove = 1;
			return true;
		}
	}
	else if (spot == 23) {

		if ((gameboard.getBoard(2) == currentplayer && gameboard.getBoard(14) == currentplayer) || (gameboard.getBoard(22) == currentplayer && gameboard.getBoard(21) == currentplayer)) {
			gameboard.tokenRemove = 1;
			return true;
		}
	}

	return false;
}

int NineManMorris::getTokensPlaced(int player) {
	//counts how many tokens are placed on the board
	int counter = 0;

	for (int i = 0; i < 24; i++) {
		if (gameboard.getBoard(i) == player) {
			counter++;
		}
	}

	return counter;
}

int NineManMorris::playAI() {

	Board bestBoard;
	int position = -1;

	alphabeta(gameboard, 4, INT_MIN, INT_MAX, 2, position);

	cout << "This position: " << position << endl;
	gameboard.setBoard(position, 2);
	numOfTokensInHandP2 -= 1; //decrease num of tokens in AI hand (main needs to know this to switch phases)
	return position;
}

//maxPlayer = 2 means the AI, maxPlayer = 1 means the human
int NineManMorris::alphabeta(Board TreeNode, int depth, int alpha, int beta, int Player, int& position) {
	//v will be the value passed up the tree
	int v;

	//check if a player won in the given board node
	if (isGameOver()) {
		return TreeNode.evaluateBoard(Player, phase);
	}

	//check if last node in branch
	if (depth == 0) {
		//return the heuristic value of node, this will generate the v value for the bottom node
		return TreeNode.evaluateBoard(Player, phase);
	}

	if (Player == 2) {
		v = INT_MIN;

		//generate all children
		vector<Board> possibleBoards = TreeNode.generateBoard(Player, phase);

		for (int i = 0; i < possibleBoards.size(); i++) {
			//see which child is the best choice
			v = max(v, alphabeta(possibleBoards.at(i), depth - 1, alpha, beta, 1, position));
			//alpha = max(alpha, v);
			if (alpha < v) {
				alpha = v;
				position = possibleBoards.at(i).getPosLastPlaced(2);
			}
			if (beta <= alpha) {
				break;		//beta cut - off
			}
		}
		return v;	//goes back up to parent node
	}
	else {
		v = INT_MAX;

		//generate child nodes
		vector<Board> possibleBoards = TreeNode.generateBoard(Player, phase);

		for (int i = 0; i < possibleBoards.size(); i++) {
			v = min(v, alphabeta(possibleBoards.at(i), depth - 1, alpha, beta, 2, position));
			beta = min(beta, v);
			if (beta <= alpha) {
				break;		//alpha cut - off
			}
		}
		return v;
	}
}

void NineManMorris::playAIRemove() {
	for (int i = 0; i < 24; i++) {
		if (gameboard.getBoard(i) == 1) {
			//test, just remove first opponent token we see
			gameboard.setBoard(i, 0);
			break;
		}
	}
}
