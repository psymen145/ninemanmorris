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

	return -1;
}

void Board::setBoard(int location, int player) {

	for (int i = 0; i < 24; i++) {
		if (gamePositions[i].getPosition() == location) {
			if (player == 0) {		//check if its a removal of a token
				gamePositions[i].setIsOccupied(false);
				gamePositions[i].setPlayerOccupy(player);
			}
			else if (player == 1) {
				gamePositions[i].setIsOccupied(true);
				gamePositions[i].setPlayerOccupy(player);
				positionLastPlacedP1 = location;
			}
			else {
				gamePositions[i].setIsOccupied(true);
				gamePositions[i].setPlayerOccupy(player);
				positionLastPlacedP2 = location;
			}
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

	return false;
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
	int counter = 0;    //used to count for eval8/eval5/eval3
	int counter2 = 0;	//used for eval5/eval3
	int counter3 = 0;	//used for eval3
	int tokencounter = 0;	//used for eval1/eval7
	int millcounter = 0;
	int eval1 = 0;
	//int eval2 = 0;
	int eval3 = 0;
	int eval4 = 0;
	int eval5 = 0;
	int eval6 = 0;
	int eval7 = 0;
	int eval8 = 0;

	if (maximizingPlayer) {
		CurrentPlayer = 1;
	}
	else {
		CurrentPlayer = 2;
	}

	//evaluation scenario 1: if 3 in a row is formed return 1, if -1 is closed by the opponent in last move
	if (CurrentPlayer == 1) {	//for maximizing player
		for (int i = 0; i < 24; i++) {
			if (gamePositions[i].getPosition() == positionLastPlacedP1) {
				vector <vector<int>> possibleMills = gamePositions[i].getMills();
				for (int j = 0; j < 2; j++) {	//2 possible mill combinations for each point on the board
					vector<int> millLocation = possibleMills.at(j);
					for (int k = 0; k < 2; k++) {	//for each possible combination, check the spot to see if is occupied by p1
						for (int l = 0; l < 24; l++) {	//find the node with this position
							if (gamePositions[l].getPosition() == millLocation.at(k)) {
								if (gamePositions[l].getPlayerOccupy() == CurrentPlayer) {
									tokencounter++;
									if (tokencounter == 2) {	//if mill is formed
										eval1 = 1;
										break;
									}
								}
							}
						}
						tokencounter = 0;	//reset the counter to check if next mill combo is good
					}
				}
				break;
			}
		}
		for (int i = 0; i < 24; i++) {	//check if the second player 
			if (gamePositions[i].getPosition() == positionLastPlacedP2) {
				vector <vector<int>> possibleMills = gamePositions[i].getMills();
				for (int j = 0; j < 2; j++) {	//2 possible mill combinations for each point on the board
					vector<int> millLocation = possibleMills.at(j);
					for (int k = 0; k < 2; k++) {	//for each possible combination, check the spot to see if is occupied by p1
						for (int l = 0; l < 24; l++) {	//find the node with this position
							if (gamePositions[l].getPosition() == millLocation.at(k)) {
								if (gamePositions[l].getPlayerOccupy() == 2) {
									tokencounter++;
									if (tokencounter == 2) {	//if mill is formed
										eval1 = 1;
										break;
									}
								}
							}
						}
						tokencounter = 0;	//reset the counter to check if next mill combo is good
					}
				}
				break;
			}
		}
		eval1 = 0;
	}
	else {	// for non maximizing player
		for (int i = 0; i < 24; i++) {
			if (gamePositions[i].getPosition() == positionLastPlacedP1) {
				vector <vector<int>> possibleMills = gamePositions[i].getMills();
				for (int j = 0; j < 2; j++) {	//2 possible mill combinations for each point on the board
					vector<int> millLocation = possibleMills.at(j);
					for (int k = 0; k < 2; k++) {	//for each possible combination, check the spot to see if is occupied by p1
						for (int l = 0; l < 24; l++) {	//find the node with this position
							if (gamePositions[l].getPosition() == millLocation.at(k)) {
								if (gamePositions[l].getPlayerOccupy() == 2) {
									tokencounter++;
									if (tokencounter == 2) {	//if mill is formed
										eval1 = 1;
										break;
									}
								}
							}
						}
						tokencounter = 0;	//reset the counter to check if next mill combo is good
					}
				}
				break;
			}
		}
		for (int i = 0; i < 24; i++) {	//check if the second player 
			if (gamePositions[i].getPosition() == positionLastPlacedP2) {
				vector <vector<int>> possibleMills = gamePositions[i].getMills();
				for (int j = 0; j < 2; j++) {	//2 possible mill combinations for each point on the board
					vector<int> millLocation = possibleMills.at(j);
					for (int k = 0; k < 2; k++) {	//for each possible combination, check the spot to see if is occupied by p1
						for (int l = 0; l < 24; l++) {	//find the node with this position
							if (gamePositions[l].getPosition() == millLocation.at(k)) {
								if (gamePositions[l].getPlayerOccupy() == 1) {
									tokencounter++;
									if (tokencounter == 2) {	//if mill is formed
										eval1 = 1;
										break;
									}
								}
							}
						}
						tokencounter = 0;	//reset the counter to check if next mill combo is good
					}
				}
				break;
			}
		}
		eval1 = 0;
	}

	//evaluation scenario 2: difference in number of morrises
	/*for (int i = 0; i < 24; i++) {
		if (gamePositions[i].getPosition() == positionLastPlacedP1) {
			vector <vector<int>> possibleMills = gamePositions[i].getMills();
			for (int j = 0; j < 2; j++) {	//2 possible mill combinations for each point on the board
				vector<int> millLocation = possibleMills.at(j);
				for (int k = 0; k < 2; k++) {	//for each possible combination, check the spot to see if is occupied by p1
					if (gamePositions[k].getPosition() == 1) {
						millcounter++;
						if (millcounter == 2) {	//if mill is formed, we can return 1, don't need to check the other mill combo
							return 1;
						}
					}
					millcounter = 0;	//reset the counter to check if next mill combo is good
				}
			}
			break;
		}
	}*/

	//evaluation scenario 3: difference between the number of blocked pieces
	counter = 0;
	counter2 = 0;
	counter3 = 0;
	for (int i = 0; i < 24; i++) {
		if (gamePositions[i].getPlayerOccupy() == CurrentPlayer) {	//checking for current player but this will benefit opponent player
			for (int j = 0; j < gamePositions[i].getAdjacentPositions().size(); j++) {	//loop through adjacent pieces to see if its blocked
				if (gamePositions[i].getAdjacentPositions().at(j) != CurrentPlayer && gamePositions[i].getAdjacentPositions().at(j) != 0) {	//this means it is blocked
					counter++;
				}
				if (counter == gamePositions[i].getAdjacentPositions().size()) {	//the piece is blocked
					counter2++;
				}
			}
			counter = 0;
		}
		else if (gamePositions[i].getPlayerOccupy() != 0) {	//opponent player
			for (int j = 0; j < gamePositions[i].getAdjacentPositions().size(); j++) {	//loop through adjacent pieces to see if its blocked
				if (gamePositions[i].getAdjacentPositions().at(j) == CurrentPlayer) {	//this means it is blocked
					counter++;
				}
				if (counter == gamePositions[i].getAdjacentPositions().size()) {	//the piece is blocked
					counter3++;
				}
			}
			counter = 0;
		}
	}
	if (CurrentPlayer == 1) {
		eval3 = counter2 - counter3;
	}
	else {
		eval3 = counter3 - counter2;
	}

	//evaluation scenario 4: difference between number of tokens
	for (int i = 0; i < 24; i++) {
		if (gamePositions[i].getPlayerOccupy() == CurrentPlayer) {
			eval4++;
		}
		else if (gamePositions[i].getPlayerOccupy() != 0) {
			eval4--;
		}
	}

	//evaluation scenario 5: difference in number of pairs of tokens
	counter = 0;
	counter2 = 0;
	for (int i = 0; i < 24; i++) {	//check for player 1
		if (gamePositions[i].getPlayerOccupy() == 1) {	//check if max player
			for (int j = 0; j < gamePositions[i].getAdjacentPositions().size(); j++) {	//check all adjacent spots
				if (gamePositions[i].getAdjacentPositions().at(j) == 1) {
					counter++;
				}
			}
		}
	}
	for (int i = 0; i < 24; i++) {	//check for player 2
		if (gamePositions[i].getPlayerOccupy() == 2) {	//check if max player
			for (int j = 0; j < gamePositions[i].getAdjacentPositions().size(); j++) {	//check all adjacent spots
				if (gamePositions[i].getAdjacentPositions().at(j) == 2) {
					counter2++;
				}
			}
		}
	}
	if (CurrentPlayer == 1) {
		eval5 = counter - counter2;
	}
	else {
		eval5 = counter2 - counter;
	}

	//evaluation scenario 6: if the move allows player to have two ways to create morris

	//evaluation scenario 7: number of double morrises
	counter = 0;	//count how many double morrises a player has
	counter2 = 0;	//count how many double morrises another player has
	tokencounter = 0;	//2 tokens make a mill
	millcounter = 0;	//2 mills will equal a double morris
	for (int i = 0; i < 24; i++) {
		if (gamePositions[i].getPosition() == CurrentPlayer) {
			vector <vector<int>> possibleMills = gamePositions[i].getMills();
			for (int j = 0; j < 2; j++) {	//2 possible mill combinations for each point on the board
				vector<int> millLocation = possibleMills.at(j);
				for (int k = 0; k < 2; k++) {	//for each possible combination, check the spot to see if is occupied by p1
					for (int l = 0; l < 24; l++) {	//find the node with this position
						if (gamePositions[l].getPosition() == millLocation.at(k)) {
							if (gamePositions[l].getPlayerOccupy() == CurrentPlayer) {
								tokencounter++;
								if (tokencounter == 2) {	//if mill is formed
									millcounter++;
								}
							}
						}
					}
					if (millcounter == 2) {	//if two mill, it means double morris
						counter++;
					}
					tokencounter = 0;
				}
			}
			millcounter = 0;
		}
		else if (gamePositions[i].getPosition() != 0) {
			vector <vector<int>> possibleMills = gamePositions[i].getMills();
			for (int j = 0; j < 2; j++) {	//2 possible mill combinations for each point on the board
				vector<int> millLocation = possibleMills.at(j);
				for (int k = 0; k < 2; k++) {	//for each possible combination, check the spot to see if is occupied by p1
					for (int l = 0; l < 24; l++) {	//find the node with this position
						if (gamePositions[l].getPosition() == millLocation.at(k)) {
							if (gamePositions[l].getPlayerOccupy() == CurrentPlayer) {
								tokencounter++;
								if (tokencounter == 2) {	//if mill is formed
									millcounter++;
								}
							}
						}
					}
					if (millcounter == 2) {	//if two mill, it means double morris
						counter2++;
					}
					tokencounter = 0;
				}
			}
			millcounter = 0;
		}
	}
	if (CurrentPlayer == 1) {
		eval7 = counter - counter2;
	}
	else {
		eval7 = counter2 - counter;
	}

	//evaluation scenario 8: if the state is winning/losing
	counter = 0;
	for (int i = 0; i < 24; i++) {
		if (gamePositions[i].getPlayerOccupy() != CurrentPlayer && gamePositions[i].getPlayerOccupy() != 0) {    //if opposing player's total token count is less than 3
			counter++;
		}
	}
	if (counter < 3) {
		eval8 = 1;
	}
	else {
		eval8 = -1;
	}

	//calculating the total evaluation points
	if (phase == 1) {	//26*(2) , 7*(6)
		return 18*(eval1) + 1*(eval3) + 9*(eval4) + 10*(eval5);
	}
	else if (phase == 2) {	//43*(2)
		return 14*(eval1) + 10*(eval3) + 11*(eval4) + 8*(eval7) + 1086*(eval8);
	}
	else {	// + 1*(6)
		return 16*(eval1) + 10*(eval5) + 1190*(eval8);
	}
}

vector<Board> Board::generateBoard(bool maximizingPlayer, int phase) {
	//temp vector used to store boards as we generate them
	vector<Board> temp_vec;
	int CurrentPlayer = 0;

	if (maximizingPlayer) {
		CurrentPlayer = 1;
	}
	else {
		CurrentPlayer = 2;
	}

	//different possible boards for each, we assuming maximizing player is player 1
	if (phase == 1) {	//phase 1
		for (int i = 0; i < 24; i++) {
			if (gamePositions[i].getIsOccupied() == false) {		//find the open spot and put the maximizingplayer's token on it
				Board newBoard(gamePositions);		//used to create new object to put into vector
				newBoard.setBoard(i, CurrentPlayer);			//change the location where we found the empty spot and put the player's token
				newBoard.setPositionLastPlaced(i, CurrentPlayer);
				temp_vec.push_back(newBoard);	//add this instance to the vector
			}
		}

		return temp_vec;
	}
	else if (phase == 2) {	//phase 2
		for (int i = 0; i < 24; i++) {
			if (gamePositions[i].getPlayerOccupy() == CurrentPlayer) {	//if there is a token on the piece
				for (int j = 0; j < gamePositions[i].getAdjacentPositions().size(); j++) { //get the adjacent positions
					for (int k = 0; k < 24; k++) {	//find the board of the adjacent positions
						if (gamePositions[k].getPosition() == gamePositions[i].getAdjacentPositions().at(j) && gamePositions[k].getIsOccupied() == false) {
							Board newBoard(gamePositions);
							newBoard.setBoard(i, 0);	//set the position of the desired token that we want to move, to 0
							newBoard.setBoard(k, CurrentPlayer);	//set the adjacent position to maximizing player
							newBoard.setPositionLastPlaced(k, CurrentPlayer);
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
			if (gamePositions[i].getPlayerOccupy() == CurrentPlayer) {
				for (int j = 0; j < 24; j++) {	//for each spot that is empty, you can generate a board for it
					if (gamePositions[j].getIsOccupied() == false) {
						Board newBoard(gamePositions);
						newBoard.setBoard(i, 0);
						newBoard.setBoard(j, CurrentPlayer);
						newBoard.setPositionLastPlaced(j, CurrentPlayer);
						temp_vec.push_back(newBoard);
					}
				}
			}
		}
		return temp_vec;
	}
}

int Board::getPosLastPlaced(int player) {
	if (player == 1) {
		return positionLastPlacedP1;
	}
	else {
		return positionLastPlacedP2;
	}
}

void Board::setPositionLastPlaced(int position, int player) {
	if (player == 1) {
		positionLastPlacedP1 = position;
	}
	else {
		positionLastPlacedP2 = position;
	}
}
