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
void NineManMorris::play(int player, int token, int MoveTo) {

	//placing stage
	if (phase == 1) {
		gameboard.setBoard(MoveTo, player);
		if (player == 1) {
			numOfTokensInHandP1--;
		}
		if (player == 2) {
			numOfTokensInHandP2--;
		}
	}
	//moving phase
	else if (phase == 2) {
		//change the spot where the player wants to move to
		gameboard.setBoard(MoveTo, player);
		//remove the spot where the player's token originally was. This gives the image that the token is moving
		gameboard.setBoard(token, 0);
	}
	else if (phase == 3) {
		//change the spot where the player wants to move to
		gameboard.setBoard(MoveTo, player);
		//remove the spot where the player's token originally was. This gives the image that the token is moving
		gameboard.setBoard(token, 0);
	}
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

void NineManMorris::checkTriple(int currentplayer, int spot) {
	//variable to hold user input about what token they want to remove
	int desiredRemove;
	int flag = 0;   //signals if there is a row, then we can prompt a token to be removed at the end of the function

					//given a spot, see if the two possible lines (horizontal/vertical) have 3 in a row
	if (spot == 0) {

		if ((gameboard.getBoard(1) == currentplayer && gameboard.getBoard(2) == currentplayer) || (gameboard.getBoard(9) == currentplayer && gameboard.getBoard(21) == currentplayer)) {
			flag = 1;
		}
	}
	else if (spot == 1) {

		if ((gameboard.getBoard(0) == currentplayer && gameboard.getBoard(2) == currentplayer) || (gameboard.getBoard(4) == currentplayer && gameboard.getBoard(7) == currentplayer)) {
			flag = 1;
		}
	}
	else if (spot == 2) {

		if ((gameboard.getBoard(0) == currentplayer && gameboard.getBoard(1) == currentplayer) || (gameboard.getBoard(23) == currentplayer && gameboard.getBoard(14) == currentplayer)) {
			flag = 1;
		}
	}
	else if (spot == 3) {

		if ((gameboard.getBoard(4) == currentplayer && gameboard.getBoard(5) == currentplayer) || (gameboard.getBoard(10) == currentplayer && gameboard.getBoard(18) == currentplayer)) {
			flag = 1;
		}
	}
	else if (spot == 4) {

		if ((gameboard.getBoard(3) == currentplayer && gameboard.getBoard(5) == currentplayer) || (gameboard.getBoard(2) == currentplayer && gameboard.getBoard(7) == currentplayer)) {
			flag = 1;
		}
	}
	else if (spot == 5) {

		if ((gameboard.getBoard(3) == currentplayer && gameboard.getBoard(4) == currentplayer) || (gameboard.getBoard(13) == currentplayer && gameboard.getBoard(20) == currentplayer)) {
			flag = 1;
		}
	}
	else if (spot == 6) {

		if ((gameboard.getBoard(7) == currentplayer && gameboard.getBoard(8) == currentplayer) || (gameboard.getBoard(11) == currentplayer && gameboard.getBoard(15) == currentplayer)) {
			flag = 1;
		}
	}
	else if (spot == 7) {

		if ((gameboard.getBoard(6) == currentplayer && gameboard.getBoard(8) == currentplayer) || (gameboard.getBoard(1) == currentplayer && gameboard.getBoard(4) == currentplayer)) {
			flag = 1;
		}
	}
	else if (spot == 8) {

		if ((gameboard.getBoard(6) == currentplayer && gameboard.getBoard(7) == currentplayer) || (gameboard.getBoard(12) == currentplayer && gameboard.getBoard(16) == currentplayer)) {
			flag = 1;
		}
	}
	else if (spot == 9) {

		if ((gameboard.getBoard(10) == currentplayer && gameboard.getBoard(11) == currentplayer) || (gameboard.getBoard(0) == currentplayer && gameboard.getBoard(21) == currentplayer)) {
			flag = 1;
		}
	}
	else if (spot == 10) {

		if ((gameboard.getBoard(9) == currentplayer && gameboard.getBoard(11) == currentplayer) || (gameboard.getBoard(3) == currentplayer && gameboard.getBoard(18) == currentplayer)) {
			flag = 1;
		}
	}
	else if (spot == 11) {

		if ((gameboard.getBoard(15) == currentplayer && gameboard.getBoard(6) == currentplayer) || (gameboard.getBoard(9) == currentplayer && gameboard.getBoard(10) == currentplayer)) {
			flag = 1;
		}
	}
	else if (spot == 12) {

		if ((gameboard.getBoard(13) == currentplayer && gameboard.getBoard(14) == currentplayer) || (gameboard.getBoard(8) == currentplayer && gameboard.getBoard(17) == currentplayer)) {
			flag = 1;
		}
	}
	else if (spot == 13) {

		if ((gameboard.getBoard(12) == currentplayer && gameboard.getBoard(14) == currentplayer) || (gameboard.getBoard(20) == currentplayer && gameboard.getBoard(5) == currentplayer)) {
			flag = 1;
		}
	}
	else if (spot == 14) {

		if ((gameboard.getBoard(12) == currentplayer && gameboard.getBoard(13) == currentplayer) || (gameboard.getBoard(2) == currentplayer && gameboard.getBoard(23) == currentplayer)) {
			flag = 1;
		}
	}
	else if (spot == 15) {

		if ((gameboard.getBoard(6) == currentplayer && gameboard.getBoard(11) == currentplayer) || (gameboard.getBoard(16) == currentplayer && gameboard.getBoard(17) == currentplayer)) {
			flag = 1;
		}
	}
	else if (spot == 16) {

		if ((gameboard.getBoard(15) == currentplayer && gameboard.getBoard(17) == currentplayer) || (gameboard.getBoard(19) == currentplayer && gameboard.getBoard(22) == currentplayer)) {
			flag = 1;
		}
	}
	else if (spot == 17) {

		if ((gameboard.getBoard(15) == currentplayer && gameboard.getBoard(16) == currentplayer) || (gameboard.getBoard(8) == currentplayer && gameboard.getBoard(12) == currentplayer)) {
			flag = 1;
		}
	}
	else if (spot == 18) {

		if ((gameboard.getBoard(3) == currentplayer && gameboard.getBoard(10) == currentplayer) || (gameboard.getBoard(19) == currentplayer && gameboard.getBoard(20) == currentplayer)) {
			flag = 1;
		}
	}
	else if (spot == 19) {

		if ((gameboard.getBoard(18) == currentplayer && gameboard.getBoard(20) == currentplayer) || (gameboard.getBoard(22) == currentplayer && gameboard.getBoard(16) == currentplayer)) {
			flag = 1;
		}
	}
	else if (spot == 20) {

		if ((gameboard.getBoard(18) == currentplayer && gameboard.getBoard(19) == currentplayer) || (gameboard.getBoard(5) == currentplayer && gameboard.getBoard(13) == currentplayer)) {
			flag = 1;
		}
	}
	else if (spot == 21) {

		if ((gameboard.getBoard(0) == currentplayer && gameboard.getBoard(9) == currentplayer) || (gameboard.getBoard(22) == currentplayer && gameboard.getBoard(23) == currentplayer)) {
			flag = 1;
		}
	}
	else if (spot == 22) {

		if ((gameboard.getBoard(21) == currentplayer && gameboard.getBoard(23) == currentplayer) || (gameboard.getBoard(16) == currentplayer && gameboard.getBoard(19) == currentplayer)) {
			flag = 1;
		}
	}
	else if (spot == 23) {

		if ((gameboard.getBoard(2) == currentplayer && gameboard.getBoard(14) == currentplayer) || (gameboard.getBoard(22) == currentplayer && gameboard.getBoard(21) == currentplayer)) {
			flag = 1;
		}
	}

	//prompt for user input if flag is 1 (if a row is formed)
	if (flag == 1) {
		while (flag == 1) {
			cout << "Player " << currentplayer << " please remove an opponent's token: " << endl;
			cin >> desiredRemove;

			//check if the selected position has a token
			if (currentplayer == 1) {
				if (gameboard.getBoard(desiredRemove) == 2) {
					gameboard.setBoard(desiredRemove, 0);
					flag = 0;   //flag is 0, so we know a valid token is chosen to be removed
				}
			}
			else if (currentplayer == 2) {
				if (gameboard.getBoard(desiredRemove) == 1) {
					gameboard.setBoard(desiredRemove, 0);
					flag = 0;
				}
			}
		}
	}
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

int NineManMorris::alphabeta(Board TreeNode, int depth, int alpha, int beta, bool maximizingPlayer) {
	//v will be the value passed up the tree
	int v;

	//check if a player won in the given board node
	if (isGameOver()) {
		return TreeNode.evaluateBoard(maximizingPlayer, phase);
	}

	//check if last node in branch
	if (depth == 0) {
		//return the heuristic value of node, this will generate the v value for the bottom node
		return TreeNode.evaluateBoard(maximizingPlayer, phase);
	}

	if (maximizingPlayer) {
		v = INT_MIN;

		//generate all children
		vector<Board> possibleBoards = TreeNode.generateBoard(maximizingPlayer, phase);

		for (int i = 0; i < possibleBoards.size(); i++) {
			//see which child is the best choice
			v = max(v, alphabeta(possibleBoards.at(i), depth - 1, alpha, beta, false));
			alpha = max(alpha, v);
			if (beta <= alpha) {
				break;		//beta cut - off
			}
		}
		return v;
	}
	else {
		v = INT_MAX;

		//generate child nodes
		vector<Board> possibleBoards = TreeNode.generateBoard(maximizingPlayer, phase);

		for (int i = 0; i < possibleBoards.size(); i++) {
			v = min(v, alphabeta(possibleBoards.at(i), depth - 1, alpha, beta, true));
			beta = min(beta, v);
			if (beta <= alpha) {
				break;		//alpha cut - off
			}
		}
		return v;
	}
}

void NineManMorris::testFunc() {
	gameboard.setBoard(23, 1);

	vector<Board> test_vec = gameboard.generateBoard(true, 3);

	for (int i = 0; i < test_vec.size(); i++) {
		test_vec.at(i).displayBoard();
	}

}

//overloaded function that gets called from main
int NineManMorris::alphabeta(int depth, int alpha, int beta, bool maximizingPlayer) {
	//v will be the value passed up the tree
	int v;

	//check if a player won in the given board node
	if (isGameOver()) {
		return gameboard.evaluateBoard(maximizingPlayer, phase);
	}

	//check if last node in branch
	if (depth == 0) {
		//return the heuristic value of node, this will generate the v value for the bottom node
		return gameboard.evaluateBoard(maximizingPlayer, phase);
	}

	if (maximizingPlayer) {
		v = INT_MIN;

		//generate all children
		vector<Board> possibleBoards = gameboard.generateBoard(maximizingPlayer, phase);

		for (int i = 0; i < possibleBoards.size(); i++) {
			//see which child is the best choice
			v = max(v, alphabeta(possibleBoards.at(i), depth - 1, alpha, beta, false));
			alpha = max(alpha, v);
			if (beta <= alpha) {
				break;		//beta cut - off
			}
		}
		return v;
	}
	else {
		v = INT_MAX;

		//generate child nodes
		vector<Board> possibleBoards = gameboard.generateBoard(maximizingPlayer, phase);

		for (int i = 0; i < possibleBoards.size(); i++) {
			v = min(v, alphabeta(possibleBoards.at(i), depth - 1, alpha, beta, true));
			beta = min(beta, v);
			if (beta <= alpha) {
				break;		//alpha cut - off
			}
		}
		return v;
	}
}
