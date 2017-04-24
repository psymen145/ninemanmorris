#include "stdafx.h"
#include "Board.h"
#include <algorithm>
#include <iostream>

using namespace std;

Board::Board() :positionLastPlacedP1(-1), positionLastPlacedP2(-1) {

	for (int i = 0; i < 24; i++) {	//make 24 positions on the board
		gamePositions[i] = Node(i);
	}
}

Board::Board(map<int, Node> board, int lastPosP1, int lastPosP2) {

	gamePositions = board;
	positionLastPlacedP1 = lastPosP1;
	positionLastPlacedP2 = lastPosP2;
}

int Board::getBoard(int position) {

	return gamePositions[position].getPlayerOccupy();
}

void Board::setBoard(int location, int player) {

	gamePositions[location].setPlayerOccupy(player);
}


bool Board::adjacentPositions(int token, int position) {

	//given the following token, the valid positions are:
	for (int i = 0; i < gamePositions[token].getAdjacentPositions().size(); i++) {
		if (gamePositions[token].getAdjacentPositions().at(i) == position) {
			return true;
		}
	}

	return false;
}

void Board::displayBoard() {

	for (int i = 0; i < 24; i++) {

		//draws the top/bottom row of the board
		if (i < 2) {
			cout << gamePositions[i].getPlayerOccupy() << "---------";
		}

		//draw the middle top row of the board
		else if (i == 2) {
			cout << gamePositions[i].getPlayerOccupy() << endl;
			cout << "|         |         |" << endl;
		}
		else if (i == 3) {
			cout << "|   " << gamePositions[i].getPlayerOccupy() << "-----";
		}

		else if (i == 4 || i == 19) {
			cout << gamePositions[i].getPlayerOccupy() << "-----";
		}
		else if (i == 5) {
			cout << gamePositions[i].getPlayerOccupy() << "   |" << endl;
			cout << "|   |     |     |   |" << endl;
		}
		else if (i == 6 || i == 15) {
			cout << "|   |  " << gamePositions[i].getPlayerOccupy();
		}
		else if (i == 7 || i == 16) {
			cout << "--" << gamePositions[i].getPlayerOccupy() << "--";
		}
		else if (i == 8 || i == 17) {
			cout << gamePositions[i].getPlayerOccupy() << "  |   |" << endl;
		}
		else if (i == 9) {
			cout << "|   |  |     |  |   |" << endl;
			cout << gamePositions[i].getPlayerOccupy() << "---";
		}
		else if (i == 10 || i == 12) {
			cout << gamePositions[i].getPlayerOccupy() << "--";
		}
		else if (i == 11) {
			cout << gamePositions[i].getPlayerOccupy() << "     ";
		}
		else if (i == 13) {
			cout << gamePositions[i].getPlayerOccupy() << "---";
		}
		else if (i == 14) {
			cout << gamePositions[i].getPlayerOccupy() << endl;
			cout << "|   |  |     |  |   |" << endl;
		}
		else if (i == 18) {
			cout << "|   |     |     |   |" << endl;
			cout << "|   " << gamePositions[i].getPlayerOccupy() << "-----";
		}
		else if (i == 20) {
			cout << gamePositions[i].getPlayerOccupy() << "   |" << endl;
			cout << "|         |         |" << endl;
		}
		else if (i == 21 || i == 22) {
			cout << gamePositions[i].getPlayerOccupy() << "---------";
		}
		else {
			cout << gamePositions[i].getPlayerOccupy() << endl;
		}
	}
}

int Board::evaluateBoard(int Player, int phase) {
	int flag = 0; //flag = 1 means token placement allowed one mill to be made, flag = 2 means move made two mills possible
	int counter = 0; //counts to see if all adjacent pieces to a token are blocked, also used for another evaluation to see if current player has more pieces
	vector<int> millToCheck;    //used to hold positions of a possible mill, mainly to help with readability
	int score = 0;

	int millcounterP2 = 0;
	int millcounterP1 = 0;

	//number of morrises
	//if (Player == 2) {
	/*for (int i = 0; i < 24; i++) {    //search entire board, if there is a piece that is player 2's check if there is a morris
		if (gamePositions[i].getPlayerOccupy() == 2) {    //check mill spots
			for (int j = 0; j < gamePositions[i].getMills().size(); j++) {
				millToCheck = gamePositions[i].getMills().at(j);
				if (gamePositions[millToCheck.at(0)].getPlayerOccupy() == 2 && gamePositions[millToCheck.at(1)].getPlayerOccupy() == 2) {
					millcounterP2++;
				}
			}
		}
	}
	//}
	//else {
	for (int i = 0; i < 24; i++) {    //search entire board, if there is a piece that is player 2's check if there is a morris
		if (gamePositions[i].getPlayerOccupy() == 1) {    //check mill spots
			for (int j = 0; j < gamePositions[i].getMills().size(); j++) {
				millToCheck = gamePositions[i].getMills().at(j);
				if (gamePositions[millToCheck.at(0)].getPlayerOccupy() == 1 && gamePositions[millToCheck.at(1)].getPlayerOccupy() == 1) {
					millcounterP1++;
				}
			}
		}
	}
	//}
	//you need to divide by 3 because we counted mills multiple times
	millcounterP2 /= 3;
	millcounterP1 /= 3;
	if (Player == 2) {
		score = millcounterP2 * 10 - millcounterP1 * 2;
	}
	else {
		score = millcounterP1 * 10 - millcounterP2 * 2;
	}*/

	//check if morris was made in last position
		cout << "Position Last placed: " << positionLastPlacedP2 << " " << positionLastPlacedP1 << endl;
	

	//if we block a mill of the opponent
	if (Player == 2) {
		//check if a mill was formed from last placement, each Node has two possible mills
		for (int i = 0; i < 24; i++) {
			for (int j = 0; j < gamePositions[i].getMills().size(); j++) {
				millToCheck = gamePositions[i].getMills().at(j);
				//we do 2 times because we know each mill has 2 other positions (what the index is, is considered one position)
				if (gamePositions[millToCheck.at(0)].getPlayerOccupy() == 1 && gamePositions[millToCheck.at(1)].getPlayerOccupy() == 1) {
					score += 10;
				}
			}
		}
	}
	else {
		//check if a mill was formed from last placement, each Node has two possible mills
		for (int i = 0; i < 24; i++) {
			for (int j = 0; j < gamePositions[i].getMills().size(); j++) {
				millToCheck = gamePositions[i].getMills().at(j);
				//we do 2 times because we know each mill has 2 other positions (what the index is, is considered one position)
				if (gamePositions[millToCheck.at(0)].getPlayerOccupy() == 2 && gamePositions[millToCheck.at(1)].getPlayerOccupy() == 2) {
					score += 10;
				}
			}
		}
	}

	//if we almost create a mill (one spot is unoccupied)
	if (Player == 2) {
		for (int i = 0; i < 24; i++) {
			//check if the last placement brought us closer to a mill
			for (int j = 0; j < 2; j++) {
				millToCheck = gamePositions[i].getMills().at(j);

				//we do 2 times because we know each mill has 2 other positions
				if (gamePositions[millToCheck.at(0)].getPlayerOccupy() == 2) {
					if (gamePositions[millToCheck.at(1)].getPlayerOccupy() != 1) {   //make sure that there is a spot open for mill, or else that move is not good
						flag++;
						score += 3;
					}
				}
				else if (gamePositions[millToCheck.at(1)].getPlayerOccupy() == 2) {
					if (gamePositions[millToCheck.at(0)].getPlayerOccupy() != 1) {
						flag++;
						score += 3;
					}
				}
			}
			if (flag == 2) {  //this means two way mill was made possible
				score += 3;
			}
		}
	}
	else {   //for player 1
		for (int i = 0; i < 24; i++) {
			//check if the last placement brought us closer to a mill
			for (int j = 0; j < 2; j++) {
				millToCheck = gamePositions[i].getMills().at(j);

				//we do 2 times because we know each mill has 2 other positions
				if (gamePositions[millToCheck.at(0)].getPlayerOccupy() == 1) {
					if (gamePositions[millToCheck.at(1)].getPlayerOccupy() != 2) {   //make sure that there is a spot open for mill, or else that move is not good
						flag++;
						score += 3;
					}
				}
				else if (gamePositions[millToCheck.at(1)].getPlayerOccupy() == 1) {
					if (gamePositions[millToCheck.at(0)].getPlayerOccupy() != 2) {
						flag++;
						score += 3;
					}
				}
			}
			if (flag == 2) {  //this means two way mill was made possible
				score += 3;
			}
		}
	}

	//check if move was blocked
	/*if(Player == 2){
	if(positionLastPlacedP2 != -1 && positionLastPlacedP1 != -1){
	//for every adjacent position, if it is the opposing player, check all adjacent pieces of that position
	//for that position, if all of its adjacent pieces blocks it from moving (current player), then we add to score
	for(int i = 0; i < gamePositions[positionLastPlacedP2].getAdjacentPositions().size(); i++){
	if(gamePositions[gamePositions[positionLastPlacedP2].getAdjacentPositions().at(i)].getPlayerOccupy() == 1){
	//check the adjacent positions of that, to see if its blocked
	int newPositionToCheck = gamePositions[positionLastPlacedP2].getAdjacentPositions().at(i);
	for(int j = 0; j < gamePositions[newPositionToCheck].getAdjacentPositions().size(); j++){
	if(gamePositions[newPositionToCheck].getAdjacentPositions().at(j) == 2){
	counter++;
	if(counter == gamePositions[newPositionToCheck].getAdjacentPositions().size()){
	score += 5;
	}
	}
	}
	}
	}
	}
	}
	else{
	if(positionLastPlacedP2 != -1 && positionLastPlacedP1 != -1){
	for(int i = 0; i < gamePositions[positionLastPlacedP1].getAdjacentPositions().size(); i++){
	if(gamePositions[gamePositions[positionLastPlacedP1].getAdjacentPositions().at(i)].getPlayerOccupy() == 2){
	//check the adjacent positions of that, to see if its blocked
	int newPositionToCheck = gamePositions[positionLastPlacedP1].getAdjacentPositions().at(i);
	for(int j = 0; j < gamePositions[newPositionToCheck].getAdjacentPositions().size(); j++){
	if(gamePositions[newPositionToCheck].getAdjacentPositions().at(j) == 1){
	counter++;
	if(counter == gamePositions[newPositionToCheck].getAdjacentPositions().size()){
	score += 5;
	}
	}
	}
	}
	}
	}
	}*/

	//count to see if you have more pieces than the opponent (this is needed so the AI can place a move despite not having any initial benefit)
	if (phase == 1) {
		counter = 0;
		for (int i = 0; i < 24; i++) {
			if (gamePositions[i].getPlayerOccupy() == Player) {
				counter++;
			}
			else if (gamePositions[i].getPlayerOccupy() != 0) {
				counter--;
			}
		}
		if (counter > 0) {
			score += 1;
		}
		else if (counter == 0) {
			score += 1;
		}
		else {
			score += 0;
		}
	}

	//see if its a winning move
	if (phase == 3) {
		counter = 0;
		for (int i = 0; i < 24; i++) {
			if (gamePositions[i].getPlayerOccupy() != Player && gamePositions[i].getPlayerOccupy() != 0) {    //if opposing player's total token count is less than 3
				counter++;
			}
		}
		if (counter < 3) {
			score += 50;
		}
	}
	counter = 0;

	return score;
}

//player 2 = AI(max player), player 1 = Human(min player)
vector<Board> Board::generateBoard(int Player, int phase) {
	//temp vector used to store boards as we generate them
	vector<Board> temp_vec;

	//different possible boards for each, we assuming maximizing player is player 1
	if (phase == 1) {	//phase 1
		for (int i = 0; i < 24; i++) {
			if (gamePositions[i].getPlayerOccupy() == 0) {		//find the open spot and put the maximizingplayer's token on it
				Board newBoard(gamePositions, positionLastPlacedP1, positionLastPlacedP2);
				//used to create new object to put into vector
				newBoard.setBoard(i, Player);		//change the location where we found the empty spot and put the player's token
				newBoard.setPositionLastPlaced(i, Player);
				temp_vec.push_back(newBoard);	//add this instance to the vector
			}
		}

		return temp_vec;
	}
	else if (phase == 2) {	//phase 2
		for (int i = 0; i < 24; i++) {
			if (gamePositions[i].getPlayerOccupy() == Player) {	//if there is a token on the piece
				for (int j = 0; j < gamePositions[i].getAdjacentPositions().size(); j++) { //get the adjacent positions
					if (gamePositions[gamePositions[i].getAdjacentPositions().at(j)].getPlayerOccupy() == 0) {	//find the board of the adjacent positions
						Board newBoard(gamePositions, positionLastPlacedP1, positionLastPlacedP2);
						newBoard.setBoard(i, 0);	//set the position of the desired token that we want to move, to 0
						newBoard.setBoard(gamePositions[i].getAdjacentPositions().at(j), Player);	//set the adjacent position to maximizing player
						newBoard.setPositionLastPlaced(gamePositions[i].getAdjacentPositions().at(j), Player);
						temp_vec.push_back(newBoard);
					}
				}
			}
		}
		return temp_vec;
	}
	else {	//phase 3
		for (int i = 0; i < 24; i++) {
			if (gamePositions[i].getPlayerOccupy() == Player) {
				for (int j = 0; j < 24; j++) {	//for each spot that is empty, you can generate a board for it
					if (gamePositions[j].getPlayerOccupy() == 0) {
						Board newBoard(gamePositions, positionLastPlacedP1, positionLastPlacedP2);
						newBoard.setBoard(i, 0);
						newBoard.setBoard(j, Player);
						newBoard.setPositionLastPlaced(j, Player);
						temp_vec.push_back(newBoard);
					}
				}
			}
		}
		return temp_vec;
	}

	//if removing phase, generate possible removes

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
