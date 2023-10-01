#include <iostream.h>
#include <vector>
#include<string.h>

using namespace std;

class Employee {
public:
  int id;
  string name;
  string address;
  string phone;
  double salary;

  Employee(int id, string name, string address, string phone, double salary) {
    this->id = id;
    this->name = name;
    this->address = address;
    this->phone = phone;
    this->salary = salary;
  }

  void print() {
    cout<<"==============================="<<endl;    
    cout << "      |     Employee ID:          " << id << endl;
   
    cout << "      |     Name:                     " << name << endl;
    
    cout << "     |     Address:                  " << address << endl;
   
    cout << "     |     Phone:                      " << phone << endl;
    
    cout << "     |     Salary after allowance increment and taxes deduction :     " << salary << endl;
    
cout<<"==============================";
  }
};

vector<Employee> employees;

void addEmployee() {
  int id,da=200,pf=300,hra=400,ma=300,ta=300,media=300,tax=500;
  string name;
  string address;
  string phone;
  double salary;
 cout<<"      ===== ADD EMPLOYEE ====="<< endl;
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
  salary=salary-(da+pf+tax)+(ma+hra+ta+media);
  cout<<"      |     salary after allowance encrement and taxes deduction :                    "<<salary<<endl;
cout<<"-------------------------------------------------------------"<<endl;
  Employee employee(id, name, address, phone, salary);
  employees.push_back(employee);
}

void deleteEmployee() {
  int id;
  cout<<"       =====    DELETE EMPLOYEE   ====="<<endl;
  cout << "     |     Enter employee ID to delete:           "<<endl;
  cin >> id;

  for (int i = 0; i < employees.size(); i++) {
    if (employees[i].id == id) {
      employees.erase(employees.begin() + i);
      break;
    }
  }
}

void updateEmployee() {
  int id;
  cout<<"              =====  UPDATE EMPLOYEE. ====="<<endl;
  cout << "     |     Enter employee ID to update:            "<< endl;
  cin >> id      ;

  for (int i = 0; i < employees.size(); i++) {
    if (employees[i].id == id) {
      string name;
      string address;
      string phone;
      double salary;
      cout<<"-------------------------------------------------------";
      cout << "     |      Enter new employee name:              ";
      cin >> name    ;
      cout << "      |     Enter new employee address:          ";
      cin >> address ;
      cout << "     |     Enter new employee phone:      |     ";
      cin >> phone;
      cout << "     |    Enter new employee salary:           ";
      cin >> salary    ;

      employees[i].name = name;
      employees[i].address = address;
      employees[i].phone = phone;
      employees[i].salary = salary;
      break;
    }
  }
}

void showEmployees() {
  for (int i = 0; i < employees.size(); i++) {
    employees[i].print();
  }
  return;
  getch();
}


int main() {
  int choice;
  char pwd[30];
  char username[40];
  
  cout<<"\n Enter username :";
 cin>>username;
  cout<<"\n password : ";
  cin>>pwd;
  if(strcmp(username,"admin") == 0 &&
      strcmp(pwd,"admin123") == 0)
{

  do {
    cout << "----------PAYROLL MANAGEMENT SYSTEM----------" << endl;
    cout << "     |     1. Add employee.           |     " << endl;
    cout << "     |     2. Delete employee.        |   " << endl;
    cout << "     |     3. Update employee.        |   " << endl;
    cout << "     |    4. Show employees.          |     " << endl;
    cout << "     |    5. Exit.                    |     " << endl;
    cout << "     | Enter your choice: ";
        cin >>choice;
    cout<<"--------------------------------------------------------"<<endl;
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
        cout<<"WRONG PASSWORD! TRY AGAIN";

  return 0;
}
