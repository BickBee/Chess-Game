#ifndef _BOARD_H_
#define _BOARD_H_

#include "piece.h"
#include "knight.h"
#include "pawn.h"
#include "king.h"
#include "rook.h"
#include "bishop.h"
#include "queen.h"
#include <vector>
#include <memory>
using namespace std;

class Board {
	
 	 vector<unique_ptr<Piece>> pieces;	
	 vector<vector<Piece *>> board;
	 //pair<int,int> whiteKingPosition;
	 //pair<int,int> blackKingPosition;
	 Piece * whiteKing;
	 Piece * blackKing;

	public:
	 Board();
	 void createDefault();
	 void printBoard();
	 void placePiece(int xCoor, int yCoor, char type);
	 void removePiece(int xCoor, int yCoor);
	 Piece * getPiece(int xCoor, int yCoor);
	 vector<vector<Piece *>> getBoard();
	 void movePiece(int xFrom, int xTo, int yFrom, int yTo);
	 //pair<int,int> getWhiteKingPosition();
	 //pair<int,int> getBlackKingPosition();
	 Piece * getWhiteKing();
	 Piece * getBlackKing();
	 void setWhiteKingPointer(Piece * newWhiteKing);
	 void setBlackKingPointer(Piece * newBlackKing);
};

#endif
