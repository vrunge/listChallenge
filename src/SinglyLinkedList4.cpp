#include "SinglyLinkedList4.h"
#include "Point.h"
#include "stdlib.h"

SinglyLinkedList4::SinglyLinkedList4(unsigned int size)
{
    head = (Point *) calloc(size+1, sizeof(Point));
    for (unsigned int i =0; i<size; i++)
    {
        head[i].nxt = head+i+1;
    }
    head[size].nxt = NULL;
    length = 0;
    lastPosition = head->nxt;
    currentPosition = head;
}

void SinglyLinkedList4::addPoint(unsigned int s, unsigned int t)
{   
    lastPosition->state = s;
    lastPosition->time = t;
    lastPosition = lastPosition->nxt;
    length++;
}

void SinglyLinkedList4::move()
{
    currentPosition = currentPosition->nxt;
}

unsigned int SinglyLinkedList4::getLength()
{
    return length;
}

SinglyLinkedList4::~SinglyLinkedList4()
{
    free(head);
}

void SinglyLinkedList4::initializeCurrentPosition()
{
    currentPosition = head;
}

void SinglyLinkedList4::deleteNxtPointAndMove(){
    currentPosition -> nxt = currentPosition->nxt->nxt;
    length--;
}
