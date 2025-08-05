//This program simulates a browser's back and forward navigation using two stacks to track visited web pages.

#include <iostream>
using namespace std;

class Browser {
private:
    string *forwardStack;  // Stack for forward history
    string *backStack;     // Stack for back history
    int topForward;        // Top of forward stack
    int topBack;           // Top of back stack
    string currentURL;     // Currently viewed page

public:
    Browser() {
        topForward = -1;
        topBack = -1;
        currentURL = " ";
        forwardStack = new string[100];  // assuming max size = 100
        backStack = new string[100];
    }

    ~Browser() {
        delete[] forwardStack;
        delete[] backStack;
    }

    // Navigates to a new page
    void visitPage(string URL) {
        if (currentURL != " ") {
            backStack[++topBack] = currentURL;  // save current in back stack
        }
        currentURL = URL; // set new page
        topForward = -1;  // clear forward history
        cout << "Visited page: " << currentURL << endl;
    }

    // Navigate back
    void backNavigation() {
        if (topBack >= 0) {
            forwardStack[++topForward] = currentURL;      // push current to forward
            currentURL = backStack[topBack--];            // pop from back
            cout << "Navigated back to page: " << currentURL << endl;
        } else {
            cout << "No history available. Cannot navigate back." << endl;
        }
    }

    // Navigate forward
    void forwardNavigation() {
        if (topForward >= 0) {
            backStack[++topBack] = currentURL;           // push current to back
            currentURL = forwardStack[topForward--];     // pop from forward
            cout << "Navigated forward to page: " << currentURL << endl;
        } else {
            cout << "No history available. Cannot navigate forward." << endl;
        }
    }

    // Display the current page
    void displayCurrentPage() {
        if (currentURL != " ") {
            cout << "Current page: " << currentURL << endl;
        } else {
            cout << "No page is currently visited." << endl;
        }
    }
};

int main() {
    Browser browser;
    int choice;
    string URL;

    do {
        cout << "\n--- Browser Navigation Menu ---\n";
        cout << "1. Visit a Page\n";
        cout << "2. Navigate Back\n";
        cout << "3. Navigate Forward\n";
        cout << "4. Display Current Page\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter URL: ";
            cin >> URL;
            browser.visitPage(URL);
            break;
        case 2:
            browser.backNavigation();
            break;
        case 3:
            browser.forwardNavigation();
            break;
        case 4:
            browser.displayCurrentPage();
            break;
        case 5:
            cout << "Exiting browser simulation.\n";
            break;
        default:
            cout << "Invalid input. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
