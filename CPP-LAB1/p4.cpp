#include <iostream>
#include <vector>
using namespace std;

class EMPLOYEE {
private:
    int empNumber;
    string empName;
    float basic;
    float DA;
    float IT;
    float netSalary;

public:
    void readData() {
        cout << "Enter Employee Number: ";
        cin >> empNumber;
        cout << "Enter Employee Name: ";
        cin.ignore();
        getline(cin, empName);
        cout << "Enter Basic Salary: ";
        cin >> basic;

    
        DA = 0.52 * basic;
        float grossSalary = basic + DA;
        IT = 0.30 * grossSalary;
        netSalary = grossSalary - IT;
    }
    void printData() const {
        cout << "Employee Number: " << empNumber;
        cout << "Employee Name: " << empName;
        cout << "Basic Salary: " << basic;
        cout << "Dearness Allowance (DA): " << DA;
        cout << "Income Tax (IT): " << IT;
        cout << "Net Salary: " << netSalary;
    }
};

int main() {
    int N;
    cout << "Enter the number of employees: ";
    cin >> N;
    vector<EMPLOYEE> employees(N);
    for (int i = 0; i < N; ++i) {
        cout << "\nEnter details for employee " << i + 1 << ":\n";
        employees[i].readData();
    }
    for (int i = 0; i < N; ++i) {
        cout << "\nDetails of employee " << i + 1 << ":\n";
        employees[i].printData();
    }

    return 0;
}
