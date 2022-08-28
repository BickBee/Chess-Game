#ifndef _PAWN_H_
#define _PAWN_H_

#include "piece.h"

class Pawn : public Piece {
	public:
	 Pawn(int row_par, int col_par, char type_par);
	 vector<pair<int,int>> possibleMoves(vector<vector<Piece *>> board) override;
};

#endif

