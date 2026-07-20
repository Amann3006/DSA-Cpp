#include <bits/stdc++.h>
using namespace std;

void maxHeapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        maxHeapify(arr, n, largest);
    }
}


// The only thing that changes is the heapify function:

// maxHeapify() chooses the largest child.
// minHeapify() chooses the smallest child.

void convertMinToMaxHeap(vector<int>& arr) {
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--) {
        maxHeapify(arr, n, i);
    }
}

int main() {
    vector<int> arr = {2, 4, 5, 8, 10, 7, 9};

    convertMinToMaxHeap(arr);

    for (int x : arr)
        cout << x << " ";

    return 0;
}