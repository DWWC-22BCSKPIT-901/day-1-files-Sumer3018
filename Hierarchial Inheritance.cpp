#include <iostream>
#include <iomanip>
using namespace std;

class Employee {
protected:
    string name;
    int id;
    double salary;
public:
    Employee(string n, int i, double s) : name(n), id(i), salary(s) {}
    virtual void calculateEarnings() = 0;
    virtual ~Employee() {}
};

class Manager : public Employee {
    int rating;
public:
    Manager(string n, int i, double s, int r) : Employee(n, i, s), rating(r) {}
    void calculateEarnings() override {
        double bonus = salary * 0.1 * rating;
        double totalEarnings = salary + bonus;
        cout << "Employee: " << name << " (ID: " << id << ")\n";
        cout << "Role: Manager\n";
        cout << "Base Salary: " << fixed << setprecision(2) << salary << "\n";
        cout << "Bonus: " << bonus << "\n";
        cout << "Total Earnings: " << totalEarnings << "\n";
    }
};

class Developer : public Employee {
    int extraHours;
public:
    Developer(string n, int i, double s, int h) : Employee(n, i, s), extraHours(h) {}
    void calculateEarnings() override {
        double overtimeCompensation = extraHours * 500;
        double totalEarnings = salary + overtimeCompensation;
        cout << "Employee: " << name << " (ID: " << id << ")\n";
        cout << "Role: Developer\n";
        cout << "Base Salary: " << fixed << setprecision(2) << salary << "\n";
        cout << "Overtime Compensation: " << overtimeCompensation << "\n";
        cout << "Total Earnings: " << totalEarnings << "\n";
    }
};

int main() {
    int employeeType;
    cout<<"1: Manager\n2: Developer";
    cin >> employeeType;

    if (employeeType == 1) {
        string name;
        int id;
        double salary;
        int rating;
        cout<<"Name,ID,Salary,Rating";
        cin >> name >> id >> salary >> rating;
        Manager m(name, id, salary, rating);
        m.calculateEarnings();
    } else if (employeeType == 2) {
        string name;
        int id;
        double salary;
        int extraHours;
        cout<<"Name,ID,Salary,Extra Hours";
        cin >> name >> id >> salary >> extraHours;
        Developer d(name, id, salary, extraHours);
        d.calculateEarnings();
    }

}
