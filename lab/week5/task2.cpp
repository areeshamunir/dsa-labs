#include <iostream>
#include <stack>
#include <vector>
using namespace std;

template <typename T>
class myQueue {
private:
    stack<T> stack1;
    stack<T> stack2;

    // Transfer elements from stack1 to stack2
    void transfer() {
        while (!stack1.empty()) {
            stack2.push(stack1.top());
            stack1.pop();
        }
    }

public:

    // Enqueue: Insert element
    void enQueue(T value) {
        stack1.push(value);
        cout << value << " inserted successfully!" << endl;
    }

    // Dequeue: Remove front element
    T deQueue() {
        if (stack2.empty()) {
            transfer();
        }

        if (stack2.empty()) {
            cout << "Queue is Empty!" << endl;
            return T();
        }

        T value = stack2.top();
        stack2.pop();

        return value;
    }

    // Return front element
    T front() {
        if (stack2.empty()) {
            transfer();
        }

        if (stack2.empty()) {
            cout << "Queue is Empty!" << endl;
            return T();
        }

        return stack2.top();
    }

    // Check empty
    bool isEmpty() const {
        return stack1.empty() && stack2.empty();
    }

    // Display all elements
    void display() const {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return;
        }

        cout << "Queue elements (Front to Rear): ";

        // Display stack2 from top to bottom
        stack<T> temp2 = stack2;

        while (!temp2.empty()) {
            cout << temp2.top() << " ";
            temp2.pop();
        }

        // Display stack1 from bottom to top
        stack<T> temp1 = stack1;
        vector<T> elements;

        while (!temp1.empty()) {
            elements.push_back(temp1.top());
            temp1.pop();
        }

        for (int i = elements.size() - 1; i >= 0; i--) {
            cout << elements[i] << " ";
        }

        cout << endl;
    }
};

int main() {

    myQueue<int> q;

    int choice, value;

    do {
        cout << "\n===== QUEUE USING TWO STACKS =====" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Front Element" << endl;
        cout << "4. Display Elements" << endl;
        cout << "5. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Enter value: ";
            cin >> value;
            q.enQueue(value);
            break;

        case 2:
            if (!q.isEmpty())
                cout << "Removed Element: " << q.deQueue() << endl;
            else
                cout << "Queue is Empty!" << endl;
            break;

        case 3:
            if (!q.isEmpty())
                cout << "Front Element: " << q.front() << endl;
            else
                cout << "Queue is Empty!" << endl;
            break;

        case 4:
            q.display();
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