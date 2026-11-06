
#include <iostream>
#include <string>
using namespace std;

// Node Class
class Node {
public:
    int patientID;
    string patientName;
    Node* next;

    Node(int id, string name) {
        patientID = id;
        patientName = name;
        next = nullptr;
    }
};

// Patient Queue ADT
class PatientQueue {
private:
    Node* head;

public:

    // Constructor
    PatientQueue() {
        head = nullptr;
    }

    // 1. Add Patient at End
    void addPatient(int id, string name) {

        Node* newNode = new Node(id, name);

        if (head == nullptr) {
            head = newNode;
        }
        else {
            Node* temp = head;

            while (temp->next != nullptr) {
                temp = temp->next;
            }

            temp->next = newNode;
        }

        cout << "Patient added successfully!" << endl;
    }

    // 2. Remove Patient by ID
    void removePatient(int id) {

        if (head == nullptr) {
            cout << "No patients in the queue!" << endl;
            return;
        }

        Node* temp = head;

        // If first patient cancels
        if (head->patientID == id) {
            head = head->next;
            delete temp;

            cout << "Patient removed successfully!" << endl;
            return;
        }

        // Search for patient
        while (temp->next != nullptr &&
            temp->next->patientID != id) {

            temp = temp->next;
        }

        if (temp->next == nullptr) {
            cout << "Patient not found!" << endl;
        }
        else {
            Node* deleteNode = temp->next;

            temp->next = deleteNode->next;

            delete deleteNode;

            cout << "Patient removed successfully!" << endl;
        }
    }

    // 3. Display Patients
    void displayPatients() {

        if (head == nullptr) {
            cout << "No patients waiting!" << endl;
            return;
        }

        Node* temp = head;

        cout << "\nPatients Waiting for Consultation:\n";

        while (temp != nullptr) {

            cout << "Patient ID: " << temp->patientID;
            cout << " | Name: " << temp->patientName << endl;

            temp = temp->next;
        }
    }

    // 4. Count Total Patients
    void countPatients() {

        int count = 0;
        Node* temp = head;

        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }

        cout << "Total Patients Waiting: " << count << endl;
    }

    // Destructor
    ~PatientQueue() {

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

    PatientQueue hospital;

    // Adding Patients
    cout << "Adding Patients:\n";

    hospital.addPatient(101, "Ali");
    hospital.addPatient(102, "Ahmed");
    hospital.addPatient(103, "Sara");
    hospital.addPatient(104, "Ayesha");

    // Display Patients
    hospital.displayPatients();

    // Count Patients
    hospital.countPatients();

    // Remove Cancelled Patient
    cout << "\nPatient 102 cancelled appointment.\n";

    hospital.removePatient(102);

    // Display Updated List
    hospital.displayPatients();

    // Count Updated Patients
    hospital.countPatients();

    return 0;
}
