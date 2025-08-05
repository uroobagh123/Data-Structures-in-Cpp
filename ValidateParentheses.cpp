
// This program checks if a string of brackets is valid based on proper opening and closing.

#include <iostream>
#include <string>
using namespace std;

// Stack implementation for parentheses validation
class ParenthesesStack {
private:
    char stack[500];  // Array to hold characters
    int top;          // Top of the stack

public:
    ParenthesesStack() {
        top = -1;
    }

    void push(char c) {
        stack[++top] = c;
    }

    char pop() {
        return stack[top--];
    }

    bool isEmpty() {
        return top == -1;
    }
};

// Function to validate the input string
bool isValid(const string& s) {
    ParenthesesStack stack;

    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') {
            stack.push(c);  // Push open brackets
        } else if (c == ')' || c == '}' || c == ']') {
            if (stack.isEmpty()) {
                return false;  // Closing bracket without opening
            }

            char topChar = stack.pop();

            // Check if the type matches
            if ((c == ')' && topChar != '(') ||
                (c == '}' && topChar != '{') ||
                (c == ']' && topChar != '[')) {
                return false;
            }
        }
    }

    return stack.isEmpty();  // If stack is empty, string is valid
}

int main() {
    string input;
    cout << "Enter a string with parentheses: ";
    cin >> input;

    if (isValid(input)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}
