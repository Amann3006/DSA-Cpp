#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

class MinHeap {
private:
    int *arr;
    int capacity;
    int size;

    int parent(int i) {
        return (i - 1) / 2;
    }

    int leftChild(int i) {
        return 2 * i + 1;
    }

    int rightChild(int i) {
        return 2 * i + 2;
    }

public:
    MinHeap(int cap) {
        capacity = cap;
        size = 0;
        arr = new int[capacity];
    }

    ~MinHeap() {
        delete[] arr;
    }

    void insert(int key) {
        if (size == capacity) {
            cout << "Heap Overflow\n";
            return;
        }

        int i = size;
        arr[size++] = key;

        while (i != 0 && arr[parent(i)] > arr[i]) {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }

    void heapify(int i) {
        int smallest = i;
        int left = leftChild(i);
        int right = rightChild(i);

        if (left < size && arr[left] < arr[smallest])
            smallest = left;

        if (right < size && arr[right] < arr[smallest])
            smallest = right;

        if (smallest != i) {
            swap(arr[i], arr[smallest]);
            heapify(smallest);
        }
    }

    int getMin() {
        if (size == 0)
            return INT_MAX;

        return arr[0];
    }

    int extractMin() {
        if (size == 0)
            return INT_MAX;

        if (size == 1)
            return arr[--size];

        int minValue = arr[0];

        arr[0] = arr[size - 1];
        size--;

        heapify(0);

        return minValue;
    }

    void decreaseKey(int index, int newValue) {
        arr[index] = newValue;

        while (index != 0 && arr[parent(index)] > arr[index]) {
            swap(arr[index], arr[parent(index)]);
            index = parent(index);
        }
    }

    void deleteKey(int index) {
        decreaseKey(index, INT_MIN);
        extractMin();
    }

    void printHeap() {
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";

        cout << endl;
    }
};

int main() {
    MinHeap heap(20);

    heap.insert(4);
    heap.insert(1);
    heap.insert(2);
    heap.insert(6);
    heap.insert(7);
    heap.insert(3);
    heap.insert(8);
    heap.insert(5);

    cout << "Heap: ";
    heap.printHeap();

    cout << "Minimum: " << heap.getMin() << endl;

    heap.insert(-1);
    cout << "After inserting -1: ";
    heap.printHeap();

    heap.decreaseKey(3, -2);
    cout << "After decreaseKey: ";
    heap.printHeap();

    heap.extractMin();
    cout << "After extractMin: ";
    heap.printHeap();

    heap.deleteKey(0);
    cout << "After deleteKey(0): ";
    heap.printHeap();

    return 0;
}