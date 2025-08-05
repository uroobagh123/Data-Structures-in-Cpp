// Program to split a doubly linked list into two: one with even values and the other with odd values.

#include <iostream>
using namespace std;

// Node class for doubly linked list
class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

// Doubly linked list class
class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    // Insert a node at the end of the list
    void insert(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Split current list into evenList and oddList based on data
    void splitIntoEvenAndOdd(DoublyLinkedList& evenList, DoublyLinkedList& oddList) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data % 2 == 0)
                evenList.insert(current->data);
            else
                oddList.insert(current->data);
            current = current->next;
        }
    }

    // Display the elements of the list
    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList originalList;
    int numElements, value;

    cout << "Enter the number of elements: ";
    cin >> numElements;

    cout << "Enter " << numElements << " elements:" << endl;
    for (int i = 0; i < numElements; i++) {
        cin >> value;
        originalList.insert(value);
    }

    DoublyLinkedList evenList;
    DoublyLinkedList oddList;

    // Split the original list into even and odd lists
    originalList.splitIntoEvenAndOdd(evenList, oddList);

    // Display the results
    cout << "\nEven List: ";
    evenList.display();

    cout << "Odd List: ";
    oddList.display();

    return 0;
}
