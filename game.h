#ifndef _GAME_H_
#define _GAME_H_

#include "move.h"
#include "board.h"
#include "player.h"
#include "piece.h"
#include "human.h"
#include "computerPlayer1.h"
#include "subject.h"
#include <vector>
#include <memory>
#include <iostream>

class Game: public Subject {
	
	 unique_ptr<Board> board;
	 vector<unique_ptr<Move>> previousMoves;
	 vector<unique_ptr<Player>> players;
	 int turn;

	public:
	 //explicit Game(Board * board): theBoard{board} {}

	 Game(int turn_par);
	 void createSetup();
	 //virtual bool makeMove(Board * gameBoard, int xFrom, int yFrom, int xTo, int yTo, vector<unique_ptr<Move>> previousMoves) = 0;
	 bool isChecked(); 
	 bool isCheckmated();
	 bool isStalemate();
	 Board * getBoard();
	 Player * getPlayer();
	 vector<unique_ptr<Move>>& getPreviousMoves();
	 void incrementTurn();
	 int getTurn();
	 void setTurn(string colour);
	 void addPlayers(string white_player, string black_player);
	 void render();

	 Board * getState() const override;

	 ~Game();
};

#endif
