#pragma once
#include <iostream>
#include <list>
#include <algorithm>
#include <vector>

using namespace std;

class AlphaBetaClass {
public:

	//constructor
	AlphaBetaClass():winBoardValue(1000), endNodeValue(10000), infinity(1001) {}

	//determine heuristic value of board
	int evaluateBoard() {
		return 0;
	};

	int alphabeta(GameState node, int depth, int alpha, int beta, bool maximizingPlayer) {
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
					break;		//beta cut - off)
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
	}
private:
	int winBoardValue;
	int endNodeValue;
	int infinity;
}