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
List listChallenge_cpp(unsigned int nbLoops, unsigned int batch, double prob, std::string method = "std")
{
  Omega omega = Omega();

  /// the different methods
  if(method == "std"){omega.list_std(nbLoops, batch, prob);}
  if(method == "mylist"){omega.list_mylist(nbLoops, batch, prob);}
  if(method == "mylist2"){omega.list_mylist2(nbLoops, batch, prob);}
  if(method == "doublylinkedlist"){omega.list_doublylinked(nbLoops, batch, prob);}
  if(method == "doublylinkedlist2"){omega.list_doublylinked(nbLoops, batch, prob);}


  List res = List::create(_["nbElements"] = omega.GetNb());

  return res;
}
