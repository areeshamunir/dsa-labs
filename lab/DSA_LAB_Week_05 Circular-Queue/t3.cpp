
#include <iostream>
#include <string>
using namespace std;

const int SIZE = 5;

// Structure for Print Job
struct PrintJob
{
    int jobID;
    string userName;
    int pages;
};

// Circular Queue Class
class CircularQueue
{
private:
    PrintJob queue[SIZE];
    int front;
    int rear;
    int count;

public:

    // Constructor
    CircularQueue()
    {
        front = 0;
        rear = -1;
        count = 0;
    }

    // Check if queue is empty
    bool isEmpty()
    {
        return count == 0;
    }

    // Check if queue is full
    bool isFull()
    {
        return count == SIZE;
    }

    // Add a new print job
    void enqueue(PrintJob p)
    {
        if (isFull())
        {
            cout << "Printer Queue is Full!\n";
            return;
        }

        rear = (rear + 1) % SIZE;
        queue[rear] = p;
        count++;

        cout << "Print Job Added Successfully!\n";
    }

    // Remove and return completed print job
    PrintJob dequeue()
    {
        PrintJob p = queue[front];

        if (isEmpty())
        {
            cout << "Printer Queue is Empty!\n";
            return { -1, "", 0 };
        }

        front = (front + 1) % SIZE;
        count--;

        return p;
    }

    // Display next print job
    void peek()
    {
        if (isEmpty())
        {
            cout << "No pending print jobs!\n";
            return;
        }

        cout << "\nNext Print Job:\n";
        cout << "Job ID: " << queue[front].jobID << endl;
        cout << "User Name: " << queue[front].userName << endl;
        cout << "Pages: " << queue[front].pages << endl;
    }

    // Display all pending jobs
    void display()
    {
        if (isEmpty())
        {
            cout << "No pending print jobs!\n";
            return;
        }

        cout << "\nPending Print Jobs:\n";

        for (int i = 0; i < count; i++)
        {
            int index = (front + i) % SIZE;

            cout << "\nJob ID: " << queue[index].jobID;
            cout << "\nUser Name: " << queue[index].userName;
            cout << "\nPages: " << queue[index].pages << endl;
        }
    }

    // Show total pending jobs
    void totalJobs()
    {
        cout << "Total Pending Print Jobs: " << count << endl;
    }
};

// Main Function
int main()
{
    CircularQueue printer;
    PrintJob p;
    int choice;

    do
    {
        cout << "\n===== PRINTER JOB MANAGEMENT SYSTEM =====\n";
        cout << "1. Submit a new print job\n";
        cout << "2. Process the next print job\n";
        cout << "3. Display the next print job\n";
        cout << "4. Display all pending print jobs\n";
        cout << "5. Show total pending print jobs\n";
        cout << "6. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter Job ID: ";
            cin >> p.jobID;

            cout << "Enter User Name: ";
            cin >> ws;
            getline(cin, p.userName);

            cout << "Enter Total Pages: ";
            cin >> p.pages;

            printer.enqueue(p);
            break;

        case 2:
            if (!printer.isEmpty())
            {
                p = printer.dequeue();

                cout << "\nPrint Job Processed Successfully!\n";
                cout << "Job ID: " << p.jobID << endl;
                cout << "User Name: " << p.userName << endl;
                cout << "Pages: " << p.pages << endl;
            }
            else
            {
                cout << "Printer Queue is Empty!\n";
            }
            break;

        case 3:
            printer.peek();
            break;

        case 4:
            printer.display();
            break;

        case 5:
            printer.totalJobs();
            break;

        case 6:
            cout << "Exiting Program...\n";
            break;

        default:
            cout << "Invalid Choice! Try Again.\n";
        }

    } while (choice != 6);

    return 0;
}
