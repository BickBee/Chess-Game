#include "game.h"
#include <memory>
#include <vector>
#include <iostream>
using namespace std;

int translateCoordinate(char c);

// translates command line coordinates to our coordinate system
/* int translateCoordinate(char c) {
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
		return NULL;
	}
} */

Game::Game(int turn_par) :
	board{make_unique<Board>()}, turn{turn_par} 
{}

void Game::addPlayers(string white_player, string black_player) {
	if (white_player == "human") {
                players.emplace_back(make_unique<Human>("White"));
        } else if (white_player == "computer1") {
                players.emplace_back(make_unique<ComputerPlayer1>("White"));
        } else if (white_player == "computer2") {
                //players.emplace_back(make_unique<ComputerPlayer2>("White"));
        } else if (white_player == "computer3") {
                //players.emplace_back(make_unique<ComputerPlayer3>("White"));
        }

        if (black_player == "human") {
                players.emplace_back(make_unique<Human>("Black"));
        } else if (black_player == "computer1") {
                players.emplace_back(make_unique<ComputerPlayer1>("Black"));
        } else if (white_player == "computer2") {
                //players.emplace_back(make_unique<ComputerPlayer2>("Black"));
        } else if (white_player == "computer3") {
                //players.emplace_back(make_unique<ComputerPlayer3>("Black"));
        }
}

void Game::createSetup() {
	bool done = false;
	int xTo, yTo;
	string cmd, piece, toCoor, colour;
	while (!done) {
		cin >> cmd;
		if (cmd == "+") {
			cin >> piece;
			cin >> toCoor;
			xTo = translateCoordinate(toCoor[0]);
			yTo = translateCoordinate(toCoor[1]);
			board->placePiece(xTo, yTo, piece[0]);
			//board->printBoard();
			render();
		} else if (cmd == "-") {
			cin >> toCoor;
			xTo = translateCoordinate(toCoor[0]);
			yTo = translateCoordinate(toCoor[1]);
			if (board->getPiece(xTo, yTo) != nullptr) {
				board->removePiece(xTo, yTo);
			}
			//board->printBoard()
			render();
		} else if (cmd == "=") {
			cin >> colour;
			setTurn(colour);
		} else if (cmd == "done") {
			int numWhiteKings = 0;
			int numBlackKings = 0;
			bool invalidPawns = false;
			for (int i = 0; i < 8; ++i) { // row number -y
					for (int j = 0; j < 8; ++j) { //column number -x
						if (board->getPiece(j,i) != nullptr) {
							if (board->getPiece(j,i)->returnType() == 'K') {
								numWhiteKings++;
								board->setWhiteKingPointer(board->getPiece(j,i));
							} else if (board->getPiece(j,i)->returnType() == 'k') {
								numBlackKings++;
								board->setBlackKingPointer(board->getPiece(j,i));
							} 
							if (i == 0 || i == 7) {
								if (board->getPiece(j,i)->returnType() == 'p' || board->getPiece(j,i)->returnType() == 'P') {
									invalidPawns = true;
								}
							}
						}
					}
			}
			if (numBlackKings == 1 && numWhiteKings == 1 && invalidPawns == false) {
				if (board->getBlackKing()->canBeCaptured(board->getBoard(), board->getBlackKing()->returnCol(), board->getBlackKing()->returnRow()) == false && 
					board->getWhiteKing()->canBeCaptured(board->getBoard(), board->getWhiteKing()->returnCol(), board->getWhiteKing()->returnRow()) == false) {
					done = true;
				}
			} else {
				done = false;
			}
		}
	}
}

// void Game::makeMove(Board * gameBoard, int xFrom, int yFrom, int xTo, int yTo) {
// 	//Piece * pieceMoved = gameBoard->getPiece(xFrom, yFrom);
// 	//Piece takenPiece = board[xTo][yTo]->returnType());
// 	//board->placePiece(xTo, yTo, board[xFrom][yFrom]->returnType());
// 	//board->removePiece(xFrom, yFrom);
// 	//Move currentMove = 
// 	//previousMoves.emplace_back
// }
	 
bool Game::isChecked() {
	string currentPlayerColour = players[turn].get()->getPieceColour();
	int xKing;
	int yKing;
	// Way to do it without the canBeCaptured() function
	
	
	// for (int i = 0; i < 8; ++i) { // i = row number -y
	// 	for (int j = 0; j < 8; ++j) { // j = column number -x
	// 		if (board->getPiece(j,i)->getCanCheckStatus() && board->getPiece(j,i)->returnOwner() == currentPlayerColour) { // (column, row) = (x, y)
	// 			return true;
	// 		} 
	// 	}
	// }
	if (currentPlayerColour == "Black") {
		xKing = board->getBlackKing()->returnCol();
		yKing = board->getBlackKing()->returnRow();
	} else {
		xKing = board->getWhiteKing()->returnCol();
		yKing = board->getWhiteKing()->returnRow();
	}
	if (board->getPiece(xKing, yKing)->canBeCaptured(board->getBoard(), xKing, yKing)) {
		return true;
	}
	return false; 
}
	 
bool Game::isCheckmated() {
	string currentPlayerColour = players[turn].get()->getPieceColour();
	int xKing;
	int yKing;
	if (currentPlayerColour == "Black") {
		xKing = board->getBlackKing()->returnCol();
		yKing = board->getBlackKing()->returnRow();
	} else {
		xKing = board->getWhiteKing()->returnCol();
		yKing = board->getWhiteKing()->returnRow();
	}
	char enemyKnight = 'k';
	if (currentPlayerColour == "Black") {
		enemyKnight = 'K';
	}
	if (isChecked()) {
		char currentKing = 'k';
        if (currentPlayerColour == "White") {
                currentKing = 'K';
        }
		vector<pair<int,int>> possibleKingMoves = board->getPiece(xKing, yKing)->avoidCaptures(board->getBoard());
		// if the king can move out of the wayy
		if (possibleKingMoves.empty() == false) { //only possible move if a double check
			return false;
		}

		//Piece * attackingPiece;
		//int xAttackingPiece;
		//int yAttackingPiece;
		vector<Piece *> attackingPieces;
		for (int i = 0; i < 8; ++i) { // i = row number -y
			for (int j = 0; j < 8; ++j) { // j = column number -x
				if (board->getPiece(j,i) != nullptr) {
					if (board->getPiece(j,i)->getCanCheckStatus() && board->getPiece(j,i)->returnOwner() != currentPlayerColour) { // (column, row) = (x, y)
						//attackingPiece = board->getPiece(j,i);
						//xAttackingPiece = j;
						//yAttackingPiece = i;
						attackingPieces.push_back(board->getPiece(j,i));
					} 
				}
			}
		}
		if (attackingPieces.size() == 1) { //single check situation
			// if the the checking pieces can be captured
			if (attackingPieces[0]->canBeCaptured(board->getBoard(), attackingPieces[0]->returnCol(), attackingPieces[0]->returnRow())) {
				return false;
			}
			// if the check can be blocked
			else if (attackingPieces[0]->returnType() != enemyKnight) {
				// tempBoard to simulate moves to identify if the check can be blocked
				//Board * tempBoard = board.get();
				Board tempBoard = Board();
				for (int m = 0; m < 8; ++m) { // row number -y
					for (int n = 0; n < 8; ++n) { //column number -x
						if (board->getPiece(n,m) != nullptr) {
							/* int col = board->getPiece(n, m)->returnCol();
							int row = board->getPiece(n, m)->returnRow();
							char type = board->getPiece(n, m)->returnType();
							
							if ((type == 'k') || (type == 'K')) {
								King kingPiece = King(col, row, type);
							} else if ((type == 'q') || (type == 'Q')) {
								Queen queenPiece = Queen(col, row, type);
							} else if ((type == 'n') || (type == 'N')) {
								Knight knightPiece = Knight(col, row, type);
							} else if ((type == 'p') || (type == 'P')) {
								Pawn pawnPiece = Pawn(col, row, type);
							} else if ((type == 'r') || (type == 'R')) {
								Rook rookPiece = Rook(col, row, type);
							} else if ((type == 'b') || (type == 'B')) {
								Bishop bishopPiece = Bishop(col, row, type);
							} */
							tempBoard.placePiece(n, m, board->getPiece(n, m)->returnType());
						}
					}
				}
				/* Board tempBoard;
				vector<Piece *> tempRow;
				for (int m = 0; m <= 7; ++m) {
					for (int n = 0; n <= 7; ++n) {
						//cout << "i: " << i << " x: " << xCoor << " j: " << j << " y: " << yCoor << " retCol: " << this->returnCol() << endl;
						if (board->getPiece(n,m)) {
							tempRow.emplace_back(nullptr);
						} else {
							tempRow.emplace_back(board->getPiece(n,m));
						}
						tempBoard.placePiece(n, m, tempRow);
					}
					tempBoard.emplace_back(tempRow);
					tempRow.clear();
				} */

				//cout << "COPY :D" << endl;
				//tempBoard.printBoard();
				for (int i = 0; i < 8; ++i) { // i = row number -y
					for (int j = 0; j < 8; ++j) { // j = column number -x
						if (tempBoard.getPiece(j,i) != nullptr) {
							if (tempBoard.getPiece(j,i)->returnOwner() == currentPlayerColour) { // (column, row) = (x, y)
								Piece * pieceMoved = tempBoard.getPiece(j, i);
								//vector<pair<int,int>> validMoves = pieceMoved->possibleMoves(tempBoard.getBoard());
								vector<pair<int,int>> validMoves;
								if (pieceMoved->returnType() == currentKing) {
										validMoves = pieceMoved->avoidCaptures(tempBoard.getBoard());

								} else {
										validMoves = pieceMoved->possibleMoves(tempBoard.getBoard());
								}
								int validMovesSize = validMoves.size();
								//cout << "validMovesSize: " << validMovesSize << endl;
								//cout << "x: " << j << " y: " << i;
								for (int k = 0; k < validMovesSize; ++k) {
									//cout << "SEG FAULT " << "(" <<  validMoves[k].first << "," << validMoves[k].second << ")" << endl;
									tempBoard.getPiece(j, i)->changeLocation(validMoves[k].first, validMoves[k].second);
									tempBoard.movePiece(j,validMoves[k].first, i, validMoves[k].second);
												//getPlayer()->makeMove(tempBoard, j, i, validMoves[k].first, validMoves[k].second, previousMoves);
									if (!tempBoard.getPiece(xKing, yKing)->canBeCaptured(tempBoard.getBoard(), xKing, yKing)) {
										return false;
									}
									//getPlayer()->makeMove(tempBoard, validMoves[k].first, validMoves[k].second, j, i, previousMoves);
									tempBoard.getPiece(validMoves[k].first, validMoves[k].second)->changeLocation(j, i);
									tempBoard.movePiece(validMoves[k].first, j, validMoves[k].second, i);
								}
							} 
							/* if (board->getPiece(j,i)->returnOwner() == currentPlayerColour) { // (column, row) = (x, y)
								Piece * pieceMoved = board->getPiece(j, i);
								vector<pair<int,int>> validMoves = pieceMoved->possibleMoves(tempBoard->getBoard());
								int validMovesSize = validMoves.size();
								for (int k = 0; k < validMovesSize; ++k) {
									tempBoard->getPiece(j, i)->changeLocation(validMoves[k].first, validMoves[k].second);
									tempBoard->movePiece(j,validMoves[k].first, i, validMoves[k].second);
												//getPlayer()->makeMove(tempBoard, j, i, validMoves[k].first, validMoves[k].second, previousMoves);
									if (tempBoard->getPiece(xKing, yKing)->canBeCaptured(tempBoard->getBoard(), xKing, yKing) == false) {
										return false;
									}
									//getPlayer()->makeMove(tempBoard, validMoves[k].first, validMoves[k].second, j, i, previousMoves);
									tempBoard->getPiece(validMoves[k].first, validMoves[k].second)->changeLocation(j, i);
									tempBoard->movePiece(validMoves[k].first, j, validMoves[k].second, i);
								}
							}  */
						}
					}
				} 
			}
			return true;
		}
	}
	return false;
}

bool Game::isStalemate() {
	string currentPlayerColour = players[turn].get()->getPieceColour();
	int xKing;
	int yKing;
	if (currentPlayerColour == "Black") {
		xKing = board->getBlackKing()->returnCol();
		yKing = board->getBlackKing()->returnRow();
	} else {
		xKing = board->getWhiteKing()->returnCol();
		yKing = board->getWhiteKing()->returnRow();
	}
	if (isChecked() == false) {
        char currentKing = 'k';
        if (currentPlayerColour == "White") {
                currentKing = 'K';
        }
		for (int i = 0; i < 8; ++i) { // i = row number -y
			for (int j = 0; j < 8; ++j) { // j = column number -x
				if (board->getPiece(j,i) != nullptr) {
					if (board->getPiece(j,i)->returnOwner() == currentPlayerColour) { // (column, row) = (x, y)
						Piece * pieceMoved = board->getPiece(j, i);
						vector<pair<int,int>> validMoves;
						if (pieceMoved->returnType() == currentKing) {
								validMoves = pieceMoved->avoidCaptures(board->getBoard());

						} else {
								validMoves = pieceMoved->possibleMoves(board->getBoard());
						}
						//vector<pair<int,int>> validMoves = pieceMoved->possibleMoves(board->getBoard());
						if (validMoves.empty() == false) {
							//Board * tempBoard = board.get();
							Board tempBoard = Board();
							for (int m = 0; m < 8; ++m) { // row number -y
								for (int n = 0; n < 8; ++n) { //column number -x
									if (board->getPiece(n,m) != nullptr) {
										tempBoard.placePiece(n, m, board->getPiece(n, m)->returnType());
									}
								}
							}

							cout << "x: " << j << " y: " << i;
							int tempSize = validMoves.size();
							int numSafeMoves = tempSize;
							cout << "Possible Moves: ";
							for (int k = 0; k < tempSize; ++k) {
								cout << "(" <<  validMoves[k].first << "," << validMoves[k].second << ")";
								// getPlayer()->makeMove(tempBoard, j, i, validMoves[k].first, validMoves[k].second, previousMoves);
								// // if (tempBoard->getPiece(xKing, yKing)->canBeCaptured(tempBoard->getBoard(), xKing, yKing) == false) {
								// // 	getPlayer()->makeMove(tempBoard, validMoves[k].first, validMoves[k].second, j, i, previousMoves);
								// // 	return false;
								// // }
								// // getPlayer()->makeMove(tempBoard, validMoves[k].first, validMoves[k].second, j, i, previousMoves);
								// // numSafeMoves--;
								// if (tempBoard->getPiece(xKing, yKing)->canBeCaptured(tempBoard->getBoard(), xKing, yKing)) {
								// 	numSafeMoves--;
								// }
								// getPlayer()->makeMove(tempBoard, validMoves[k].first, validMoves[k].second, j, i, previousMoves);
								tempBoard.getPiece(j, i)->changeLocation(validMoves[k].first, validMoves[k].second);
								tempBoard.movePiece(j,validMoves[k].first, i, validMoves[k].second);
											//getPlayer()->makeMove(tempBoard, j, i, validMoves[k].first, validMoves[k].second, previousMoves);
								//cout << "SEGGG" << endl;
								if (tempBoard.getPiece(xKing, yKing)->canBeCaptured(tempBoard.getBoard(), xKing, yKing)) {
									numSafeMoves--;
								}
								//getPlayer()->makeMove(tempBoard, validMoves[k].first, validMoves[k].second, j, i, previousMoves);
								tempBoard.getPiece(validMoves[k].first, validMoves[k].second)->changeLocation(j, i);
								tempBoard.movePiece(validMoves[k].first, j, validMoves[k].second, i);
							}
							cout << endl;
							if (numSafeMoves == 0) {
								return true;
							}
							return false;
						} 
					}
				} 
			}
		}
		return true; 
	}
	return false;
}

Board * Game::getBoard() {
	return board.get();
}

Player * Game::getPlayer() {
	return players[turn].get();
}

vector<unique_ptr<Move>>& Game::getPreviousMoves() {
	return previousMoves;
}

void Game::incrementTurn() {
	if (turn == 0) {
		turn++;
	} else {
		turn--;
	}
}

int Game::getTurn() {
	return turn;
}

void Game::setTurn(string colour) {
	if (colour == "White" || colour == "white") {
		turn = 0;
	} else if (colour == "Black" || colour == "black") {
		turn = 1;
	}
}

// For observers
void Game::render() {
	//cout << "RENDER" << endl;
	//cout << "Obs size " << observers.size() << endl;
	notifyObservers();
}

Board * Game::getState() const {
	return board.get();
}

Game::~Game() {}
