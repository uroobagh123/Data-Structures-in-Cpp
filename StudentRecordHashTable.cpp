//This program maintains student records organized by their admission year. It uses a hash table with chaining (linked lists) to store records efficiently.

#include <iostream>
#include <string>
using namespace std;

// Node class representing a student
class studentNode {
public:
    string rollNo;
    string name;
    string fatherName;
    string dept;
    string degree;
    studentNode *next;

    studentNode(string rollNo, string name, string fatherName, string dept, string degree) {
        this->rollNo = rollNo;
        this->name = name;
        this->fatherName = fatherName;
        this->dept = dept;
        this->degree = degree;
        next = NULL;
    }
};

// Linked list class to handle chaining in each hash table slot
class linkedList {
private:
    studentNode *head;
public:
    linkedList() {
        head = NULL;
    }

    ~linkedList() {
        while (head != NULL) {
            studentNode *temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Insert student at the beginning of the list
    void insert(string rollNo, string name, string fatherName, string dept, string degree) {
        studentNode *newNode = new studentNode(rollNo, name, fatherName, dept, degree);
        newNode->next = head;
        head = newNode;
    }

    // Search for a student by roll number
    studentNode *get(string rollNo) {
        studentNode *curr = head;
        while (curr != NULL) {
            if (curr->rollNo == rollNo) {
                return curr;
            }
            curr = curr->next;
        }
        return NULL;
    }
};

// Hash table class to store and retrieve student records
class studentHashtable {
private:
    static const int TABLE_SIZE = 100; // For roll numbers from 00 to 99
    linkedList hashtable[TABLE_SIZE];

    // Hash function: Extracts admission year from roll number (e.g., "23P-1234" → 23)
    int extractYear(const string &rollNo) {
        return (rollNo[0] - '0') * 10 + (rollNo[1] - '0');
    }

public:
    studentHashtable() {}

    // Insert student into hash table
    void insert(string rollNo, string name, string fatherName, string dept, string degree) {
        int index = extractYear(rollNo);
        hashtable[index].insert(rollNo, name, fatherName, dept, degree);
    }

    // Retrieve student by roll number
    studentNode *get(string rollNo) {
        int index = extractYear(rollNo);
        return hashtable[index].get(rollNo);
    }
};

// Main function to demonstrate the system
int main() {
    studentHashtable t1;

    // Inserting records
    t1.insert("22P-9216", "Urooba Gohar", "Gohar Saeed", "Computer Science", "Bachelors");
    t1.insert("22P-9247", "Laiba Shahi", "Shafi Ullah", "Computer Science", "Bachelors");
    t1.insert("23P-1010", "Ali Khan", "Aslam Khan", "Electrical Engineering", "Bachelors");

    // Searching for a record
    string searchRoll = "22P-9216";
    studentNode* student = t1.get(searchRoll);
    
    if (student != NULL) {
        cout << "Student Found:\n";
        cout << "Roll No: " << student->rollNo << endl;
        cout << "Name: " << student->name << endl;
        cout << "Father's Name: " << student->fatherName << endl;
        cout << "Department: " << student->dept << endl;
        cout << "Degree: " << student->degree << endl;
    } else {
        cout << "Student with roll number " << searchRoll << " not found." << endl;
    }

    return 0;
}
