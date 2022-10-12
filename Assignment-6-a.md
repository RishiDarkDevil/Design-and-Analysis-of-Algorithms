# Problem
Given a set of points in $\mathbf{R}^2$, without loss of generality assume points can take value is $\mathbf{Z}\times \mathbf{Z}$ i.e. has integer coordinates. Find the convex hull for this set of points recursively.

# Algorithm
The function for finding the convex hull for a set of sorted points `points` based on their x-coordinate, say `find_convex_hull` is explained below:
- `find_convex_hull(points, l, r)` returns the convex hull for the `points[l:r]`.
- Set `mid = (l+r) / 2`.
- `DIVIDE STEP`: Store the convex hull for `points[l:mid]` and `points[mid:r]` by recursively using the `conv_hull_l = find_convex_hull(points, l, mid)` and `conv_hull_r = find_convex_hull(points, mid, r)`.
- `COMBINE STEP`: Join the two convex hulls `conv_hull_l` and `conv_hull_r` to find the overall `conv_hull` for `points[l:r]`.
- Return `conv_hull`.

The `COMBINE STEP` is performed by:
- Finding the lower and upper extreme tangent, where we start with a random choice of points on each of the convex hulls `conv_hull_l` and `conv_hull_r` and join them.
- We shift one end till both the adjacent points to that end on the convex hull are on the upper side. Similarly, repeat this with the other end. This results in the lower extreme tangent.
- We shift one end till both the adjacent points to that end on the convex hull are on the lower side. Similarly, repeat this with the other end. This results in the upper extreme tangent.

# Worst Case Complexity
- Sorting the `points` based on x-coordinate takes $O(n.\log(n))$ time.
- The combine step takes $O(n)$ time.
- The recursion step gives the following recursive time complexity expression same as merge-sort.
$$T(n) = 2T(\frac{n}{2}) + O(n)$$
which gives us the overall time complexity of $O(n.\log(n)) + O(n.\log(n)) = O(n.\log(n))$ time.

# Implementation
Code:
```
```
