#include "king.h"

King::King(int row_par, int col_par, char type_par) 
	: Piece{row_par, col_par, type_par}
{}

vector<pair<int,int>> King::possibleMoves(vector<vector<Piece *>> board) {
	vector<pair<int,int>> listOfMoves;
	int cur_row = this->returnRow();
	int cur_col = this->returnCol();

	// Check above
	if ((cur_row - 1 >= 0) && (cur_row - 1 <= 7) && (cur_col >= 0) && (cur_col <= 7) &&
            ((board[cur_col][cur_row - 1] == nullptr) || (board[cur_col][cur_row - 1]->returnOwner() != this->returnOwner()))) {
        listOfMoves.emplace_back(make_pair(cur_col, cur_row - 1));
    }

	// Check below
	if ((cur_row + 1 >= 0) && (cur_row + 1 <= 7) && (cur_col >= 0) && (cur_col <= 7) && 
			((board[cur_col][cur_row + 1] == nullptr) || (board[cur_col][cur_row + 1]->returnOwner() != this->returnOwner()))) {
		listOfMoves.emplace_back(make_pair(cur_col, cur_row + 1));
	}

	// Check right
	if ((cur_row >= 0) && (cur_row <= 7) && (cur_col + 1 >= 0) && (cur_col + 1 <= 7) &&
                        ((board[cur_col + 1][cur_row] == nullptr) || (board[cur_col + 1][cur_row]->returnOwner() != this->returnOwner()))) {
                listOfMoves.emplace_back(make_pair(cur_col + 1, cur_row));
        }

	// Check left
	if ((cur_row >= 0) && (cur_row <= 7) && (cur_col - 1 >= 0) && (cur_col - 1 <= 7) &&
                        ((board[cur_col - 1][cur_row] == nullptr) || (board[cur_col - 1][cur_row]->returnOwner() != this->returnOwner()))) {
                listOfMoves.emplace_back(make_pair(cur_col - 1, cur_row));
        }

	// Check top right
	if ((cur_row - 1 >= 0) && (cur_row - 1 <= 7) && (cur_col + 1 >= 0) && (cur_col + 1 <= 7) &&
                        ((board[cur_col + 1][cur_row - 1] == nullptr) || (board[cur_col + 1][cur_row - 1]->returnOwner() != this->returnOwner()))) {
                listOfMoves.emplace_back(make_pair(cur_col + 1, cur_row - 1));
        }

	// Check top left
	if ((cur_row - 1 >= 0) && (cur_row - 1 <= 7) && (cur_col - 1 >= 0) && (cur_col - 1 <= 7) &&
                        ((board[cur_col - 1][cur_row - 1] == nullptr) || (board[cur_col - 1][cur_row - 1]->returnOwner() != this->returnOwner()))) {
                listOfMoves.emplace_back(make_pair(cur_col - 1, cur_row - 1));
        }

	// Check bottom right
	if ((cur_row + 1 >= 0) && (cur_row + 1 <= 7) && (cur_col + 1 >= 0) && (cur_col + 1 <= 7) &&
                        ((board[cur_col + 1][cur_row + 1] == nullptr) || (board[cur_col + 1][cur_row + 1]->returnOwner() != this->returnOwner()))) {
                listOfMoves.emplace_back(make_pair(cur_col + 1, cur_row + 1));
        }

	// Check bottom left
	if ((cur_row + 1 >= 0) && (cur_row + 1 <= 7) && (cur_col - 1 >= 0) && (cur_col - 1 <= 7) &&
                        ((board[cur_col - 1][cur_row + 1] == nullptr) || (board[cur_col - 1][cur_row + 1]->returnOwner() != this->returnOwner()))) {
                listOfMoves.emplace_back(make_pair(cur_col - 1, cur_row + 1));
        }

	return listOfMoves;
}
