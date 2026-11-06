
#include <iostream>
using namespace std;

// Node Class
class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// LinkedList ADT Class
class LinkedList {
private:
    Node* head;

public:

    // Constructor
    LinkedList() {
        head = nullptr;
    }

    // 1. Insert at Beginning
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);

        newNode->next = head;
        head = newNode;
    }

    // 2. Insert at End
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);

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

    // 3. Delete Node by Value
    void deleteNode(int value) {

        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }

        // If first node contains the value
        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Node deleted successfully!" << endl;
            return;
        }

        Node* temp = head;

        while (temp->next != nullptr &&
            temp->next->data != value) {
            temp = temp->next;
        }

        if (temp->next == nullptr) {
            cout << "Value not found!" << endl;
        }
        else {
            Node* deleteNode = temp->next;
            temp->next = deleteNode->next;
            delete deleteNode;

            cout << "Node deleted successfully!" << endl;
        }
    }

    // 4. Traverse and Display
    void display() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* temp = head;

        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }

        cout << "NULL" << endl;
    }

    // Destructor
    ~LinkedList() {
        Node* temp;

        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

// Main Function
int main() {

    LinkedList list;

    list.insertAtBeginning(20);
    list.insertAtBeginning(10);

    list.insertAtEnd(30);
    list.insertAtEnd(40);

    cout << "Original Linked List: ";
    list.display();

    list.deleteNode(20);

    cout << "After Deletion: ";
    list.display();

    return 0;
}
