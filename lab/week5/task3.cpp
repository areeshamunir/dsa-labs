#include <iostream>
#include <queue>
#include <stack>
using namespace std;

// Reverse first K elements
void reverseK(queue<int>& q, int k) {

    int n = q.size();

    // Handle K greater than queue size
    if (k > n) {
        k = n;
    }

    // No reversal needed
    if (k <= 1) {
        return;
    }

    stack<int> s;

    // Step 1: Push first K elements into stack
    for (int i = 0; i < k; i++) {
        s.push(q.front());
        q.pop();
    }

    // Step 2: Insert elements back from stack
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }

    // Step 3: Move remaining elements to the back
    for (int i = 0; i < n - k; i++) {
        q.push(q.front());
        q.pop();
    }
}

// Display Queue
void display(queue<int> q) {

    cout << "Queue: ";

    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }

    cout << endl;
}

int main() {

    queue<int> q;

    int n, value, k;

    // Read queue size
    cout << "Enter number of elements: ";
    cin >> n;

    if (n < 0) {
        cout << "Invalid queue size!" << endl;
        return 0;
    }

    // Read queue elements
    cout << "Enter queue elements:" << endl;

    for (int i = 0; i < n; i++) {
        cin >> value;
        q.push(value);
    }

    // Display original queue
    cout << "\nOriginal ";
    display(q);

    // Read K
    cout << "Enter value of K: ";
    cin >> k;

    if (k < 0) {
        cout << "Invalid K value!" << endl;
        return 0;
    }

    // Reverse first K elements
    reverseK(q, k);

    // Display final queue
    cout << "\nOutput ";
    display(q);

    return 0;
}