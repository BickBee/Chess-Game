#ifndef _KNIGHT_H_
#define _KNIGHT_H_

#include "piece.h"

class Knight : public Piece {
	public:
	 Knight(int row_par, int col_par, char type_par);
	 vector<pair<int,int>> possibleMoves(vector<vector<Piece *>> board) override;
};

#endif
