// MIT License
// Copyright (c) 2019 Arnaud Liehrmann

#include "PointDoubly.h"
#include<iostream>

#include "math.h"

//####### constructor #######////####### constructor #######////####### constructor #######//
//####### constructor #######////####### constructor #######////####### constructor #######//

PointDoubly::PointDoubly(unsigned int s, unsigned int t) : state(s), time(t), prev(this), nxt(this){}

