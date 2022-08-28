#ifndef GRAPHICDISPLAY_H
#define GRAPHICDISPLAY_H
#include "observer.h"
#include "window.h"
#include "game.h"

class GraphicDisplay: public Observer {
  Subject *subject;
  Xwindow *theWindow;
 public:
  GraphicDisplay( Game * myGame, Xwindow *myWindow );
  void notify() override;
  ~GraphicDisplay();
};

#endif
