#pragma once
#ifndef NODE_H
#define NODE_H
#include <vector>

using namespace std;

class Node {
public:
	Node(bool isOccupied = false, int position = -1, int playerOccupy = -1);
	bool getIsOccupied();	//getter for isOccupied
	void setIsOccupied(bool occupy);	//setter for isOccupied
	int getPosition();	//getter for position, no setter, does not need to change
	int getPlayerOccupy();	//getter for playerOccupy
	void setPlayerOccupy(int player);	//setter for playerOccupy
	vector<vector<int>> getMills();
	vector<int> getAdjacentPositions();

private:
	bool isOccupied;
	int position;
	int playerOccupy;
	vector<vector<int>> possibleMills;
	vector<int> adjacentPositions;
};

#endif
