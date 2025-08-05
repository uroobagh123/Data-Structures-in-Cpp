// Josephus Problem Simulator using Circular Doubly Linked List in C++

#include <iostream>
#include <string>
using namespace std;

// Node representing each person
class Node {
public:
    string name;
    Node* prev;
    Node* next;

    Node(string name) {
        this->name = name;
        prev = nullptr;
        next = nullptr;
    }
};

// Class to handle the circle of people and elimination logic
class Circle {
private:
    Node* head;

public:
    Circle() {
        head = nullptr;
    }

    // Insert a person into the circle
    void insertPerson(string name) {
        Node* newNode = new Node(name);
        if (!head) {
            head = newNode;
            head->next = head;
            head->prev = head;
        } else {
            Node* tail = head->prev;
            tail->next = newNode;
            newNode->prev = tail;
            newNode->next = head;
            head->prev = newNode;
        }
        cout << "Person " << name << " added to the circle.\n";
    }

    // Print all current people in the circle
    void printCircle() {
        if (!head) {
            cout << "Circle is empty.\n";
            return;
        }

        Node* temp = head;
        cout << "Current persons in the circle: ";
        do {
            cout << temp->name;
            temp = temp->next;
            if (temp != head) cout << ", ";
        } while (temp != head);
        cout << "\n";
    }

    // Eliminate persons according to Josephus logic
    void startElimination(string startName, int jump, bool clockwise) {
        if (!head) {
            cout << "Circle is empty. Add persons first.\n";
            return;
        }

        Node* curr = head;
        // Find starting point
        bool found = false;
        do {
            if (curr->name == startName) {
                found = true;
                break;
            }
            curr = curr->next;
        } while (curr != head);

        if (!found) {
            cout << "Starting person not found in the circle.\n";
            return;
        }

        cout << "Elimination sequence:\n";
        while (curr->next != curr) {
            // Move jump - 1 steps in the specified direction
            for (int i = 1; i < jump; ++i) {
                curr = clockwise ? curr->next : curr->prev;
            }

            // Eliminate the person
            cout << "Eliminate person: " << curr->name << "\n";
            Node* toDelete = curr;
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;

            // Move to next person after deletion
            curr = curr->next;

            if (toDelete == head) head = curr;

            delete toDelete;
        }

        cout << "The survivor is: " << curr->name << "\n";

        // Reset head so new simulation can start
        delete curr;
        head = nullptr;
    }

    // Check if circle is empty
    bool isEmpty() {
        return head == nullptr;
    }
};

// Main function with menu
int main() {
    Circle circle;
    int choice;

    cout << "--- Josephus Problem Simulator ---\n";

    do {
        cout << "\n1. Add Person\n";
        cout << "2. Start Elimination Process\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Clear newline from buffer

        if (choice == 1) {
            string name;
            cout << "Enter the name for the person: ";
            getline(cin, name);
            circle.insertPerson(name);
            circle.printCircle();
        } else if (choice == 2) {
            if (circle.isEmpty()) {
                cout << "Circle is empty. Add persons first.\n";
                continue;
            }

            string startName;
            int jump, dirChoice;
            bool clockwise;

            circle.printCircle();
            cout << "Enter the starting point (name): ";
            getline(cin, startName);
            cout << "Enter the jump value: ";
            cin >> jump;
            cout << "Choose direction (1. Clockwise / 2. Anticlockwise): ";
            cin >> dirChoice;
            clockwise = (dirChoice == 1);

            circle.startElimination(startName, jump, clockwise);
        } else if (choice == 3) {
            cout << "Exiting the program...\n";
        } else {
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 3);

    return 0;
}
