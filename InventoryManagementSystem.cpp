// Inventory Management System using Doubly Linked List in C++

#include <iostream>
#include <string>
using namespace std;

// Node structure for a product
struct node {
    int id;
    string name;
    int quantity;
    float price;
    node *prev;
    node *next;
};

// Inventory class to manage product operations
class Inventory {
private:
    node *head;

public:
    Inventory() {
        head = NULL;
    }

    // Insert product in ascending order of ID
    void insertProduct(int id, string name, float price, int quantity) {
        node *n = new node();
        n->id = id;
        n->name = name;
        n->price = price;
        n->quantity = quantity;
        n->prev = NULL;
        n->next = NULL;

        if (head == NULL) {
            head = n;
            return;
        }

        if (id < head->id) {
            n->next = head;
            head->prev = n;
            head = n;
            return;
        }

        node *curr = head;
        while (curr->next != NULL && curr->next->id < id) {
            curr = curr->next;
        }

        n->next = curr->next;
        if (curr->next != NULL) {
            curr->next->prev = n;
        }
        curr->next = n;
        n->prev = curr;
    }

    // Remove product by ID
    void removeProduct(int id) {
        node *curr = head;

        while (curr != NULL && curr->id != id) {
            curr = curr->next;
        }

        if (curr == NULL) {
            cout << " Product with ID " << id << " not found.\n";
            return;
        }

        if (curr->prev != NULL) {
            curr->prev->next = curr->next;
        } else {
            head = curr->next;
        }

        if (curr->next != NULL) {
            curr->next->prev = curr->prev;
        }

        delete curr;
        cout << " Product with ID " << id << " removed successfully.\n";
    }

    // Display all products
    void displayProducts() {
        if (head == NULL) {
            cout << " Inventory is empty.\n";
            return;
        }

        node *curr = head;
        cout << "\n Inventory List:\n";
        cout << "ID\tName\t\tPrice\tQuantity\n";
        cout << "---------------------------------------\n";
        while (curr != NULL) {
            cout << curr->id << "\t" << curr->name << "\t\t" 
                 << curr->price << "\t" << curr->quantity << "\n";
            curr = curr->next;
        }
    }

    // Update price of product by ID
    void updatePrice(int id, float newPrice) {
        node *curr = head;
        while (curr != NULL && curr->id != id) {
            curr = curr->next;
        }

        if (curr == NULL) {
            cout << " Product with ID " << id << " not found.\n";
            return;
        }

        curr->price = newPrice;
        cout << " Price of product with ID " << id << " updated to " << newPrice << ".\n";
    }

    // Find and display a product by ID
    void findProduct(int id) {
        node *curr = head;
        while (curr != NULL && curr->id != id) {
            curr = curr->next;
        }

        if (curr == NULL) {
            cout << " Product with ID " << id << " not found.\n";
            return;
        }

        cout << "\n Product Found:\n";
        cout << "ID: " << curr->id << "\n";
        cout << "Name: " << curr->name << "\n";
        cout << "Price: " << curr->price << "\n";
        cout << "Quantity: " << curr->quantity << "\n";
    }
};

// Main menu function
int main() {
    Inventory inventory;
    int choice, id, quantity;
    string name;
    float price;

    while (true) {
        cout << "\n========= Inventory Management Menu =========\n";
        cout << "1. Add Product\n";
        cout << "2. Remove Product\n";
        cout << "3. Display Products\n";
        cout << "4. Update Price of a Product\n";
        cout << "5. Find a Product\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Product ID: ";
                cin >> id;
                cout << "Enter Product Name: ";
                cin.ignore(); // clear input buffer
                getline(cin, name);
                cout << "Enter Product Price: ";
                cin >> price;
                cout << "Enter Product Quantity: ";
                cin >> quantity;
                inventory.insertProduct(id, name, price, quantity);
                break;

            case 2:
                cout << "Enter Product ID to Remove: ";
                cin >> id;
                inventory.removeProduct(id);
                break;

            case 3:
                inventory.displayProducts();
                break;

            case 4:
                cout << "Enter Product ID to Update Price: ";
                cin >> id;
                cout << "Enter New Price: ";
                cin >> price;
                inventory.updatePrice(id, price);
                break;

            case 5:
                cout << "Enter Product ID to Find: ";
                cin >> id;
                inventory.findProduct(id);
                break;

            case 6:
                cout << " Exiting program...\n";
                return 0;

            default:
                cout << " Invalid choice. Please try again.\n";
        }
    }
}
