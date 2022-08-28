#ifndef SUBJECT_H
#define SUBJECT_H

#include "board.h"
#include <vector>

class Observer;

class Subject {
  std::vector<Observer*> observers;
 public:
  void attach(Observer *o);
  void detach(Observer *o);
  void notifyObservers();
  virtual Board * getState() const = 0;
  virtual ~Subject() = default;
};

#endif
