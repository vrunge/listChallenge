// MIT License
// Copyright (c) 2019 Vincent Runge

#ifndef LISTPOINT2_H
#define LISTPOINT2_H

#include "Point.h"
#include <math.h>

class ListPoint2 ///DANGER: THERE IS "NO" EMPTY LIST. ALWAYS ADD SOME ELEMENTS
{
public:
  ListPoint2(); //create an empty list
  ~ListPoint2();
  unsigned int getState();
  unsigned int getTime();
  unsigned int getLength();

  void addPoint(Point* P); //at the beginning after (0,0)
  void move();
  void deleteNxtPointAndMove();

  void initializeCurrentPosition(); //currentPosition = firstPoint

private:
  Point* firstPoint;
  Point* currentPosition;

  unsigned int length;
};

#endif // LISTPOINT2_H
