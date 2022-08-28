#include "piece.h"
#include "board.h"

Piece::Piece(int col_par, int row_par, char type_par) {

	if ((type_par == 'k') || (type_par == 'K')) {
		value = 99;
	} else if ((type_par == 'q') || (type_par == 'Q')) {
		value = 9;
	} else if ((type_par == 'n') || (type_par == 'N')) {
		value = 3;
	} else if ((type_par == 'p') || (type_par == 'P')) {
		value = 1;
	} else if ((type_par == 'r') || (type_par == 'R')) {
		value = 5;
	} else if ((type_par == 'b') || (type_par == 'B')) {
		value = 3;
	}

	if (isupper(type_par)) {
		owner = "White";
	} else {
		owner = "Black";
	}

	type = type_par;
	row = row_par;
	col = col_par;
	hasMoved = false;
	canCheck = false;
}

bool Piece::canBeCaptured(vector<vector<Piece *>> board, int xCoor, int yCoor) {
	// Create temp simulation board
	vector<vector<Piece *>> temp_board;
	vector<Piece *> temp_row;
	int pieceCol = this->returnCol();
	int pieceRow = this->returnRow();
	//int pieceCol = xCoor;
	//int pieceRow = yCoor;
	for (int i = 0; i <= 7; ++i) {
		for (int j = 0; j <= 7; ++j) {
			//cout << "i: " << i << " x: " << xCoor << " j: " << j << " y: " << yCoor << " retCol: " << this->returnCol() << endl;
			if ((i == xCoor) && (j == yCoor)) {
				temp_row.emplace_back(this);
			} else if ((i == pieceCol) && (j == pieceRow)) {
				temp_row.emplace_back(nullptr);
			} else {
				temp_row.emplace_back(board[i][j]);
			}
		}
		temp_board.emplace_back(temp_row);
		temp_row.clear();
	}
	
	for (int i = 0; i <= 7; ++i) {
		for (int j = 0; j <= 7; ++j) {
			if ((temp_board[i][j] != nullptr) && (temp_board[i][j]->returnOwner() != this->returnOwner())) {
				vector<pair<int,int>> temp = temp_board[i][j]->possibleMoves(temp_board);
				int temp_size = temp.size();
				for (int x = 0; x < temp_size; ++x) {
					if ((temp[x].first == xCoor) && (temp[x].second == yCoor)) {
						return true;
					}
				}
			}
		}
	}
	
	return false;
}

vector<pair<int,int>> Piece::possibleCaptures(vector<vector<Piece *>> board) {
	vector<pair<int,int>> listOfMoves = this->possibleMoves(board);
	vector<pair<int,int>> captureMoves;

	int counter = listOfMoves.size();
	for (int i = 0; i < counter; ++i) {
		if (board[listOfMoves[i].first][listOfMoves[i].second] != nullptr) {
			captureMoves.emplace_back(listOfMoves[i]);
		}
	}

	return captureMoves;
}

// Places the piece can be moved without being captured
vector<pair<int,int>> Piece::avoidCaptures(vector<vector<Piece *>> board) {
	vector<pair<int,int>> listOfMoves = this->possibleMoves(board);
	vector<pair<int,int>> avoidCaptures;

	int counter = listOfMoves.size();
	for (int i = 0; i < counter; ++i) {
		if (!(this->canBeCaptured(board, listOfMoves[i].first, listOfMoves[i].second))) {
			avoidCaptures.emplace_back(listOfMoves[i]);
		}
	}
	return avoidCaptures;
}

char Piece::returnType() {
	return type;
}

int Piece::returnRow() {
	return row;
}

int Piece::returnCol() {
	return col;
}

string Piece::returnOwner() {
	return owner;
}

bool Piece::returnHasMoved() {
	return hasMoved;
}

int Piece::returnValue() {
	return value;
}

void Piece::changeLocation(int xTo, int yTo) {
	col = xTo;
	row = yTo;
	hasMoved = true;
}

void Piece::setCanCheckToTrue() {
	canCheck = true;
}

void Piece::setCanCheckToFalse() {
	canCheck = false;
}

bool Piece::getCanCheckStatus() {
	return canCheck;
}
