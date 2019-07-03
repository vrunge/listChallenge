// MIT License
// Copyright (c) 2019 Vicent Runge

#include "DoublyLinkedListPoint.h"
#include<iostream>

#include "math.h"



//####### constructor #######////####### constructor #######////####### constructor #######//
//####### constructor #######////####### constructor #######////####### constructor #######//

DoublyLinkedListPoint::DoublyLinkedListPoint()
{
  sentinel = new PointDoubly(0,0);
  currentPosition = sentinel;
}

//####### accessor #######////####### accessor #######////####### accessor #######//
//####### accessor #######////####### accessor #######////####### accessor #######//

unsigned int DoublyLinkedListPoint::getState()
  {return(currentPosition -> nxt -> state);}


unsigned int DoublyLinkedListPoint::getTime()
  {return(currentPosition -> nxt -> time);}




//####### addPoint #######////####### addPoint #######////####### addPoint #######//
//####### addPoint #######////####### addPoint #######////####### addPoint #######//

void DoublyLinkedListPoint::addPoint(PointDoubly* P)
{
  sentinel->prev->nxt = P;
  P->prev = sentinel->prev;
  sentinel->prev = P;
  P->nxt = sentinel;
}

//####### deleteCurrentPoint #######////####### deleteCurrentPoint #######////####### deleteCurrentPoint #######//
//####### deleteCurrentPoint #######////####### deleteCurrentPoint #######////####### deleteCurrentPoint #######//

void DoublyLinkedListPoint::deleteNextPoint()
{
  PointDoubly * P = currentPosition -> nxt;
  P->prev->nxt = P->nxt;
  P->nxt->prev = P->prev;
  delete P;
}

//####### initializeCurrentPosition #######////####### initializeCurrentPosition #######////####### initializeCurrentPosition #######//
//####### initializeCurrentPosition #######////####### initializeCurrentPosition #######////####### initializeCurrentPosition #######//

void DoublyLinkedListPoint::initializeCurrentPosition()
{currentPosition = sentinel;}


//####### move #######////####### move #######////####### move #######//
//####### move #######////####### move #######////####### move #######//


void DoublyLinkedListPoint::move()
{
  currentPosition = currentPosition -> nxt;
}

//####### checkSentinel #######////####### checkSentinel #######////####### checkSentinel #######//
//####### checkSentinel #######////####### checkSentinel #######////####### checkSentinel #######//

bool DoublyLinkedListPoint::nextPointIsNotSentinel()
{
  return currentPosition->nxt != sentinel;
}

//####### destructor #######////####### destructor #######////####### destructor #######//
//####### destructor #######////####### destructor #######////####### destructor #######//

DoublyLinkedListPoint::~DoublyLinkedListPoint()
{
  sentinel->prev->nxt=NULL;
  while(sentinel != NULL)
  {
    PointDoubly* pointToDelete = sentinel;
    sentinel = sentinel -> nxt;
    delete(pointToDelete);
  }
}

