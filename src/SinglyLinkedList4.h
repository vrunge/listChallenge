#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "Point.h"

class SinglyLinkedList4
{
    private:
    Point * head;
    Point * currentPosition;
    Point * lastPosition;
    unsigned int length;

    public:
    SinglyLinkedList4(unsigned int size);
    ~SinglyLinkedList4();
    void move();
    void addPoint(unsigned int a, unsigned int b);
    void deleteNxtPointAndMove();
    void initializeCurrentPosition();
    unsigned int getLength();

};

#endif