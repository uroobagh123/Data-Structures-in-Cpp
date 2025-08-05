// Program to manage a playlist using a circular linked list with add, remove, and display functionalities.

#include <iostream>
using namespace std;

// Node class representing a song
class Node {
public:
    string data;
    Node* next;

    Node(string val) {
        data = val;
        next = nullptr;
    }
};

// Playlist class using a circular singly linked list
class Playlist {
private:
    Node* head;
    int length;

public:
    Playlist() {
        head = nullptr;
        length = 0;
    }

    // Destructor to deallocate memory
    ~Playlist() {
        if (!head) return;
        Node* curr = head->next;
        while (curr != head) {
            Node* temp = curr;
            curr = curr->next;
            delete temp;
        }
        delete head;
        head = nullptr;
    }

    // Insert song at the beginning
    void addSongAtBeginning(const string& val) {
        Node* newNode = new Node(val);

        if (!head) {
            head = newNode;
            head->next = head;
        } else {
            Node* tail = head;
            while (tail->next != head)
                tail = tail->next;

            newNode->next = head;
            tail->next = newNode;
            head = newNode;
        }
        length++;
    }

    // Remove song from the end
    void removeSongAtEnd() {
        if (!head) {
            cout << "Playlist is empty." << endl;
            return;
        }

        if (head->next == head) {
            delete head;
            head = nullptr;
            cout << "Last song removed from the playlist." << endl;
            return;
        }

        Node* temp = head;
        while (temp->next->next != head) {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = head;
        cout << "Last song removed from the playlist." << endl;
        length--;
    }

    // Display the playlist
    void display() {
        if (!head) {
            cout << "Playlist is empty." << endl;
            return;
        }

        Node* curr = head;
        do {
            cout << curr->data << endl;
            curr = curr->next;
        } while (curr != head);
    }
};

// Main function
int main() {
    Playlist playlist;
    int choice;

    while (true) {
        cout << "\n--- Playlist Menu ---\n";
        cout << "1. Add song at beginning\n";
        cout << "2. Remove song at end\n";
        cout << "3. Display playlist\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Clear input buffer

        if (choice == 1) {
            string song;
            cout << "Enter the name of the song: ";
            getline(cin, song);
            playlist.addSongAtBeginning(song);
            cout << "Song added to the beginning of the playlist." << endl;
        } else if (choice == 2) {
            playlist.removeSongAtEnd();
        } else if (choice == 3) {
            cout << "Current Playlist:\n";
            playlist.display();
        } else if (choice == 4) {
            cout << "Exiting program." << endl;
            break;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
