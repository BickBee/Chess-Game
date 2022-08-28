#include "knight.h"

Knight::Knight(int row_par, int col_par, char type_par) 
	: Piece{row_par, col_par, type_par}
{}

vector<pair<int,int>> Knight::possibleMoves(vector<vector<Piece *>> board) {
	vector<pair<int,int>> listOfMoves;
	int cur_row = this->returnRow();
	int cur_col = this->returnCol();

	// top left
	if ((cur_row - 2 >= 0) && (cur_row - 2 <= 7) && (cur_col - 1 >= 0) && (cur_col - 1 <= 7) &&
                        ((board[cur_col - 1][cur_row - 2] == nullptr) || (board[cur_col - 1][cur_row - 2]->returnOwner() != this->returnOwner()))) {
                listOfMoves.emplace_back(make_pair(cur_col - 1, cur_row - 2));
        }

	// top right
	if ((cur_row - 2 >= 0) && (cur_row - 2 <= 7) && (cur_col + 1 >= 0) && (cur_col + 1 <= 7) &&
                        ((board[cur_col + 1][cur_row - 2] == nullptr) || (board[cur_col + 1][cur_row - 2]->returnOwner() != this->returnOwner()))) {
                listOfMoves.emplace_back(make_pair(cur_col + 1, cur_row - 2));
        }
	
	// bottom left
	if ((cur_row + 2 >= 0) && (cur_row + 2 <= 7) && (cur_col - 1 >= 0) && (cur_col - 1 <= 7) &&
                        ((board[cur_col - 1][cur_row + 2] == nullptr) || (board[cur_col - 1][cur_row + 2]->returnOwner() != this->returnOwner()))) {
                listOfMoves.emplace_back(make_pair(cur_col - 1, cur_row + 2));
        }

	// bottom right
	if ((cur_row + 2 >= 0) && (cur_row + 2 <= 7) && (cur_col + 1 >= 0) && (cur_col + 1 <= 7) &&
                        ((board[cur_col + 1][cur_row + 2] == nullptr) || (board[cur_col + 1][cur_row + 2]->returnOwner() != this->returnOwner()))) {
                listOfMoves.emplace_back(make_pair(cur_col + 1, cur_row + 2));
        }

	// left top
	if ((cur_row - 1 >= 0) && (cur_row - 1 <= 7) && (cur_col - 2 >= 0) && (cur_col - 2 <= 7) &&
                        ((board[cur_col - 2][cur_row - 1] == nullptr) || (board[cur_col - 2][cur_row - 1]->returnOwner() != this->returnOwner()))) {
                listOfMoves.emplace_back(make_pair(cur_col - 2, cur_row - 1));
        }
	
	// left bottom
	if ((cur_row + 1 >= 0) && (cur_row + 1 <= 7) && (cur_col - 2 >= 0) && (cur_col - 2 <= 7) &&
                        ((board[cur_col - 2][cur_row + 1] == nullptr) || (board[cur_col - 2][cur_row + 1]->returnOwner() != this->returnOwner()))) {
                listOfMoves.emplace_back(make_pair(cur_col - 2, cur_row + 1));
        }
	
	// right top
	if ((cur_row - 1 >= 0) && (cur_row - 1 <= 7) && (cur_col + 2 >= 0) && (cur_col + 2 <= 7) &&
                        ((board[cur_col + 2][cur_row - 1] == nullptr) || (board[cur_col + 2][cur_row - 1]->returnOwner() != this->returnOwner()))) {
                listOfMoves.emplace_back(make_pair(cur_col + 2, cur_row - 1));
        }
	
	// right bottom
	if ((cur_row + 1 >= 0) && (cur_row + 1 <= 7) && (cur_col + 2 >= 0) && (cur_col + 2 <= 7) &&
                        ((board[cur_col + 2][cur_row + 1] == nullptr) || (board[cur_col + 2][cur_row + 1]->returnOwner() != this->returnOwner()))) {
                listOfMoves.emplace_back(make_pair(cur_col + 2, cur_row + 1));
        }

	return listOfMoves;
}
