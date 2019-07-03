// MIT License
// Copyright (c) 2019 Vincent Runge

#ifndef OMEGA_H
#define OMEGA_H

#include <math.h>
#include<vector>
#include <list>

class Omega
{
  public:
    Omega();
    unsigned int GetLength() const;

    void list_std(unsigned int nbLoops, unsigned int batch, double prob);
    void list_mylist(unsigned int nbLoops, unsigned int batch, double prob);
    void list_mylist2(unsigned int nbLoops, unsigned int batch, double prob);
    void list_doublylinked(unsigned int nbLoops, unsigned int batch, double prob);
    void list_doublylinked2(unsigned int nbLoops, unsigned int batch, double prob);
  private:
    unsigned int length;
};

#endif // OMEGA_H
