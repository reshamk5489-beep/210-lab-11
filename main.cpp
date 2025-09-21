#include <iostream>
using namespace std;

const int MAX_DEPARTMENTS = 4;

struct Department
{
    string name;
    int id;
    int *employeeIds;

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
    Department *departments = new Department[MAX_DEPARTMENTS];
    for (int i = 0; i < MAX_DEPARTMENTS; ++i)
    {
       
    }
}