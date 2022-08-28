#ifndef _COMPUTERPLAYER1_H_
#define _COMPUTERPLAYER1_H_

#include "player.h"
#include "board.h"
#include "move.h"
#include <utility>

class ComputerPlayer1 : public Player {

	public:
	 ComputerPlayer1(string pieceColour);
	 virtual bool makeMove(Board * gameBoard, int xFrom, int yFrom, int xTo, int yTo, vector<unique_ptr<Move>>& previousMoves) override;
	 //virtual bool makeMove(Board * gameBoard, vector<unique_ptr<Move>>& previousMoves) override;

};

#endif
