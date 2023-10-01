#include <iostream.h>
#include <string.h>
#include<stdlib.h>
#include<conio.h>

class Employee {
public:
    int id;
    char name[50];
    char address[50];
    char phone[50];
    double salary;

    // Default constructor
    Employee() : id(0), salary(0) {
        strcpy(name, "");
        strcpy(address, "");
        strcpy(phone, "");
    }

    // Parameterized constructor
    Employee(int id, const char* name, const char* address, const char* phone, double salary) {
        this->id = id;
        strncpy(this->name, name, 50);
        strncpy(this->address, address, 50);
        strncpy(this->phone, phone, 50);
        this->salary = salary;
    }

    void print() {
        cout << "===============================" << endl;
        cout << "      |     Employee ID:          " << id << endl;
        cout << "      |     Name:                 " << name << endl;
        cout << "      |     Address:              " << address << endl;
        cout << "      |     Phone:                " << phone << endl;
        cout << "      |     Salary:               " << salary << endl;
        cout << "===============================" << endl;
    }
};

const int MAX_EMPLOYEES = 100;  // Adjust as needed
Employee employees[MAX_EMPLOYEES];
int employeeCount = 0;

void addEmployee() {
    int id, da = 200, pf = 300, hra = 400, ma = 300, ta = 300, media = 300, tax = 500;
    char name[50];
    char address[50];
    char phone[50];
    double salary;
    clrscr();
    cout << "      ===== ADD EMPLOYEE =====" << endl;
    cout << "  \n   |      Enter employee ID:                        ";
    cin >> id;
    cout << "     |     Enter employee name:         ";
    cin >> name;
    cout << "     |     Enter employee address:         ";
    cin >> address;
    cout << "     |     Enter employee phone:            ";
    cin >> phone;
    cout << "     |     Enter employee salary:             ";
    cin >> salary;
    salary = salary - (da + pf + tax) + (ma + hra + ta + media);
    cout << "      |     Salary after allowance increment and taxes deduction :                    " << salary << endl;
    cout << "-------------------------------------------------------------" << endl;
    Employee employee(id, name, address, phone, salary);
    if (employeeCount < MAX_EMPLOYEES) {
	employees[employeeCount++] = employee;
    }
    else {
	cout << "Cannot add more employees. Array is full." << endl;
    }
}

void deleteEmployee() {
    int id;
    clrscr();
    cout << "       =====    DELETE EMPLOYEE   =====" << endl;
    cout << "     |     Enter employee ID to delete:           " << endl;
    cin >> id;

    for (int i = 0; i < employeeCount; i++) {
	if (employees[i].id == id) {
	    for (int j = i; j < employeeCount - 1; j++) {
		employees[j] = employees[j + 1];
	    }
	    employeeCount--;
	    break;
	}
    }
}

void updateEmployee() {
    int id;
    clrscr();
    cout << "              =====  UPDATE EMPLOYEE. =====" << endl;
    cout << "     |     Enter employee ID to update:            " << endl;
    cin >> id;

    for (int i = 0; i < employeeCount; i++) {
	if (employees[i].id == id) {
	    char name[50];
	    char address[50];
	    char phone[50];
	    double salary;
	    cout << "-------------------------------------------------------";
	    cout << "     |      Enter new employee name:              ";
	    cin >> name;
	    cout << "      |     Enter new employee address:          ";
	    cin >> address;
	    cout << "     |     Enter new employee phone:      |     ";
	    cin >> phone;
	    cout << "     |    Enter new employee salary:           ";
	    cin >> salary;

	    strncpy(employees[i].name, name, 50);
	    strncpy(employees[i].address, address, 50);
	    strncpy(employees[i].phone, phone, 50);
	    employees[i].salary = salary;
	    break;
	}
    }
}

void showEmployees() {
    for (int i = 0; i < employeeCount; i++) {
	employees[i].print();
    }
    getch();
    }

int main() {
    int choice;
    char pwd[30];
    char username[40];
    clrscr();

    cout << "\n Enter username :";
    cin >> username;
    cout << "\n password : ";
    cin >> pwd;
    if (strcmp(username, "admin") == 0 &&
	strcmp(pwd, "admin123") == 0) {

	do {
	    clrscr();
	    cout << "----------PAYROLL MANAGEMENT SYSTEM----------" << endl;
	    cout << "     |     1. Add employee.           |     " << endl;
	    cout << "     |     2. Delete employee.        |   " << endl;
	    cout << "     |     3. Update employee.        |   " << endl;
	    cout << "     |    4. Show employees.          |     " << endl;
	    cout << "     |    5. Exit.                    |     " << endl;
	    cout << "     | Enter your choice: ";
	    cin >> choice;
	    cout << "--------------------------------------------------------" << endl;
	    switch (choice) {
		case 1:
		    addEmployee();
		    break;
		case 2:
		    deleteEmployee();
		    break;
		case 3:
		    updateEmployee();
		    break;
		case 4:
		    clrscr();
		    showEmployees();
		    
		    break;
		case 5:
		    exit(0);
		    break;
		default:
		    cout << "Invalid choice" << endl;
	    }
	} while (choice != 5);
    }
    else
	cout << "WRONG PASSWORD! TRY AGAIN";

    return 0;
}
