
#include <iostream>
#include <string>
using namespace std;

// Structure for Customer
struct Customer {
    string name;
    string transaction;
};

// Circular Queue Class
class BankQueue {
private:
    Customer queue[5];
    int front;
    int rear;
    int count;

public:

    // Constructor
    BankQueue() {
        front = 0;
        rear = -1;
        count = 0;
    }

    // Check if Queue is Empty
    bool isEmpty() {
        return count == 0;
    }

    // Check if Queue is Full
    bool isFull() {
        return count == 5;
    }

    // 1. Enqueue: Add Customer
    void enqueue(Customer c) {

        if (isFull()) {
            cout << "Queue Overflow! Bank queue is full."
                << endl;
            return;
        }

        rear = (rear + 1) % 5;

        queue[rear] = c;

        count++;

        cout << "Customer added successfully!" << endl;
    }

    // 2. Dequeue: Remove and Return Customer
    Customer dequeue() {

        if (isEmpty()) {
            cout << "Queue Underflow! No customer to serve."
                << endl;

            return { "", "" };
        }

        Customer served = queue[front];

        front = (front + 1) % 5;

        count--;

        return served;
    }

    // 3. Display Waiting Customers
    void display() {

        if (isEmpty()) {
            cout << "No customers waiting!" << endl;
            return;
        }

        cout << "\nCustomers Waiting in Bank:\n";

        for (int i = 0; i < count; i++) {

            int index = (front + i) % 5;

            cout << "Name: " << queue[index].name
                << " | Transaction: "
                << queue[index].transaction << endl;
        }
    }

    // 4. Count Customers
    void totalCustomers() {
        cout << "Total customers waiting: "
            << count << endl;
    }
};

// Main Function
int main() {

    BankQueue bank;
    Customer c;
    Customer served;

    int choice;

    do {

        cout << "\n===== BANK QUEUE SYSTEM =====" << endl;

        cout << "1. Add Customer (Enqueue)" << endl;
        cout << "2. Serve Customer (Dequeue)" << endl;
        cout << "3. Display Waiting Customers" << endl;
        cout << "4. Total Customers" << endl;
        cout << "5. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1:

            cout << "Enter customer name: ";
            getline(cin >> ws, c.name);

            cout << "Enter transaction type: ";
            getline(cin, c.transaction);

            bank.enqueue(c);

            break;

        case 2:

            served = bank.dequeue();

            if (served.name != "") {

                cout << "\nCustomer Served Successfully!"
                    << endl;

                cout << "Name: " << served.name << endl;

                cout << "Transaction: "
                    << served.transaction << endl;
            }

            break;

        case 3:

            bank.display();

            break;

        case 4:

            bank.totalCustomers();

            break;

        case 5:

            cout << "Exiting Bank Queue System..."
                << endl;

            break;

        default:

            cout << "Invalid choice! Try again."
                << endl;
        }

    } while (choice != 5);

    return 0;
}
