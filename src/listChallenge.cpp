// MIT License
// Copyright (c) 2019 Vincent Runge

#include<Rcpp.h>
// Enable C++11 via this plugin (Rcpp 0.10.3 or later)
// [[Rcpp::plugins(cpp11)]]

#include"Omega.h"
#include<vector>

using namespace std;
using namespace Rcpp;

// [[Rcpp::export]]
unsigned int listChallenge_cpp(unsigned int nbLoops, unsigned int batch, double prob, std::string method, int default_length)
{
  Omega omega = Omega();

  /// the different methods
  if(method == "std"){omega.list_std(nbLoops, batch, prob);}
  if(method == "vr1"){omega.list_mylist(nbLoops, batch, prob);}
  if(method == "vr2"){omega.list_mylist2(nbLoops, batch, prob);}
  if(method == "vr3"){omega.list_mylist3(nbLoops, batch, prob);}
  if(method == "al1"){omega.list_doublylinked(nbLoops, batch, prob);}
  if(method == "al2"){omega.list_doublylinked2(nbLoops, batch, prob);}
  if(method == "al3"){omega.list_SinglyLinkedList4(nbLoops, batch, prob, default_length);}
  if(method == "al4"){omega.list_SinglyLinkedList5(nbLoops, batch, prob);}

  return omega.GetLength();
}
