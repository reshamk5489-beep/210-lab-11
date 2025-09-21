#include <iostream>
using namespace std;

// Comment #1: Define a constant for the maximum number of departments.
const int MAX_DEPARTMENTS = 4;

// Comment #2: Define a constant for the maximum number of employees per department.
const int MAX_EMPLOYEES = 3;  

// Comment #3: Define a structure to represent a department containing its 
// name, ID, and a dynamic array of employee IDs.
struct Department
{
    string name;
    int id;
    int *employeeIds;

    // Comment #4: Destructor to free dynamically allocated memory for employee IDs.
    ~Department()
    {
        if (employeeIds)
        {
            delete [] employeeIds;
        }
        
        employeeIds = nullptr;
    }
};

void inputDepartment(Department *deptPtr);

int main()
{
    // Comment #5: Dynamically allocate an array of Department structures.
    Department *departments = new Department[MAX_DEPARTMENTS];

    // Comment #6: Input details for each department.
    for (int i = 0; i < MAX_DEPARTMENTS; ++i)
    {
       inputDepartment(&departments[i]);
    }
}

void inputDepartment(Department *deptPtr)
{
    cout << "Enter department name: ";
    cin >> deptPtr->name;

    cout << "Enter the department ID:";
    cin >> deptPtr->id;

    deptPtr->employeeIds = new int[MAX_EMPLOYEES];

    for(int i = 0; i < MAX_EMPLOYEES; ++i)
    {
        cout << "Enter employee ID " << (i + 1) << ": ";
        cin >> deptPtr->employeeIds[i];
    }
}