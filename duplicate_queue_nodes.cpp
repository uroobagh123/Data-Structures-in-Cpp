// Program to duplicate each node in a queue based on its data value

#include <iostream>
using namespace std;

struct node { // Structure for a queue node
    int data;
    node* next;
    node(int val) {
        data = val;
        next = NULL;
    }
};

class queue {
private:
    node* front;
    node* rear;

public:
    queue() {
        front = NULL;
        rear = NULL;
    }

    bool isEmpty() { // Check if the queue is empty
        return front == NULL;
    }

    void enqueue(int val) { // Add an item to the rear
        node* newNode = new node(val);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void duplicateNodes() { // Duplicate each node according to its data
        node* curr = front;
        while (curr != NULL) {
            int count = curr->data;
            node* nextOriginal = curr->next;

            for (int i = 1; i < count; i++) { // already have 1 node, duplicate count-1 times
                node* newNode = new node(curr->data);
                newNode->next = curr->next;
                curr->next = newNode;
                curr = newNode; // move to the new node
            }
            curr = nextOriginal; // move to next original node
        }
    }

    void displayQueue() { // Print the queue
        node* curr = front;
        while (curr != NULL) {
            cout << curr->data;
            if (curr->next != NULL)
                cout << " -> ";
            curr = curr->next;
        }
        cout << endl;
    }
};

int main() {
    queue q;
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(2);

    cout << "Original Queue:" << endl;
    q.displayQueue();

    q.duplicateNodes();

    cout << "Queue after duplication:" << endl;
    q.displayQueue();

    return 0;
}
