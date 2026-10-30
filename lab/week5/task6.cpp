#include <iostream>
#include <queue>
#include <string>
#include <iomanip>
#include <sstream>
using namespace std;

// Convert HH:MM into minutes
int convertTime(string time) {
    int hour, minute;
    char colon;

    stringstream ss(time);
    ss >> hour >> colon >> minute;

    if (ss.fail() || colon != ':' ||
        hour < 0 || hour > 23 ||
        minute < 0 || minute > 59) {
        return -1;
    }

    return hour * 60 + minute;
}

// Package structure
struct Package {
    int packageID;
    string address;
    string startTime;
    string endTime;
    int startMinutes;
    int endMinutes;
};

class DeliverySystem {
private:
    queue<Package> packages;

public:

    // 1. Enqueue: Add new package
    void enqueue(int id, string address,
        string start, string end) {

        if (id <= 0) {
            cout << "Invalid Package ID!" << endl;
            return;
        }

        // Check duplicate ID
        queue<Package> temp = packages;

        while (!temp.empty()) {
            if (temp.front().packageID == id) {
                cout << "Package ID already exists!" << endl;
                return;
            }
            temp.pop();
        }

        int startMin = convertTime(start);
        int endMin = convertTime(end);

        if (startMin == -1 || endMin == -1 ||
            startMin > endMin) {
            cout << "Invalid delivery time window!" << endl;
            return;
        }

        Package p;

        p.packageID = id;
        p.address = address;
        p.startTime = start;
        p.endTime = end;
        p.startMinutes = startMin;
        p.endMinutes = endMin;

        packages.push(p);

        cout << "Package added successfully!" << endl;
    }

    // 2. Check front package
    void front() {

        if (packages.empty()) {
            cout << "No pending packages!" << endl;
            return;
        }

        Package p = packages.front();

        cout << "\nNext Package Details:" << endl;
        cout << "Package ID: " << p.packageID << endl;
        cout << "Address: " << p.address << endl;
        cout << "Delivery Window: "
            << p.startTime << " - " << p.endTime << endl;
    }

    // 3. Display all packages
    void display() {

        if (packages.empty()) {
            cout << "No pending packages!" << endl;
            return;
        }

        queue<Package> temp = packages;

        cout << "\n===== PENDING PACKAGES =====" << endl;

        while (!temp.empty()) {

            Package p = temp.front();

            cout << "\nPackage ID: " << p.packageID << endl;
            cout << "Address: " << p.address << endl;
            cout << "Time Window: "
                << p.startTime << " - " << p.endTime << endl;

            temp.pop();
        }
    }

    // 4. Check delivery time
    bool timeToDeliver(int currentTime) {

        // Skip expired packages
        while (!packages.empty() &&
            currentTime > packages.front().endMinutes) {

            cout << "Package "
                << packages.front().packageID
                << " has expired!" << endl;

            packages.pop();
        }

        if (packages.empty()) {
            cout << "No packages available for delivery!" << endl;
            return false;
        }

        Package p = packages.front();

        if (currentTime < p.startMinutes) {
            cout << "Package " << p.packageID
                << " delivery window has not started yet!" << endl;
            return false;
        }

        cout << "Package " << p.packageID
            << " can be delivered now!" << endl;

        return true;
    }

    // 5. Dequeue: Deliver package
    void dequeue(int currentTime) {

        if (timeToDeliver(currentTime)) {

            cout << "Package "
                << packages.front().packageID
                << " delivered successfully!" << endl;

            packages.pop();
        }
    }
};

// Main Function
int main() {

    DeliverySystem ds;

    int choice, id, currentTime;
    string address, start, end, time;

    do {

        cout << "\n===== PACKAGE DELIVERY SYSTEM =====" << endl;
        cout << "1. Add New Package" << endl;
        cout << "2. Deliver Package" << endl;
        cout << "3. Front Package" << endl;
        cout << "4. Display All Packages" << endl;
        cout << "5. Check Delivery Time" << endl;
        cout << "6. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        cin.ignore(10000, '\n');

        switch (choice) {

        case 1:
            cout << "Enter Package ID: ";
            cin >> id;
            cin.ignore(10000, '\n');

            cout << "Enter Recipient Address: ";
            getline(cin, address);

            cout << "Enter Start Time (HH:MM): ";
            cin >> start;

            cout << "Enter End Time (HH:MM): ";
            cin >> end;

            ds.enqueue(id, address, start, end);
            break;

        case 2:
            cout << "Enter Current Time (HH:MM): ";
            cin >> time;

            currentTime = convertTime(time);

            if (currentTime == -1)
                cout << "Invalid time format!" << endl;
            else
                ds.dequeue(currentTime);
            break;

        case 3:
            ds.front();
            break;

        case 4:
            ds.display();
            break;

        case 5:
            cout << "Enter Current Time (HH:MM): ";
            cin >> time;

            currentTime = convertTime(time);

            if (currentTime == -1)
                cout << "Invalid time format!" << endl;
            else
                ds.timeToDeliver(currentTime);
            break;

        case 6:
            cout << "Exiting Delivery System!" << endl;
            break;

        default:
            cout << "Invalid Choice!" << endl;
        }

    } while (choice != 6);

    return 0;
}