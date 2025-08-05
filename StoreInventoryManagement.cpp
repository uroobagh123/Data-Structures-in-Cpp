// Inventory Management Program using Pointers in C++
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Products {
    int id;
    int stock;
};

// Function to find the mean (average) stock level using pointer notation
double findMean(Products* inventory, int size) {
    double total = 0;
    for (Products* ptr = inventory; ptr < inventory + size; ++ptr) {
        total += ptr->stock;
    }
    return total / size;
}

// Function to count products that are critically low (less than average)
int countCriticalProducts(Products* inventory, int size, double average) {
    int count = 0;
    for (Products* ptr = inventory; ptr < inventory + size; ++ptr) {
        if (ptr->stock < average) count++;
    }
    return count;
}

// Function to print the top-selling product (highest stock)
void identifyTopSellingProduct(Products* inventory, int size) {
    int maxIndex = 0;
    for (int i = 1; i < size; ++i) {
        if (inventory[i].stock > inventory[maxIndex].stock) {
            maxIndex = i;
        }
    }
    cout << "Top-selling Product ID: " << inventory[maxIndex].id 
         << " | Stock: " << inventory[maxIndex].stock << endl;
}

// Function to identify the second best-selling product
int identifySecondBestSeller(Products* inventory, int size) {
    int maxIndex = 0;
    int secondMaxIndex = -1;

    for (int i = 1; i < size; ++i) {
        if (inventory[i].stock > inventory[maxIndex].stock) {
            secondMaxIndex = maxIndex;
            maxIndex = i;
        } else if (secondMaxIndex == -1 || inventory[i].stock > inventory[secondMaxIndex].stock) {
            secondMaxIndex = i;
        }
    }
    return secondMaxIndex;
}

// Function to sort the inventory in descending order of stock
void sortInDescendingOrder(Products* inventory, int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (inventory[j].stock > inventory[i].stock) {
                swap(inventory[i], inventory[j]);
            }
        }
    }

    cout << "\nProducts sorted by popularity (descending stock levels):\n";
    for (int i = 0; i < size; ++i) {
        cout << "Product ID: " << inventory[i].id 
             << " | Stock: " << inventory[i].stock << endl;
    }
}

int main() {
    srand(static_cast<unsigned>(time(0)));

    int size;
    cout << "Enter the size of the inventory array: ";
    cin >> size;

    // Dynamically allocate memory for the inventory array
    Products* inventory = new Products[size];

    // Initialize product IDs and random stock values
    for (int i = 0; i < size; ++i) {
        inventory[i].id = i + 1;
        inventory[i].stock = rand() % 100 + 1; // stock between 1 and 100
    }

    cout << "\n--- Inventory Report ---\n";

    double average = findMean(inventory, size);
    cout << "Average Stock Level: " << average << endl;

    int criticalCount = countCriticalProducts(inventory, size, average);
    cout << "Number of Critical Products (below average): " << criticalCount << endl;

    identifyTopSellingProduct(inventory, size);

    if (size <= 1) {
        cout << "Not enough products to determine a second best-seller.\n";
    } else {
        int secondBest = identifySecondBestSeller(inventory, size);
        cout << "Second Best-Selling Product ID: " << inventory[secondBest].id 
             << " | Stock: " << inventory[secondBest].stock << endl;
    }

    sortInDescendingOrder(inventory, size);

    delete[] inventory; // Free dynamically allocated memory
    return 0;
}
