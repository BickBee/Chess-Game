#include <iostream>
#include "board.h"
#include "piece.h"
#include "queen.h"
#include "king.h"
#include "knight.h"
#include "pawn.h"
#include "rook.h"
#include "bishop.h"
#include "game.h"
#include "player.h"
#include "human.h"
#include "computerPlayer1.h"
#include "textDisplay.h"
#include "observer.h"
#include "subject.h"
#include "graphicDisplay.h"
#include "window.h"

using namespace std;

// translates command line coordinates to our coordinate system
int translateCoordinate(char c) {
    if ('a' <= c && c <= 'h') {
        return (int)c - 'a';
    } else if (c == '8') {
        return 0;
    } else if (c == '7') {
        return 1;
    } else if (c == '6') {
        return 2;
    } else if (c == '5') {
        return 3;
    } else if (c == '4') {
        return 4;
    } else if (c == '3') {
        return 5;
    } else if (c == '2') {
        return 6;
    } else if (c == '1') {
        return 7;
    } else {
        return -1;
    }
}

int main() {
	bool valid_move;
	bool in_game = false;
	bool is_default_board = true;
	int xFrom, xTo, yFrom, yTo;
        string cmd, fromCoor, toCoor, player1, player2;
	bool PlayerOneIsComputer;
	bool PlayerTwoIsComputer;
	bool validCommand;
	unique_ptr<Game> new_game = make_unique<Game>(0);
	vector<unique_ptr<Observer>> allObservers;
	int player1Score = 0;
	int player2Score = 0;

	//unique_ptr<Xwindow> myWindow;

	//allObservers.emplace_back( new TextDisplay(new_game.get()) );
	//TextDisplay * myTextDisplay = new TextDisplay(new_game.get());
   	//cout << allObservers.size() << endl;
	//allObservers.push_back(myTextDisplay);
	//cout << allObservers.size() << endl;

	cout << "Welcome to our game of Chess!" << endl;

	while (cin.eof() != true) {
		validCommand = true;
		if (in_game) {
			//new_game->getBoard()->printBoard();
			new_game->render();
			cout << "\nPlayer " << new_game->getTurn() + 1 << "'s Turn: ";
		} else {
			cout << "Enter a Command: ";
		}

		if (!(cin >> cmd)) {
			break;
		}

		if ((cmd == "game") && (!in_game)) {
			cin >> player1 >> player2;
			
			if (player1 == "human") {
				PlayerOneIsComputer = false;
			} else {
				PlayerOneIsComputer = true;
			}

			if (player2 == "human") {
				PlayerTwoIsComputer = false;
			} else {
				PlayerTwoIsComputer = true;
			}
			
			if (is_default_board) {
				//cout << "default board" << endl;
				new_game = make_unique<Game>(0);
				//cout << "new game" << endl;
				allObservers.emplace_back(make_unique<TextDisplay>(new_game.get()));
				//cout << "here" << endl;
				/*unique_ptr<Xwindow>*/ //myWindow = make_unique<Xwindow>(500, 500);
				//allObservers.emplace_back(make_unique<GraphicDisplay>(new_game.get(), myWindow.get()));
				new_game->addPlayers(player1, player2);

				//cout << "player " << new_game->getPlayer()->getPieceColour() << endl;

				new_game->getBoard()->createDefault();
			} else {
				new_game->addPlayers(player1, player2);
			}
			in_game = true;
		} else if ((cmd == "resign") && (in_game)) {
			if (new_game->getTurn() == 0) {
				cout << "Player 1 Has Resigned." << endl;
				player2Score++;
			} else if (new_game->getTurn() == 1) {
				cout << "Player 2 Has Resigned." << endl;
				player1Score++;
			}
			in_game = false;
			//cout << "+++++++++++++++++++++++++++++++++++++++++++++" << endl;
		} else if ((cmd == "move") && (in_game)) {
			cin >> fromCoor;
			cin >> toCoor;

			if (cin.eof() == true) {
					break;
			}

			xFrom = translateCoordinate(fromCoor[0]);
			yFrom = translateCoordinate(fromCoor[1]);
			xTo = translateCoordinate(toCoor[0]);
			yTo = translateCoordinate(toCoor[1]);

			valid_move = new_game->getPlayer()->makeMove(new_game->getBoard(), xFrom, yFrom, xTo, yTo, new_game->getPreviousMoves());

			if (!valid_move) {
					cout << "INVALID MOVE!" << endl;
			} else {
						
				new_game->incrementTurn();
				//cout <<

				// Print Checkmate, Check and Stalemate
				if (new_game->isCheckmated()) {
					cout << "+++++++++++++++++++++++++++++++++++++++++++++" << endl;
					//new_game->getBoard()->printBoard();
					new_game->render();
					if (new_game->getTurn() == 0) {
						cout << "Checkmate! Player 2 wins!" << endl;
					} else if (new_game->getTurn() == 1) {
							cout << "Checkmate! Player 1 wins!" << endl;
					}
					in_game = false;
				} else if (new_game->isChecked()) {
						if (new_game->getTurn() == 0) {
							cout << "Player 1 is in check." << endl;
						} else if (new_game->getTurn() == 1) {
								cout << "Player 2 is in check." << endl;
						}
				}/* else if (new_game->isStalemate()) {
					cout << "Stalemate!" << endl;
					in_game = false;
				}*/
				//cout << "+++++++++++++++++++++++++++++++++++++++++++++" << endl;

			}
		} else if ((cmd == "setup") && (!in_game)) {
			new_game = make_unique<Game>(0);
			allObservers.emplace_back(make_unique<TextDisplay>(new_game.get()));
			/*unique_ptr<Xwindow>*/ //myWindow = make_unique<Xwindow>(500, 500);
			//allObservers.emplace_back(make_unique<GraphicDisplay>(new_game.get(), myWindow.get()));
			new_game->createSetup();
			is_default_board = false;
		} else {
			validCommand = false;
			cout << "NOT A VALID COMMAND!" << endl;
			if (cmd == "game") {
				cout << "-- Cannot use 'game' while in a game --" << endl;
			} else if (cmd == "move") {
				cout << "-- Cannot use 'move' while not in a game --" << endl;
			} else if (cmd == "resign") {
				cout << "-- Cannot use 'resign' while not in a game --" << endl;
			} else if (cmd == "setup") {
				cout << "-- Cannot use 'setup' while in a game --" << endl;
			}
			//cout << "+++++++++++++++++++++++++++++++++++++++++++++" << endl;
		}

			//		cout << "player " << new_game->getPlayer()->getPieceColour() << endl;

		if (in_game) {
			//cout << "player " << new_game->getPlayer()->getPieceColour() << endl;

			//	cout << "turn " << new_game->getTurn() << endl;


			while (((new_game->getTurn() == 0) && (PlayerOneIsComputer)) || ((new_game->getTurn() == 1) && (PlayerTwoIsComputer)))  {
			//	cout << "hello" << endl;
				new_game->getPlayer()->makeMove(new_game->getBoard(), 0, 0, 0, 0, new_game->getPreviousMoves());

				new_game->incrementTurn();

				// Print Checkmate, Check and Stalemate
				if (new_game->isCheckmated()) {
					cout << "+++++++++++++++++++++++++++++++++++++++++++++" << endl;
					//new_game->getBoard()->printBoard();
					new_game->render();
					if (new_game->getTurn() == 0) {
						cout << "Checkmate! Player 2 wins!" << endl;
					} else if (new_game->getTurn() == 1) {
						cout << "Checkmate! Player 1 wins!" << endl;
					}
					in_game = false;

				} else if (new_game->isChecked()) {
					if (new_game->getTurn() == 0) {
						cout << "Player 1 is in check." << endl;
					} else if (new_game->getTurn() == 1) {
						cout << "Player 2 is in check." << endl;
					}
							}/* else if (new_game->isStalemate()) {
					cout << "Stalemate!" << endl;
					in_game = false;
				}*/
				//cout << "+++++++++++++++++++++++++++++++++++++++++++++" << endl;
			}
		}
	      // 	allObservers.emplace_back( new TextDisplay(new_game.get()) );
		cout << "+++++++++++++++++++++++++++++++++++++++++++++" << endl;
	}
	cout << "Final Score:\nWhite: " << player1Score << "\nBlack: " << player2Score << endl;
}
