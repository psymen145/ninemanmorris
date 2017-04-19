
#include "board.h"
#include "nineman.h"
#include <stdlib.h>
#include <iostream>
#include <time.h>

using namespace std;

int main() {
	int CurrentPlayer;
	srand(time(NULL));  //so rand() will generate random number
	int token = -1;  //used to hold player's token choice
	int moveToPosition = -1;
	int flag = 0;   //1 if the player can go again
	char humanOrAI;

	NineManMorris NineManGame;

	cout << "NINE MAN MORRIS\n--------------------------------" << endl;

	//ask user if they want to play with human or AI
	cout << "HUMAN VS HUMAN (Press 'h')\nHUMAN VS AI (Press 'a')" << endl;
	cin >> humanOrAI;

	NineManGame.display();

	//determine which player goes first
	if (rand() % 2 == 0) {
		CurrentPlayer = 1;
		cout << "Player 1 goes first!\n" << endl;
	}
	else {
		CurrentPlayer = 2;
		cout << "Player 2 goes first!\n" << endl;
	}

	//while the game is not over, keep playing
	while (!NineManGame.isGameOver()) {
		if (NineManGame.getPhase() == 1) {
			cout << "[Phase 1]: Player " << CurrentPlayer << " which position would you want to place your token: " << endl;
			cin >> moveToPosition;

			if (NineManGame.isValid(CurrentPlayer, token, moveToPosition)) {
				NineManGame.play(CurrentPlayer, -1, moveToPosition);

				//tell player how many tokens they have left in hand
				if (CurrentPlayer == 1) {
					cout << "\nPlayer " << CurrentPlayer << " you have " << NineManGame.getNumTokensP1() << " tokens remaining in your hand\n" << endl;
				}
				else {
					cout << "\nPlayer " << CurrentPlayer << " you have " << NineManGame.getNumTokensP2() << " tokens remaining in your hand\n" << endl;
				}

			}
			else {
				cout << "Invalid Move!" << endl;
				flag = 1;
			}
		}
		else if (NineManGame.getPhase() == 2) {
			cout << "[Phase 2]: Player " << CurrentPlayer << " which token would you like to move: " << endl;
			cin >> token;
			cout << "Where would you like to move the token: " << endl;
			cin >> moveToPosition;

			if (NineManGame.isValid(CurrentPlayer, token, moveToPosition)) {
				NineManGame.play(CurrentPlayer, token, moveToPosition);
			}
			else {
				cout << "Invalid Move!" << endl;
				flag = 1;
			}
		}
		else if (NineManGame.getPhase() == 3) {
			cout << "[Phase 3]: Player " << CurrentPlayer << " which token would you like to move: " << endl;
			cin >> token;
			cout << "Where would you like to move the token: " << endl;
			cin >> moveToPosition;
			if (NineManGame.isValid(CurrentPlayer, token, moveToPosition)) {
				NineManGame.play(CurrentPlayer, token, moveToPosition);
			}
			else {
				cout << "Invalid Move!" << endl;
				flag = 1;
			}
		}

		//check if there is a triple only if move was valid (indicated by flag still being 0)
		if (flag == 0) {
			NineManGame.checkTriple(CurrentPlayer, moveToPosition);
		}

		//display board after move
		NineManGame.display();

		//switch players only if there is no flag
		if (CurrentPlayer == 1 && flag == 0) {
			CurrentPlayer = 2;
		}
		else if (CurrentPlayer == 2 && flag == 0) {
			CurrentPlayer = 1;
		}

		//reset the flag after each turn
		flag = 0;

		//check if it is time to switch turns
		//changes to phase 2
		//also have to make sure that we don't keep changing back to phase 2 after we changed to phase 3
		if (NineManGame.getNumTokensP1() == 0 && NineManGame.getNumTokensP2() == 0 && NineManGame.getPhase() == 1) {
			cout << "------------------------------------------\n\t\tPHASE 2\n------------------------------------------\n" << endl;
			NineManGame.setPhase(2);
		}

		//changes to phase 3 if a player has 3 or less pieces
		if (NineManGame.getTokensPlaced(CurrentPlayer) <= 3 && NineManGame.getPhase() == 2) {
			cout << "------------------------------------------\n\t\tPHASE 3\n------------------------------------------\n" << endl;
			NineManGame.setPhase(3);
		}
		else if(NineManGame.getTokensPlaced(CurrentPlayer) > 3 && NineManGame.getPhase() == 3) {
			cout << "------------------------------------------\n\t\tPHASE 2\n------------------------------------------\n" << endl;
			NineManGame.setPhase(2);
		}
	}

	cout << "\n----------GAME OVER----------" << endl;
	if (CurrentPlayer == 1) {	//player 2 has won and not player 1 because we switched players at the end of the while loop
		cout << "\t\tPlayer 2 has won!" << endl;
	}
	else {
		cout << "\t\tPlayer 1 has won!" << endl;
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
