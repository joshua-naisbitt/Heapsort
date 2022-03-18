// Heapsort.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
using namespace std;
void heapify(int A[], int size, int i) { // size = heap size, i = root node index
    int largest = i; //initialize root as largest, initialize left/right node indexes
    int leftNodeIndex = 2 * i + 1;
    int rightNodeIndex = 2 * i + 2;
    // Left child > root
    if (leftNodeIndex < size && A[leftNodeIndex] > A[largest]) {
        largest = leftNodeIndex;
    }
    // Right child > largest
    if (rightNodeIndex < size && A[rightNodeIndex] > A[largest]) {
        largest = rightNodeIndex;
    }
    // Largest is not root
    if (largest != i) {
        swap(A[i], A[largest]);

        // Recursive heapify sub-tree call
        heapify(A, size, largest);
    }
}
void buildMaxHeap(int A[], int size){//takes an unsorted array and converts it to a max heap, size = size of input array
    for (int i = (size / 2) - 1; i >= 0; i--)
        heapify(A, size, i);
}
void heapsort(int A[], int size){//Sorts the input array, size = size of input array
    // Calls buildMaxHeap so that the input array does not necessarily need to already be in max heap form
    buildMaxHeap(A, size);

    // Delete element from heap, sort largest element
    for (int i = size - 1; i >= 0; i--) {
        swap(A[0], A[i]);
        // Call heapify on the reduced heap
        heapify(A, i, 0);
    }
}
void printArray(int A[], int size){ //prints input array, size = size of input array
    for (int i = 0; i < size; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}
int main()
{   // initialize Array and array size
    int mySampleArray[30] = {3, 1111, 50, 4, 40, 13, 10, 224, 8, 15, 17, 3, 11, 5, 69, 420, 310, 10, 4, 8, 15, 17, 38, 99, 1000, 1, 29, 66, 142, 0};
    int size = (sizeof(mySampleArray) / sizeof(mySampleArray[0]));
    
    // debugging, check size
    cout << "Array size: " << size << endl;
    cout << "\nUnsorted sample array:\n";
    printArray(mySampleArray, size);

    buildMaxHeap(mySampleArray, size);
    // I wrote this line to print buildMaxHeap to help me debug, but I chose to leave it in because it demonstrates how the function works.
    cout << "\nAfter calling buildMaxHeap:\n";
    printArray(mySampleArray, size);
    
    heapsort(mySampleArray, size);
    cout << "\nSorted array after calling heapsort:\n";
    printArray(mySampleArray, size);

    int mySampleArray2[30] = { 50, 100, 110, 10, 1400, 40, 90, 60, 70, 3, 99, 42, 69, 111, 420, 50, 1, 110, 10, 142, 40, 90, 6, 70, 30, 99, 42, 69, 111, 420 };
    cout << "Array size: " << size << endl;
    cout << "\n\n\nUnsorted sample array 2:\n";
    printArray(mySampleArray2, size);

    buildMaxHeap(mySampleArray2, size);
    cout << "\nAfter calling buildMaxHeap:\n";
    printArray(mySampleArray2, size);

    heapsort(mySampleArray, size);
    cout << "\nSorted array 2 after calling heapsort:\n";
    printArray(mySampleArray2, size);

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
