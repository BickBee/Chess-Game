#include "computerPlayer1.h"
#include <iostream>
#include <random>

using namespace std;

ComputerPlayer1::ComputerPlayer1(string pieceColour)
    : Player{pieceColour}
{}

bool ComputerPlayer1::makeMove(Board *gameBoard, int xFrom, int yFrom, int xTo, int yTo, vector<unique_ptr<Move>> &previousMoves){  

    bool underCheck = false;
    int xKing;
    int yKing;
    int numberOfPieces;
    int chosenPiece;
    int numberOfMoves;
    int chosenMove;
    Piece *pieceMoved;
    Piece *takenPiece;

    // check if king is in check
    string currentColour = gameBoard->getPiece(xFrom, yFrom)->returnOwner();
    //char currentKing = 'k';
    
    if (currentColour == "White") {
        //currentKing = 'K';
        xKing = gameBoard->getWhiteKing()->returnCol();
        yKing = gameBoard->getWhiteKing()->returnRow();

        //King is under check
        if (gameBoard->getWhiteKing()->canBeCaptured(gameBoard->getBoard(), xKing, yKing)) {
            underCheck = true;
        }
    } else if (currentColour == "Black") {
        //currentKing = 'K';
        xKing = gameBoard->getBlackKing()->returnCol();
        yKing = gameBoard->getBlackKing()->returnRow();

        //King is under check
        if (gameBoard->getBlackKing()->canBeCaptured(gameBoard->getBoard(), xKing, yKing)) {
            underCheck = true;
        }
    }

    if (!underCheck) {

        numberOfPieces = getPiecesInPlay(gameBoard).size();
        random_device dev;
        mt19937 rng(dev());
        //mt19937 rng1(dev());

        //cout << numberOfPieces << endl;
        uniform_int_distribution<mt19937::result_type> randomPiece(0, numberOfPieces - 1);
        //int randomPiece = rand() % numberOfPieces;

        chosenPiece = randomPiece(rng);

        //cout << "random Piece: " << chosenPiece << endl;

        while (getPiecesInPlay(gameBoard)[chosenPiece]->possibleMoves(gameBoard->getBoard()).size() == 0) {
            chosenPiece = randomPiece(rng);
            //cout << "new Piece: " << chosenPiece << endl;
        }

            
        pieceMoved = getPiecesInPlay(gameBoard)[chosenPiece];

    /*
        if (pieceMoved == nullptr || this->getPieceColour() != pieceMoved->returnOwner()){
            return false;
        }*/

        xFrom = pieceMoved->returnCol();
        yFrom = pieceMoved->returnRow();

        //cout <<"from " << xFrom << yFrom << endl;

        vector<pair<int, int>> validMoves = pieceMoved->possibleMoves(gameBoard->getBoard());
    /*
        int size = pieceMoved->possibleMoves(gameBoard->getBoard()).size();

        cout << "size: " << size << endl;

            //print out all valid moves
            for (int i = 0; i < size; ++i) {
                    cout << "valid moves: " << validMoves[i].first << validMoves[i].second << endl;
            }
            
    */
        numberOfMoves = validMoves.size();
        //cout << validMoves.size() << endl;

        //random_device dev;
        //mt19937 rng(dev());
        uniform_int_distribution<mt19937::result_type> randomMove(0, numberOfMoves - 1);

        //int randomMove = rand() % numberOfMoves;

        chosenMove = randomMove(rng);

        //cout << "random move: " << chosenMove << endl;

        xTo = validMoves[chosenMove].first;
        yTo = validMoves[chosenMove].second;

        //cout << xTo << yTo<< endl;

        takenPiece = gameBoard->getPiece(xTo, yTo);

        previousMoves.emplace_back(make_unique<Move>(xFrom, yFrom, xTo, yTo, pieceMoved, takenPiece, false, false));
        gameBoard->getPiece(xFrom, yFrom)->changeLocation(xTo, yTo);
        gameBoard->movePiece(xFrom, xTo, yFrom, yTo);

      //  return true;
        
    }  else {

        for (int i = 0; i < numberOfPieces; i++) {
            chosenPiece = i;
            pieceMoved = getPiecesInPlay(gameBoard)[chosenPiece];
            xFrom = pieceMoved->returnCol();
            yFrom = pieceMoved->returnRow();
            numberOfMoves = pieceMoved->possibleMoves(gameBoard->getBoard()).size();
            
            for (int j = 0; j < numberOfMoves; j++) {
                
                chosenMove = j;       

                
                xTo = pieceMoved->possibleMoves(gameBoard->getBoard())[chosenMove].first;
                yTo = pieceMoved->possibleMoves(gameBoard->getBoard())[chosenMove].second;
                takenPiece = gameBoard->getPiece(xTo, yTo);
                
                gameBoard->getPiece(xFrom, yFrom)->changeLocation(xTo, yTo);
                gameBoard->movePiece(xFrom, xTo, yFrom, yTo);

                if (currentColour == "White") {
                    if (gameBoard->getWhiteKing()->canBeCaptured(gameBoard->getBoard(), gameBoard->getWhiteKing()->returnCol(), gameBoard->getWhiteKing()->returnRow())) {
                            gameBoard->getPiece(xTo, yTo)->changeLocation(xFrom, yFrom);
                            gameBoard->movePiece(xTo, xFrom, yTo, yFrom);
                    } else {
                        previousMoves.emplace_back(make_unique<Move>(xFrom, yFrom, xTo, yTo, pieceMoved, takenPiece, false, false));

                        underCheck = false;
                        return true;
                    }
                } else {
                    if (gameBoard->getBlackKing()->canBeCaptured(gameBoard->getBoard(), gameBoard->getBlackKing()->returnCol(), gameBoard->getBlackKing()->returnRow())) {
                            gameBoard->getPiece(xTo, yTo)->changeLocation(xFrom, yFrom);
                            gameBoard->movePiece(xTo, xFrom, yTo, yFrom);
                    } else {
                        previousMoves.emplace_back(make_unique<Move>(xFrom, yFrom, xTo, yTo, pieceMoved, takenPiece, false, false));

                        underCheck = false;
                        return true;
                    }
                }
            }
            
        }
    }

    return true;
}
