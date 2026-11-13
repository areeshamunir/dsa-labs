
#include <iostream>
using namespace std;

// Step 1: Create Node structure
struct Node {
    int data;
    Node* next;
};

// Step 2: Insert at Beginning
void insertAtBeginning(Node*& head, int value) {
    Node* newNode = new Node();

    newNode->data = value;
    newNode->next = head;

    head = newNode;

    cout << "Node inserted at beginning.\n";
}

// Step 3: Insert at End
void insertAtEnd(Node*& head, int value) {
    Node* newNode = new Node();

    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* temp = head;

    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = newNode;

    cout << "Node inserted at end.\n";
}

// Step 4: Insert After a Given Position
void insertAtPosition(Node*& head, int value, int position) {

    if (position < 1) {
        cout << "Invalid position!\n";
        return;
    }

    Node* temp = head;

    for (int i = 1; i < position && temp != nullptr; i++) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Position does not exist!\n";
        return;
    }

    Node* newNode = new Node();

    newNode->data = value;
    newNode->next = temp->next;

    temp->next = newNode;

    cout << "Node inserted after position "
        << position << ".\n";
}

// Step 5: Display Linked List
void display(Node* head) {

    if (head == nullptr) {
        cout << "Linked List is empty.\n";
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

int main() {

    Node* head = nullptr;

    int choice, value, position;

    do {
        cout << "\n===== SINGLY LINKED LIST MENU =====\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert After Given Position\n";
        cout << "4. Display Linked List\n";
        cout << "5. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Enter value: ";
            cin >> value;
            insertAtBeginning(head, value);
            break;

        case 2:
            cout << "Enter value: ";
            cin >> value;
            insertAtEnd(head, value);
            break;

        case 3:
            cout << "Enter value: ";
            cin >> value;
            cout << "Enter position: ";
            cin >> position;
            insertAtPosition(head, value, position);
            break;

        case 4:
            display(head);
            break;

        case 5:
            cout << "Program ended.\n";
            break;

        default:
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 5);

    return 0;
}
