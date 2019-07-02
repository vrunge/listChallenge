// MIT License
// Copyright (c) 2019 Vicent Runge

#include "DoublyLinkedListPoint2.h"
#include<iostream>

#include "math.h"



//####### constructor #######////####### constructor #######////####### constructor #######//
//####### constructor #######////####### constructor #######////####### constructor #######//

DoublyLinkedListPoint2::DoublyLinkedListPoint2()
{
  sentinel = new PointDoubly(0,0);
  currentPosition = sentinel;
  length = 0;
}

//####### accessor #######////####### accessor #######////####### accessor #######//
//####### accessor #######////####### accessor #######////####### accessor #######//

unsigned int DoublyLinkedListPoint2::getState()
  {return(currentPosition -> nxt -> state);}


unsigned int DoublyLinkedListPoint2::getTime()
  {return(currentPosition -> nxt -> time);}




//####### addPoint #######////####### addPoint #######////####### addPoint #######//
//####### addPoint #######////####### addPoint #######////####### addPoint #######//

void DoublyLinkedListPoint2::addPoint(PointDoubly* P)
{
  sentinel->prev->nxt = P;
  P->prev = sentinel->prev;
  sentinel->prev = P;
  P->nxt = sentinel;
  length++;
}

//####### deleteCurrentPoint #######////####### deleteCurrentPoint #######////####### deleteCurrentPoint #######//
//####### deleteCurrentPoint #######////####### deleteCurrentPoint #######////####### deleteCurrentPoint #######//

void DoublyLinkedListPoint2::deleteNextPoint()
{
  PointDoubly * P = currentPosition -> nxt;
  P->prev->nxt = P->nxt;
  P->nxt->prev = P->prev;
  delete P;
  length--;
}

//####### initializeCurrentPosition #######////####### initializeCurrentPosition #######////####### initializeCurrentPosition #######//
//####### initializeCurrentPosition #######////####### initializeCurrentPosition #######////####### initializeCurrentPosition #######//

void DoublyLinkedListPoint2::initializeCurrentPosition()
{currentPosition = sentinel;}


//####### move #######////####### move #######////####### move #######//
//####### move #######////####### move #######////####### move #######//


void DoublyLinkedListPoint2::move()
{
  currentPosition = currentPosition -> nxt;
}

unsigned int DoublyLinkedListPoint2::getLength()
{
  return length;
}