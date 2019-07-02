// MIT License
// Copyright (c) 2019 Vincent Runge

#ifndef DOUBLY_LINKED_LIST_POINT_H
#define DOUBLY_LINKED_LIST_POINT_H

#include "PointDoubly.h"
#include <math.h>

class DoublyLinkedListPoint ///DANGER: THERE IS "NO" EMPTY LIST. ALWAYS ADD SOME ELEMENTS
{
public:
  DoublyLinkedListPoint();
  unsigned int getState();
  unsigned int getTime();

  void addPoint(PointDoubly * P);
  void move();
  void deleteNextPoint();
  void initializeCurrentPosition();
  bool nextPointIsNotSentinel();

private:
  PointDoubly* sentinel;
  PointDoubly* currentPosition;
};

#endif