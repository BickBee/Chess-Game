#ifndef _PIECE_H_
#define _PIECE_H_

#include <vector>
#include <utility>
#include <memory>
#include <iostream>
using namespace std;

class Piece {
	 string owner;
	 int value;
	 int row;
	 int col;
	 char type;
	 bool hasMoved;
	 bool canCheck;
	
	public:
	 // Piece Creation
	 Piece(int row_par, int col_par, char type_par);

	 // Return Values
	 char returnType();
	 int returnRow();
	 int returnCol();
	 int returnValue();
	 string returnOwner();
	 bool returnHasMoved();

	 // Possible Move Options Functions
	 bool canBeCaptured(vector<vector<Piece *>> board, int xCoor, int yCoor);
	 virtual vector<pair<int,int>> possibleMoves(vector<vector<Piece *>> board) = 0;
	 vector<pair<int,int>> possibleCaptures(vector<vector<Piece *>> board);
	 vector<pair<int,int>> avoidCaptures(vector<vector<Piece *>> board);
	 void changeLocation(int xTo, int yTo);
	 void setCanCheckToTrue();
	 void setCanCheckToFalse();
	 bool getCanCheckStatus();
};

#endif
