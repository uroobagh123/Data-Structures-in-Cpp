// This program processes characters from a string based on type (vowel, consonant, digit) and stores transformed values in a linked list.

#include <iostream>
#include <string>
using namespace std;

// Node class for linked list
class Node {
public:
    char input;
    Node* next;

    Node(char input) {
        this->input = input;
        next = nullptr;
    }
};

// Linked list class
class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    // Append new character node to the end of the list
    void append(char input) {
        if (head == nullptr) {
            head = new Node(input);
        } else {
            Node* curr = head;
            while (curr->next != nullptr) {
                curr = curr->next;
            }
            curr->next = new Node(input);
        }
    }

    // Process the input string and apply transformation rules
    void processInput(const string& data) {
        int pos = 1;
        for (char ch : data) {
            if (isConsonant(ch)) {
                append(processConsonant(ch, pos));
            } else if (isVowel(ch)) {
                append(processVowel(ch, pos));
            } else if (isdigit(ch)) {
                append(processDigit(ch));
            }
            pos++;
        }
    }

    // Display the final linked list
    void displayList() {
        Node* curr = head;
        while (curr != nullptr) {
            cout << curr->input << endl;
            curr = curr->next;
        }
    }

private:
    // Check if the character is a consonant
    bool isConsonant(char ch) {
        ch = tolower(ch);
        return isalpha(ch) && !isVowel(ch);
    }

    // Check if the character is a vowel
    bool isVowel(char ch) {
        ch = tolower(ch);
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

    // Transform consonant: x + ch + position
    char processConsonant(char ch, int pos) {
        return 'x' + ch + static_cast<char>(pos + '0');
    }

    // Transform vowel: ch + position * 'y'
    char processVowel(char ch, int pos) {
        return static_cast<char>(ch + pos * 'y');
    }

    // Transform digit: (digit^2) + '0'
    char processDigit(char ch) {
        int digit = ch - '0';
        return static_cast<char>(digit * digit + '0');
    }
};

// Main function
int main() {
    LinkedList l1;
    string data;

    cout << "Enter a string: ";
    cin >> data;

    l1.processInput(data);
    cout << "Processed linked list:\n";
    l1.displayList();

    return 0;
}
