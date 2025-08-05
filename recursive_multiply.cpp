// Program to multiply two positive integers using only + and - operators

#include <iostream>
using namespace std;

int multiply(int num1, int num2) {
    if (num1 == 0 || num2 == 0) {
        return 0; // Base case: multiplication by zero
    }
    if (num2 < 0) {
        return -multiply(num1, -num2); // Handle negative multiplier
    }
    return num1 + multiply(num1, num2 - 1); // Recursively add num1, num2 times
}

int main() {
    int num1, num2;
    cout << "Enter two positive integers: ";
    cin >> num1 >> num2;

    if (num1 < 0 || num2 < 0) {
        cout << "The integers should be positive." << endl;
        return 1;
    }

    int result = multiply(num1, num2);
    cout << "Product is: " << result << endl;

    return 0;
}
