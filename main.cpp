#include "stdafx.h"
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
	char humanOrAI; //determine what type of game it's going to be
	bool playInput = true;  //determine if user made a valid choice (a or h)
	char playAgain;     //used to ask if user wants to play again

	NineManMorris NineManGame;

	cout << "NINE MAN MORRIS\n--------------------------------" << endl;

	do {

		//ask user if they want to play with human or AI
		cout << "HUMAN VS HUMAN (Press 'h')\nHUMAN VS AI (Press 'a') ";
		cin >> humanOrAI;
		humanOrAI = toupper(humanOrAI);

		//determine type of game
		switch (humanOrAI) {

		case 'H':   //Human Game

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
					cout << "[Phase 1]: Player " << CurrentPlayer << " which position would you want to place your token: ";
					cin >> moveToPosition;

					if (NineManGame.isValid(CurrentPlayer, token, moveToPosition)) {
						NineManGame.play(CurrentPlayer, -1, moveToPosition,0);

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
					cout << "[Phase 2]: Player " << CurrentPlayer << " which token would you like to move: ";
					cin >> token;
					cout << endl << "Where would you like to move the token: ";
					cin >> moveToPosition;

					if (NineManGame.isValid(CurrentPlayer, token, moveToPosition)) {
						NineManGame.play(CurrentPlayer, token, moveToPosition,0);
					}
					else {
						cout << "\nInvalid Move!" << endl;
						flag = 1;
					}
				}
				else if (NineManGame.getPhase() == 3) {
					cout << "[Phase 3]: Player " << CurrentPlayer << " which token would you like to move: ";
					cin >> token;
					cout << endl << "Where would you like to move the token: ";
					cin >> moveToPosition;
					if (NineManGame.isValid(CurrentPlayer, token, moveToPosition)) {
						NineManGame.play(CurrentPlayer, token, moveToPosition,0);
					}
					else {
						cout << "\nInvalid Move!" << endl;
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

				//check if it is time to switch phases
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
				else if (NineManGame.getTokensPlaced(CurrentPlayer) > 3 && NineManGame.getPhase() == 3) {
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

			cout << "Play again? (Press 'y'): ";    //ask if user wants to play again
			cin >> playAgain;
			playAgain = toupper(playAgain);

			if (playAgain == 'Y') {
				playInput = true;
			}
			else {
				playInput = false;
			}

			break;

		case 'A':   //AI Game

			NineManGame.display();

			//determine which player goes first
			if (rand() % 2 == 0) {
				CurrentPlayer = 1;
				cout << "Player 1 goes first!\n" << endl;
			}
			else {
				CurrentPlayer = 2;
				cout << "AI goes first!\n" << endl;
			}

			while (!NineManGame.isGameOver()) {     //keep playing if game isn't over
				if (CurrentPlayer == 1) {
					if (NineManGame.getPhase() == 1) {
						cout << "[Phase 1]: Player which position would you want to place your token: ";
						cin >> moveToPosition;

						if (NineManGame.isValid(CurrentPlayer, token, moveToPosition)) {
							NineManGame.play(CurrentPlayer, -1, moveToPosition,0);

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
					else if (NineManGame.getPhase() == 2) {	//check if phase 2
						cout << "[Phase 2]: Player " << CurrentPlayer << " which token would you like to move: ";
						cin >> token;
						cout << endl << "Where would you like to move the token: ";
						cin >> moveToPosition;

						if (NineManGame.isValid(CurrentPlayer, token, moveToPosition)) {
							NineManGame.play(CurrentPlayer, token, moveToPosition,0);
						}
						else {
							cout << "\nInvalid Move!" << endl;
							flag = 1;
						}
					}
					else if (NineManGame.getPhase() == 3) {	//check if phase 3
						cout << "[Phase 3]: Player " << CurrentPlayer << " which token would you like to move: ";
						cin >> token;
						cout << endl << "Where would you like to move the token: ";
						cin >> moveToPosition;
						if (NineManGame.isValid(CurrentPlayer, token, moveToPosition)) {
							NineManGame.play(CurrentPlayer, token, moveToPosition,0);
						}
						else {
							cout << "\nInvalid Move!" << endl;
							flag = 1;
						}
					}

					//check if there is a triple only if move was valid (indicated by flag still being 0)
					if (flag == 0) {
						if (NineManGame.checkTriple(CurrentPlayer, moveToPosition)) {
							int desiredRemove;

							cout << "Which piece would you like to remove: ";
							cin >> desiredRemove;


							while (!NineManGame.play(0, desiredRemove, 0, 1)) {
								cout << "Please enter a valid piece: ";
								cin >> desiredRemove;
							}

							NineManGame.play(0, desiredRemove, 0, 1);
						}
					}

					//display board after move
					NineManGame.display();

					//switch players only if there is no flag
					if (flag == 0) {
						CurrentPlayer = 2;
					}

					//reset the flag after each turn
					flag = 0;

					//check if it is time to switch phases
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
					else if (NineManGame.getTokensPlaced(CurrentPlayer) > 3 && NineManGame.getPhase() == 3) {
						cout << "------------------------------------------\n\t\tPHASE 2\n------------------------------------------\n" << endl;
						NineManGame.setPhase(2);
					}

				}
				else {
					cout << "\n--------AI's turn--------" << endl;

					int moveMade;
					moveMade = NineManGame.playAI();

					//check if triple was made from the move
					if (NineManGame.checkTriple(2, moveMade)) {
						cout << "AI removing a piece..." << endl;
						NineManGame.playAIRemove();
					}

					NineManGame.display();

					//switch players only if there is no flag

					CurrentPlayer = 1;
	
				}

			}

			cout << "Play again? (Press 'y'): ";    //ask if user wants to play again
			cin >> playAgain;
			playAgain = toupper(playAgain);

			if (playAgain == 'Y') {
				playInput = true;
			}
			else {
				playInput = false;
			}

			break;

		default:

			cout << "Please enter a valid command\n" << endl;
			playInput = true;
		}

	} while (playInput);



	return 0;
}
