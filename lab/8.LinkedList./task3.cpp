
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Node Structure
struct Node {
    int rollNo;
    string name;
    float marks;
    Node* next;
};

// Check duplicate roll number
bool rollExists(Node* head, int roll) {
    while (head != nullptr) {
        if (head->rollNo == roll)
            return true;

        head = head->next;
    }
    return false;
}

// Insert at Beginning
void insertAtBeginning(Node*& head, int roll,
    string name, float marks) {

    if (rollExists(head, roll)) {
        cout << "Roll number already exists!\n";
        return;
    }

    Node* newNode = new Node();

    newNode->rollNo = roll;
    newNode->name = name;
    newNode->marks = marks;

    newNode->next = head;
    head = newNode;

    cout << "Student inserted successfully.\n";
}

// Insert at End
void insertAtEnd(Node*& head, int roll,
    string name, float marks) {

    if (rollExists(head, roll)) {
        cout << "Roll number already exists!\n";
        return;
    }

    Node* newNode = new Node();

    newNode->rollNo = roll;
    newNode->name = name;
    newNode->marks = marks;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
        cout << "Student inserted successfully.\n";
        return;
    }

    Node* temp = head;

    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = newNode;

    cout << "Student inserted successfully.\n";
}

// Insert After Specific Roll Number
void insertAfterRoll(Node*& head, int targetRoll,
    int roll, string name, float marks) {

    if (rollExists(head, roll)) {
        cout << "Roll number already exists!\n";
        return;
    }

    Node* temp = head;

    while (temp != nullptr &&
        temp->rollNo != targetRoll) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Target roll number not found!\n";
        return;
    }

    Node* newNode = new Node();

    newNode->rollNo = roll;
    newNode->name = name;
    newNode->marks = marks;

    newNode->next = temp->next;
    temp->next = newNode;

    cout << "Student inserted successfully.\n";
}

// Delete Student by Roll Number
void deleteStudent(Node*& head, int roll) {

    if (head == nullptr) {
        cout << "List is empty!\n";
        return;
    }

    if (head->rollNo == roll) {
        Node* temp = head;
        head = head->next;
        delete temp;

        cout << "Student deleted successfully.\n";
        return;
    }

    Node* temp = head;

    while (temp->next != nullptr &&
        temp->next->rollNo != roll) {
        temp = temp->next;
    }

    if (temp->next == nullptr) {
        cout << "Student not found!\n";
        return;
    }

    Node* deleteNode = temp->next;
    temp->next = deleteNode->next;

    delete deleteNode;

    cout << "Student deleted successfully.\n";
}

// Search Student
void searchStudent(Node* head, int roll) {

    while (head != nullptr) {

        if (head->rollNo == roll) {
            cout << "\nStudent Found!\n";
            cout << "Roll Number: " << head->rollNo << endl;
            cout << "Name: " << head->name << endl;
            cout << "Marks: " << head->marks << endl;
            return;
        }

        head = head->next;
    }

    cout << "Student not found!\n";
}

// Update Student
void updateStudent(Node* head, int roll) {

    while (head != nullptr) {

        if (head->rollNo == roll) {

            int choice;

            cout << "1. Update Name\n";
            cout << "2. Update Marks\n";
            cout << "Enter choice: ";
            cin >> choice;

            if (choice == 1) {
                cout << "Enter new name: ";
                getline(cin >> ws, head->name);
                cout << "Name updated successfully.\n";
            }
            else if (choice == 2) {
                cout << "Enter new marks: ";
                cin >> head->marks;
                cout << "Marks updated successfully.\n";
            }
            else {
                cout << "Invalid choice!\n";
            }

            return;
        }

        head = head->next;
    }

    cout << "Student not found!\n";
}

// Display Students
void display(Node* head) {

    if (head == nullptr) {
        cout << "No student records available.\n";
        return;
    }

    cout << "\n";
    cout << left << setw(15) << "Roll No"
        << setw(25) << "Name"
        << setw(10) << "Marks" << endl;

    cout << "---------------------------------------------\n";

    while (head != nullptr) {

        cout << left << setw(15) << head->rollNo
            << setw(25) << head->name
            << setw(10) << head->marks << endl;

        head = head->next;
    }
}

// Calculate Statistics
void statistics(Node* head) {

    if (head == nullptr) {
        cout << "No records available.\n";
        return;
    }

    float highest = head->marks;
    float lowest = head->marks;
    float total = 0;
    int count = 0;

    while (head != nullptr) {

        if (head->marks > highest)
            highest = head->marks;

        if (head->marks < lowest)
            lowest = head->marks;

        total += head->marks;
        count++;

        head = head->next;
    }

    cout << "\n===== STUDENT STATISTICS =====\n";
    cout << "Highest Marks: " << highest << endl;
    cout << "Lowest Marks: " << lowest << endl;
    cout << "Average Marks: " << total / count << endl;
    cout << "Total Students: " << count << endl;
}

// Free Memory
void clearList(Node*& head) {

    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

// Main Function
int main() {

    Node* head = nullptr;

    int choice, roll, targetRoll;
    string name;
    float marks;

    do {

        cout << "\n===== STUDENT RECORD MANAGEMENT =====\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert After Roll Number\n";
        cout << "4. Delete Student\n";
        cout << "5. Search Student\n";
        cout << "6. Update Student\n";
        cout << "7. Display Students\n";
        cout << "8. Calculate Statistics\n";
        cout << "9. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
        case 2:
        case 3:

            cout << "Enter Roll Number: ";
            cin >> roll;

            cout << "Enter Student Name: ";
            getline(cin >> ws, name);

            cout << "Enter Marks: ";
            cin >> marks;

            if (choice == 1) {
                insertAtBeginning(head, roll, name, marks);
            }
            else if (choice == 2) {
                insertAtEnd(head, roll, name, marks);
            }
            else {
                cout << "Enter target roll number: ";
                cin >> targetRoll;

                insertAfterRoll(head, targetRoll,
                    roll, name, marks);
            }

            break;

        case 4:
            cout << "Enter Roll Number to delete: ";
            cin >> roll;
            deleteStudent(head, roll);
            break;

        case 5:
            cout << "Enter Roll Number to search: ";
            cin >> roll;
            searchStudent(head, roll);
            break;

        case 6:
            cout << "Enter Roll Number to update: ";
            cin >> roll;
            updateStudent(head, roll);
            break;

        case 7:
            display(head);
            break;

        case 8:
            statistics(head);
            break;

        case 9:
            cout << "Program ended.\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 9);

    clearList(head);

    return 0;
}
