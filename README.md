<a id="top"></a>

<!-- 
%\VignetteEngine{knitr::rmarkdown} 
%\VignetteIndexEntry{listChallenge}
--> 

# listChallenge
### July 1st, 2019

**Contributors :**

* Vincent Runge (Evry University). method : std, vr1, vr2

* Arnaud Liehrmann (M1 student Evry University). method : al1, al2

* ...


> [The challenge](#challenge)

> [How to add a new list structure?](#list)

> [The listChallenge function](#function)

> [Description of the methods](#methods)

> [The competition](#competition)


<a id="challenge"></a>

## The challenge

Dynamic programming for changepoint detection is based on the search for the minimal value in a set. This set is encoded by a linked list with only two necessary properties : add element and delete element.

This challenge consists in coding the **fastest possible** list structure in C++. Precisely, our main function has 3 parameters :

-- ***length*** : the number of elements to add in the list

-- ***batch*** : the number of elements to add at each loop

-- ***prob*** : the probability to delete an element

 
The number of loops is determined by the greatest integers `p` such that `batch x p <= length`.
At the end of each loop (after adding `batch` elements), the algorithm scans all the elements of the list and for each element chooses to delete it with a probability `prob`.

In our implementation, the elements are called `Point` (instance of the `Point` class). Each Point is made of two unsigned integers whose values are chosen randomly with the C++ rand() operator.

The method to use is defined in the `method` parameter of the main function `listChallenge`. Notice that this function returns two parameters, the system time and `nb` which contains the number of elements in the list after the batch loop (but before the pruning loop with probability `prob`) 

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

And challenge the 5 available functions :

```r
listChallenge(length = 10^7, batch = 10^4, prob = 0.1, method = "std")
```

```
## $finalLength
## [1] 89942
## 
## $time
## [1] 3.125883
```

```r
listChallenge(length = 10^7, batch = 10^4, prob = 0.1, method = "vr1")
```

```
## $finalLength
## [1] 90077
## 
## $time
## [1] 3.034521
```

```r
listChallenge(length = 10^7, batch = 10^4, prob = 0.1, method = "vr2")
```

```
## $finalLength
## [1] 90079
## 
## $time
## [1] 3.187864
```

```r
listChallenge(length = 10^7, batch = 10^4, prob = 0.1, method = "al1")
```

```
## $finalLength
## [1] 100020
## 
## $time
## [1] 4.349238
```

```r
listChallenge(length = 10^7, batch = 10^4, prob = 0.1, method = "al2")
```

```
## $finalLength
## [1] 99965
## 
## $time
## [1] 3.421283
```

Notice that the number of elements after the last loop is in the `finalLength` parameter.

<a id="methods"></a>

## Description of the methods


<a id="competition"></a>

## The competition


[Back to Top](#top)
