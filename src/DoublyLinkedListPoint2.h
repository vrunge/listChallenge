// MIT License
// Copyright (c) 2019 Vincent Runge

#ifndef DOUBLY_LINKED_LIST_POINT2_H
#define DOUBLY_LINKED_LIST_POINT2_H

#include "PointDoubly.h"
#include <math.h>

class DoublyLinkedListPoint2 ///DANGER: THERE IS "NO" EMPTY LIST. ALWAYS ADD SOME ELEMENTS
{
public:
  DoublyLinkedListPoint2();
  ~DoublyLinkedListPoint();
  unsigned int getState();
  unsigned int getTime();

  void addPoint(PointDoubly * P);
  void move();
  void deleteNextPoint();
  void initializeCurrentPosition();
  unsigned int getLength();

private:
  PointDoubly* sentinel;
  PointDoubly* currentPosition;
  unsigned int length;
};

#endif
