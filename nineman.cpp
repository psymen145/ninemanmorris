#include "nineman.h"
#include <iostream>

using namespace std;

NineManMorris::NineManMorris() :phase(1), numOfTokensInHandP1(9), numOfTokensInHandP2(9) {
    
}

void NineManMorris::display() {
    
    board.displayBoard();
    
}

bool NineManMorris::isGameOver() {
    
    //check if game is over by seeing if theres less than 3 pieces on the board
    //it also has to be in phase 3, or else this will read as game over in phase 1
    if (getTokensPlaced(1) < 3 && phase == 3) {
        return true;
    }
    else if (getTokensPlaced(2) < 3 && phase == 3) {
        return true;
    }
    
    //if a player gets trapped in phase 2 where a player slides pieces around
    
    return false;
    
}

//first checks if it is time to change phases
void NineManMorris::play(int player, int token, int MoveTo) {
    
    //placing stage
    if (phase == 1) {
        board.setBoard(MoveTo, player);
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
        board.setBoard(MoveTo, player);
        //remove the spot where the player's token originally was. This gives the image that the token is moving
        board.setBoard(token, 0);
    }
    else if (phase == 3) {
        //change the spot where the player wants to move to
        board.setBoard(MoveTo, player);
        //remove the spot where the player's token originally was. This gives the image that the token is moving
        board.setBoard(token, 0);
    }
}

//will check if move is valid first. If it is, then the board's function to actually complete the action is called
bool NineManMorris::isValid(int player, int token, int position) {
    
    //regardless of phase, the position that the token wants to go to has to be empty
    if (board.getBoard(position) != 0) {
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
            if (board.getBoard(token) != 1) {
                return false;
            }
            else {
                //returns true or false
                return board.adjacentPositions(token, position);
            }
        }
        else {		//player 2
            if (board.getBoard(token) != 2) {
                return false;
            }
            else {
                return board.adjacentPositions(token, position);
            }
        }
    }
    
    //phase 3 set of rules:
    //1. the spot they choose to get the token from has to be their token
    else if (phase == 3) {
        if (player == 1) {    //if player 1, we have to check the token they want to move is actually their token
            if (board.getBoard(token) == 1) {
                return true;
            }
        }
        if (player == 2) {    //same as player 1
            if (board.getBoard(token) == 2) {
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
        
        if ((board.getBoard(1) == currentplayer && board.getBoard(2) == currentplayer) || (board.getBoard(9) == currentplayer && board.getBoard(21) == currentplayer)) {
            flag = 1;
        }
    }
    else if (spot == 1) {
        
        if ((board.getBoard(0) == currentplayer && board.getBoard(2) == currentplayer) || (board.getBoard(4) == currentplayer && board.getBoard(7) == currentplayer)) {
            flag = 1;
        }
    }
    else if (spot == 2) {
        
        if ((board.getBoard(0) == currentplayer && board.getBoard(1) == currentplayer) || (board.getBoard(23) == currentplayer && board.getBoard(14) == currentplayer)) {
            flag = 1;
        }
    }
    else if (spot == 3) {
        
        if ((board.getBoard(4) == currentplayer && board.getBoard(5) == currentplayer) || (board.getBoard(10) == currentplayer && board.getBoard(18) == currentplayer)) {
            flag = 1;
        }
    }
    else if (spot == 4) {
        
        if ((board.getBoard(3) == currentplayer && board.getBoard(5) == currentplayer) || (board.getBoard(2) == currentplayer && board.getBoard(7) == currentplayer)) {
            flag = 1;
        }
    }
    else if (spot == 5) {
        
        if ((board.getBoard(3) == currentplayer && board.getBoard(4) == currentplayer) || (board.getBoard(13) == currentplayer && board.getBoard(20) == currentplayer)) {
            flag = 1;
        }
    }
    else if (spot == 6) {
        
        if ((board.getBoard(7) == currentplayer && board.getBoard(8) == currentplayer) || (board.getBoard(11) == currentplayer && board.getBoard(15) == currentplayer)) {
            flag = 1;
        }
    }
    else if (spot == 7) {
        
        if ((board.getBoard(6) == currentplayer && board.getBoard(8) == currentplayer) || (board.getBoard(1) == currentplayer && board.getBoard(4) == currentplayer)) {
            flag = 1;
        }
    }
    else if (spot == 8) {
        
        if ((board.getBoard(6) == currentplayer && board.getBoard(7) == currentplayer) || (board.getBoard(12) == currentplayer && board.getBoard(16) == currentplayer)) {
            flag = 1;
        }
    }
    else if (spot == 9) {
        
        if ((board.getBoard(10) == currentplayer && board.getBoard(11) == currentplayer) || (board.getBoard(0) == currentplayer && board.getBoard(21) == currentplayer)) {
            flag = 1;
        }
    }
    else if (spot == 10) {
        
        if ((board.getBoard(9) == currentplayer && board.getBoard(11) == currentplayer) || (board.getBoard(3) == currentplayer && board.getBoard(18) == currentplayer)) {
            flag = 1;
        }
    }
    else if (spot == 11) {
        
        if ((board.getBoard(15) == currentplayer && board.getBoard(6) == currentplayer) || (board.getBoard(9) == currentplayer && board.getBoard(10) == currentplayer)) {
            flag = 1;
        }
    }
    else if (spot == 12) {
        
        if ((board.getBoard(13) == currentplayer && board.getBoard(14) == currentplayer) || (board.getBoard(8) == currentplayer && board.getBoard(17) == currentplayer)) {
            flag = 1;
        }
    }
    else if (spot == 13) {
        
        if ((board.getBoard(12) == currentplayer && board.getBoard(14) == currentplayer) || (board.getBoard(20) == currentplayer && board.getBoard(5) == currentplayer)) {
            flag = 1;
        }
    }
    else if (spot == 14) {
        
        if ((board.getBoard(12) == currentplayer && board.getBoard(13) == currentplayer) || (board.getBoard(2) == currentplayer && board.getBoard(23) == currentplayer)) {
            flag = 1;
        }
    }
    else if (spot == 15) {
        
        if ((board.getBoard(6) == currentplayer && board.getBoard(11) == currentplayer) || (board.getBoard(16) == currentplayer && board.getBoard(17) == currentplayer)) {
            flag = 1;
        }
    }
    else if (spot == 16) {
        
        if ((board.getBoard(15) == currentplayer && board.getBoard(17) == currentplayer) || (board.getBoard(19) == currentplayer && board.getBoard(22) == currentplayer)) {
            flag = 1;
        }
    }
    else if (spot == 17) {
        
        if ((board.getBoard(15) == currentplayer && board.getBoard(16) == currentplayer) || (board.getBoard(8) == currentplayer && board.getBoard(12) == currentplayer)) {
            flag = 1;
        }
    }
    else if (spot == 18) {
        
        if ((board.getBoard(3) == currentplayer && board.getBoard(10) == currentplayer) || (board.getBoard(19) == currentplayer && board.getBoard(20) == currentplayer)) {
            flag = 1;
        }
    }
    else if (spot == 19) {
        
        if ((board.getBoard(18) == currentplayer && board.getBoard(20) == currentplayer) || (board.getBoard(22) == currentplayer && board.getBoard(16) == currentplayer)) {
            flag = 1;
        }
    }
    else if (spot == 20) {
        
        if ((board.getBoard(18) == currentplayer && board.getBoard(19) == currentplayer) || (board.getBoard(5) == currentplayer && board.getBoard(12) == currentplayer)) {
            flag = 1;
        }
    }
    else if (spot == 21) {
        
        if ((board.getBoard(0) == currentplayer && board.getBoard(9) == currentplayer) || (board.getBoard(22) == currentplayer && board.getBoard(23) == currentplayer)) {
            flag = 1;
        }
    }
    else if (spot == 22) {
        
        if ((board.getBoard(21) == currentplayer && board.getBoard(23) == currentplayer) || (board.getBoard(16) == currentplayer && board.getBoard(19) == currentplayer)) {
            flag = 1;
        }
    }
    else if (spot == 23) {
        
        if ((board.getBoard(2) == currentplayer && board.getBoard(14) == currentplayer) || (board.getBoard(22) == currentplayer && board.getBoard(21) == currentplayer)) {
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
                if (board.getBoard(desiredRemove) == 2) {
                    board.setBoard(desiredRemove, 0);
                    flag = 0;   //flag is 0, so we know a valid token is chosen to be removed
                }
            }
            else if (currentplayer == 2) {
                if (board.getBoard(desiredRemove) == 1) {
                    board.setBoard(desiredRemove, 0);
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
        if (board.getBoard(i) == player) {
            counter++;
        }
    }
    
    return counter;
}

int NineManMorris::alphabeta(Board node, int depth, int alpha, int beta, bool maximizingPlayer) {
	//v will be the value passed up the tree
	int v;
 
	//check if a player won in the given board node
	if (isGameOver) {
        return node.evaluateBoard(maximizingPlayer,getPhase());
	}
 
	//check if last node in branch
	if (depth == 0) {
        //return the heuristic value of node, this will generate the v value for the bottom node
        return node.evaluateBoard(phase);
	}
 
	if (maximizingPlayer) {
        v = INT_MIN;
 
        //generate all children
        vector<Board> possibleBoards = node.generateBoard();
 
        for(int i = 0; i < possibleBoards.size(); i++){
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
        vector<Board> possibleBoards = node.generateBoard();
 
        for (int i = 0; i < possibleBoards.size; i++) {
            v = min(v, alphabeta(possibleBoards.at(i), depth - 1, alpha, beta, true));
            beta = min(beta, v);
            if (beta <= alpha) {
                break;		//alpha cut - off
            }
        }
        return v;
	}
 }
