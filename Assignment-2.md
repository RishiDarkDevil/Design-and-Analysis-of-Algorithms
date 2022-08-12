# Problem
You have a stack of $n$ plates, the only operation you are allowed to do is to pick out any number of plates and flip them and insert them back.
Sort from smallest on top to largest on bottom. Can you do it in less than $2n-3$ flips?

# Algorithms
Basic Algorithm:
- At the $i^{th}$ step, we choose the $i^{th}$ largest plate.
- Flip all the top plates upto the position of the $i^{th}$ plate(including it, from the top). Now, $i^{th}$ largest plate is on the top.
- Flip the entire stack of plates except the bottom $i-1$ plates. Now, the $i^{th}$ plate is in it's required place.
- These $i$ plates on the bottom will now be invariant and we will repeat the same algorithm for the plates above.

Little Better Algorithm:
- Do Basic Algorithm for $n-2$ larger plate.
- For the last $2$ smaller plates. We can simply swap them, if required.

Even Better Algorithm:
- Do the Basic Algorithm for $n-4$ plates.
- For the last $4$ smaller plates, do as shown below.

[Last 4 Plates Sorting](Plots/Last-4-Plate.jpg)
*Sorting the Last 4 plates in one of the two worst cases.*


# Worst Case Complexity
The worst case complexities of the above algorithms are:
- Basic Algorithm: Each step requires $2$ flips. Thus, total $2n$ flips.
- Little Better Algorithm: Each of the $n-2$ plates require $2$ flips except top $2$, which require $1$ flip. Hence, total $2(n-2)+1 = 2n-3$ flips.
- Even Better Algorithm: Each of the $n-4$ plates require $2$ flips except top $4$, which requires at max $4$ flips. Hence, total $2(n-4)+4=2n-4$ flips.
