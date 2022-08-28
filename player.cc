#include "player.h"
#include <string>

Player::Player(string pieceColour) : pieceColour{pieceColour}
{}

string Player::getPieceColour() {
    return pieceColour;
}

vector<Piece *> Player::getPiecesInPlay(Board * gameBoard) {
        
    vector<Piece *> temp;

    for (int i = 0; i < 8; ++i) { // i = row number -y
	//cout << i << ": ";
		for (int j = 0; j < 8; ++j) { // j = column number -x
			if (gameBoard->getPiece(j, i) != nullptr) { // (column, row) = (x, y)
				//cout << '-';

                if (gameBoard->getPiece(j, i)->returnOwner() == this->getPieceColour()) {
                    temp.emplace_back(gameBoard->getPiece(j, i));
                }
            }
		}
	}
        //piecesInPlay.emplace_back
        //vector<Piece *>> piecesInPlay = gameBoard->getBoard();
    piecesInPlay.swap(temp);
    return piecesInPlay;
}


void Player::addEnPassant(Board * gameboard, int xFrom, int yFrom, vector<pair<int,int>> possibleMoves, vector<unique_ptr<Move>>& previousMoves) {
	// Detect if XFrom YFrom is actually a pawn
	// Detect if the last pawn moved was one that is next to that at xFrom yFrom
	// Add the position to list of possible moves
}

void Player::addCastling(Board * gameboard, int xFrom, int yFrom, vector<pair<int,int>> possibleMoves) {
	// Detect if the king or rooks have moved
	// // Potential struggle: accessing the pieces horizontal to the king piece, and detecting if a piece exists (actually may not be too hard)
	// Add positions to possible moves
}
