#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int l, int h) {
	int pivot = arr[h];
	int i = l-1;
	for (int j = l; j <= h-1; ++j) {
		if (arr[j] < pivot) {
			i++; // right position of the pivot
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i+1], arr[h]);
	return i+1;
}

void quick_sort(int arr[], int l, int h) {
	if (l < h) {
		int pivot = partition(arr, l, h);
		quick_sort(arr, l, pivot-1);
		quick_sort(arr, pivot+1, h);
	}
}

int main() {
	int n;
	cin >> n;

	int arr[n];
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	quick_sort(arr, 0, n-1);

	for (int i = 0; i < n; ++i)
		cout << arr[i] << " ";
}