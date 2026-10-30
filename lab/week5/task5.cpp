#include <iostream>
#include <queue>
#include <string>
#include <limits>
using namespace std;

class PrinterQueue {
private:
    queue<string> printQueue;

public:

    // 1. Enqueue
    void enqueue(string document_name) {
        printQueue.push(document_name);
        cout << document_name << " added to print queue!" << endl;
    }

    // 2. Dequeue
    void dequeue() {
        if (printQueue.empty()) {
            cout << "Print queue is empty!" << endl;
            return;
        }

        cout << "Printing: " << printQueue.front() << endl;
        printQueue.pop();
    }

    // 3. Front
    void front() {
        if (printQueue.empty()) {
            cout << "Print queue is empty!" << endl;
            return;
        }

        cout << "Front Document: " << printQueue.front() << endl;
    }

    // 4. Display
    void display() {
        if (printQueue.empty()) {
            cout << "Print queue is empty!" << endl;
            return;
        }

        queue<string> temp = printQueue;

        cout << "Documents in Print Queue:" << endl;

        while (!temp.empty()) {
            cout << temp.front() << endl;
            temp.pop();
        }
    }
};

int main() {

    PrinterQueue printer;
    int choice;
    string document_name;

    do {
        cout << "\n===== DOCUMENT PRINTING SYSTEM =====" << endl;
        cout << "1. Enqueue (Add Document)" << endl;
        cout << "2. Dequeue (Print Document)" << endl;
        cout << "3. Front (Check Next Document)" << endl;
        cout << "4. Display Documents" << endl;
        cout << "5. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {

        case 1:
            cout << "Enter Document Name: ";
            getline(cin, document_name);
            printer.enqueue(document_name);
            break;

        case 2:
            printer.dequeue();
            break;

        case 3:
            printer.front();
            break;

        case 4:
            printer.display();
            break;

        case 5:
            cout << "Program Exited!" << endl;
            break;

        default:
            cout << "Invalid Choice!" << endl;
        }

    } while (choice != 5);

    return 0;
}