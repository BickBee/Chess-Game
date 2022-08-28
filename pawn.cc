#include "pawn.h"
#include <iostream>

using namespace std;

Pawn::Pawn(int row_par, int col_par, char type_par) 
	: Piece{row_par, col_par, type_par}
{}

vector<pair<int,int>> Pawn::possibleMoves(vector<vector<Piece *>> board) {
	vector<pair<int,int>> listOfMoves;
	int cur_row = this->returnRow();
	int cur_col = this->returnCol();
	
	if (this->returnType() == 'p') {

                //cout << "row: " << cur_row << endl;
                //cout << "col: " << cur_col << endl;

		// One Move Forward
		if ((cur_row + 1 >= 0) && (cur_row + 1 <= 7) && (cur_col >= 0) && (cur_col <= 7) && (board[cur_col][cur_row + 1] == nullptr)) {
			listOfMoves.emplace_back(make_pair(cur_col, cur_row + 1));
		}

                //cout << "one move forward" << endl;

        	// Two Moves Forward
		if ((cur_row + 2 >= 0) && (cur_row + 2 <= 7) && (cur_col >= 0) && (cur_col <= 7) && (this->returnHasMoved() == false) &&
			       	(board[cur_col][cur_row + 2] == nullptr) && (board[cur_col][cur_row + 1] == nullptr)) {
                        listOfMoves.emplace_back(make_pair(cur_col, cur_row + 2));
                }

                //cout << "two moves forward" << endl;

       		// Move Diagonally
		if ((cur_row + 1 >= 0) && (cur_row + 1 <= 7) && (cur_col - 1 >= 0) && (cur_col - 1 <= 7) &&
				(board[cur_col - 1][cur_row + 1] != nullptr) && (board[cur_col - 1][cur_row + 1]->returnOwner() != this->returnOwner())) {
			listOfMoves.emplace_back(make_pair(cur_col - 1, cur_row + 1));
		}

		if ((cur_row + 1 >= 0) && (cur_row + 1 <= 7) && (cur_col + 1 >= 0) && (cur_col + 1 <= 7) &&
                                (board[cur_col + 1][cur_row + 1] != nullptr) && (board[cur_col + 1][cur_row + 1]->returnOwner() != this->returnOwner())) {
                        listOfMoves.emplace_back(make_pair(cur_col + 1, cur_row + 1));
                }

	} else if (this->returnType() == 'P') {

		// One Move Forward
                if ((cur_row - 1 >= 0) && (cur_row - 1 <= 7) && (cur_col >= 0) && (cur_col <= 7) && (board[cur_col][cur_row - 1] == nullptr)) {
                        listOfMoves.emplace_back(make_pair(cur_col, cur_row - 1));
                }

                // Two Moves Forward
                if ((cur_row - 2 >= 0) && (cur_row - 2 <= 7) && (cur_col >= 0) && (cur_col <= 7) && (this->returnHasMoved() == false) &&
                                (board[cur_col][cur_row - 2] == nullptr) && (board[cur_col][cur_row - 1] == nullptr)) {
                        listOfMoves.emplace_back(make_pair(cur_col, cur_row - 2));
                }

                // Move Diagonally
                if ((cur_row - 1 >= 0) && (cur_row - 1 <= 7) && (cur_col - 1 >= 0) && (cur_col - 1 <= 7) &&
                                (board[cur_col - 1][cur_row - 1] != nullptr) && (board[cur_col - 1][cur_row - 1]->returnOwner() != this->returnOwner())) {
                        listOfMoves.emplace_back(make_pair(cur_col - 1, cur_row - 1));
                }

                if ((cur_row - 1 >= 0) && (cur_row - 1 <= 7) && (cur_col + 1 >= 0) && (cur_col + 1 <= 7) &&
                                (board[cur_col + 1][cur_row - 1] != nullptr) && (board[cur_col + 1][cur_row - 1]->returnOwner() != this->returnOwner())) {
                        listOfMoves.emplace_back(make_pair(cur_col + 1, cur_row - 1));
                }

	}

	return listOfMoves;
}
