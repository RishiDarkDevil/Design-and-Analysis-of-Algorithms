# Problem
Given a sorted(ascending) array `a` of length $n$ and a number $x$, determine the exact number of steps required to perform Binary Search on the given array.

# Algorithm
- Calculate $mid = \lfloor\frac{n}{2}\rfloor$.
- If $x > a[mid]$, set $a=a[(mid+1):]$ i.e. the array, right of $mid$.
- Else if $x < a[mid] $, set $a=a[:mid]$ i.e. the array, left of $mid$. 
- Else $x = a[mid]$, return found and exit.
- Otherwise if length of $a$ becomes $1$, return not found and exit.

# Worst Case Complexity
Now, the worst case arises when the array, `a`, does not contains the element $x$. In this case, we will keep on halving the array size at each step and it will continue till the array size decreases to $0$.
So, $n/(2^{steps}) = 1$ i.e. at each step the array size keeps on getting half and this goes on till the array has $1$ element.\
Hence, the number $steps = log_2(n)$. But we see when the length of the array is not equal to some power of $2$, then the $steps$ required is the $\lceil log_2(n)\rceil$.

n | steps
--|--
1 | 0
2 |	1
3 |	1
4 |	2
5 |	2
6 |	2
7 |	2
8 |	3
9 |	3
10 | 3
