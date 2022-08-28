#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H
#include "observer.h"
#include "game.h"

class TextDisplay: public Observer {
  Subject *subject;

 public:
  TextDisplay( Game *  myGame );
  void notify() override;
  ~TextDisplay();
};

#endif
