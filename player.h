#ifndef _PLAYER_H_
#define _PLAYER_H_

//#include "game.h"
#include "board.h"
#include "move.h"
#include <string>

using namespace std;

class Player {
	
 	 string pieceColour;
	 vector<Piece *> piecesInPlay;

	public:
	 Player(string pieceColour);
	 virtual bool makeMove(Board * gameBoard, int xFrom, int yFrom, int xTo, int yTo, vector<unique_ptr<Move>>& previousMoves) = 0;
	 void addEnPassant(Board * gameboard, int xFrom, int yFrom, vector<pair<int,int>> possibleMoves, vector<unique_ptr<Move>>& previousMoves);
	 void addCastling(Board * gameboard, int xFrom, int yFrom, vector<pair<int,int>> possibleMoves);
	 string getPieceColour();
	 vector<Piece *> getPiecesInPlay(Board * gameBoard); 

};

#endif
