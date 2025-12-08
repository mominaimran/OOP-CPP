#include <iostream>
using namespace std;

class LinkedList {
private:
    struct Node {
        int data;
        Node* next;
    };
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    // Insert at front
    void insert(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = head;
        head = newNode;
        cout << value << " inserted at the front.\n";
    }

    // Delete a value
    void deleteValue(int value) {
        if (head == nullptr) {
            cout << "List is empty!\n";
            return;
        }

        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << value << " deleted from the list.\n";
            return;
        }

        Node* current = head;
        while (current->next != nullptr && current->next->data != value) {
            current = current->next;
        }

        if (current->next == nullptr) {
            cout << value << " not found in the list.\n";
            return;
        }

        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;
        cout << value << " deleted from the list.\n";
    }

    // Display the list
    void display() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        Node* temp = head;
        cout << "Linked List: ";
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

// ---------------- MAIN FUNCTION ----------------
int main() {
    LinkedList list;
    int choice, value;

    while (true) {
        cout << "\n--- MENU ---\n";
        cout << "1. Insert at Front\n";
        cout << "2. Delete a Value\n";
        cout << "3. Display List\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                list.insert(value);
                break;

            case 2:
                cout << "Enter value to delete: ";
                cin >> value;
                list.deleteValue(value);
                break;

            case 3:
                list.display();
                break;

            case 4:
                cout << "Exiting...\n";
                return 0;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    }
}


// Node class = “What is a node?”
// LinkedList class = “What can we DO with nodes?”