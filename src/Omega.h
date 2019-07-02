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
    std::vector< unsigned int > GetNb() const;

    void list_std(unsigned int nbLoops, unsigned int batch, double prob);
    void list_mylist(unsigned int nbLoops, unsigned int batch, double prob);
    void list_mylist2(unsigned int nbLoops, unsigned int batch, double prob);
    void list_doublylinked(unsigned int nbLoops, unsigned int batch, double prob);
    void list_doublylinked2(unsigned int nbLoops, unsigned int batch, double prob);
  private:
    std::vector< unsigned int > nb;
};

#endif // OMEGA_H
