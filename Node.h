#ifndef NODE_H
#define NODE_H
#include <vector>

using namespace std;

class Node {
public:
    Node();
    Node(int position, int playerOccupy = 0);
    int getPlayerOccupy();	//getter for playerOccupy
    void setPlayerOccupy(int player);	//setter for playerOccupy
    vector<vector<int>> getMills();
    vector<int> getAdjacentPositions();
    
private:
    int playerOccupy;
    vector<vector<int>> possibleMills;
    vector<int> adjacentPositions;
};

#endif
