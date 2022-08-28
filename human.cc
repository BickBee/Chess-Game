#include "human.h"

#include <iostream>
using namespace std;

Human::Human(string pieceColour)
	: Player{pieceColour}
{}

bool Human::makeMove(Board * gameBoard, int xFrom, int yFrom, int xTo, int yTo, vector<unique_ptr<Move>>& previousMoves) {
        if (xFrom == xTo && yFrom == yTo) {
                return false;
        }

        //cout << "stop1" << endl;

        Piece * pieceMoved = gameBoard->getPiece(xFrom, yFrom);
        Piece * takenPiece = gameBoard->getPiece(xTo, yTo);
        if (pieceMoved == nullptr) {
                return false;
        }

        string currentColour = gameBoard->getPiece(xFrom, yFrom)->returnOwner();
        char currentKing = 'k';
        if (currentColour == "White") {
                currentKing = 'K';
        }
        //cout << "stop2" << endl;

        //cout << pieceMoved->returnType() << endl;
        vector<pair<int,int>> validMoves;
        if (pieceMoved->returnType() == currentKing) {
                validMoves = pieceMoved->avoidCaptures(gameBoard->getBoard());

        } else {
                validMoves = pieceMoved->possibleMoves(gameBoard->getBoard());
        }
        //vector<pair<int,int>> validMoves = pieceMoved->possibleMoves(gameBoard->getBoard());

        int size = validMoves.size();

        /*cout << "size: " << size << endl;

        //print out all valid moves
        for (int i = 0; i < size; ++i) {
                cout << "valid moves: " << validMoves[i].first << validMoves[i].second << endl;
        }
        */

        for (int i = 0; i < size; ++i) {
                if (xTo == validMoves[i].first && yTo == validMoves[i].second) {
                        if (this->getPieceColour() != currentColour) {
                                break;
                        }
                        if (currentColour == "White" && gameBoard->getWhiteKing()->canBeCaptured(gameBoard->getBoard(), gameBoard->getWhiteKing()->returnCol(), gameBoard->getWhiteKing()->returnRow())) {
                                gameBoard->getPiece(xFrom, yFrom)->changeLocation(xTo, yTo);
                                gameBoard->movePiece(xFrom, xTo, yFrom, yTo);
                                if (gameBoard->getWhiteKing()->canBeCaptured(gameBoard->getBoard(), gameBoard->getWhiteKing()->returnCol(), gameBoard->getWhiteKing()->returnRow())) {
                                        gameBoard->getPiece(xTo, yTo)->changeLocation(xFrom, yFrom);
                                        gameBoard->movePiece(xTo, xFrom, yTo, yFrom);
                                        return false;
                                }
                                previousMoves.emplace_back(make_unique<Move>(xFrom, yFrom, xTo, yTo, pieceMoved, takenPiece, false, false));
                                return true;
                        } else if (currentColour == "Black" && gameBoard->getBlackKing()->canBeCaptured(gameBoard->getBoard(), gameBoard->getBlackKing()->returnCol(), gameBoard->getBlackKing()->returnRow())) {
                                gameBoard->getPiece(xFrom, yFrom)->changeLocation(xTo, yTo);
                                gameBoard->movePiece(xFrom, xTo, yFrom, yTo);
                                if (gameBoard->getBlackKing()->canBeCaptured(gameBoard->getBoard(), gameBoard->getBlackKing()->returnCol(), gameBoard->getBlackKing()->returnRow())) {
                                        gameBoard->getPiece(xTo, yTo)->changeLocation(xFrom, yFrom);
                                        gameBoard->movePiece(xTo, xFrom, yTo, yFrom);
                                        return false;
                                }
                                previousMoves.emplace_back(make_unique<Move>(xFrom, yFrom, xTo, yTo, pieceMoved, takenPiece, false, false));
                                return true;
                        }
                        //Move currentMove = Move(xFrom, yFrom, xTo, yTo, pieceMoved, takenPiece, false, false);
                        previousMoves.emplace_back(make_unique<Move>(xFrom, yFrom, xTo, yTo, pieceMoved, takenPiece, false, false));
                        //previousMoves.emplace_back(currentMove);
			gameBoard->getPiece(xFrom, yFrom)->changeLocation(xTo, yTo);
                        gameBoard->movePiece(xFrom, xTo, yFrom, yTo);
                        
                        // check if the piece has put the enemy king in check
                        pair<int,int> enemyKingPosition;
                        if (currentColour == "White") {
                                //enemyKingPosition = make_pair(gameBoard->getBlackKingPosition().first, gameBoard->getBlackKingPosition().second);
                                enemyKingPosition = make_pair(gameBoard->getBlackKing()->returnCol(), gameBoard->getBlackKing()->returnRow());
                        } else {
                                //enemyKingPosition = make_pair(gameBoard->getWhiteKingPosition().first, gameBoard->getWhiteKingPosition().second);
                                enemyKingPosition = make_pair(gameBoard->getWhiteKing()->returnCol(), gameBoard->getWhiteKing()->returnRow());
                        }
                        Piece * movedPieceToNewPosition = gameBoard->getPiece(xTo, yTo);
                        vector<pair<int,int>> newMoves = movedPieceToNewPosition->possibleMoves(gameBoard->getBoard());
                        int newMovesSize = newMoves.size();
                        for (int j = 0; j < newMovesSize; ++j) {
                                if (newMoves[j].first == enemyKingPosition.first && newMoves[j].second == enemyKingPosition.second) {
                                        gameBoard->getPiece(xTo, yTo)->setCanCheckToTrue();
                                } else {
                                        gameBoard->getPiece(xTo, yTo)->setCanCheckToFalse();
                                }
                        }
                        return true;
                } 
        }
        return false;
}
