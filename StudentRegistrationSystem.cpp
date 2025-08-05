// C++ program implementing a student registration system using a singly linked list.

#include <iostream>
#include <string>
using namespace std;

// Class to represent individual student records
class StudentRecord {
private:
    int id;
    string name;
    float gpa;

public:
    StudentRecord(int id, string name, float gpa) {
        this->id = id;
        this->name = name;
        this->gpa = gpa;
    }

    int getId() const {
        return id;
    }

    string getName() const {
        return name;
    }

    float getGpa() const {
        return gpa;
    }

    void displayRecord() const {
        cout << "Student ID: " << id << endl;
        cout << "Student Name: " << name << endl;
        cout << "Student GPA: " << gpa << endl;
        cout << "------------------------" << endl;
    }
};

// Node for the singly linked list
struct Node {
    StudentRecord info;
    Node* next;

    Node(int id, string name, float gpa) : info(id, name, gpa), next(nullptr) {}
};

// Class to manage the linked list of student records
class LinkedList {
private:
    Node* head;
    float totalGpa;
    int size;

public:
    LinkedList() {
        head = nullptr;
        totalGpa = 0.0;
        size = 0;
    }

    ~LinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void addStudent(int id, const string& name, float gpa) {
        Node* newNode = new Node(id, name, gpa);
        newNode->next = head;
        head = newNode;
        totalGpa += gpa;
        size++;
        cout << "Student added successfully.\n";
    }

    void removeStudent(int id) {
        Node* curr = head;
        Node* prev = nullptr;

        while (curr != nullptr && curr->info.getId() != id) {
            prev = curr;
            curr = curr->next;
        }

        if (curr == nullptr) {
            cout << " No student with ID " << id << " found.\n";
            return;
        }

        if (prev == nullptr) {
            head = curr->next;
        } else {
            prev->next = curr->next;
        }

        totalGpa -= curr->info.getGpa();
        delete curr;
        size--;
        cout << "Student removed successfully.\n";
    }

    void displayAllStudents() const {
        if (head == nullptr) {
            cout << "No student records available.\n";
            return;
        }

        cout << "\n Student Records:\n";
        Node* current = head;
        while (current != nullptr) {
            current->info.displayRecord();
            current = current->next;
        }
    }

    void searchStudentById(int id) const {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->info.getId() == id) {
                cout << " Student found:\n";
                temp->info.displayRecord();
                return;
            }
            temp = temp->next;
        }
        cout << " Student with ID " << id << " not found.\n";
    }

    float calculateAverageGpa() const {
        if (size == 0) return 0.0;
        return totalGpa / size;
    }
};

// Main program for user interaction
int main() {
    LinkedList studentList;
    cout << "🎓 Welcome to the Student Registration System!\n";

    while (true) {
        cout << "\nMenu:\n"
             << "1: Add a Student\n"
             << "2: Remove a Student\n"
             << "3: Search for a Student\n"
             << "4: Display All Students\n"
             << "5: Calculate Average GPA\n"
             << "6: Exit\n";
        cout << "Enter your choice (1-6): ";

        int choice;
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << " Invalid input. Please enter a number between 1 and 6.\n";
            continue;
        }

        switch (choice) {
            case 1: {
                int id;
                string name;
                float gpa;
                cout << "Enter Student ID: ";
                cin >> id;
                cout << "Enter Student Name: ";
                cin.ignore(); // flush newline
                getline(cin, name);
                cout << "Enter Student GPA: ";
                cin >> gpa;
                studentList.addStudent(id, name, gpa);
                break;
            }
            case 2: {
                int id;
                cout << "Enter Student ID to remove: ";
                cin >> id;
                studentList.removeStudent(id);
                break;
            }
            case 3: {
                int id;
                cout << "Enter Student ID to search: ";
                cin >> id;
                studentList.searchStudentById(id);
                break;
            }
            case 4:
                studentList.displayAllStudents();
                break;
            case 5:
                cout << " Average GPA: " << studentList.calculateAverageGpa() << endl;
                break;
            case 6:
                cout << "👋 Exiting the system. Goodbye!\n";
                return 0;
            default:
                cout << " Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
