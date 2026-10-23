
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

class Employee {
private:
    int employeeID;
    string name;
    double basicSalary;
    double hra;
    double da;
    double deductions;

public:
    Employee(int id, string n, double basic) {
        employeeID = id;
        name = n;
        basicSalary = basic;
        hra = basicSalary * 0.20;
        da = basicSalary * 0.10;
        deductions = basicSalary * 0.05;
    }

    double calculateGrossSalary() const {
        return basicSalary + hra + da;
    }

    double calculateNetSalary() const {
        return calculateGrossSalary() - deductions;
    }

    void displaySalarySlip() const {
        cout << fixed << setprecision(2);
        cout << "\n========== SALARY SLIP ==========\n";
        cout << "Employee ID   : " << employeeID << endl;
        cout << "Employee Name : " << name << endl;
        cout << "Basic Salary  : Rs. " << basicSalary << endl;
        cout << "HRA (20%)     : Rs. " << hra << endl;
        cout << "DA (10%)      : Rs. " << da << endl;
        cout << "Gross Salary  : Rs. "
             << calculateGrossSalary() << endl;
        cout << "Deductions    : Rs. " << deductions << endl;
        cout << "Net Salary    : Rs. "
             << calculateNetSalary() << endl;
        cout << "=================================\n";
    }

    int getID() const {
        return employeeID;
    }
};

int main() {
    vector<Employee> employees;
    int choice;
    
    do {
        cout << "\n===== EMPLOYEE PAYROLL SYSTEM =====\n";
        cout << "1. Add Employee\n";
        cout << "2. Display All Salary Slips\n";
        cout << "3. Search Employee\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int id;
            string name;
            double basic;

            cout << "Enter employee ID: ";
            cin >> id;

            bool exists = false;

            for (const Employee &e : employees) {
                if (e.getID() == id) {
                    exists = true;
                    break;
                }
            }

            if (exists) {
                cout << "Employee ID already exists!\n";
                break;
            }

            cout << "Enter employee name: ";
            cin >> ws;
            getline(cin, name);

            cout << "Enter basic monthly salary: Rs. ";
            cin >> basic;

            if (basic <= 0) {
                cout << "Salary must be greater than zero!\n";
                break;
            }

            employees.emplace_back(id, name, basic);
            cout << "Employee added successfully!\n";
            break;
        }

        case 2:
            if (employees.empty()) {
                cout << "No employee records available!\n";
            } else {
                for (const Employee &e : employees) {
                    e.displaySalarySlip();
                }
            }
            break;

        case 3: {
            int searchID;
            bool found = false;

            cout << "Enter employee ID to search: ";
            cin >> searchID;

            for (const Employee &e : employees) {
                if (e.getID() == searchID) {
                    e.displaySalarySlip();
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "Employee not found!\n";
            }
            break;
        }

        case 4:
            cout << "Exiting payroll system...\n";
            break;

        default:
            cout << "Invalid choice! Please try again.\n";
        }

    } while (choice != 4);

    return 0;
}
