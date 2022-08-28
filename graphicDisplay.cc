#include "graphicDisplay.h"
#include <vector>
#include <iostream>

GraphicDisplay::GraphicDisplay( Game * myGame, Xwindow *myWindow )
  : subject{myGame}, theWindow{myWindow}
{
  subject->attach( this );
}

GraphicDisplay::~GraphicDisplay() {
  subject->detach( this );
}

void GraphicDisplay::notify() {
  int squareCounter = 1;
  //int colour = squareCounter % 2;
  for (int i = 0; i < 8; ++i) {
    for (int j = 0; j < 8; ++j) {
      int colour = squareCounter % 2;
      //if (i % 2 == 0)
      //theWindow->fillRectangle(j * 15, i * 15, 15, 15, 2);
      //string word = "w";
      
      /* if (i % 2 == 0 && j % 2 == 0) {
        colour = 1;
        //word = "b";
      } */
      if (colour == 1) {
        colour = 3;
      }

      theWindow->fillRectangle(j * 40, i * 40, 40, 40, colour);
      squareCounter++;
      
    }
    squareCounter++;
    string rightLabel[8] = {"8","7","6","5","4","3","2","1"};
    theWindow->drawString(340, 20 + 40 * i, rightLabel[i]);
  }
  string bottomLabel[8] = {"a","b","c","d","e","f","g","h"};
  for (int i = 0; i < 8; ++i) {
    theWindow->drawString(20 + 40 * i, 340, bottomLabel[i]);
  }
  // theWindow->drawString(20, 20, "OK");
  // theWindow->fillRectangle(0, 0, 40, 40, 3);
  // theWindow->drawString(20, 20, "NO");

  for (int i = 0; i < 8; ++i) {
    for (int j = 0; j < 8; ++j) {
      if (subject->getState()->getBoard()[j][i] != nullptr) {  
        theWindow->drawString(20 + 40 * j, 20 + 40 * i, string(1, subject->getState()->getBoard()[j][i]->returnType()));     	
     	}
    }
  }

  // if (subject->) {
	// 			cout << "+++++++++++++++++++++++++++++++++++++++++++++" << endl;
	// 			//new_game->getBoard()->printBoard();
	// 			new_game->render();
	// 			if (new_game->getTurn() == 0) {
  //                                      cout << "Checkmate! Player 2 wins!" << endl;
  //                               } else if (new_game->getTurn() == 1) {
  //                                       cout << "Checkmate! Player 1 wins!" << endl;
  //                               }
	// 			in_game = false;
	// 		} else if (new_game->isChecked()) {
  //                               if (new_game->getTurn() == 0) {
  //                                      cout << "Player 1 is in check." << endl;
  //                               } else if (new_game->getTurn() == 1) {
  //                                       cout << "Player 2 is in check." << endl;
  //                               }
  //                       }/* else if (new_game->isStalemate()) {
	// 			cout << "Stalemate!" << endl;
	// 			in_game = false;
	// 		}*/
	// 		cout << "+++++++++++++++++++++++++++++++++++++++++++++" << endl;
}



  /* for (int i = 0; i < 8; ++i) {
    theWindow->fillRectangle( * 10, i * 10, 10, 10, 0);
  } */
    

  /* cout << endl;
	for (int i = 0; i < 8; ++i) { // i = row number -y
		if (i == 0) {
			cout << "8 ";
		} else if (i == 1) {
			cout << "7 ";
		} else if (i == 2) {
			cout << "6 ";
		} else if (i == 3) {
			cout << "5 ";
		} else if (i == 4) {
			cout << "4 ";
		} else if (i == 5) {
			cout << "3 ";
		} else if (i == 6) {
			cout << "2 ";
		} else if (i == 7) {
			cout << "1 ";
		}

	for (int j = 0; j < 8; ++j) { // j = column number -x
      		if (subject->getState()->getBoard()[j][i] == nullptr) { // (column, row) = (x, y)
        		cout << '-';
     	 	} else {
        		cout << subject->getState()->getBoard()[j][i]->returnType();
     		}
    	} 
	cout << endl;
  	}

	  cout << endl <<  "  ";
    for (int i = 0; i < 8; ++i) {
      if (i == 0) {
        cout << "a";
      } else if (i == 1) {
        cout << "b";
      } else if (i == 2) {
        cout << "c";
      } else if (i == 3) {
        cout << "d";
      } else if (i == 4) {
        cout << "e";
      } else if (i == 5) {
        cout << "f";
      } else if (i == 6) {
        cout << "g";
      } else if (i == 7) {
        cout << "h";
      }
    }
    cout << endl;
} */
