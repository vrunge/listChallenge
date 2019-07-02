// MIT License
// Copyright (c) 2019 Arnaud Liehrmann

#ifndef POINT_DOUBLY_H
#define POINT_DOUBLY_H

#include <math.h>

class PointDoubly
{
  public:
    PointDoubly(unsigned int s, unsigned int t);
    unsigned int state;
    unsigned int time;
    PointDoubly* nxt;
    PointDoubly* prev;
};

#endif // POINT_H
