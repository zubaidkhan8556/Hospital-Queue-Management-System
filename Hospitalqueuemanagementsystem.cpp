#include <iostream>
#include <queue>
#include <string>
using namespace std;

class Patient {
public:
    string name;
    int priority; // Higher = more emergency

    Patient(string n, int p) {
        name = n;
        priority = p;
    }

    // For max-heap based on priority
    bool operator<(const Patient& other) const {
        return priority < other.priority;
    }
};

int main() {
    priority_queue<Patient> pq;  // max-heap

    while (true) {
        cout << "\n--- Hospital Queue Management ---\n";
        cout << "1. Add Patient\n2. Serve Patient\n3. View Next Patient\n4. Exit\n";
        cout << "Enter choice: ";

        int choice;
        cin >> choice;

        if (choice == 1) {
            string name;
            int priority;

            cout << "Enter patient name: ";
            cin >> name;
            cout << "Enter priority (1-10): ";
            cin >> priority;

            pq.push(Patient(name, priority));
            cout << "Patient added!\n";
        }

        else if (choice == 2) {
            if (pq.empty()) {
                cout << "No patients in queue.\n";
            } else {
                Patient p = pq.top();
                pq.pop();
                cout << "Serving patient: " << p.name 
                     << " (Priority: " << p.priority << ")\n";
            }
        }

        else if (choice == 3) {
            if (pq.empty()) {
                cout << "No patients in queue.\n";
            } else {
                Patient p = pq.top();
                cout << "Next patient: " << p.name 
                     << " (Priority: " << p.priority << ")\n";
            }
        }

        else if (choice == 4) {
            cout << "Exiting...\n";
            break;
        }

        else {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}
