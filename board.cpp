#include "board.h"
#include <iostream>

using namespace std;

board::board(){
    
    for(int i = 0; i < 24; i++){
        gameboard[i] = 0;
    }
    
}

int board::getBoard(int position){
    
    return gameboard[position];
    
}

void board::setBoard(int location, int player){
    
    gameboard[location] = player;
    
}


bool board::adjacentPositions(int token, int position){
    
    if(position == 0){
        if(token == 1 || token == 9){
            return true;
        }
        else{
            return false;
        }
    }
    else if(position == 1){
        if(token == 0 || token == 4){
            return true;
        }
        else{
            return false;
        }
    }
    else if(position == 2){
        if(token == 1 || token == 14){
            return true;
        }
        else{
            return false;
        }
    }
    else if(position == 3){
        if(token == 4 || token == 10){
            return true;
        }
        else{
            return false;
        }
    }
    else if(position == 4){
        if(token == 2 || token == 3 || token == 5 || token == 7){
            return true;
        }
        else{
            return false;
        }
    }
    else if(position == 5){
        if(token == 4 || token == 13){
            return true;
        }
        else{
            return false;
        }
    }
    else if(position == 6){
        if(token == 7 || token == 11){
            return true;
        }
        else{
            return false;
        }
    }
    else if(position == 7){
        if(token == 6|| token == 4 || token == 8){
            return true;
        }
        else{
            return false;
        }
    }
    else if(position == 8){
        if(token == 7 || token == 12){
            return true;
        }
        else{
            return false;
        }
    }
    else if(position == 9){
        if(token == 0 || token == 21){
            return true;
        }
        else{
            return false;
        }
    }
    else if(position == 10){
        if(token == 3 || token == 18){
            return true;
        }
        else{
            return false;
        }
    }
    else if(position == 11){
        if(token == 6 || token == 15 || token == 10){
            return true;
        }
        else{
            return false;
        }
    }
    else if(position == 12){
        if(token == 8 || token == 17){
            return true;
        }
        else{
            return false;
        }
    }
    else if(position == 13){
        if(token == 5 || token == 12 || token == 14 || token == 20){
            return true;
        }
        else{
            return false;
        }
    }
    else if(position == 14){
        if(token == 2 || token == 13 || token == 22){
            return true;
        }
        else{
            return false;
        }
    }
    else if(position == 15){
        if(token == 11 || token == 16){
            return true;
        }
        else{
            return false;
        }
    }
    else if(position == 16){
        if(token == 15 || token == 17 || token == 19){
            return true;
        }
        else{
            return false;
        }
    }
    else if(position == 17){
        if(token == 12|| token == 16){
            return true;
        }
        else{
            return false;
        }
    }
    else if(position == 18){
        if(token == 10 || token == 19){
            return true;
        }
        else{
            return false;
        }
    }
    else if(position == 19){
        if(token == 18 || token == 16 || token == 20 || token == 21){
            return true;
        }
        else{
            return false;
        }
    }
    else if(position == 20){
        if(token == 13 || token == 19){
            return true;
        }
        else{
            return false;
        }
    }
    else if(position == 21){
        if(token == 9 || token == 22){
            return true;
        }
        else{
            return false;
        }
    }
    else if(position == 22){
        if(token == 19 || token == 21 || token == 23){
            return true;
        }
        else{
            return false;
        }
    }
    else if(position == 23){
        if(token == 2 || token == 22){
            return true;
        }
        else{
            return false;
        }
    }
    
    return false;
}

void board::displayBoard(){
    
    for(int i = 0; i < 24; i++){
        
        //draws the top/bottom row of the board
        if(i < 2){
            cout << gameboard[i] << "---------";
        }
        
        //draw the middle top row of the board
        else if(i==2){
            cout << gameboard[i] << endl;
            cout << "|         |         |" << endl;
        }
        else if(i==3){
            cout << "|   " << gameboard[i] << "-----";
        }
        
        else if(i==4 || i==19){
            cout << gameboard[i] << "-----";
        }
        else if(i==5){
            cout << gameboard[i] << "   |" << endl;
            cout << "|   |     |     |   |" << endl;
        }
        else if(i==6 || i==15){
            cout << "|   |  " << gameboard[i];
        }
        else if(i==7 || i==16){
            cout << "--" << gameboard[i] << "--";
        }
        else if(i==8 || i==17){
            cout << gameboard[i] << "  |   |" << endl;
        }
        else if(i==9){
            cout << "|   |  |     |  |   |" << endl;
            cout << gameboard[i] << "---";
        }
        else if(i==10 || i==12){
            cout << gameboard[i] << "--";
        }
        else if(i==11){
            cout << gameboard[i] << "     ";
        }
        else if(i==13){
            cout << gameboard[i] << "---";
        }
        else if(i==14){
            cout << gameboard[i] << endl;
            cout << "|   |  |     |  |   |" << endl;
        }
        else if(i==18){
            cout << "|   |     |     |   |" << endl;
            cout << "|   " << gameboard[i] << "-----";
        }
        else if(i==20){
            cout << gameboard[i] << "   |" << endl;
            cout << "|         |         |" << endl;
        }
        else if(i==21 || i==22){
            cout << gameboard[i] << "---------";
        }
        else{
            cout << gameboard[i] << endl;
        }
    }
    
}

int board::getTokensPlacedP1(){
    
    //we should just go through the array and count how many 1s in the board
    int playerOneToken = 0;
    
    for(int i = 0; i < 24; i++){
        if(gameboard[i] == 1){
            playerOneToken++;
        }
    }
    
    return playerOneToken;
    
}


int board::getTokensPlacedP2(){
    
    //similar to method P1
    int playerTwoToken = 0;
    
    for(int i = 0; i < 24; i++){
        if(gameboard[i] == 2){
            playerTwoToken++;
        }
    }
    
    return playerTwoToken;
    
}

