#ifndef _KING_H_
#define _KING_H_

#include "piece.h"

class King : public Piece {
	public:
	 King(int row_par, int col_par, char type_par);
	 vector<pair<int,int>> possibleMoves(vector<vector<Piece *>> board) override;
};

#endif
