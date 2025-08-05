// Program to implement List ADT operations using an array-based class in C++

#include <iostream>
using namespace std;

class List {
private:
    int* arr;
    int capacity;
    int length;
    int* curr;

public:
    List(int size) {
        arr = new int[size];
        capacity = size;
        length = 0;
        curr = NULL;
    }

    ~List() {
        delete[] arr;
    }

    void back() {
        curr--;
    }

    void tail() {
        curr = arr + length - 1;
    }

    void next() {
        curr++;
    }

    void createList() {
        length = 0;
    }

    void copy(const List& other) {
        if (capacity != other.capacity) {
            cout << "Cannot copy lists of different sizes" << endl;
            return;
        }
        length = other.length;
        for (int i = 0; i < length; ++i) {
            arr[i] = other.arr[i];
        }
        cout << "Copied list elements: " << endl;
        display();
    }

    void clear() {
        length = 0;
        cout << "List cleared" << endl;
        display();
    }

    void insert(int val) {
        if (length == capacity) {
            cout << "Array is full. Cannot insert more elements" << endl;
            return;
        }
        arr[length++] = val;
    }

    void insert(int val, int pos) {
        if (pos < 0 || pos > length) {
            cout << "Invalid position" << endl;
            return;
        }
        if (length == capacity) {
            cout << "List is full. Cannot insert more elements" << endl;
            return;
        }
        for (int i = length; i > pos; --i) {
            arr[i] = arr[i - 1];
        }
        arr[pos] = val;
        length++;
        cout << "Element " << val << " inserted at position " << pos << endl;
        display();
    }

    void remove(int pos) {
        if (length == 0) {
            cout << "List is already empty. Cannot remove elements" << endl;
            return;
        }
        if (pos < 0 || pos >= length) {
            cout << "Invalid position for removal" << endl;
            return;
        }
        for (int i = pos; i < length - 1; ++i) {
            arr[i] = arr[i + 1];
        }
        length--;
        cout << "Element at position " << pos << " removed" << endl;
        display();
    }

    int get(int pos) {
        if (pos < 0 || pos >= length) {
            cout << "Invalid position" << endl;
            return -1;
        }
        return arr[pos];
    }

    void update(int val, int pos) {
        if (pos < 0 || pos >= length) {
            cout << "Invalid position" << endl;
            return;
        }
        arr[pos] = val;
        cout << "Element at position " << pos << " updated to " << val << endl;
        display();
    }

    bool find(int val) {
        for (int i = 0; i < length; i++) {
            if (arr[i] == val) {
                cout << "Element " << val << " found at position " << i << endl;
                return true;
            }
        }
        cout << "Element " << val << " not found in the list" << endl;
        return false;
    }

    int getLength() {
        return length;
    }

    void display() {
        cout << "List elements: ";
        for (int i = 0; i < length; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void reverseList() {
        int start = 0;
        int end = length - 1;
        while (start < end) {
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            start++;
            end--;
        }
        cout << "List reversed" << endl;
        display();
    }

    void sort() {
        for (int i = 0; i < length - 1; i++) {
            for (int j = 0; j < length - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
        cout << "List sorted" << endl;
        display();
    }

    bool isFull() {
        return length == capacity;
    }

    bool isEmpty() {
        return length == 0;
    }
};

int main() {
    const int capacity = 10;
    List list(capacity);
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1: Create list\n";
        cout << "2: Copy list\n";
        cout << "3: Clear list\n";
        cout << "4: Insert at end\n";
        cout << "5: Insert at position\n";
        cout << "6: Remove element\n";
        cout << "7: Get element\n";
        cout << "8: Update element\n";
        cout << "9: Find element\n";
        cout << "10: Get length\n";
        cout << "11: Display list\n";
        cout << "12: Reverse list\n";
        cout << "13: Sort list\n";
        cout << "14: Is full?\n";
        cout << "15: Is empty?\n";
        cout << "16: Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            list.createList();
            cout << "List created" << endl;
            break;
        case 2: {
            List otherList(capacity);
            otherList.copy(list);
            cout << "List copied" << endl;
            break;
        }
        case 3:
            list.clear();
            break;
        case 4: {
            int val;
            cout << "Enter value to insert: ";
            cin >> val;
            list.insert(val);
            break;
        }
        case 5: {
            int val, pos;
            cout << "Enter value to insert: ";
            cin >> val;
            cout << "Enter position: ";
            cin >> pos;
            list.insert(val, pos);
            break;
        }
        case 6: {
            int pos;
            cout << "Enter position to remove: ";
            cin >> pos;
            list.remove(pos);
            break;
        }
        case 7: {
            int pos;
            cout << "Enter position to get: ";
            cin >> pos;
            int element = list.get(pos);
            if (element != -1) {
                cout << "Element at position " << pos << ": " << element << endl;
            }
            break;
        }
        case 8: {
            int val, pos;
            cout << "Enter value to update: ";
            cin >> val;
            cout << "Enter position to update: ";
            cin >> pos;
            list.update(val, pos);
            break;
        }
        case 9: {
            int val;
            cout << "Enter value to find: ";
            cin >> val;
            list.find(val);
            break;
        }
        case 10:
            cout << "Length of list: " << list.getLength() << endl;
            break;
        case 11:
            list.display();
            break;
        case 12:
            list.reverseList();
            break;
        case 13:
            list.sort();
            break;
        case 14:
            cout << (list.isFull() ? "List is full" : "List is not full") << endl;
            break;
        case 15:
            cout << (list.isEmpty() ? "List is empty" : "List is not empty") << endl;
            break;
        case 16:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 16);

    return 0;
}
