// Merge Sort 
// Input:
// 10
// 10 9 8 7 6 5 4 3 2 1
// Output:
// 1 2 3 4 5 6 7 8 9 10 

#include <bits/stdc++.h>
using namespace std;

// Merge Function
void merge(int arr[], int l, int mid, int h) {
	int arr_temp[h-l+1];
	int i = l, j = mid, k = 0, m = 0;
	while (i < mid && j <= h) {
		if (arr[i] < arr[j])
			arr_temp[k++] = arr[i++];
		else
			arr_temp[k++] = arr[j++];
	}
	if (i == mid) {
		while (j <= h)
			arr_temp[k++] = arr[j++];
	} else {
		while (i < mid)
			arr_temp[k++] = arr[i++];
	}
	for (int i = l; i <= h; ++i)
		arr[i] = arr_temp[m++];
}

// Merge Sort Function
void merge_sort(int arr[], int l, int h) { 
	if (l < h) {
		int mid = (l + h) / 2;
		// Merge first half of the array
		merge_sort(arr, l, mid);
		// Merge second half of the array
		merge_sort(arr, mid+1, h);
		// Merge two sorted arrays
		merge(arr, l, mid+1, h);
	}
}

int main() {
	int n;
	cin >> n;
	
	int arr[n];
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	merge_sort(arr, 0, n-1);

	for (int i = 0; i < n; ++i)
		cout << arr[i] << " ";
}