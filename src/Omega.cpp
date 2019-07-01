//
// MIT License
// Copyright (c) 2019 Vincent Runge
//

#include "Omega.h"

#include "ListPoint.h"
#include "ListPoint2.h"

#include "Point.h"
#include "Point_std.h"

#include<iostream>
#include <stdlib.h>

Omega::Omega(){}

std::vector< unsigned int > Omega::GetNb() const
{
  return(nb);
}


//####### list_std #######////####### list_std #######////####### list_std #######//
//####### list_std #######////####### list_std #######////####### list_std #######//

void Omega::list_std(unsigned int nbLoops, unsigned int batch, double prob)
{
  unsigned int count = 0;
  std::list<Point_std*> myList;
  std::list<Point_std*>::iterator it;

  for(unsigned int i = 0; i < nbLoops; i++)
  {
    count = 0;
    ///ADD bach elements
    for(unsigned int j = 0; j < batch; j++)
    {
      myList.push_back(new Point_std(rand(),rand()));
    }

    ///DELETE a proportion prob of elements
    it = myList.begin();
    while (it != myList.end())
    {
      count = count + 1;
      if(rand()/(1.0*RAND_MAX) < prob){myList.erase(it);}
      it++;
    }
    nb.push_back(count);
  }
}


//####### list_mylist #######////####### list_mylist #######////####### list_mylist #######//
//####### list_mylist #######////####### list_mylist #######////####### list_mylist #######//

void Omega::list_mylist(unsigned int nbLoops, unsigned int batch, double prob)
{
  bool mov;
  unsigned int count = 0;
  ListPoint* myList = new ListPoint();

  for(unsigned int i = 0; i < nbLoops; i++)
  {
    count = 0;
    ///ADD bach elements
    for(unsigned int j = 0; j < batch; j++)
    {
      myList -> addPoint(new Point(rand(),rand()));
    }

    ///DELETE a proportion prob of elements
    myList -> initializeCurrentPosition();
    mov = true;
    while(mov == true)
    {
      count = count + 1;
      if(rand()/(1.0*RAND_MAX) < prob){myList -> deleteNxtPoint();}
        else{mov = myList -> move();}
    }

    nb.push_back(count);
  }

  delete(myList);
}



//####### list_mylist2 #######////####### list_mylist2 #######////####### list_mylist2 #######//
//####### list_mylist2 #######////####### list_mylist2 #######////####### list_mylist2 #######//

void Omega::list_mylist2(unsigned int nbLoops, unsigned int batch, double prob)
{
  unsigned int n;
  unsigned int count = 0;
  ListPoint2* myList = new ListPoint2();

  for(unsigned int i = 0; i < nbLoops; i++)
  {
    count = 0;
    ///ADD bach elements
    for(unsigned int j = 0; j < batch; j++)
    {
      myList -> addPoint(new Point(rand(),rand()));
    }

    ///DELETE a proportion prob of elements
    myList -> initializeCurrentPosition();
    n = myList -> getLength();
    for(unsigned int i = 0; i < n;i++)
    {
      count = count + 1;
      if(rand()/(1.0*RAND_MAX) < prob){myList -> deleteNxtPointAndMove();}
      else{myList -> move();}
    }

    nb.push_back(count);
  }

  delete(myList);
}
