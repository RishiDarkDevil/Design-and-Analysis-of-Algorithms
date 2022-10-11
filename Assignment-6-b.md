# Problem
Given a set of points in $\mathbf{R}^2$, without loss of generality assume points can take value is $\mathbf{Z}\times \mathbf{Z}$ i.e. has integer coordinates. Find the closest pair of points.

# Algorithm
- Sort the array of points wrt it's x-coordinate in increasing order and store it in an array, say `point_x`.
- Sort the array of points wrt it's y-coordinate in decreasing order and store it in an array, say `point_y`.
- Find the median point in `point_x`, say `mid_point`.
- Find the part of `point_y` lying on the left and right of `mid_point`, which preserves the sorted nature of `point_y`. 
- Use recursion to find the minimum distance and the closest points on the left(`d_l`) and right(`d_r`) of `mid_point` which uses the above created parts.
- Set `d = min(d_l,d_r)` and create a strip of thickness `d` on either side of `mid_point`.
- Find the points in `point_y` within this strip, say `strip_points`, which is already sorted.
- Iterate over the `strip_points` and compute y-coordinate difference of all the following points with the current point until the difference is $< d$, which as proven in class can iterate maximum over $7$ points.
- Return the minimum of the minimum pair distance in the strip and the distances given by recursion.
- For the base case i.e. $\leq 3$ all pair-wise distance between points are computed and the minimum is tracked.

# Worst Case Complexity
- Sorting takes $O(n.\log(n))$. 
- Finding median takes $O(1)$.
- Splitting the `point_y` takes $O(n)$.
- Finding points in strip takes $O(n)$.
- Finding the minimum distance in the strip takes $O(n)$.
- Since, at each step the problem is split into two smaller equal halved parts, where each step takes $O(1) + O(n) + O(n) + O(n) = O(n)$ time. The following recursion relation same as merge-sort is obtained,
$$T(n) = 2T(\frac{n}{2}) + O(n)$$
Therefore, the overall worst case time complexity is $O(n.\log(n))$

# Implementation
Code:
```
#include <bits/stdc++.h>
using namespace std;

// comparator for sorting points in increasing x coordinate
bool compare_x(pair<int, int> p1, pair<int, int> p2) {
	return p1.first <= p2.first;
}

// comparator for sorting points in decreasing y coordinate
bool compare_y(pair<int, int> p1, pair<int, int> p2) {
	return p1.second >= p2.second;
}

// compute distance between two points in plane
double dist(pair<int, int> p1, pair<int, int> p2) {
	return sqrt(pow(p1.first-p2.first, 2) + pow(p1.second-p2.second, 2));
}

// return the minimum pair distance in the strip if exists else returns the strip width along with the pair of points
pair<double, pair<pair<int, int>, pair<int, int>>> compare_strip_dist(vector<pair<int, int>> &strip_points, double d, pair<pair<int, int>, pair<int, int>> pts) {
	double min_dist = d;
	pair<pair<int, int>, pair<int, int>> ans = pts;
	for (int i = 0; i < strip_points.size(); ++i) {
		// Runs atmost 7 times
		for (int j = i+1; (j < strip_points.size()) && (strip_points[i].second - strip_points[j].second <= d); j++) {
			min_dist = dist(strip_points[i], strip_points[j]);
			ans = {strip_points[i], strip_points[j]};
		}
	}
	return {min_dist, ans};
}

// returns the closest distance between pair of points present among the set of points and the pair of points 
pair<double, pair<pair<int, int>, pair<int, int>>> closest_dist(vector<pair<int, int>> &points_x, vector<pair<int, int>> &points_y, int n) {

	pair<pair<int, int>, pair<int, int>> ans; 
	// base case with <= 3 points simply try all combinations and return minimum distance and pair of points
	if (n <= 3) {
		double min_dist = DBL_MAX;
		for (int i = 0; i < n; ++i) {
			for (int j = i+1; j < n; ++j) {
				double distance = dist(points_x[i], points_x[j]);
				if (distance < min_dist)
					ans = {points_x[i], points_x[j]};
				min_dist = min(min_dist, distance);
			}
		}
		return {min_dist, ans};
	}
	
	// median point wrt to sorted x coordinate points
	int mid = n / 2;
	pair<int, int> mid_point = points_x[mid];
	
	vector<pair<int, int>> points_y_l;
	vector<pair<int, int>> points_y_r;

	// split the sorted points according to y coordinate into left half and right half of the mid_point
	int l = 0;
	for (int i = 0; i < n; ++i) {
		if ((points_y[i].first < mid_point.first) && (l < mid)) {
			points_y_l.push_back(points_y[i]); l++;
		}
		else {
			points_y_r.push_back(points_y[i]);
		}
	}

	// find the min_dist on either halves
	pair<double, pair<pair<int, int>, pair<int, int>>> d_l_pts = closest_dist(points_x, points_y_l, mid);
	pair<double, pair<pair<int, int>, pair<int, int>>> d_r_pts = closest_dist(points_x, points_y_r, n-mid);
	double d_l = d_l_pts.first;
	double d_r = d_r_pts.first;

	// find the thickness of the strip
	double d_strip = min(d_l, d_r);
	if (d_l <= d_r)
		ans = d_l_pts.second;
	else
		ans = d_r_pts.second;

	// find the points lying in the strip (which by our setup will be in decreasing y coordinate)
	vector<pair<int, int>> strip_points;
	for (int i = 0; i < n; ++i) {
		if (abs(points_y[i].first - mid_point.first) <= d_strip)
			strip_points.push_back(points_y[i]);
	}

	return compare_strip_dist(strip_points, d_strip, ans);
}

int main() {
	// take input for n points
	int n;
	cin >> n;

	vector<pair<int, int>> points;
	for (int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		points.push_back({x, y});
	}

	// sort the points as per their x and y coordinates in two copies
	vector<pair<int, int>> points_x = points;
	vector<pair<int, int>> points_y = points;
	sort(points_x.begin() ,points_x.end(), compare_x);
	sort(points_y.begin() ,points_y.end(), compare_y);

	pair<double, pair<pair<int, int>, pair<int, int>>> ans = closest_dist(points_x, points_y, n);
	cout << "Minimum Distance: " << ans.first << endl;
	cout << "Points: " << endl;
	cout << ans.second.first.first << " " << ans.second.first.second << endl;
	cout << ans.second.second.first << " " << ans.second.second.second << endl;
}
```
Sample Input: Number of points followed by the coordinate of the points
```
6
3 10
12 30
12 50
12 1
3 4
4 3
```
Sample Output:
```
Minimum Distance: 1.41421
Points: 
3 4
4 3
```
