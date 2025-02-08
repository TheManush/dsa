#include <iostream>
using namespace std;

int heap1[100000]; // First heap
int heap2[100000]; // Second heap
int mergedHeap[200000]; // Merged heap
int last_index1 = -1; // Last index of first heap
int last_index2 = -1; // Last index of second heap
int last_index_merged = -1; // Last index of merged heap

// Get parent, left child, and right child indices
int parent(int i) {
    return (i - 1) / 2;
}
int leftChild(int i) {
    return 2 * i + 1;
}
int rightChild(int i) {
    return 2 * i + 2;
}

// Restore the heap property by moving an element down
void heapifyDown(int heap[], int i, int last_index) {
    if (leftChild(i) > last_index) {
        return; // No children, stop
    }

    int mn_node = -1;
    if (leftChild(i) <= last_index && rightChild(i) > last_index) {
        mn_node = leftChild(i); // Only left child exists
    } else if (heap[leftChild(i)] < heap[rightChild(i)]) {
        mn_node = leftChild(i); // Left child is smaller
    } else {
        mn_node = rightChild(i); // Right child is smaller
    }

    if (heap[i] <= heap[mn_node]) {
        return; // Already satisfies the heap property
    }

    // Swap heap[i] with the smaller child
    int temp = heap[i];
    heap[i] = heap[mn_node];
    heap[mn_node] = temp;

    heapifyDown(heap, mn_node, last_index); // Recursively heapify down
}

// Restore the heap property by moving an element up
void heapifyUp(int heap[], int i) {
    while (i > 0 && heap[parent(i)] > heap[i]) {
        // Swap heap[i] with its parent
        int temp = heap[parent(i)];
        heap[parent(i)] = heap[i];
        heap[i] = temp;

        i = parent(i); // Move up to the parent
    }
}

// Insert an element into a heap
void insert(int heap[], int &last_index, int x) {
    heap[++last_index] = x;
    heapifyUp(heap, last_index); // Restore the heap property
}

// Rebuild the heap from an array
void buildHeap(int heap[], int &last_index) {
    for (int i = last_index / 2; i >= 0; i--) {
        heapifyDown(heap, i, last_index);
    }
}

// Merge two heaps
void mergeHeaps(int heap1[], int last_index1, int heap2[], int last_index2, int mergedHeap[], int &last_index_merged) {
    // Copy elements from heap1
    for (int i = 0; i <= last_index1; i++) {
        mergedHeap[++last_index_merged] = heap1[i];
    }
    // Copy elements from heap2
    for (int i = 0; i <= last_index2; i++) {
        mergedHeap[++last_index_merged] = heap2[i];
    }

    // Rebuild the heap
    buildHeap(mergedHeap, last_index_merged);
}

// Main function
int main() {
    int n1, n2;

    // Input the first heap
    cout << "Enter number of elements in first heap: ";
    cin >> n1;
    for (int i = 0; i < n1; i++) {
        int value;
        cin >> value;
        insert(heap1, last_index1, value);
    }

    // Input the second heap
    cout << "Enter number of elements in second heap: ";
    cin >> n2;
    for (int i = 0; i < n2; i++) {
        int value;
        cin >> value;
        insert(heap2, last_index2, value);
    }

    // Merge the heaps
    mergeHeaps(heap1, last_index1, heap2, last_index2, mergedHeap, last_index_merged);

    // Print the merged heap
    cout << "Merged heap elements (in min-heap order):" << endl;
    while (last_index_merged != -1) {
        cout << mergedHeap[0] << " ";
        mergedHeap[0] = mergedHeap[last_index_merged];
        last_index_merged--;
        heapifyDown(mergedHeap, 0, last_index_merged);
    }
    cout << endl;

    return 0;
}
