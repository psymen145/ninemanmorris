#include "Node.h"

using namespace std;

Node::Node(bool isOccupied, int position, int playerOccupy) :isOccupied(isOccupied),
position(position), playerOccupy(playerOccupy) {
    
    vector<int> mill1;
    vector<int> mill2;
    
    //given the following token, the valid positions are:
    if (position == 0) {
        mill1.push_back(1);
        mill1.push_back(2);
        mill2.push_back(9);
        mill2.push_back(21);
        
        adjacentPositions.push_back(1);
        adjacentPositions.push_back(9);
    }
    else if (position == 1) {
        mill1.push_back(0);
        mill1.push_back(2);
        mill2.push_back(4);
        mill2.push_back(7);
        
        adjacentPositions.push_back(0);
        adjacentPositions.push_back(4);
        adjacentPositions.push_back(2);
    }
    else if (position == 2) {
        mill1.push_back(0);
        mill1.push_back(1);
        mill2.push_back(14);
        mill2.push_back(23);
        
        adjacentPositions.push_back(1);
        adjacentPositions.push_back(14);
    }
    else if (position == 3) {
        mill1.push_back(4);
        mill1.push_back(5);
        mill2.push_back(10);
        mill2.push_back(18);
        
        adjacentPositions.push_back(4);
        adjacentPositions.push_back(10);
    }
    else if (position == 4) {
        mill1.push_back(1);
        mill1.push_back(7);
        mill2.push_back(3);
        mill2.push_back(5);
        
        adjacentPositions.push_back(1);
        adjacentPositions.push_back(4);
        adjacentPositions.push_back(5);
        adjacentPositions.push_back(7);
    }
    else if (position == 5) {
        mill1.push_back(3);
        mill1.push_back(4);
        mill2.push_back(13);
        mill2.push_back(20);
        
        adjacentPositions.push_back(4);
        adjacentPositions.push_back(13);
    }
    else if (position == 6) {
        mill1.push_back(7);
        mill1.push_back(8);
        mill2.push_back(11);
        mill2.push_back(15);
        
        adjacentPositions.push_back(7);
        adjacentPositions.push_back(11);
    }
    else if (position == 7) {
        mill1.push_back(1);
        mill1.push_back(4);
        mill2.push_back(6);
        mill2.push_back(8);
        
        adjacentPositions.push_back(6);
        adjacentPositions.push_back(4);
        adjacentPositions.push_back(8);
    }
    else if (position == 8) {
        mill1.push_back(6);
        mill1.push_back(7);
        mill2.push_back(12);
        mill2.push_back(17);
        
        adjacentPositions.push_back(7);
        adjacentPositions.push_back(12);
    }
    else if (position == 9) {
        mill1.push_back(0);
        mill1.push_back(21);
        mill2.push_back(10);
        mill2.push_back(11);
        
        adjacentPositions.push_back(0);
        adjacentPositions.push_back(21);
        adjacentPositions.push_back(10);
    }
    else if (position == 10) {
        mill1.push_back(9);
        mill1.push_back(11);
        mill2.push_back(3);
        mill2.push_back(18);
        
        adjacentPositions.push_back(3);
        adjacentPositions.push_back(18);
        adjacentPositions.push_back(9);
        adjacentPositions.push_back(11);
    }
    else if (position == 11) {
        mill1.push_back(6);
        mill1.push_back(15);
        mill2.push_back(9);
        mill2.push_back(10);
        
        adjacentPositions.push_back(6);
        adjacentPositions.push_back(15);
        adjacentPositions.push_back(10);
    }
    else if (position == 12) {
        mill1.push_back(8);
        mill1.push_back(17);
        mill2.push_back(13);
        mill2.push_back(14);
        
        adjacentPositions.push_back(8);
        adjacentPositions.push_back(17);
        adjacentPositions.push_back(13);
    }
    else if (position == 13) {
        mill1.push_back(5);
        mill1.push_back(20);
        mill2.push_back(12);
        mill2.push_back(14);
        
        adjacentPositions.push_back(5);
        adjacentPositions.push_back(12);
        adjacentPositions.push_back(14);
        adjacentPositions.push_back(20);
    }
    else if (position == 14) {
        mill1.push_back(2);
        mill1.push_back(23);
        mill2.push_back(12);
        mill2.push_back(13);
        
        adjacentPositions.push_back(2);
        adjacentPositions.push_back(13);
        adjacentPositions.push_back(23);
    }
    else if (position == 15) {
        mill1.push_back(6);
        mill1.push_back(11);
        mill2.push_back(16);
        mill2.push_back(17);
        
        adjacentPositions.push_back(11);
        adjacentPositions.push_back(16);
    }
    else if (position == 16) {
        mill1.push_back(15);
        mill1.push_back(17);
        mill2.push_back(18);
        mill2.push_back(22);
        
        adjacentPositions.push_back(15);
        adjacentPositions.push_back(17);
        adjacentPositions.push_back(19);
    }
    else if (position == 17) {
        mill1.push_back(15);
        mill1.push_back(16);
        mill2.push_back(8);
        mill2.push_back(12);
        
        adjacentPositions.push_back(12);
        adjacentPositions.push_back(16);
    }
    else if (position == 18) {
        mill1.push_back(3);
        mill1.push_back(10);
        mill2.push_back(19);
        mill2.push_back(20);
        
        adjacentPositions.push_back(10);
        adjacentPositions.push_back(19);
    }
    else if (position == 19) {
        mill1.push_back(16);
        mill1.push_back(22);
        mill2.push_back(18);
        mill2.push_back(20);
        
        adjacentPositions.push_back(18);
        adjacentPositions.push_back(16);
        adjacentPositions.push_back(20);
        adjacentPositions.push_back(22);
    }
    else if (position == 20) {
        mill1.push_back(5);
        mill1.push_back(13);
        mill2.push_back(18);
        mill2.push_back(19);
        
        adjacentPositions.push_back(13);
        adjacentPositions.push_back(19);
    }
    else if (position == 21) {
        mill1.push_back(22);
        mill1.push_back(23);
        mill2.push_back(0);
        mill2.push_back(9);
        
        adjacentPositions.push_back(9);
        adjacentPositions.push_back(22);
    }
    else if (position == 22) {
        mill1.push_back(21);
        mill1.push_back(23);
        mill2.push_back(16);
        mill2.push_back(19);
        
        adjacentPositions.push_back(19);
        adjacentPositions.push_back(21);
        adjacentPositions.push_back(23);
    }
    else if (position == 23) {
        mill1.push_back(2);
        mill1.push_back(14);
        mill2.push_back(21);
        mill2.push_back(22);
        
        adjacentPositions.push_back(14);
        adjacentPositions.push_back(22);
    }
    
    possibleMills.push_back(mill1);
    possibleMills.push_back(mill2);
}

bool Node::getIsOccupied() {
    return isOccupied;
}

void Node::setIsOccupied(bool occupy) {
    isOccupied = occupy;
}

int Node::getPosition() {
    return position;
}

int Node::getPlayerOccupy() {
    return playerOccupy;
}

void Node::setPlayerOccupy(int player) {
    playerOccupy = player;
}

vector<vector<int>> Node::getMills() {
    return possibleMills;
}

vector<int> Node::getAdjacentPositions() {
    return adjacentPositions;
}
