// MIT License
// Copyright (c) 2019 Vincent Runge

#include "ListPoint2.h"
#include<iostream>

#include "math.h"

//####### constructor #######////####### constructor #######////####### constructor #######//
//####### constructor #######////####### constructor #######////####### constructor #######//

ListPoint2::ListPoint2()
{
  length = 0;
  firstPoint = new Point(0,0);
  currentPosition = firstPoint;
  //the first Point = an empty point : we consider point->nxt in functions
}



//####### destructor #######////####### destructor #######////####### destructor #######//
//####### destructor #######////####### destructor #######////####### destructor #######//

ListPoint2::~ListPoint2()
{
  for(unsigned int i = 0; i < length; i++)
  {
    Point* pointToDelete = firstPoint;
    firstPoint = firstPoint -> nxt;
    delete(pointToDelete);
  }
}

//####### accessor #######////####### accessor #######////####### accessor #######//
//####### accessor #######////####### accessor #######////####### accessor #######//

unsigned int ListPoint2::getState()
  {return(currentPosition -> nxt -> state);}


unsigned int ListPoint2::getTime()
  {return(currentPosition -> nxt -> time);}


unsigned int ListPoint2::getLength()
  {return(length);}

//####### addPoint #######////####### addPoint #######////####### addPoint #######//
//####### addPoint #######////####### addPoint #######////####### addPoint #######//

void ListPoint2::addPoint(Point* P)
{
  P -> nxt = firstPoint -> nxt;
  firstPoint -> nxt = P;
  length = length + 1;
}


//####### deleteNxtPoint #######////####### deleteNxtPoint #######////####### deleteNxtPoint #######//
//####### deleteNxtPoint #######////####### deleteNxtPoint #######////####### deleteNxtPoint #######//



void ListPoint2::deleteNxtPointAndMove()
{
  Point* pointToDelete = currentPosition -> nxt;
  currentPosition -> nxt = currentPosition -> nxt -> nxt;
  length = length - 1;
  delete(pointToDelete);
}

//####### initializeCurrentPosition #######////####### initializeCurrentPosition #######////####### initializeCurrentPosition #######//
//####### initializeCurrentPosition #######////####### initializeCurrentPosition #######////####### initializeCurrentPosition #######//

void ListPoint2::initializeCurrentPosition()
{currentPosition = firstPoint;}


//####### move #######////####### move #######////####### move #######//
//####### move #######////####### move #######////####### move #######//


void ListPoint2::move()
{
  currentPosition = currentPosition -> nxt;
}








