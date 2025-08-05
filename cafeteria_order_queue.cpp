//This C++ program simulates a cafeteria order management system using a queue implemented via a singly linked list. 

#include <iostream>
#include <iomanip>
using namespace std;

// Structure to represent a food item
struct FoodItem {
    string name;
    double price;
    FoodItem* next;

    FoodItem(string itemName, double itemPrice) {
        name = itemName;
        price = itemPrice;
        next = nullptr;
    }
};

// Queue class implemented using linked list
class OrderQueue {
private:
    FoodItem* front;
    FoodItem* rear;

public:
    OrderQueue() {
        front = nullptr;
        rear = nullptr;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    // Add an item to the queue
    void enqueue(string itemName, double itemPrice) {
        FoodItem* newItem = new FoodItem(itemName, itemPrice);
        if (isEmpty()) {
            front = rear = newItem;
        } else {
            rear->next = newItem;
            rear = newItem;
        }
        cout << itemName << " added to the queue." << endl;
    }

    // Remove an item from the front of the queue
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Nothing to process." << endl;
            return;
        }
        FoodItem* temp = front;
        front = front->next;
        cout << temp->name << " processed and removed from the queue." << endl;
        delete temp;
    }

    // Display all items in the queue
    void displayQueue() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        FoodItem* current = front;
        cout << "\nCurrent orders in the queue:" << endl;
        while (current != nullptr) {
            cout << setw(15) << left << current->name << " $" << fixed << setprecision(2) << current->price << endl;
            current = current->next;
        }
        cout << endl;
    }
};

// Display the menu
void displayMenu() {
    cout << "\nMenu:" << endl;
    cout << setw(15) << left << "1. Burger"   << "$5.00" << endl;
    cout << setw(15) << left << "2. Pizza"    << "$8.00" << endl;
    cout << setw(15) << left << "3. Salad"    << "$4.50" << endl;
    cout << setw(15) << left << "4. Sandwich" << "$6.00" << endl;
    cout << setw(15) << left << "5. Coffee"   << "$2.50" << endl;
}

int main() {
    OrderQueue ordersQueue;
    int choice;

    do {
        cout << "\nSelect an option:" << endl;
        cout << "1. Place an order" << endl;
        cout << "2. Process next order" << endl;
        cout << "3. Display current orders" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                displayMenu();
                int itemChoice;
                cout << "Enter the number of the item you want to order: ";
                cin >> itemChoice;

                switch (itemChoice) {
                    case 1: ordersQueue.enqueue("Burger", 5.00); break;
                    case 2: ordersQueue.enqueue("Pizza", 8.00); break;
                    case 3: ordersQueue.enqueue("Salad", 4.50); break;
                    case 4: ordersQueue.enqueue("Sandwich", 6.00); break;
                    case 5: ordersQueue.enqueue("Coffee", 2.50); break;
                    default: cout << "Invalid item choice." << endl;
                }
                break;
            }

            case 2:
                ordersQueue.dequeue();
                break;

            case 3:
                ordersQueue.displayQueue();
                break;

            case 4:
                cout << "Exiting program. Goodbye!" << endl;
                break;

            default:
                cout << "Invalid menu option. Try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
