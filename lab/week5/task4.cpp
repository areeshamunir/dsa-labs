#include <iostream>
#include <queue>
using namespace std;

class CustomerSupport {
private:
    queue<int> tickets;

public:

    // Add new ticket
    void enqueue(int ticket_id) {

        if (ticket_id < 1000 || ticket_id > 9999) {
            cout << "Ticket ID must be 4 digits!" << endl;
            return;
        }

        tickets.push(ticket_id);
        cout << "Ticket " << ticket_id
            << " added successfully!" << endl;
    }

    // Resolve ticket
    void dequeue() {

        if (tickets.empty()) {
            cout << "No pending tickets!" << endl;
            return;
        }

        cout << "Ticket " << tickets.front()
            << " has been resolved!" << endl;

        tickets.pop();
    }

    // Check next ticket
    void front() {

        if (tickets.empty()) {
            cout << "No pending tickets!" << endl;
            return;
        }

        cout << "Next Ticket ID: "
            << tickets.front() << endl;
    }

    // Display all tickets
    void display() {

        if (tickets.empty()) {
            cout << "No pending tickets!" << endl;
            return;
        }

        queue<int> temp = tickets;

        cout << "Pending Tickets: ";

        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }

        cout << endl;
    }
};

int main() {

    CustomerSupport cs;

    int choice, ticket_id;

    do {

        cout << "\n===== CUSTOMER SUPPORT SYSTEM =====" << endl;
        cout << "1. Add New Ticket" << endl;
        cout << "2. Resolve Ticket" << endl;
        cout << "3. Next Ticket" << endl;
        cout << "4. Display Pending Tickets" << endl;
        cout << "5. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Enter 4-digit Ticket ID: ";
            cin >> ticket_id;
            cs.enqueue(ticket_id);
            break;

        case 2:
            cs.dequeue();
            break;

        case 3:
            cs.front();
            break;

        case 4:
            cs.display();
            break;

        case 5:
            cout << "Exiting Customer Support System!" << endl;
            break;

        default:
            cout << "Invalid Choice!" << endl;
        }

    } while (choice != 5);

    return 0;
}