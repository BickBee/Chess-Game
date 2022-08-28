#include "board.h"
#include <iostream>

using namespace std;

Board::Board () {
	for (int i = 0; i < 8; ++i) {
		vector<Piece *> temp = vector<Piece *>();
		for (int j = 0; j < 8; ++j) {
			temp.emplace_back(nullptr);
		}
		board.emplace_back(temp);
	}
}

void Board::printBoard() {
	/*
	cout << "   ";
	for (int i = 0; i < 8; ++i) {
		cout << i;
	}
	cout << endl;
	*/

	cout << endl;
	for (int i = 0; i < 8; ++i) { // i = row number -y
		if (i == 0) {
			cout << "8 ";
		} else if (i == 1) {
			cout << "7 ";
		} else if (i == 2) {
			cout << "6 ";
		} else if (i == 3) {
			cout << "5 ";
		} else if (i == 4) {
			cout << "4 ";
		} else if (i == 5) {
			cout << "3 ";
		} else if (i == 6) {
			cout << "2 ";
		} else if (i == 7) {
			cout << "1 ";
		}

		//cout << i << " ";
		for (int j = 0; j < 8; ++j) { // j = column number -x
			if (board[j][i] == nullptr) { // (column, row) = (x, y)
				cout << '-';
			} else {
				cout << board[j][i]->returnType();
			}
		}
		cout << endl;
	}

	cout << endl <<  "  ";
    for (int i = 0; i < 8; ++i) {
        if (i == 0) {
			cout << "a";
		} else if (i == 1) {
			cout << "b";
		} else if (i == 2) {
			cout << "c";
		} else if (i == 3) {
			cout << "d";
		} else if (i == 4) {
			cout << "e";
		} else if (i == 5) {
			cout << "f";
		} else if (i == 6) {
			cout << "g";
		} else if (i == 7) {
			cout << "h";
		}
    }
    cout << endl;
	// Output For Testing
	/*int xCoor = 3;
	int yCoor = 3;
	int temp;

	cout << "=== INFORMATION FOR PIECE AT (" << xCoor << "," << yCoor << ") ===" << endl;

	vector<pair<int,int>> output = board[xCoor][yCoor]->possibleMoves(board);
	temp = output.size();
	cout << "Possible Moves: ";
	for (int x = 0; x < temp; ++x) {
		cout << "(" <<  output[x].first << "," << output[x].second << ")";
	}
	cout << endl;

	vector<pair<int,int>> output1 = board[xCoor][yCoor]->possibleCaptures(board);
        temp = output1.size();
        cout << "Possible Captures: ";
        for (int x = 0; x < temp; ++x) {
                cout << "(" <<  output1[x].first << "," << output1[x].second << ")";
        }
        cout << endl;

	vector<pair<int,int>> output2 = board[xCoor][yCoor]->avoidCaptures(board);
        temp = output2.size();
        cout << "Possible Avoid Captures: ";
        for (int x = 0; x < temp; ++x) {
                cout << "(" <<  output2[x].first << "," << output2[x].second << ")";
        }
        cout << endl; */
	//-------------------------
}

void Board::placePiece(int xCoor, int yCoor, char type) {

	if ((type == 'k') || (type == 'K')) {
		pieces.emplace_back(make_unique<King>(xCoor, yCoor, type));
	} else if ((type == 'q') || (type == 'Q')) {
		pieces.emplace_back(make_unique<Queen>(xCoor, yCoor, type));
	} else if ((type == 'n') || (type == 'N')) {
		pieces.emplace_back(make_unique<Knight>(xCoor, yCoor, type));
	} else if ((type == 'p') || (type == 'P')) {
		pieces.emplace_back(make_unique<Pawn>(xCoor, yCoor, type));
	} else if ((type == 'r') || (type == 'R')) {
		pieces.emplace_back(make_unique<Rook>(xCoor, yCoor, type));
	} else if ((type == 'b') || (type == 'B')) {
		pieces.emplace_back(make_unique<Bishop>(xCoor, yCoor, type));
	}

	board[xCoor][yCoor] = pieces[pieces.size() - 1].get();
}
	 
void Board::removePiece(int xCoor, int yCoor) {
	board[xCoor][yCoor] = nullptr;
}

void Board::createDefault() {
	// Place Kings
	this->placePiece(4, 0, 'k');
	//blackKingPosition = make_pair(4,0);
	blackKing = getPiece(4,0);
	this->placePiece(4, 7, 'K');
	//whiteKingPosition = make_pair(4,7);
	whiteKing = getPiece(4, 7);

	// Place Queens
	this->placePiece(3, 0, 'q');
	this->placePiece(3, 7, 'Q');

	// Place Knights
	this->placePiece(1, 0, 'n');
	this->placePiece(6, 0, 'n');
	this->placePiece(1, 7, 'N');
	this->placePiece(6, 7, 'N');

	// Place Pawns
	for (int i = 0; i <= 7; ++i) {
		this->placePiece(i, 1, 'p');
		this->placePiece(i, 6, 'P');
	}

	// Place Rooks
	this->placePiece(0, 0, 'r');
	this->placePiece(7, 0, 'r');
	this->placePiece(0, 7, 'R');
	this->placePiece(7, 7, 'R');

	// Place Bishops
	this->placePiece(2, 0, 'b');
	this->placePiece(5, 0, 'b');
	this->placePiece(2, 7, 'B');
	this->placePiece(5, 7, 'B');
}

Piece * Board::getPiece(int xCoor, int yCoor) {

	//cout << "get " << xCoor << yCoor << endl;

	return board[xCoor][yCoor];
}

vector<vector<Piece *>> Board::getBoard() {
	return board;
}

void Board::movePiece(int xFrom, int xTo, int yFrom, int yTo) {
	board[xTo][yTo] = board[xFrom][yFrom];
	board[xFrom][yFrom] = nullptr;
}

/* pair<int,int> Board::getWhiteKingPosition() {
	return whiteKingPosition; 
}

pair<int,int> Board::getBlackKingPosition() {
	return blackKingPosition; 
} */

Piece * Board::getWhiteKing() {
	return whiteKing;
}

Piece * Board::getBlackKing() {
	return blackKing;
}

void Board::setWhiteKingPointer(Piece * newWhiteKing) {
	whiteKing = newWhiteKing;
}

void Board::setBlackKingPointer(Piece * newBlackKing) {
	blackKing = newBlackKing;
}
