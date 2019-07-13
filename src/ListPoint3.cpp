// MIT License
// Copyright (c) 2019 Vincent Runge

#include "ListPoint3.h"
#include<iostream>

#include "math.h"

//####### constructor #######////####### constructor #######////####### constructor #######//
//####### constructor #######////####### constructor #######////####### constructor #######//

ListPoint3::ListPoint3()
{
  length = 0;
  firstPoint = new Point(0,0);
  //the first Point = an empty point : we consider point->nxt in functions
}



//####### destructor #######////####### destructor #######////####### destructor #######//
//####### destructor #######////####### destructor #######////####### destructor #######//

ListPoint3::~ListPoint3()
{
  for(unsigned int i = 0; i < (length + 1); i++) //first Point is unused
  {
    Point* pointToDelete = firstPoint;
    firstPoint = firstPoint -> nxt;
    delete(pointToDelete);
  }
}

//####### accessor #######////####### accessor #######////####### accessor #######//
//####### accessor #######////####### accessor #######////####### accessor #######//

unsigned int ListPoint3::getState()
  {return(currentPosition -> nxt -> state);}


unsigned int ListPoint3::getTime()
  {return(currentPosition -> nxt -> time);}


unsigned int ListPoint3::getLength()
  {return(length);}

//####### addPoint #######////####### addPoint #######////####### addPoint #######//
//####### addPoint #######////####### addPoint #######////####### addPoint #######//

void ListPoint3::addPoint(Point* P)
{
  P -> nxt = firstPoint -> nxt;
  firstPoint -> nxt = P;
  length = length + 1;
}


//####### deleteNxtPoint #######////####### deleteNxtPoint #######////####### deleteNxtPoint #######//
//####### deleteNxtPoint #######////####### deleteNxtPoint #######////####### deleteNxtPoint #######//


void ListPoint3::deleteNxtPointAndMove()
{
  Point* pointToDelete = currentPosition;
  currentPosition = currentPosition -> nxt;
  currentMinus1Position -> nxt = currentPosition;
  length = length - 1;
  delete(pointToDelete);
}

//####### initializeCurrentPosition #######////####### initializeCurrentPosition #######////####### initializeCurrentPosition #######//
//####### initializeCurrentPosition #######////####### initializeCurrentPosition #######////####### initializeCurrentPosition #######//

void ListPoint3::initializeCurrentPosition()
{
  currentMinus1Position = firstPoint;
  currentPosition = firstPoint -> nxt;
}


//####### move #######////####### move #######////####### move #######//
//####### move #######////####### move #######////####### move #######//


void ListPoint3::move()
{
  currentMinus1Position = currentPosition;
  currentPosition = currentPosition -> nxt;
}


