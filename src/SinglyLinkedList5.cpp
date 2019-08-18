#include "SinglyLinkedList5.h"
#include "Point.h"
#include <iostream>
#include "stdlib.h"


SinglyLinkedList5::SinglyLinkedList5()
{
    lengthList = 0;
    head = new Point(0,0);
    head -> nxt = NULL;
    lastActivePosition = head;
    tail = head;
    currentPosition = head;
}

void SinglyLinkedList5::addPoint(unsigned int s, unsigned int t)
{
    if (lastActivePosition -> nxt == NULL)
    {
        tail = new Point(s,t);
        lastActivePosition -> nxt = tail;
        lastActivePosition = lastActivePosition->nxt;
    }
    else
    {
        lastActivePosition = lastActivePosition->nxt;
        lastActivePosition->state = s;
        lastActivePosition->time = t;
    }
    lengthList ++;
}

void SinglyLinkedList5::move()
{
    currentPosition = currentPosition->nxt;
}

unsigned int SinglyLinkedList5::getLength()
{
    return lengthList;
}

SinglyLinkedList5::~SinglyLinkedList5()
{
  while(head != NULL)
  {
    Point* pointToDelete = head;
    head = head -> nxt;
    delete(pointToDelete);
  }
}

void SinglyLinkedList5::initializeCurrentPosition()
{
    currentPosition = head;
}

void SinglyLinkedList5::deleteNxtPointAndMove(){
    tail -> nxt = currentPosition -> nxt;
    currentPosition -> nxt = currentPosition->nxt->nxt;
    tail->nxt->nxt = NULL;
    tail = tail->nxt;
    lengthList--;
}
