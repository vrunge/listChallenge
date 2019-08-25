#ifndef LINKED_LIST2_H
#define LINKED_LIST2_H

#include "Point.h"
#include <vector>

class SinglyLinkedList5
{
    private:
    Point * head;
    Point * currentPosition;
    Point * lastActivePosition;
    Point * tail;
    unsigned int lengthList;

    public:
    SinglyLinkedList5();
    ~SinglyLinkedList5();
    void move();
    void addPoint(unsigned int a, unsigned int b);
    void deleteNxtPointAndMove();
    void initializeCurrentPosition();
    unsigned int getLength();

};

#endif
