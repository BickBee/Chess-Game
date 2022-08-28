#ifndef _MOVE_H_
#define _MOVE_H_

#include "piece.h"
#include <vector>
#include <utility>
#include <memory>

class Move {
	 int xFrom;
	 int yFrom;
	 int xTo;
	 int yTo;
	 Piece * pieceMoved;
	 Piece * takenPiece;
	 bool isCastle;
	 bool isEnPassant;
	
	public:
	 Move(int xFrom_par, int yFrom_par, int xTo_par, int yTo_par, Piece * pieceMoved_par, Piece * takenPiece_par, bool isCastle_par, bool isEnPassant_par);
	 int returnXFrom();
	 int returnYFrom();
	 int returnXTo();
	 int returnYTo();
	 Piece * returnPieceMoved();
	 Piece * returnTakenPiece();
	 bool returnIsCastle();
	 bool returnIsEnPassant();
};

#endif
