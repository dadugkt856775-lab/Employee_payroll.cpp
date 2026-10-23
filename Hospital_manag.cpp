
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Patient {
private:
    int patientID;
    string name;
    int age;
    string disease;
    string status;

public:
    Patient(int id, string n, int a, string d) {
        patientID = id;
        name = n;
        age = a;
        disease = d;
        status = "Under Treatment";
    }

    int getID() const {
        return patientID;
    }

    void updateStatus(string newStatus) {
        status = newStatus;
        cout << "Treatment status updated successfully!\n";
    }

    void display() const {
        cout << "\n----- Patient Details -----\n";
        cout << "Patient ID : " << patientID << endl;
        cout << "Name       : " << name << endl;
        cout << "Age        : " << age << endl;
        cout << "Disease    : " << disease << endl;
        cout << "Status     : " << status << endl;
        cout << "---------------------------\n";
    }
};

int main() {
    vector<Patient> patients;
    int choice;

    do {
        cout << "\n===== HOSPITAL MANAGEMENT =====\n";
        cout << "1. Register Patient\n";
        cout << "2. Display All Patients\n";
        cout << "3. Search Patient\n";
        cout << "4. Update Treatment Status\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int id, age;
            string name, disease;
            bool exists = false;

            cout << "Enter patient ID: ";
            cin >> id;

            for (const Patient &p : patients) {
                if (p.getID() == id) {
                    exists = true;
                    break;
                }
            }

            if (exists) {
                cout << "Patient ID already exists!\n";
                break;
            }

            cout << "Enter patient name: ";
            cin >> ws;
            getline(cin, name);

            cout << "Enter patient age: ";
            cin >> age;

            if (age < 0 || age > 130) {
                cout << "Invalid age!\n";
                break;
            }

            cout << "Enter disease: ";
            cin >> ws;
            getline(cin, disease);

            patients.emplace_back(id, name, age, disease);
            cout << "Patient registered successfully!\n";
            break;
        }

        case 2:
            if (patients.empty()) {
                cout << "No patient records available!\n";
            } else {
                for (const Patient &p : patients) {
                    p.display();
                }
            }
            break;

        case 3: {
            int id;
            bool found = false;

            cout << "Enter patient ID to search: ";
            cin >> id;

            for (const Patient &p : patients) {
                if (p.getID() == id) {
                    p.display();
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "Patient not found!\n";
            }
            break;
        }

        case 4: {
            int id;
            string newStatus;
            bool found = false;

            cout << "Enter patient ID: ";
            cin >> id;

            for (Patient &p : patients) {
                if (p.getID() == id) {
                    cout << "Enter new status "
                         << "(Under Treatment/Recovered/Discharged): ";
                    cin >> ws;
                    getline(cin, newStatus);

                    p.updateStatus(newStatus);
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "Patient not found!\n";
            }
            break;
        }

        case 5:
            cout << "Exiting hospital management system...\n";
            break;

        default:
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 5);

    return 0;
}
