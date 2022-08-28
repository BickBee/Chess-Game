#include "move.h"
#include <memory>
#include "board.h"
#include <iostream>
using namespace std;

Move::Move(int xFrom_par, int yFrom_par, int xTo_par, int yTo_par, Piece * pieceMoved_par, Piece * takenPiece_par, bool isCastle_par, bool isEnPassant_par) :
	xFrom{xFrom_par}, yFrom{yFrom_par}, xTo{xTo_par}, yTo{yTo_par}, pieceMoved{pieceMoved_par}, takenPiece{takenPiece_par}, isCastle{isCastle_par}, isEnPassant{isEnPassant_par} 
{}

int Move::returnXFrom() {
	return xFrom;
}

int Move::returnYFrom() {
	return yFrom;
}

int Move::returnXTo() {
	return xTo;
}

int Move::returnYTo() {
	return yTo;
}

Piece * Move::returnPieceMoved() {
	return pieceMoved;
}

Piece * Move::returnTakenPiece() {
	return takenPiece;
}

bool Move::returnIsCastle() {
	return isCastle;
}

bool Move::returnIsEnPassant() {
	return isEnPassant;
}
