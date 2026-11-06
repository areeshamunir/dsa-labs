
#include <iostream>
#include <string>
using namespace std;

// Structure for Booking
struct Booking {
    int customerID;
    string customerName;
    int numberOfTickets;
};

// Circular Queue Class
class CinemaQueue {
private:
    Booking queue[5];
    int front;
    int rear;
    int count;

public:

    // Constructor
    CinemaQueue() {
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

    // 1. Enqueue: Add Booking
    void enqueue(Booking b) {

        if (isFull()) {
            cout << "Queue Overflow! No seats available."
                << endl;
            return;
        }

        rear = (rear + 1) % 5;

        queue[rear] = b;

        count++;

        cout << "Booking added successfully!" << endl;
    }

    // 2. Dequeue: Remove and Return Booking
    Booking dequeue() {

        if (isEmpty()) {
            cout << "Queue Underflow! No booking available."
                << endl;

            return { -1, "", 0 };
        }

        Booking cancelled = queue[front];

        front = (front + 1) % 5;

        count--;

        return cancelled;
    }

    // 3. Peek: Display First Booking
    void peek() {

        if (isEmpty()) {
            cout << "No booking available!" << endl;
            return;
        }

        cout << "\nNext Booking:\n";
        cout << "Customer ID: "
            << queue[front].customerID << endl;

        cout << "Customer Name: "
            << queue[front].customerName << endl;

        cout << "Number of Tickets: "
            << queue[front].numberOfTickets << endl;
    }

    // 4. Display All Bookings
    void display() {

        if (isEmpty()) {
            cout << "No bookings available!" << endl;
            return;
        }

        cout << "\n===== ALL CINEMA BOOKINGS =====\n";

        for (int i = 0; i < count; i++) {

            int index = (front + i) % 5;

            cout << "\nCustomer ID: "
                << queue[index].customerID << endl;

            cout << "Customer Name: "
                << queue[index].customerName << endl;

            cout << "Number of Tickets: "
                << queue[index].numberOfTickets << endl;
        }
    }

    // 5. Total Bookings
    void totalBookings() {
        cout << "Total bookings: " << count << endl;
    }
};

// Main Function
int main() {

    CinemaQueue cinema;
    Booking b;
    Booking cancelled;

    int choice;

    do {

        cout << "\n===== CINEMA TICKET BOOKING SYSTEM ====="
            << endl;

        cout << "1. Book Tickets (Enqueue)" << endl;
        cout << "2. Cancel First Booking (Dequeue)" << endl;
        cout << "3. Display Next Booking (Peek)" << endl;
        cout << "4. Display All Bookings" << endl;
        cout << "5. Show Total Bookings" << endl;
        cout << "6. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1:

            cout << "Enter Customer ID: ";
            cin >> b.customerID;

            cout << "Enter Customer Name: ";
            getline(cin >> ws, b.customerName);

            cout << "Enter Number of Tickets: ";
            cin >> b.numberOfTickets;

            if (b.numberOfTickets <= 0) {
                cout << "Invalid number of tickets!" << endl;
                break;
            }

            cinema.enqueue(b);

            break;

        case 2:

            cancelled = cinema.dequeue();

            if (cancelled.customerID != -1) {

                cout << "\nBooking Cancelled Successfully!"
                    << endl;

                cout << "Customer ID: "
                    << cancelled.customerID << endl;

                cout << "Customer Name: "
                    << cancelled.customerName << endl;

                cout << "Tickets: "
                    << cancelled.numberOfTickets << endl;
            }

            break;

        case 3:

            cinema.peek();

            break;

        case 4:

            cinema.display();

            break;

        case 5:

            cinema.totalBookings();

            break;

        case 6:

            cout << "Exiting Cinema Booking System..."
                << endl;

            break;

        default:

            cout << "Invalid choice! Try again."
                << endl;
        }

    } while (choice != 6);

    return 0;
}
