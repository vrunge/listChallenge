<a id="top"></a>

<!-- 
%\VignetteEngine{knitr::rmarkdown} 
%\VignetteIndexEntry{listChallenge}
--> 

# listChallenge
### July 1st, 2019

**Contributors :**

* Vincent Runge (Evry University). method : std, vr1, vr2, vr3

* Arnaud Liehrmann (M1 student Evry University). method : al1, al2, al3, al4


> [The challenge](#challenge)

> [How to add a new list structure?](#list)

> [The listChallenge function](#function)

> [Description of the methods](#methods)

> [The competition](#competition)


<a id="challenge"></a>

## The challenge

Dynamic programming for changepoint detection is based on the search for the minimal value in a set. This set is encoded by a linked list with only two necessary properties : add element and delete element.

This challenge consists in coding the **fastest possible** list structure in C++. Precisely, our main function has 3 parameters :

- ***length*** : the number of elements to add in the list

- ***batch*** : the number of elements to add at each loop

- ***prob*** : the probability to delete an element

 
The number of loops is determined by the greatest integers `p` such that `batch x p <= length`. At the end of each loop (after adding `batch` elements), the algorithm scans all the elements of the list and for each element decides to delete it (or not) with a probability `prob`.

In our implementation, the elements are called `Point` (instance of the `Point` class). Each Point is made of two unsigned integers whose values are chosen randomly with the C++ rand() operator.

The method to use is defined in the `method` parameter of the main function `listChallenge`. Notice that this function returns two parameters, the system time and `nb` which contains the number of elements in the list at the end of the dynamic programming algorithm.

<a id="list"></a>

## How to add a new list structure?

1) add a new exception in the error message in **listChallenge.R**

`if(method != "std" && method != "mylist" && method != "mylist2"){stop('Argument "method" not appropriate. Choose among "std", "mylist" or "mylist2')}`

2) add a new line in **listChallenge.cpp** to call your function (here `list_mynewlist`)

`if(method == "mynewlist"){omega.list_mynewlist(nbLoops, batch, prob);}`

3) This previous code means that you have to add a member function `list_mynewlist` in the `Omega` class.

4) In **Omega.cpp** you can include the header of your new list class. As for example `#include "ListPoint.h"` or `#include "ListPoint2.h"`.


<a id="function"></a>

## The listChallenge function

We install the package from Github:


```r
#devtools::install_github("vrunge/listChallenge")
library(listChallenge)
```

And challenge the 7 available functions :

```r
listChallenge(length = 10^7, batch = 10^4, prob = 0.1, method = "std")
```

```
## $finalLength
## [1] 90022
## 
## $time
## [1] 3.498905
```

```r
listChallenge(length = 10^7, batch = 10^4, prob = 0.1, method = "vr1")
```

```
## $finalLength
## [1] 89987
## 
## $time
## [1] 3.260789
```

```r
listChallenge(length = 10^7, batch = 10^4, prob = 0.1, method = "vr2")
```

```
## $finalLength
## [1] 90362
## 
## $time
## [1] 3.535025
```

```r
listChallenge(length = 10^7, batch = 10^4, prob = 0.1, method = "vr3")
```

```
## $finalLength
## [1] 90088
## 
## $time
## [1] 3.215803
```

```r
listChallenge(length = 10^7, batch = 10^4, prob = 0.1, method = "al1")
```

```
## $finalLength
## [1] 89773
## 
## $time
## [1] 3.353224
```

```r
listChallenge(length = 10^7, batch = 10^4, prob = 0.1, method = "al2")
```

```
## $finalLength
## [1] 89615
## 
## $time
## [1] 3.377432
```

```r
listChallenge(length = 10^7, batch = 10^4, prob = 0.1, method = "al3", default_length= 10^7)
```

```
## $finalLength
## [1] 90385
## 
## $time
## [1] 2.4966
```

```r
listChallenge(length = 10^7, batch = 10^4, prob = 0.1, method = "al4")
```

```
##$finalLength
##[1] 90333
##
##$time
##[1] 2.4756
```

Notice that the number of elements after the last loop is in the `finalLength` parameter.

<a id="methods"></a>

## Description of the methods

### Singly-linked list

1) *vr1*

In this implementation elements are added at the beginning (the head) of the list. The head is a dummy element. We loop through and delete elements of the list with the pointer `currentPosition` on which we can act with the methods `initializeCurrentPoisition`, `deleteNxtPoint` and `move`.

2) *vr2*

Same as *vr1*. In addition to that, we save the length of the list so that we know how many elements we have to loop on.

3) *vr3*

Same as *vr2*. In addition to that, we keep a pointer on the element minus one pointed by `currentPosition`.

4) *al3*

In this implementation default elements are instantiated by blocks (contigously in the memory) and linked to each other. The number of elements in one block is defined by the user. We keep a pointer on the last element of the list so that when an element is deleted it is actually linked at the end of the list. When the list contain more elements than can contain one block, we instantiate another block of default elements. Then the last element of the list is linked to the first element of the new block. In the same way as *al1* and *al2*, we loop through and delete elements of the list with the pointer `currentPosition` on which we can act with the methods `initializeCurrentPoisition`, `deleteNxtPoint` and `move`.

5) *al4*

In this implementation, the list has two states: active and inactive . We keep a pointer (`lastActivePosition`) on the last element of the active part. We also keep a pointer (`tail`) on the last element of the list, not necessarily active, so that when an element is deleted it is actually linked at the end of the list. We loop through and delete elements of the list with the pointer `currentPosition` on which we can act with the methods `initializeCurrentPoisition`, `deleteNxtPoint` and `move`.

### Doubly-linked list

1) *std*

Implementation that uses the doubly-linked list available in the standard library. The elements are added and deleted with the respective methods `push_back` and `erase`. We loop through the list with an iterator.

2) *al1*

In this implementation the doubly-linked list is actually circular. A dummy element, the `sentinel`, plays the role of head and tail to prevent border effects. We loop through and delete elements of the list with the pointer `currentPosition` on which we can act with the methods `initializeCurrentPoisition`, `deleteNxtPoint` and `move`.

3) *al2*

Same as *al1*. In addition to that, we save the length of the list so that we know how many elements we have to loop on.

<a id="competition"></a>

## The competition

![ ](img/time_comp_plot.png)

![ ](img/time_comp_plot2.png)

![ ](img/time_comp_plot3.png)

[Back to Top](#top)
