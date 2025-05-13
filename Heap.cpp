#include <iostream>
#include <vector>
using namespace std;

// ---------------- HEAPIFY FUNCTION ----------------
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;           // Assume root is largest
    int left = 2*i + 1;        // Left child index
    int right = 2*i + 2;       // Right child index

    // Compare with left child
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // Compare with right child
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not the root
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected subtree
        heapify(arr, n, largest);
    }
}

// ---------------- BUILDHEAP FUNCTION ----------------
void buildMaxHeap(vector<int>& arr, int n) {
    // Start from the last non-leaf node and heapify each
    for (int i = n/2 - 1; i >= 0; i--) {
        heapify(arr, n, i);  // Calling HEAPIFY here
    }
}

// ---------------- HEAPSORT FUNCTION ----------------
void heapSort(vector<int>& arr) {
    int n = arr.size();

    // Step 1: BUILD MAX HEAP
    buildMaxHeap(arr, n);   // BUILDHEAP

    // Step 2: Extract elements one by one from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root (max) to end
        swap(arr[0], arr[i]);

        // Call heapify on reduced heap
        heapify(arr, i, 0);   // HEAPIFY during sorting
    }
}
