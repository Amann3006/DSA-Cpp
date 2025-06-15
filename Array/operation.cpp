#include <iostream>
using namespace std;

// Search function
int search(int *arr, int n, int x) {
    for(int i = 0; i < n; i++) {
        if(arr[i] == x) {
            return i;
        }
    }
    return -1;
}

// Insert function
int insert(int arr[], int n, int x, int pos, int cap) {
    if(n == cap) {
        cout << "Cannot insert, array is at full capacity." << endl;
        return n;
    }

    int index = pos - 1;
    for(int i = n - 1; i >= index; i--) {
        arr[i + 1] = arr[i];
    }
    arr[index] = x;
    return n + 1;
}

// Delete function
int deleteno(int *arr, int n, int x) {
    int i;
    for(i = 0; i < n; i++) {
        if(arr[i] == x) {
            break;
        }
    }

    if(i == n) {
        cout << "Element not found, nothing deleted." << endl;
        return n;
    }

    for(int j = i; j < n - 1; j++) {
        arr[j] = arr[j + 1];
    }

    return n - 1;
}

int main() {
    int arr[100] = {5, 10, 20, 23}; // Extra capacity to allow insertions
    int n = 4; // Current size of the array

    int x, pos, cap;
    cout << "Enter element to insert: ";
    cin >> x;
    cout << "Enter position to insert at (1-based index): ";
    cin >> pos;
    cout << "Enter capacity of array: ";
    cin >> cap;

    // Insert operation
    n = insert(arr, n, x, pos, cap);

    cout << "Array after insertion: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Delete operation
    n = deleteno(arr, n, x);

    cout << "Array after deletion: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Search operation (optional)
    cout << "Enter element to search: ";
    int toFind;
    cin >> toFind;
    int foundIndex = search(arr, n, toFind);
    if(foundIndex != -1) {
        cout << "Element found at index: " << foundIndex << endl;
    } else {
        cout << "Element not found in array." << endl;
    }

    return 0;
}
