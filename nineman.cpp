
#include "nineman.h"
#include <iostream>

using namespace std;

NineManMorris::NineManMorris() :phase(1), numOfTokensInHandP1(9), numOfTokensInHandP2(9) {

}

void NineManMorris::display() {

	Game.displayBoard();

}

bool NineManMorris::isGameOver() {

	//check if game is over by seeing if theres less than 3 pieces on the board
	//it also has to be in phase 3, or else this will read as game over in phase 1
	if (getTokensPlaced(1) < 3 && phase == 3) {
		cout << "\n-----------player 2 has won!----------" << endl;
		return true;
	}
	else if (getTokensPlaced(2) < 3 && phase == 3) {
		cout << "\n-----------player 1 has won!----------" << endl;
		return true;
	}

	//if a player gets trapped in phase 2 where a player slides pieces around

	return false;

}

//first checks if it is time to change phases
void NineManMorris::play(int player, int token, int MoveTo) {

	//placing stage
	if (phase == 1) {
		Game.setBoard(MoveTo, player);
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
		Game.setBoard(MoveTo, player);
		//remove the spot where the player's token originally was. This gives the image that the token is moving
		Game.setBoard(token, 0);
	}
	else if (phase == 3) {
		//change the spot where the player wants to move to
		Game.setBoard(MoveTo, player);
		//remove the spot where the player's token originally was. This gives the image that the token is moving
		Game.setBoard(token, 0);
	}
}

//will check if move is valid first. If it is, then the board's function to actually complete the action is called
bool NineManMorris::isValid(int player, int token, int position) {

	//regardless of phase, the position that the token wants to go to has to be empty
	if (Game.getBoard(position) != 0) {
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
			if (Game.getBoard(token) != 1) {
				return false;
			}
			else {
				//returns true or false
				return Game.adjacentPositions(token, position);
			}
		}
		else {		//player 2
			if (Game.getBoard(token) != 2) {
				return false;
			}
			else {
				return Game.adjacentPositions(token, position);
			}
		}
	}

	//phase 3 set of rules:
	//1. the spot they choose to get the token from has to be their token
	else if (phase == 3) {
		if (player == 1) {    //if player 1, we have to check the token they want to move is actually their token
			if (Game.getBoard(token) == 1) {
				return true;
			}
		}
		if (player == 2) {    //same as player 1
			if (Game.getBoard(token) == 2) {
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

		if ((Game.getBoard(1) == currentplayer && Game.getBoard(2) == currentplayer) || (Game.getBoard(9) == currentplayer && Game.getBoard(21) == currentplayer)) {
			flag = 1;
		}
	}
	else if (spot == 1) {

		if ((Game.getBoard(0) == currentplayer && Game.getBoard(2) == currentplayer) || (Game.getBoard(4) == currentplayer && Game.getBoard(7) == currentplayer)) {
			flag = 1;
		}
	}
	else if (spot == 2) {

		if ((Game.getBoard(0) == currentplayer && Game.getBoard(1) == currentplayer) || (Game.getBoard(23) == currentplayer && Game.getBoard(14) == currentplayer)) {
			flag = 1;
		}
	}
	else if (spot == 3) {

		if ((Game.getBoard(4) == currentplayer && Game.getBoard(5) == currentplayer) || (Game.getBoard(10) == currentplayer && Game.getBoard(18) == currentplayer)) {
			flag = 1;
		}
	}
	else if (spot == 4) {

		if ((Game.getBoard(3) == currentplayer && Game.getBoard(5) == currentplayer) || (Game.getBoard(2) == currentplayer && Game.getBoard(7) == currentplayer)) {
			flag = 1;
		}
	}
	else if (spot == 5) {

		if ((Game.getBoard(3) == currentplayer && Game.getBoard(4) == currentplayer) || (Game.getBoard(13) == currentplayer && Game.getBoard(20) == currentplayer)) {
			flag = 1;
		}
	}
	else if (spot == 6) {

		if ((Game.getBoard(7) == currentplayer && Game.getBoard(8) == currentplayer) || (Game.getBoard(11) == currentplayer && Game.getBoard(15) == currentplayer)) {
			flag = 1;
		}
	}
	else if (spot == 7) {

		if ((Game.getBoard(6) == currentplayer && Game.getBoard(8) == currentplayer) || (Game.getBoard(1) == currentplayer && Game.getBoard(4) == currentplayer)) {
			flag = 1;
		}
	}
	else if (spot == 8) {

		if ((Game.getBoard(6) == currentplayer && Game.getBoard(7) == currentplayer) || (Game.getBoard(12) == currentplayer && Game.getBoard(16) == currentplayer)) {
			flag = 1;
		}
	}
	else if (spot == 9) {

		if ((Game.getBoard(10) == currentplayer && Game.getBoard(11) == currentplayer) || (Game.getBoard(0) == currentplayer && Game.getBoard(21) == currentplayer)) {
			flag = 1;
		}
	}
	else if (spot == 10) {

		if ((Game.getBoard(9) == currentplayer && Game.getBoard(11) == currentplayer) || (Game.getBoard(3) == currentplayer && Game.getBoard(18) == currentplayer)) {
			flag = 1;
		}
	}
	else if (spot == 11) {

		if ((Game.getBoard(15) == currentplayer && Game.getBoard(6) == currentplayer) || (Game.getBoard(9) == currentplayer && Game.getBoard(10) == currentplayer)) {
			flag = 1;
		}
	}
	else if (spot == 12) {

		if ((Game.getBoard(13) == currentplayer && Game.getBoard(14) == currentplayer) || (Game.getBoard(8) == currentplayer && Game.getBoard(17) == currentplayer)) {
			flag = 1;
		}
	}
	else if (spot == 13) {

		if ((Game.getBoard(12) == currentplayer && Game.getBoard(14) == currentplayer) || (Game.getBoard(20) == currentplayer && Game.getBoard(5) == currentplayer)) {
			flag = 1;
		}
	}
	else if (spot == 14) {

		if ((Game.getBoard(12) == currentplayer && Game.getBoard(13) == currentplayer) || (Game.getBoard(2) == currentplayer && Game.getBoard(23) == currentplayer)) {
			flag = 1;
		}
	}
	else if (spot == 15) {

		if ((Game.getBoard(6) == currentplayer && Game.getBoard(11) == currentplayer) || (Game.getBoard(16) == currentplayer && Game.getBoard(17) == currentplayer)) {
			flag = 1;
		}
	}
	else if (spot == 16) {

		if ((Game.getBoard(15) == currentplayer && Game.getBoard(17) == currentplayer) || (Game.getBoard(19) == currentplayer && Game.getBoard(22) == currentplayer)) {
			flag = 1;
		}
	}
	else if (spot == 17) {

		if ((Game.getBoard(15) == currentplayer && Game.getBoard(16) == currentplayer) || (Game.getBoard(8) == currentplayer && Game.getBoard(12) == currentplayer)) {
			flag = 1;
		}
	}
	else if (spot == 18) {

		if ((Game.getBoard(3) == currentplayer && Game.getBoard(10) == currentplayer) || (Game.getBoard(19) == currentplayer && Game.getBoard(20) == currentplayer)) {
			flag = 1;
		}
	}
	else if (spot == 19) {

		if ((Game.getBoard(18) == currentplayer && Game.getBoard(20) == currentplayer) || (Game.getBoard(22) == currentplayer && Game.getBoard(16) == currentplayer)) {
			flag = 1;
		}
	}
	else if (spot == 20) {

		if ((Game.getBoard(18) == currentplayer && Game.getBoard(19) == currentplayer) || (Game.getBoard(5) == currentplayer && Game.getBoard(12) == currentplayer)) {
			flag = 1;
		}
	}
	else if (spot == 21) {

		if ((Game.getBoard(0) == currentplayer && Game.getBoard(9) == currentplayer) || (Game.getBoard(22) == currentplayer && Game.getBoard(23) == currentplayer)) {
			flag = 1;
		}
	}
	else if (spot == 22) {

		if ((Game.getBoard(21) == currentplayer && Game.getBoard(23) == currentplayer) || (Game.getBoard(16) == currentplayer && Game.getBoard(19) == currentplayer)) {
			flag = 1;
		}
	}
	else if (spot == 23) {

		if ((Game.getBoard(2) == currentplayer && Game.getBoard(14) == currentplayer) || (Game.getBoard(22) == currentplayer && Game.getBoard(21) == currentplayer)) {
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
				if (Game.getBoard(desiredRemove) == 2) {
					Game.setBoard(desiredRemove, 0);
					flag = 0;   //flag is 0, so we know a valid token is chosen to be removed
				}
			}
			else if (currentplayer == 2) {
				if (Game.getBoard(desiredRemove) == 1) {
					Game.setBoard(desiredRemove, 0);
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
		if (Game.getBoard(i) == player) {
			counter++;
		}
	}

	return counter;
}

/*int NineManMorris::alphabeta(GameState node, int depth, int alpha, int beta, bool maximizingPlayer) {
//v will be the value passed up the tree
int v;

//check if terminal node by:
//1. No more possible moves (e.g. phase 2 and all nodes are stuck, phase 1 no more pl
//2.
if (depth == 0 || node is a terminal node) {
//return the heuristic value of node, this will generate the v value for the bottom node
evaluateBoard();
}
if (maximizingPlayer) {
v = -infinity;

//generate child nodes
vector<GameState> PossibleStates = generateStates();

//for each child node
for(int i = 0; i < PossibleStates.size; i++){
v = max(v, alphabeta(PossibleStates.at(i), depth - 1, alpha, beta, false));
alpha = max(alpha, v);
if (beta <= alpha)
break;		//beta cut - off
}
return v;
}
else {
v = infinity;

//generate child nodes
vector<GameState> PossibleStates = generateStates();

for (int i = 0; i < PossibleStates.size; i++) {
v = min(v, alphabeta(PossibleStates.at(i), depth - 1, alpha, beta, true));
beta = min(beta, v);
if (beta <= alpha) {
break;		//alpha cut - off
}
}
return v;
}
}*/
