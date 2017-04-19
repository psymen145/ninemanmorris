#ifndef nineman_h
#define nineman_h
#include "board.h"
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class NineManMorris{
public:
    
    NineManMorris();
    void display();
    
    //determine if there is a winner
    bool isGameOver();
    
    void play(int player, int token, int MoveTo);
    
    bool isValid(int player, int token, int position);
    
    int getPhase();
    void setPhase(int p);
    
    //getter/setter for number of tokens for player 1
    int getNumTokensP1();
    void setNumTokensP1(int RemoveAdd);
    
    //getter/setter for number of tokens for player 2
    int getNumTokensP2();
    void setNumTokensP2(int RemoveAdd);
    
    //check if move made three
    bool checkTriple(int currentplayer, int spot);
    
    //alphabeta prunning for the AI
    //int alphabeta(GameState node, int depth, int alpha, int beta, bool maximizingPlayer);
    
private:
    board Game;
    int phase;  //determines if its placing stage, moving stage or flying stage
    int numOfTokensInHandP1;
    int numOfTokensInHandP2;
};

#endif
