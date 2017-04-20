#include "stdafx.h"
#include "Board.h"
#include <algorithm>
#include <iostream>

using namespace std;

Board::Board(Node board[24]) {

	if (board == NULL) {
		for (int i = 0; i < 24; i++) {	//make 24 positions on the board
			gamePositions[i] = Node(0, i, 0);
		}
	}
	else {
		for (int i = 0; i < 24; i++) {
			//copy over the board passed in as a parameter, over the private gameboard object
			gamePositions[i] = Node(board[i].getIsOccupied(), board[i].getPosition(), board[i].getPlayerOccupy());
		}
	}

}

int Board::getBoard(int position) {

	for (int i = 0; i < 24; i++) {
		if (gamePositions[i].getPosition() == position) {
			return gamePositions[i].getPlayerOccupy();
		}
	}

}

void Board::setBoard(int location, int player) {

	for (int i = 0; i < 24; i++) {
		if (gamePositions[i].getPosition() == location) {
			if (player == 0) {		//check if its a removal of a token
				gamePositions[i].setIsOccupied(false);
				gamePositions[i].setPlayerOccupy(player);
			}
			gamePositions[i].setIsOccupied(true);
			gamePositions[i].setPlayerOccupy(player);
		}
	}

}


bool Board::adjacentPositions(int token, int position) {

	//given the following token, the valid positions are:
	for (int i = 0; i < 24; i++) {
		if (gamePositions[i].getPosition() == token) {
			for (int j = 0; j < gamePositions[i].getAdjacentPositions().size(); j++) {	//getAdjacentPositions returns a vector of int(positions)
				if (gamePositions[i].getAdjacentPositions().at(j) == position) {	//if the desired position is in the vector
					return true;
				}
			}
			return false;
		}
	}
}

void Board::displayBoard() {

	for (int i = 0; i < 24; i++) {

		//draws the top/bottom row of the board
		if (gamePositions[i].getPosition() < 2) {
			cout << gamePositions[i].getPlayerOccupy() << "---------";
		}

		//draw the middle top row of the board
		else if (gamePositions[i].getPosition() == 2) {
			cout << gamePositions[i].getPlayerOccupy() << endl;
			cout << "|         |         |" << endl;
		}
		else if (gamePositions[i].getPosition() == 3) {
			cout << "|   " << gamePositions[i].getPlayerOccupy() << "-----";
		}

		else if (gamePositions[i].getPosition() == 4 || gamePositions[i].getPosition() == 19) {
			cout << gamePositions[i].getPlayerOccupy() << "-----";
		}
		else if (gamePositions[i].getPosition() == 5) {
			cout << gamePositions[i].getPlayerOccupy() << "   |" << endl;
			cout << "|   |     |     |   |" << endl;
		}
		else if (gamePositions[i].getPosition() == 6 || gamePositions[i].getPosition() == 15) {
			cout << "|   |  " << gamePositions[i].getPlayerOccupy();
		}
		else if (gamePositions[i].getPosition() == 7 || gamePositions[i].getPosition() == 16) {
			cout << "--" << gamePositions[i].getPlayerOccupy() << "--";
		}
		else if (gamePositions[i].getPosition() == 8 || gamePositions[i].getPosition() == 17) {
			cout << gamePositions[i].getPlayerOccupy() << "  |   |" << endl;
		}
		else if (gamePositions[i].getPosition() == 9) {
			cout << "|   |  |     |  |   |" << endl;
			cout << gamePositions[i].getPlayerOccupy() << "---";
		}
		else if (gamePositions[i].getPosition() == 10 || gamePositions[i].getPosition() == 12) {
			cout << gamePositions[i].getPlayerOccupy() << "--";
		}
		else if (gamePositions[i].getPosition() == 11) {
			cout << gamePositions[i].getPlayerOccupy() << "     ";
		}
		else if (gamePositions[i].getPosition() == 13) {
			cout << gamePositions[i].getPlayerOccupy() << "---";
		}
		else if (gamePositions[i].getPosition() == 14) {
			cout << gamePositions[i].getPlayerOccupy() << endl;
			cout << "|   |  |     |  |   |" << endl;
		}
		else if (gamePositions[i].getPosition() == 18) {
			cout << "|   |     |     |   |" << endl;
			cout << "|   " << gamePositions[i].getPlayerOccupy() << "-----";
		}
		else if (gamePositions[i].getPosition() == 20) {
			cout << gamePositions[i].getPlayerOccupy() << "   |" << endl;
			cout << "|         |         |" << endl;
		}
		else if (gamePositions[i].getPosition() == 21 || gamePositions[i].getPosition() == 22) {
			cout << gamePositions[i].getPlayerOccupy() << "---------";
		}
		else {
			cout << gamePositions[i].getPlayerOccupy() << endl;
		}
	}
}

int Board::evaluateBoard(bool maximizingPlayer, int phase) {
	int CurrentPlayer;
	int eval1 = 0;
	int eval2 = 0; 

	if (maximizingPlayer) {
		CurrentPlayer = 1;
	}
	else {
		CurrentPlayer = 2;
	}

	//evaluation scenario 1: if 3 in a row is formed return 1, if -1 is closed by the opponent in last move
	for (int i = 0; i < 24; i++) {
		if (gamePositions[i].getPlayerOccupy() == CurrentPlayer) {	//if there is a 1, check if possible mills 
			vector<vector<int>> possibleMills = gamePositions[i].getMills(); //2 possible mills for each position
			for (int j = 0; j < possibleMills.size(); j++) {
				vector<int> possiblePositions = possibleMills.at(j);
				for (int k = 0; k < 2; k++) {		//2 ints for each mill
					if(gamePositions[i].getMills().at(j).at(k) == CurrentPlayer
				}
			}
		}
	}

	//evaluation scenario 2: difference between number of tokens
	for (int i = 0; i < 24; i++) {
		if (gamePositions[i].getPlayerOccupy() == CurrentPlayer) {
			eval2++;
		}
		else if(gamePositions[i].getPlayerOccupy() != 0){
			eval2--;
		}
	}


	if (phase == 1) {
		return 18 * (1) + 26 * (2) + 1 * (3) + 9 * (4) + 10 * (5) + 7 * (6);
	}
	else if (phase == 2) {
		return 14 * (1) + 43 * (2) + 10 * (3) + 11 * (4) + 8 * (7) + 1086 * (8);
	}
	else {
		return 16 * (1) + 10 * (5) + 1 * (6) + 1190 * (8);
	}
}

vector<Board> Board::generateBoard(bool maximizingPlayer, int phase) {
	//temp vector used to store boards as we generate them
	vector<Board> temp_vec;

	//different possible boards for each, we assuming maximizing player is player 1
	if (maximizingPlayer) {
		if (phase == 1) {	//phase 1
			for (int i = 0; i < 24; i++) {
				if (gamePositions[i].getIsOccupied() == false) {		//find the open spot and put the maximizingplayer's token on it
					Board newBoard(gamePositions);		//used to create new object to put into vector
					newBoard.setBoard(i, 1);			//change the location where we found the empty spot and put the player's token
					temp_vec.push_back(newBoard);	//add this instance to the vector
				}
			}

			return temp_vec;
		}
		else if (phase == 2) {	//phase 2
			for (int i = 0; i < 24; i++) {  
				if (gamePositions[i].getPlayerOccupy() == 1) {	//if there is a token on the piece
					for (int j = 0; j < gamePositions[i].getAdjacentPositions().size(); j++) { //get the adjacent positions
						for (int k = 0; k < 24; k++) {	//find the board of the adjacent positions
							if (gamePositions[k].getPosition() == gamePositions[i].getAdjacentPositions().at(j) && gamePositions[k].getIsOccupied() == false) {
								Board newBoard(gamePositions);
								newBoard.setBoard(i, 0);	//set the position of the desired token that we want to move, to 0
								newBoard.setBoard(k, 1);	//set the adjacent position to 1
								temp_vec.push_back(newBoard);
							}
						}
					}
				}
			}
			return temp_vec;
		}
		else {	//phase 3
			for (int i = 0; i < 24; i++) {
				if (gamePositions[i].getPlayerOccupy() == 1) {
					for (int j = 0; j < 24; j++) {	//for each spot that is empty, you can generate a board for it
						if (gamePositions[j].getIsOccupied() == false) {
							Board newBoard(gamePositions);
							newBoard.setBoard(i, 0);
							newBoard.setBoard(j, 1);
							temp_vec.push_back(newBoard);
						}
					}
				}
			}
			return temp_vec;
		}

	}
	else {		//non maximizing player
		if (phase == 1) {	//phase 1
			for (int i = 0; i < 24; i++) {
				if (gamePositions[i].getIsOccupied() == false) {		//find the open spot and put the maximizingplayer's token on it
					Board newBoard(gamePositions);		//used to create new object to put into vector
					newBoard.setBoard(i, 2);			//change the location where we found the empty spot and put the player's token
					temp_vec.push_back(newBoard);	//add this instance to the vector
				}
			}

			return temp_vec;
		}
		else if (phase == 2) {	//phase 2
			for (int i = 0; i < 24; i++) {
				if (gamePositions[i].getPlayerOccupy() == 2) {	//if there is a token on the piece
					for (int j = 0; j < gamePositions[i].getAdjacentPositions().size(); j++) { //get the adjacent positions
						for (int k = 0; k < 24; k++) {	//find the board of the adjacent positions
							if (gamePositions[k].getPosition() == gamePositions[i].getAdjacentPositions().at(j) && gamePositions[k].getIsOccupied() == false) {
								Board newBoard(gamePositions);
								newBoard.setBoard(i, 0);	//set the position of the desired token that we want to move, to 0
								newBoard.setBoard(k, 2);	//set the adjacent position to 1
								temp_vec.push_back(newBoard);
							}
						}
					}
				}
			}
			return temp_vec;
		}
		else {	//phase 3
			for (int i = 0; i < 24; i++) {
				if (gamePositions[i].getPlayerOccupy() == 2) {
					for (int j = 0; j < 24; j++) {	//for each spot that is empty, you can generate a board for it
						if (gamePositions[j].getIsOccupied() == false) {
							Board newBoard(gamePositions);
							newBoard.setBoard(i, 0);
							newBoard.setBoard(j, 2);
							temp_vec.push_back(newBoard);
						}
					}
				}
			}
			return temp_vec;
		}
	}
}
