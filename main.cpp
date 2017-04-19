#include "board.h"
#include "nineman.h"
#include <stdlib.h>
#include <iostream>

using namespace std;


int main(){
    int CurrentPlayer;
    srand(time(NULL));  //so rand() will generate random number
    int token = -1;  //used to hold player's token choice
    int moveToPosition = -1;
    int flag = 0;   //1 if the player can go again
    
    NineManMorris NineManGame;
    
    cout << "NINE MAN MORRIS" << endl;
    NineManGame.display();
    
    //determine which player goes first
    if( rand() % 2 == 0){
        CurrentPlayer = 1;
        cout << "Player 1 goes first!\n" << endl;
    }
    else{
        CurrentPlayer = 2;
        cout << "Player 2 goes first!\n" << endl;
    }
    
    //while the game is not over, keep playing
    while(!NineManGame.isGameOver()){
        if(NineManGame.getPhase() == 1){
            cout << "[Phase 1]: Player " << CurrentPlayer << " which position would you want to place your token: " << endl;
            cin >> moveToPosition;
            if(NineManGame.isValid(CurrentPlayer,token,moveToPosition)){
                NineManGame.play(CurrentPlayer,-1,moveToPosition);
            }
            else{
                flag = 1;
            }
        }
        else if(NineManGame.getPhase() == 2){
            cout << "[Phase 2]: Player " << CurrentPlayer << " which would token you like to move: " << endl;
            cin >> token;
            cout << "Where would you like to move the token: " << endl;
            cin >> moveToPosition;
            if(NineManGame.isValid(CurrentPlayer,token,moveToPosition)){
                NineManGame.play(CurrentPlayer,token,moveToPosition);
            }
            else{
                flag = 1;
            }
        }
        else if(NineManGame.getPhase() == 3){
            cout << "[Phase 3]: Player " << CurrentPlayer << " which token would you like to move: " << endl;
            cin >> token;
            cout << "Where would you like to move the token: " << endl;
            cin >> moveToPosition;
            if(NineManGame.isValid(CurrentPlayer,token,moveToPosition)){
                NineManGame.play(CurrentPlayer,token,moveToPosition);
            }
            else{
                flag = 1;
            }
        }
        
        //check if there is a triple
        NineManGame.checkTriple(CurrentPlayer, moveToPosition);
        
        //display board after move
        NineManGame.display();
        
        //switch players only if there is no flag
        if(CurrentPlayer == 1 && flag == 0){
            CurrentPlayer = 2;
        }
        else if(CurrentPlayer == 2 && flag == 0){
            CurrentPlayer = 1;
        }
        //reset the flag after each turn
        flag = 0;
    }
    //1 is human 2 is AI
    
    //Random number generator to determine who comes first
    
    //while checkWin returns false
    //while(!checkWin()){
        //player gets to move
        
        //checkwin, if win break
        //NineMan.checkWin();
        
        //next player gets to move
    
    return 0; 
}
