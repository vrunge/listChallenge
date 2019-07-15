//
// MIT License
// Copyright (c) 2019 Vincent Runge
//

#include "Omega.h"

#include "ListPoint.h"
#include "ListPoint2.h"
#include "ListPoint3.h"
#include "DoublyLinkedListPoint.h"
#include "DoublyLinkedListPoint2.h"
#include "SinglyLinkedList4.h";

#include "Point.h"
#include "Point_std.h"
#include "PointDoubly.h"

#include<iostream>

#include <stdio.h>
#include <stdlib.h>

Omega::Omega(){}

unsigned int Omega::GetLength() const
{
  return(length);
}


//####### list_std #######////####### list_std #######////####### list_std #######//
//####### list_std #######////####### list_std #######////####### list_std #######//

void Omega::list_std(unsigned int nbLoops, unsigned int batch, double prob)
{
  std::list<Point_std> myList;
  std::list<Point_std>::iterator it;

  for(unsigned int i = 0; i < nbLoops; i++)
  {
    ///ADD bach elements
    for(unsigned int j = 0; j < batch; j++)
    {
      myList.push_back(Point_std(rand(),rand()));
    }

    /////DELETE a proportion prob of elements
    it = myList.begin();
    while (it != myList.end())
    {
      if(rand()/(1.0*RAND_MAX) < prob){it = myList.erase(it);
      }else{it++;}
    }
  }

  unsigned int count = 0;
  it = myList.begin();
  while(it != myList.end()){count = count + 1; it++;}
  length = count;

}


//####### list_mylist #######////####### list_mylist #######////####### list_mylist #######//
//####### list_mylist #######////####### list_mylist #######////####### list_mylist #######//

void Omega::list_mylist(unsigned int nbLoops, unsigned int batch, double prob)
{
  bool mov;
  ListPoint* myList = new ListPoint();

  for(unsigned int i = 0; i < nbLoops; i++)
  {
    ///ADD bach elements
    for(unsigned int j = 0; j < batch; j++)
    {
      myList -> addPoint(new Point(rand(),rand()));
    }

    /////DELETE a proportion prob of elements
    myList -> initializeCurrentPosition();
    mov = true;
    while(mov == true)
    {
      if(rand()/(1.0*RAND_MAX) < prob){myList -> deleteNxtPoint();}
        else{mov = myList -> move();}
    }
  }
  unsigned int count = 0;
  myList -> initializeCurrentPosition();
  mov = true;
  while(mov == true)
  {
    count = count + 1;
    mov = myList -> move();
  }
  length = count;

  delete(myList);
}



//####### list_mylist2 #######////####### list_mylist2 #######////####### list_mylist2 #######//
//####### list_mylist2 #######////####### list_mylist2 #######////####### list_mylist2 #######//

void Omega::list_mylist2(unsigned int nbLoops, unsigned int batch, double prob)
{
  unsigned int n;
  ListPoint2* myList = new ListPoint2();

  for(unsigned int i = 0; i < nbLoops; i++)
  {
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
      if(rand()/(1.0*RAND_MAX) < prob){myList -> deleteNxtPointAndMove();}
      else{myList -> move();}
    }

    length = myList -> getLength();
  }

  delete(myList);
}



//####### list_mylist3 #######////####### list_mylist3 #######////####### list_mylist3 #######//
//####### list_mylist3 #######////####### list_mylist3 #######////####### list_mylist3 #######//

void Omega::list_mylist3(unsigned int nbLoops, unsigned int batch, double prob)
{
  unsigned int n;
  ListPoint3* myList = new ListPoint3();

  for(unsigned int i = 0; i < nbLoops; i++)
  {
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
      if(rand()/(1.0*RAND_MAX) < prob){myList -> deleteNxtPointAndMove();}
      else{myList -> move();}
    }

    length = myList -> getLength();
  }

  delete(myList);
}

//####### doublylinkedlist #######////####### doublylinkedlist #######////####### doublylinkedlist #######//
//####### doublylinkedlist #######////####### doublylinkedlist #######////####### doublylinkedlist #######//

void Omega::list_doublylinked(unsigned int nbLoops, unsigned int batch, double prob)
{
  DoublyLinkedListPoint* myList = new DoublyLinkedListPoint();
  length = 0;
  for(unsigned int i = 0; i < nbLoops; i++)
  {
    ///ADD bach elements
    for(unsigned int j = 0; j < batch; j++)
    {
      myList -> addPoint(new PointDoubly(rand(),rand()));
      length++;
    }
    ///DELETE a proportion prob of elements
    myList -> initializeCurrentPosition();
    while (myList->nextPointIsNotSentinel())
    {
      if(rand()/(1.0*RAND_MAX) < prob){myList -> deleteNextPoint();length--;}
      else{myList -> move();}
    }
  }

  delete(myList);
}


//####### doublylinkedlist2 #######////####### doublylinkedlist2 #######////####### doublylinkedlist2 #######//
//####### doublylinkedlist2 #######////####### doublylinkedlist2 #######////####### doublylinkedlist2 #######//

void Omega::list_doublylinked2(unsigned int nbLoops, unsigned int batch, double prob)
{
  unsigned int n;
  DoublyLinkedListPoint2* myList = new DoublyLinkedListPoint2();

  for(unsigned int i = 0; i < nbLoops; i++)
  {
    ///ADD bach elements
    for(unsigned int j = 0; j < batch; j++)
    {
      myList -> addPoint(new PointDoubly(rand(),rand()));
    }
    ///DELETE a proportion prob of elements
    myList -> initializeCurrentPosition();
    n = myList -> getLength();
    for (unsigned int z = 0; z<n; z++)
    {
      if(rand()/(1.0*RAND_MAX) < prob){myList -> deleteNextPoint();}
      else{myList -> move();}
    }
  length = myList->getLength();
  }

  delete(myList);
}


//####### SinglyLinkedList4 #######////####### SinglyLinkedList4 #######////####### SinglyLinkedList4 #######//
//####### SinglyLinkedList4 #######////####### SinglyLinkedList4 #######////####### SinglyLinkedList4 #######//


void Omega::list_SinglyLinkedList4(unsigned int nbLoops, unsigned int batch, double prob)
{
  unsigned int n;
  SinglyLinkedList4 myList = SinglyLinkedList4(nbLoops*batch);

  for(unsigned int i = 0; i < nbLoops; i++)
  {
    ///ADD bach elements
    for(unsigned int j = 0; j < batch; j++)
    {
      myList.addPoint(rand(),rand());
    }

    ///DELETE a proportion prob of elements
    myList.initializeCurrentPosition();
    n = myList.getLength();
    for(unsigned int i = 0; i < n;i++)
    {
      if(rand()/(1.0*RAND_MAX) < prob){myList.deleteNxtPointAndMove();}
      else{myList.move();}
    }
  }
  length = myList.getLength();
}