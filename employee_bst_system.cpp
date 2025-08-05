//This C++ program implements an employee hierarchy using a Binary Search Tree (BST).
#include <iostream>
#include <string>
using namespace std;

// Structure representing an employee node in the BST
struct Employee {
    int ID;
    string name;
    string department;
    Employee *left;
    Employee *right;
};

// Class to manage the Employee Hierarchy using a Binary Search Tree
class EmployeeHierarchy {
private:
    Employee *root;

    // Utility function to create a new employee node
    Employee* createEmployeeNode(int id, string name, string dept) {
        Employee* newNode = new Employee;
        newNode->ID = id;
        newNode->name = name;
        newNode->department = dept;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }

    // Recursive function to insert a new employee in the BST
    Employee* insertEmployee(Employee* node, int id, string name, string dept) {
        if (node == NULL)
            return createEmployeeNode(id, name, dept);
        if (id < node->ID)
            node->left = insertEmployee(node->left, id, name, dept);
        else if (id > node->ID)
            node->right = insertEmployee(node->right, id, name, dept);
        return node;
    }

    // Recursive function to search for an employee by ID
    Employee* findEmployeeByID(Employee* node, int id) {
        if (node == NULL || node->ID == id)
            return node;
        if (id < node->ID)
            return findEmployeeByID(node->left, id);
        else
            return findEmployeeByID(node->right, id);
    }

    // Recursive function to find employees at the same authority level (tree depth)
    void findEmployeesWithSameAuthority(Employee* node, int authorityLevel, int level = 1) {
        if (node == NULL) return;
        if (level == authorityLevel)
            cout << node->name << " (ID: " << node->ID << ")\n";
        findEmployeesWithSameAuthority(node->left, authorityLevel, level + 1);
        findEmployeesWithSameAuthority(node->right, authorityLevel, level + 1);
    }

    // Recursive function to calculate the depth of the BST
    int calculateTotalDepth(Employee* node) {
        if (node == NULL) return 0;
        int leftDepth = calculateTotalDepth(node->left);
        int rightDepth = calculateTotalDepth(node->right);
        return max(leftDepth, rightDepth) + 1;
    }

    // Utility function to print all nodes in a subtree
    void printSubordinates(Employee* node) {
        if (!node) return;
        cout << node->name << " (ID: " << node->ID << ")\n";
        printSubordinates(node->left);
        printSubordinates(node->right);
    }

    // Recursive function to find and print subordinates of a specific employee
    void findSubordinates(Employee* node, int id) {
        if (node == NULL) return;
        if (node->ID == id) {
            cout << "Subordinates of " << node->name << ":\n";
            printSubordinates(node->left);
            printSubordinates(node->right);
            return;
        }
        findSubordinates(node->left, id);
        findSubordinates(node->right, id);
    }

    // Recursive function to print all employee details (in-order traversal)
    void printEmployeeDetails(Employee* node) {
        if (node == NULL) return;
        printEmployeeDetails(node->left);
        cout << "Employee ID: " << node->ID << ", Name: " << node->name << ", Department: " << node->department << endl;
        printEmployeeDetails(node->right);
    }

public:
    EmployeeHierarchy() {
        root = NULL;
    }

    void insert(int id, string name, string dept) {
        root = insertEmployee(root, id, name, dept);
    }

    Employee* search(int id) {
        return findEmployeeByID(root, id);
    }

    void findSameAuthority(int authorityLevel) {
        cout << "Employees at authority level " << authorityLevel << ":\n";
        findEmployeesWithSameAuthority(root, authorityLevel);
    }

    int depth() {
        return calculateTotalDepth(root);
    }

    void subordinates(int id) {
        findSubordinates(root, id);
    }

    void details() {
        cout << "\nAll Employee Details:\n";
        printEmployeeDetails(root);
    }
};

int main() {
    EmployeeHierarchy hierarchy;

    // Inserting sample employee data
    hierarchy.insert(9216, "Urooba Gohar", "Engineering");
    hierarchy.insert(9173, "Faryal Hanif", "Marketing");
    hierarchy.insert(9247, "Laiba Shahi", "Finance");
    hierarchy.insert(9407, "Meerab Aslam", "HR");

    // Searching for an employee
    Employee* employee = hierarchy.search(9247);
    if (employee != NULL) {
        cout << "\nEmployee found: " << employee->name << ", Department: " << employee->department << endl;
    } else {
        cout << "\nEmployee not found." << endl;
    }

    // Finding employees at the same authority level (e.g., depth 2)
    hierarchy.findSameAuthority(2);

    // Displaying the total depth of the hierarchy
    cout << "\nTotal depth of hierarchy: " << hierarchy.depth() << endl;

    // Finding subordinates of a specific employee
    hierarchy.subordinates(9216);

    // Displaying all employee details
    hierarchy.details();

    return 0;
}
