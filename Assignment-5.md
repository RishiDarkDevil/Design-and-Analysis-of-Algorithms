# Problem
Find the average time complexity of finding the $k^{th}$ smallest element of the array( $arr$) of size $n$ using the following algorithm.

# Algorithm
- Randomly select any index $i$ from $1$ to $n$.
- Determine the number of elements smaller than $arr[i]$ in the array and store them in $LESSER$ array and the remaining elements except $arr[i]$ in $GREATER$ array.
- If size of $LESSER \le k-1$ repeat the algorithm by taking $GREATER$ as our original array. 
- If size of $LESSER \ge k-1$ repeat the algorithm by taking $GREATER$ as our original array.
- Otherwise size of $LESSER = k-1$ which implies $arr[i]$ is the $k^{th}$ smallest element of the array.

# Proof
- The worst case complexity is ofcourse $O(n^2)$ since, at each step in the worst case we either pick up the maximum or the minimum element of the array and have to search again in the array of size $n-1$, $n-2$ and so on.
- Whereas we are interested in the average case complexity for randomly but uniformly distributed numbers for the array. The randomly chosen number be $X$.
$$EX = \frac{\sum_i arr[i]}{n}$$
- So, in on an average $\frac{n}{2}$ many elements are in the $GREATER$ and the $LESSER$ arrays at each step.
- Let $T(n)$ be the average time complexity of the algorithm. So, we can say,
$$T(n) = T(\frac{n}{2}) + n$$
where, $n$ comparisons need to be made to determine the $LESSER$ and the $GREATER$ arrays. Searching them would require $T(\frac{n}{2})$ many steps on an average.
- So, the average time complexity is $O(n)$. Since, $T(n) = n(1+\frac{1}{2}+\frac{1}{2^2}+\frac{1}{2^3}+..+\frac{1}{2^{log(n)}})$

# Implementation
Code
```
import random
def find_kth_small(arr, k, steps = 1):
    if len(arr) == 0:
        return -1, steps
    n = len(arr)
    j = random.randint(0, n-1)
    x = arr[j]
    GREATER, LESSER = list(), list()
    for i in range(n):
        if i == j:
            continue
        if arr[i] < x:
            LESSER.append(arr[i])
        else:
            GREATER.append(arr[i])
    if len(LESSER) < k-1:
        ele_steps = find_kth_small(GREATER, k-len(LESSER)-1)
        return ele_steps[0], ele_steps[1]+1
    elif len(LESSER) > k-1:
        ele_steps = find_kth_small(LESSER, k)
        return ele_steps[0], ele_steps[1]+1
    else:
        return x, steps
```

# Performance
On testing the number of steps taken to find the median for various array sizes where array elements are random integers from 0 to N. We got the following result.
[Growth of number of Steps with Array Size](Plots/QuickSelect.png)
