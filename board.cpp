#include "board.h"
#include <iostream>

board::board() {

	for (int i = 0; i < 24; i++) {
		gameboard[i] = 0;
	}

}

int board::getBoard(int position) {

	return gameboard[position];

}

void board::setBoard(int location, int player) {

	gameboard[location] = player;

}


bool board::adjacentPositions(int token, int position) {

	//given the following token, the valid positions are:
	if (token == 0) {
		if (position == 1 || position == 9) {
			return true;
		}
		else {
			return false;
		}
	}
	else if (token == 1) {
		if (position == 0 || position == 4 || position == 2) {
			return true;
		}
		else {
			return false;
		}
	}
	else if (token == 2) {
		if (position == 1 || position == 14) {
			return true;
		}
		else {
			return false;
		}
	}
	else if (token == 3) {
		if (position == 4 || position == 10) {
			return true;
		}
		else {
			return false;
		}
	}
	else if (token == 4) {
		if (position == 1 || position == 3 || position == 5 || position == 7) {
			return true;
		}
		else {
			return false;
		}
	}
	else if (token == 5) {
		if (position == 4 || position == 13) {
			return true;
		}
		else {
			return false;
		}
	}
	else if (token == 6) {
		if (position == 7 || position == 11) {
			return true;
		}
		else {
			return false;
		}
	}
	else if (token == 7) {
		if (position == 6 || position == 4 || position == 8) {
			return true;
		}
		else {
			return false;
		}
	}
	else if (token == 8) {
		if (position == 7 || position == 12) {
			return true;
		}
		else {
			return false;
		}
	}
	else if (token == 9) {
		if (position == 0 || position == 21 || position == 10) {
			return true;
		}
		else {
			return false;
		}
	}
	else if (token == 10) {
		if (position == 3 || position == 18 || position == 9 || position == 11) {
			return true;
		}
		else {
			return false;
		}
	}
	else if (token == 11) {
		if (position == 6 || position == 15 || position == 10) {
			return true;
		}
		else {
			return false;
		}
	}
	else if (token == 12) {
		if (position == 8 || position == 17 || position == 13) {
			return true;
		}
		else {
			return false;
		}
	}
	else if (token == 13) {
		if (position == 5 || position == 12 || position == 14 || position == 20) {
			return true;
		}
		else {
			return false;
		}
	}
	else if (token == 14) {
		if (position == 2 || position == 13 || position == 23) {
			return true;
		}
		else {
			return false;
		}
	}
	else if (token == 15) {
		if (position == 11 || position == 16) {
			return true;
		}
		else {
			return false;
		}
	}
	else if (token == 16) {
		if (position == 15 || position == 17 || position == 19) {
			return true;
		}
		else {
			return false;
		}
	}
	else if (token == 17) {
		if (position == 12 || position == 16) {
			return true;
		}
		else {
			return false;
		}
	}
	else if (token == 18) {
		if (position == 10 || position == 19) {
			return true;
		}
		else {
			return false;
		}
	}
	else if (token == 19) {
		if (position == 18 || position == 16 || position == 20 || position == 22) {
			return true;
		}
		else {
			return false;
		}
	}
	else if (token == 20) {
		if (position == 13 || position == 19) {
			return true;
		}
		else {
			return false;
		}
	}
	else if (token == 21) {
		if (position == 9 || position == 22) {
			return true;
		}
		else {
			return false;
		}
	}
	else if (token == 22) {
		if (position == 19 || position == 21 || position == 23) {
			return true;
		}
		else {
			return false;
		}
	}
	else if (token == 23) {
		if (position == 14 || position == 22) {
			return true;
		}
		else {
			return false;
		}
	}

	return false;
}

void board::displayBoard() {

	for (int i = 0; i < 24; i++) {

		//draws the top/bottom row of the board
		if (i < 2) {
			cout << gameboard[i] << "---------";
		}

		//draw the middle top row of the board
		else if (i == 2) {
			cout << gameboard[i] << endl;
			cout << "|         |         |" << endl;
		}
		else if (i == 3) {
			cout << "|   " << gameboard[i] << "-----";
		}

		else if (i == 4 || i == 19) {
			cout << gameboard[i] << "-----";
		}
		else if (i == 5) {
			cout << gameboard[i] << "   |" << endl;
			cout << "|   |     |     |   |" << endl;
		}
		else if (i == 6 || i == 15) {
			cout << "|   |  " << gameboard[i];
		}
		else if (i == 7 || i == 16) {
			cout << "--" << gameboard[i] << "--";
		}
		else if (i == 8 || i == 17) {
			cout << gameboard[i] << "  |   |" << endl;
		}
		else if (i == 9) {
			cout << "|   |  |     |  |   |" << endl;
			cout << gameboard[i] << "---";
		}
		else if (i == 10 || i == 12) {
			cout << gameboard[i] << "--";
		}
		else if (i == 11) {
			cout << gameboard[i] << "     ";
		}
		else if (i == 13) {
			cout << gameboard[i] << "---";
		}
		else if (i == 14) {
			cout << gameboard[i] << endl;
			cout << "|   |  |     |  |   |" << endl;
		}
		else if (i == 18) {
			cout << "|   |     |     |   |" << endl;
			cout << "|   " << gameboard[i] << "-----";
		}
		else if (i == 20) {
			cout << gameboard[i] << "   |" << endl;
			cout << "|         |         |" << endl;
		}
		else if (i == 21 || i == 22) {
			cout << gameboard[i] << "---------";
		}
		else {
			cout << gameboard[i] << endl;
		}
	}

}



