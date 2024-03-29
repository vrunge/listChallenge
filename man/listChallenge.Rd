% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/listChallenge.R
\name{listChallenge}
\alias{listChallenge}
\title{listChallenge}
\usage{
listChallenge(length, batch, prob, method = "std", default_length = -1)
}
\arguments{
\item{length}{number of element to add into the list}

\item{batch}{number of elements to add at each loop}

\item{prob}{probability of deleting an element. The list is scanned after each batch loop}

\item{method}{the method to use: std, vr1, vr2, al1, al2,...}

\item{default_length}{number of elements in memory block (only needed for al3)}
}
\value{
a list with (i) the number of elements in the list after each loop (nb) and (ii) the overall system time in seconds (time)
}
\description{
Challenge different singly linked lists written in C++ with a simplified structure. The only needed operations are : add element / delete element. Each element is made of two random unsigned integers obtained with the C rand function.
}
