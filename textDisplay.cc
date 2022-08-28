#include "textDisplay.h"
#include <vector>
#include <iostream>

using namespace std;

TextDisplay::TextDisplay( Game *  myGame )
  : subject{myGame}
{
  subject->attach( this );
}

TextDisplay::~TextDisplay() {
  subject->detach( this );
}

void TextDisplay::notify() {
	//cout << "TEXT!" << endl;
  /* int theRow = theBottom - theTop;
  int theCol = theRight - theLeft;
  out << '+';
  for (int j = 0; j <= theCol; ++j) out << '-';
  out << '+' << std::endl;
  for (int i = 0; i <= theRow; ++i) {
    out << '|';
    for (int j = 0; j <= theCol; ++j) {
      out << subject->getState(i + theTop, j + theLeft);
    }
    out << '|' << std::endl;
  }
  out << '+';
  for (int j = 0; j <= theCol; ++j) out << '-';
  out << '+' << std::endl; */

  cout << endl;
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
}
