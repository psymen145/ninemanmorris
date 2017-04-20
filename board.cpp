#include "Board.h"
#include <algorithm>
#include <iostream>

using namespace std;

Board::Board(int arr[]) {
    
    if (arr == NULL) {
        for (int i = 0; i < 24; i++) {
            gameboard[i] = 0;
        }
    }
    else {
        copy(arr, arr + 24, gameboard);
    }
    
}

int Board::getBoard(int position) {
    
    return gameboard[position];
    
}

void Board::setBoard(int location, int player) {
    
    gameboard[location] = player;
    
}


bool Board::adjacentPositions(int token, int position) {
    
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

void Board::displayBoard() {
    
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

int Board::evaluateBoard(int maximizingPlayer, int phase) {
    
    if(phase == 1) {
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
                if(gameboard[i] == 0) {		//find the open spot and put the maximizingplayer's token on it
                    Board newBoard(gameboard);		//used to create new object to put into vector
                    newBoard.setBoard(i,1);			//change the location where we found the empty spot and put the player's token
                    temp_vec.push_back(newBoard);	//add this instance to the vector
                }
            }
            
            return temp_vec;
        }
        else if (phase == 2) {	//phase 2
            for(int i = 0; i < 24; i++){    //for each 1, it can slide to adjacent pieces
                if(gameboard[i] == 1){
                    //check if adjacent spots are empty, if it is then move token there and generate the board and push into vector
                    switch(i){
                        case 1:
                            if(gameboard[] == 0){
                                Board newBoard(gameboard);
                                newBoard.setBoard(i,0);
                            }
                            break;
                        case 2:
                            break;
                        case 3:
                            break;
                        case 4:
                            break;
                        case 5:
                            break;
                        case 6:
                            break;
                        case 7:
                            break;
                        case 8:
                            break;
                        case 9:
                            break;
                        case 10:
                            break;
                        case 11:
                            break;
                        case 12:
                            break;
                        case 13:
                            break;
                        case 14:
                            break;
                        case 15:
                            break;
                        case 16:
                            break;
                        case 17:
                            break;
                        case 18:
                            break;
                        case 19:
                            break;
                        case 20:
                            break;
                        case 21:
                            break;
                        case 22:
                            break;
                        case 23:
                            break;
                        default:
                            
                    }
                }
            }
        }
        else {	//phase 3
            
        }
        
    }
    else {
        return temp_vec;
    }
}
