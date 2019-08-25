#include "SinglyLinkedList4.h"
#include "Point.h"
#include <iostream>
#include "stdlib.h"

SinglyLinkedList4::SinglyLinkedList4(unsigned int size)
{
    resizeConst = size;
    lengthList = 0;
    head = (Point *) calloc(size+1, sizeof(Point));
    for (unsigned int i =0; i<size; i++)
    {
        head[i].nxt = head+i+1;
    }
    head[size].nxt = NULL;
    tail = head+size;
    lastPosition = head->nxt;
    currentPosition = head;
    headVec.push_back(head);
}

void SinglyLinkedList4::addPoint(unsigned int s, unsigned int t)
{
    lastPosition->state = s;
    lastPosition->time = t;
    if (lastPosition->nxt == NULL){
        Point * newHead = (Point *) calloc(resizeConst, sizeof(Point));
        for (unsigned int i =0; i<resizeConst-1; i++)
        {
        newHead[i].nxt = newHead+i+1;
        }
        newHead[resizeConst-1].nxt = NULL;
        tail = newHead + resizeConst -1;
        lastPosition -> nxt = newHead;
        headVec.push_back(newHead);
    }
    lastPosition = lastPosition->nxt;
    lengthList++;
}

void SinglyLinkedList4::move()
{
    currentPosition = currentPosition->nxt;
}

unsigned int SinglyLinkedList4::getLength()
{
    return lengthList;
}

SinglyLinkedList4::~SinglyLinkedList4()
{
    for (Point * h:headVec)
    {
        free(h);
    }
}

void SinglyLinkedList4::initializeCurrentPosition()
{
    currentPosition = head;
}

void SinglyLinkedList4::deleteNxtPointAndMove(){
    tail -> nxt = currentPosition -> nxt;
    currentPosition -> nxt = currentPosition->nxt->nxt;
    tail->nxt->nxt = NULL;
    tail = tail->nxt;
    lengthList--;
}
