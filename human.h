#ifndef _HUMAN_H_
#define _HUMAN_H_

#include "player.h"
#include "board.h"
#include "move.h"
#include <utility>

class Human : public Player {
	public:
	 Human(string pieceColour);
	 virtual bool makeMove(Board * gameBoard, int xFrom, int yFrom, int xTo, int yTo, vector<unique_ptr<Move>>& previousMoves) override;
};

#endif
