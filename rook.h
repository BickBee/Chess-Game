#ifndef _ROOK_H_
#define _ROOK_H_

#include "piece.h"

class Rook : public Piece {
	public:
	 Rook(int row_par, int col_par, char type_par);
	 vector<pair<int,int>> possibleMoves(vector<vector<Piece *>> board) override;
};

#endif
