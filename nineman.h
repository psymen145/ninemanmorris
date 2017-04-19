#pragma once

#ifndef nineman_h
#define nineman_h
#include "board.h"
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class NineManMorris {
public:

	NineManMorris();
	void display();		//same as board class display, used so main can call it
	bool isGameOver();	//return true if there's a winner
	void play(int player, int token, int MoveTo);	//finalizes the move onto the board
	bool isValid(int player, int token, int position);	//returns true if move is suffices all conditions
	int getPhase();
	void setPhase(int p);
	int getNumTokensP1();	//return the number of tokens in hand of P1
	int getNumTokensP2();	//return the number of tokens in hand of P2
	void checkTriple(int currentplayer, int spot);	//check if a three in a row 
	int getTokensPlaced(int player);	//returns how many tokens are placed on the board by parameter

	//alphabeta prunning for the AI
	int alphabeta(Board node, int depth, int alpha, int beta, bool maximizingPlayer);

private:
	Board board;
	int phase;  //determines if its placing stage, moving stage or flying stage
	int numOfTokensInHandP1;
	int numOfTokensInHandP2;
};

#endif
