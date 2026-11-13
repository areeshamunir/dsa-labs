
#include <iostream>
using namespace std;

// Step 1: Create Node Structure
struct Node {
    int data;
    Node* next;
};

// Step 2: Delete from Beginning
void deleteFromBeginning(Node*& head) {

    if (head == nullptr) {
        cout << "Linked List is empty!\n";
        return;
    }

    Node* temp = head;
    head = head->next;

    delete temp;

    cout << "First node deleted successfully.\n";
    display(head);
}

// Step 3: Delete from End
void deleteFromEnd(Node*& head) {

    if (head == nullptr) {
        cout << "Linked List is empty!\n";
        return;
    }

    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        cout << "Last node deleted successfully.\n";
        display(head);
        return;
    }

    Node* temp = head;

    while (temp->next->next != nullptr) {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = nullptr;

    cout << "Last node deleted successfully.\n";
    display(head);
}

// Step 4: Delete from Specific Position
void deleteFromPosition(Node*& head, int position) {

    if (head == nullptr) {
        cout << "Linked List is empty!\n";
        return;
    }

    if (position < 1) {
        cout << "Invalid position!\n";
        return;
    }

    if (position == 1) {
        deleteFromBeginning(head);
        return;
    }

    Node* temp = head;

    for (int i = 1; i < position - 1 && temp != nullptr; i++) {
        temp = temp->next;
    }

    if (temp == nullptr || temp->next == nullptr) {
        cout << "Invalid position!\n";
        return;
    }

    Node* deleteNode = temp->next;

    temp->next = deleteNode->next;

    delete deleteNode;

    cout << "Node deleted successfully.\n";
    display(head);
}

// Step 5: Search an Element
void search(Node* head, int value) {

    int position = 1;

    while (head != nullptr) {

        if (head->data == value) {
            cout << "Element found at position: "
                << position << endl;
            return;
        }

        head = head->next;
        position++;
    }

    cout << "Element not found in the list.\n";
}

// Step 6: Update a Node's Value
void update(Node* head, int position, int newValue) {

    if (position < 1) {
        cout << "Invalid position!\n";
        return;
    }

    Node* temp = head;

    for (int i = 1; i < position && temp != nullptr; i++) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Invalid position!\n";
        return;
    }

    temp->data = newValue;

    cout << "Node updated successfully.\n";
    display(head);
}

// Step 7: Display Linked List
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

// Step 8: Insert at End (to create a list)
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
}

// Main Function
int main() {

    Node* head = nullptr;

    int choice, value, position, newValue;

    do {

        cout << "\n===== LINKED LIST MENU =====\n";
        cout << "1. Insert at End\n";
        cout << "2. Delete from Beginning\n";
        cout << "3. Delete from End\n";
        cout << "4. Delete from Position\n";
        cout << "5. Search an Element\n";
        cout << "6. Update a Node\n";
        cout << "7. Display Linked List\n";
        cout << "8. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Enter value: ";
            cin >> value;
            insertAtEnd(head, value);
            cout << "Node inserted successfully.\n";
            break;

        case 2:
            deleteFromBeginning(head);
            break;

        case 3:
            deleteFromEnd(head);
            break;

        case 4:
            cout << "Enter position to delete: ";
            cin >> position;
            deleteFromPosition(head, position);
            break;

        case 5:
            cout << "Enter value to search: ";
            cin >> value;
            search(head, value);
            break;

        case 6:
            cout << "Enter position to update: ";
            cin >> position;
            cout << "Enter new value: ";
            cin >> newValue;
            update(head, position, newValue);
            break;

        case 7:
            display(head);
            break;

        case 8:
            cout << "Program ended.\n";
            break;

        default:
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 8);

    return 0;
}
