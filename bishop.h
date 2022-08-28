#ifndef _BISHOP_H_
#define _BISHOP_H_

#include "piece.h"

class Bishop : public Piece {
	public:
	 Bishop(int row_par, int col_par, char type_par);
	 vector<pair<int,int>> possibleMoves(vector<vector<Piece *>> board) override;
};

#endif
