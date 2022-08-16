# Problem
Prove that the minimum number of comparisons needed to find the maximum and minimum elements of an unsorted array is $\lceil \frac{3n}{2} \rceil - 2$\
For simplicity prove the result for $n$ even.

# Algorithm
- Compare pairwise elements of the array i.e. $0^{th}$ index to $(n-1)^{th}$ index, $1^{st}$ index to $(n-2)^{th}$ index, $\dots$, $\frac{n}{2}^{th}$ index to $(\frac{n}{2}+1)^{th}$ index.
- Each of the above comparison results in a larger element and a smaller element.
- The larger element is stored.
- The smaller element is stored.
- After all the comparisons between elements of the original array.
- The maximum of the larger elements is set as the maximum.
- The maximum of the smaller elements is set as the minimum.

# Proof
Now, there is no direct way to make one comparison between elements of the original array and find the global maximum or minimum.\
So, each comparison fills up the larger element set and the smaller element set, which can be done in $\geq \frac{n}{2}$ comparisons.\
Now, the only way to find the maximum and minimum element is to find $n-2$ neither maximum or minimum elements which can be found in $\geq n-2$ comparisons.\
This gives the maximum and minimum in $n-2$ comparisons.\
The above algorithm attains the minimum number of comparisons i.e. $\frac{n}{2} + (\frac{n}{2} - 1) + (\frac{n}{2} - 1) = \frac{n}{2} + (n-2) = \frac{3n}{2} - 2$ comparisons.

[Diagramatic Explanation of the Proof](./Plots/Min-Max-Array.png)

# Implementation
For implementation, I didn't use another arrays to store larger elements and smaller elements, instead I reused the original array.\
Code:
```
def max_min(arr):
    
    n = len(arr)
    max_element = min_element = arr[0]
    
    for i in range(n//2):
        if arr[i] > arr[n-i-1]:
            arr[i], arr[n-i-1] = arr[n-i-1], arr[i]
    
    for i in range(n//2):
        if min_element > arr[i]:
            min_element = arr[i]
        if max_element < arr[(n//2)+i+(n%2 == 1)]:
            max_element = arr[(n//2)+i+(n%2 == 1)]
            
    return max_element, min_element
```
