#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "Point.h"
#include <vector>

class SinglyLinkedList4
{
    private:
    Point * head;
    Point * currentPosition;
    Point * lastPosition;
    Point * tail;
    unsigned int lengthList;
    unsigned int resizeConst;
    std::vector<Point *> headVec;

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