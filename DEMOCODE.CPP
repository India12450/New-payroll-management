#include<iostream.h>
#include<fstream.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>

class Person {
public:
    char name[50];
    char address[50];
    char phone[50];

    // Default constructor
    Person() {
	strcpy(name, "");
	strcpy(address, "");
	strcpy(phone, "");
    }

    // Parameterized constructor
    Person(const char* name, const char* address, const char* phone) {
	strncpy(this->name, name, 50);
	strncpy(this->address, address, 50);
	strncpy(this->phone, phone, 50);
    }
};

class Employee : public Person {
public:
    int id;
    double basicSalary;
    double netSalary;

    // Constants for salary calculation
    static const double da;
    static const double pf;
    static const double tax;
    static const double ma;
    static const double hra;
    static const double ta;
    static const double media;

    // Default constructor
    Employee() : id(0), basicSalary(0), netSalary(0) {}

    // Parameterized constructor
    Employee(int id, const char* name, const char* address, const char* phone, double basicSalary)
	: Person(name, address, phone), id(id), basicSalary(basicSalary) {
	calculateNetSalary();
    }

    void calculateNetSalary() {
	netSalary = basicSalary - (da + pf + tax) + (ma + hra + ta + media);
    }

    void print() {
	cout << "===============================" << endl;
	cout << "      |     Employee ID:          " << id << endl;
	cout << "      |     Name:                 " << name << endl;
	cout << "      |     Address:              " << address << endl;
	cout << "      |     Phone:                " << phone << endl;
	cout << "      |     Basic Salary:         " << basicSalary << endl;
	cout << "      |     Net Salary:           " << netSalary << endl;
	cout << "===============================" << endl;
    }
};

// Initialize static constants
const double Employee::da = 200;
const double Employee::pf = 300;
const double Employee::tax = 500;
const double Employee::ma = 300;
const double Employee::hra = 400;
const double Employee::ta = 300;
const double Employee::media = 300;

const int MAX_EMPLOYEES = 100;  // Adjust as needed
Employee employees[MAX_EMPLOYEES];
int employeeCount = 0;

void saveDataToFile() {
    ofstream outFile("employee_data.txt");

    for (int i = 0; i < employeeCount; i++) {
	outFile << employees[i].id << " "
		<< employees[i].name << " "
		<< employees[i].address << " "
		<< employees[i].phone << " "
		<< employees[i].basicSalary << " "
		<< employees[i].netSalary << endl;
    }

    outFile.close();
}

void loadDataFromFile() {
    ifstream inFile("employee_data.txt");

    while (inFile >> employees[employeeCount].id >> employees[employeeCount].name
		   >> employees[employeeCount].address >> employees[employeeCount].phone
		   >> employees[employeeCount].basicSalary >> employees[employeeCount].netSalary) {
	employeeCount++;

	if (employeeCount >= MAX_EMPLOYEES) {
	    cout << "Cannot add more employees. Array is full." << endl;
	    break;
	}
    }

    inFile.close();
}

void addEmployee() {
    int id;
    char name[50];
    char address[50];
    char phone[50];
    double basicSalary;

    cout << "      ===== ADD EMPLOYEE =====" << endl;
    cout << "  \n   |      Enter employee ID:                        ";
    cin >> id;
    cout << "     |     Enter employee name:         ";
    cin >> name;
    cout << "     |     Enter employee address:         ";
    cin >> address;
    cout << "     |     Enter employee phone:            ";
    cin >> phone;
    cout << "     |     Enter employee basic salary:             ";
    cin >> basicSalary;

    Employee employee(id, name, address, phone, basicSalary);
    if (employeeCount < MAX_EMPLOYEES) {
	employees[employeeCount++] = employee;
    } else {
	cout << "Cannot add more employees. Array is full." << endl;
    }

    saveDataToFile();
}

void deleteEmployee() {
    int id;

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

    saveDataToFile();
}

void updateEmployee() {
    int id;

    cout << "              =====  UPDATE EMPLOYEE. =====" << endl;
    cout << "     |     Enter employee ID to update:            " << endl;
    cin >> id;

    for (int i = 0; i < employeeCount; i++) {
	if (employees[i].id == id) {
	    char name[50];
	    char address[50];
	    char phone[50];
	    double basicSalary;

	    cout << "-------------------------------------------------------";
	    cout << "     |      Enter new employee name:              ";
	    cin >> name;
	    cout << "      |     Enter new employee address:          ";
	    cin >> address;
	    cout << "     |     Enter new employee phone:      |     ";
	    cin >> phone;
	    cout << "     |    Enter new employee basic salary:           ";
	    cin >> basicSalary;

	    strncpy(employees[i].name, name, 50);
	    strncpy(employees[i].address, address, 50);
	    strncpy(employees[i].phone, phone, 50);
	    employees[i].basicSalary = basicSalary;
	    employees[i].calculateNetSalary(); // Recalculate net salary
	    break;
	}
    }

    saveDataToFile();
}

void showEmployees() {
    for (int i = 0; i < employeeCount; i++) {
	employees[i].print();
    }
}

int main() {
    // Add some initial records
    employees[employeeCount++] = Employee(1, "John Doe", "123 Main St", "555-1234", 50000.00);
    employees[employeeCount++] = Employee(2, "Jane Smith", "456 Oak St", "555-5678", 60000.00);
    employees[employeeCount++] = Employee(3, "Bob Johnson", "789 Pine St", "555-9876", 70000.00);

    int choice;
    char pwd[30];
    char username[40];
    clrscr();
    cout << "\n Enter username :";
    cin >> username;
    cout << "\n password : ";
    cin >> pwd;

    if (strcmp(username, "admin") == 0 && strcmp(pwd, "admin123") == 0) {
	loadDataFromFile();

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
		    showEmployees();
		    getch();
		    break;
		case 5:
		    exit(0);
		    break;
		default:
		    cout << "Invalid choice" << endl;
	    }
	} while (choice != 5);
    } else {
        cout << "WRONG PASSWORD! TRY AGAIN";
    }

    return 0;
}
