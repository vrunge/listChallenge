<a id="top"></a>

<!-- 
%\VignetteEngine{knitr::rmarkdown} 
%\VignetteIndexEntry{listChallenge}
--> 

# listChallenge
### July 1st, 2019

**Contributors :**

-- Vincent Runge (Evry University). method : std, mylist, mylist2

-- ...

-- ...



> [The challenge](#challenge)

> [How to add a new list structure?](#list)

> [The listChallenge function](#function)


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

And challenge the 3 available functions :

```r
l1 <- listChallenge(length = 10^7, batch = 10^4, prob = 0.1, method = "std")
l2 <- listChallenge(length = 10^7, batch = 10^4, prob = 0.1, method = "mylist")
l3 <- listChallenge(length = 10^7, batch = 10^4, prob = 0.1, method = "mylist2")
l1$time
```

```
## [1] 5.810064
```

```r
l2$time
```

```
## [1] 7.160098
```

```r
l3$time
```

```
## [1] 2.918087
```

We observe the pruning efficiency in the nb response parameter

```r
listChallenge(length = 10^4, batch = 10^2, prob = 0.1, method = "std")
```

```
## $nb
##   [1]  100  194  277  346  404  472  521  571  620  644  673  712  732  775
##  [15]  807  840  861  877  882  895  899  912  904  907  926  933  931  952
##  [29]  951  958  968  965  949  950  957  974  998  998 1003 1011 1027 1027
##  [43] 1020 1028 1019 1001  997 1001 1012 1016 1014 1000  987  997 1004 1006
##  [57]  990 1003 1009 1001 1012 1022 1012 1003  992  994  995  986  990  995
##  [71] 1003 1012 1006  991  999  991  992  998 1003  997  982  992  993  992
##  [85] 1002  997 1010 1006 1011 1023 1033 1031 1033 1046 1042 1028 1029 1024
##  [99] 1024 1017
## 
## $time
## [1] 0.003118277
```


[Back to Top](#top)
