// MIT License
// Copyright (c) 2019 Vincent Runge

#ifndef LISTPOINT_H
#define LISTPOINT_H

#include "Point.h"
#include <math.h>

class ListPoint ///DANGER: THERE IS "NO" EMPTY LIST. ALWAYS ADD SOME ELEMENTS
{
public:
  ListPoint(); //create an empty list
  unsigned int getState();
  unsigned int getTime();

  void addPoint(Point* P); //at the beginning after (0,0)
  void deleteNxtPoint();

  void initializeCurrentPosition(); //currentPosition = firstPoint
  bool move(); //DANGER we can move only in a non-empty list
  bool isEmpty(); //DANGER we can move only in a non-empty list

private:
  Point* firstPoint;
  Point* currentPosition;

};

#endif // LISTPOINT_H
