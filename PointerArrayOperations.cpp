// C++ program using pointer functions to display, check sum, and swap elements in an array

#include <iostream>
using namespace std;

// Function to display array elements using pointer arithmetic
void display(int* array, int size) {
    for (int* ptr = array; ptr < array + size; ++ptr) {
        cout << *ptr << " ";
    }
    cout << endl;
}

// Function to check if sum of elements equals user-entered number
int check(int* array, int size, int userSum) {
    int sum = 0;
    for (int* ptr = array; ptr < array + size; ++ptr) {
        sum += *ptr;
    }
    return sum == userSum;
}

// Function to swap adjacent even-odd index elements
void swapElements(int* array, int size) {
    for (int i = 0; i < size - 1; i += 2) {
        int temp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = temp;
    }
}

int main() {
    int size;

    // Prompt for even-sized array
    do {
        cout << "Enter size of array (even number): ";
        cin >> size;
    } while (size % 2 != 0);

    int* array = new int[size];

    cout << "Enter " << size << " elements:\n";
    for (int i = 0; i < size; ++i) {
        cin >> array[i];
    }

    // Declare function pointers
    void (*displayPtr)(int*, int) = display;
    int (*checkPtr)(int*, int, int) = check;
    void (*swapPtr)(int*, int) = swapElements;

    cout << "\nOriginal array:\n";
    displayPtr(array, size);  // Call via pointer

    int userInput;
    cout << "\nEnter a number to compare with sum of array elements: ";
    cin >> userInput;

    if (checkPtr(array, size, userInput)) {
        cout << "Sum is equal to the entered number.\n";
    } else {
        cout << "Sum is NOT equal to the entered number.\n";
    }

    cout << "\nSwapping elements...\n";
    swapPtr(array, size);  // Call via pointer

    cout << "Array after swapping:\n";
    displayPtr(array, size);  // Call via pointer

    delete[] array;
    return 0;
}
