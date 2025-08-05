// Function to return substring between two indices in a char array

#include <iostream>
using namespace std;

char* alphabets(const char* arr, int startIndex, int stopIndex) {
    int length = stopIndex - startIndex + 1;
    char* result = new char[length + 1]; // +1 for null terminator

    for (int i = 0; i < length; i++) {
        result[i] = arr[startIndex + i];
    }

    result[length] = '\0'; // Add null terminator
    return result;
}

int main() {
    const char* array = "my name is ali";
    cout << "Entered string is: " << array << endl;

    int startIndex = 3;
    cout << "Start index: " << startIndex << endl;

    int stopIndex = 6;
    cout << "Stop index: " << stopIndex << endl;

    char* result = alphabets(array, startIndex, stopIndex);
    cout << "Function will return: " << result << endl;

    delete[] result; // Free memory
    return 0;
}
