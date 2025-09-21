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

// Comment #5: Function prototypes for input and output operations.
void inputDepartment(Department *deptPtr);
void outputDepartment(Department *deptPtr);

int main()
{
    // Comment #6: Dynamically allocate an array of Department structures.
    Department *departments = new Department[MAX_DEPARTMENTS];

    // Comment #7: Input details for each department.
    for (int i = 0; i < MAX_DEPARTMENTS; ++i)
    {
       inputDepartment(&departments[i]);
    }

    // Comment #8: Output details for each department.
    for (int i = 0; i < MAX_DEPARTMENTS; ++i)
    {
       outputDepartment(&departments[i]);
    }

    return 0;
}

void inputDepartment(Department *deptPtr)
{
    // Comment #9: Input department name, ID, and employee IDs.
    cout << "Enter department name: ";
    cin >> deptPtr->name;

    cout << "Enter the department ID#:";
    cin >> deptPtr->id;

    deptPtr->employeeIds = new int[MAX_EMPLOYEES];

    for(int i = 0; i < MAX_EMPLOYEES; ++i)
    {
        cout << "Enter employee ID# " << (i + 1) << ": ";
        cin >> deptPtr->employeeIds[i];
    }
}

void outputDepartment(Department *deptPtr)
{
    cout << "Department Name: " << deptPtr->name << endl;
    cout << "Department ID#: " << deptPtr->id << endl;

    // Comment #10: Output each employee ID in the department.
    for(int i = 0; i < MAX_EMPLOYEES; ++i)
    {
        cout << "Employee ID# " << (i + 1) << ": " << deptPtr->employeeIds[i] << " " << endl;
    }
}