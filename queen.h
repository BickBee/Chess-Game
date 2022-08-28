#ifndef _QUEEN_H_
#define _QUEEN_H_

#include "piece.h"

class Queen : public Piece {
	public:
	 Queen(int row_par, int col_par, char type_par);
	 vector<pair<int,int>>  possibleMoves(vector<vector<Piece *>> board) override;
};

#endif
