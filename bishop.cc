#include "bishop.h"

Bishop::Bishop(int row_par, int col_par, char type_par) 
	: Piece{row_par, col_par, type_par}
{}

vector<pair<int,int>> Bishop::possibleMoves(vector<vector<Piece *>> board) {
	vector<pair<int,int>> listOfMoves;
	int cur_row = this->returnRow();
	int cur_col = this->returnCol();
	
	// Check top right
	for (int i = 1; i <= 7; ++i) {
                if ((cur_row - i >= 0) && (cur_row - i <= 7) && (cur_col + i >= 0) && (cur_col + i <= 7) &&
                        ((board[cur_col + i][cur_row - i] == nullptr) || (board[cur_col + i][cur_row - i]->returnOwner() != this->returnOwner()))) {
                        listOfMoves.emplace_back(make_pair(cur_col + i, cur_row - i));
                        if (board[cur_col + i][cur_row - i] != nullptr) {
                                break;
                        }
                } else {
                        break;
                }
        }

	// Check top left
	for (int i = 1; i <= 7; ++i) {
                if ((cur_row - i >= 0) && (cur_row - i <= 7) && (cur_col - i >= 0) && (cur_col - i <= 7) &&
                        ((board[cur_col - i][cur_row - i] == nullptr) || (board[cur_col - i][cur_row - i]->returnOwner() != this->returnOwner()))) {
                        listOfMoves.emplace_back(make_pair(cur_col - i, cur_row - i));
                        if (board[cur_col - i][cur_row - i] != nullptr) {
                                break;
                        }
                } else {
                        break;
                }
        }

	// Check bottom right
	for (int i = 1; i <= 7; ++i) {
                if ((cur_row + i >= 0) && (cur_row + i <= 7) && (cur_col + i >= 0) && (cur_col + i <= 7) &&
                        ((board[cur_col + i][cur_row + i] == nullptr) || (board[cur_col + i][cur_row + i]->returnOwner() != this->returnOwner()))) {
                        listOfMoves.emplace_back(make_pair(cur_col + i, cur_row + i));
                        if (board[cur_col + i][cur_row + i] != nullptr) {
                                break;
                        }
                } else {
                        break;
                }
        }

	// Check bottom left
	for (int i = 1; i <= 7; ++i) {
                if ((cur_row + i >= 0) && (cur_row + i <= 7) && (cur_col - i >= 0) && (cur_col - i <= 7) &&
                        ((board[cur_col - i][cur_row + i] == nullptr) || (board[cur_col - i][cur_row + i]->returnOwner() != this->returnOwner()))) {
                        listOfMoves.emplace_back(make_pair(cur_col - i, cur_row + i));
                        if (board[cur_col - i][cur_row + i] != nullptr) {
                                break;
                        }
                } else {
                        break;
                }
        }
	
	return listOfMoves;
}
