#include <iostream>
#include "employee.cpp"
#include "mangeremployee.cpp"
// #include "salariedemployee.cpp"
#include "hourlyemployee.cpp"
#include "commissionemployee.cpp"
using namespace std;
#ifndef HRSYSTEM_H
#define HRSYSTEM_H

class hrsystem
{
private:
    employee **employeelist;
    int employee_count;
    int employee_size;

public:
    hrsystem();
    hrsystem(int);
    ~hrsystem();
    void calctotalpayroll();
    void addemployee();
    void editemployee();
    void delemployee();
    void findemployee();
    void showall();
};

hrsystem ::hrsystem(){

};
hrsystem ::hrsystem(int size)
{
    employee_size = size;
    employeelist = new employee *[employee_size];
    employee_count = 0;
    /*for (int i = 0; i < employee_size; i++)
    {
        employeelist[i] = nullptr;
    }*/
};
hrsystem ::~hrsystem()
{
    for (int i = 0; i < employee_count; i++)
        delete employeelist[i];

    delete[] employeelist;
};

void hrsystem::addemployee()
{
    int n;
    cout << "How many ? (0-" << employee_size - employee_count << ") : ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int c;
        bool f = 1;
        cout << " Choose Employee Type : \n";
        cout << "\t1-Hourly Employee\n"
             << "\t2-Commission Employee\n"
             << "\t3-Salaried Employee\n"
             << "\t4-Manger Employee\n";
        cout << "Enter Selection ==> ";
        cin >> c;

        switch (c)
        {
        case 1:
        {
            employeelist[employee_count++] = new hourlyemployee();

            cout << "Created hourly employee at index " << employee_count << endl;
            employeelist[employee_count]->setid(employee_count + 1);
            // cout << "Set ID to " << employee_count + 1 << endl;
            employeelist[employee_count]->getinfo();
            // cout << "Got info for employee at index " << employee_count << endl;
            // cout << e->displaydetails() << endl;
            // employee_count++;
            cout << employee_count;
            // employeelist[employee_count] = e;
        }
        break;
        case 2:
        {
            employeelist[employee_count] = new commissionemployee();
            employeelist[employee_count]->getinfo();
            employeelist[employee_count]->setid(employee_count + 1);
            employee_count++;
        }
        break;
        case 3:
        {
            employeelist[employee_count] = new salariedemployee();
            employeelist[employee_count]->getinfo();
            employeelist[employee_count]->setid(employee_count + 1);
            employee_count++;
        }
        break;

        case 4:
        {
            employeelist[employee_count] = new mangeremployee();
        }
        break;
        default:
            // f = 0;
            break;
        }
        // if (f)
        // {
        //     employeelist[employee_count]->setid(i + 1);
        //     employeelist[employee_count]->getinfo();
        //     // cin.ignore();
        //     employee_count++;
        // }
    }
}
void hrsystem::editemployee()
{
    int edid;

    if (employee_count == 0)
        cout << "\nThere are No Employees  to search for ! \n";
    else
    {
        cout << "\nEnter Employee ID to Edit please : ";
        cin >> edid;
        while (edid > employee_count)
        {
            cout << "\nThere is No Employees with this Id\n";
            cout << "Please Enter valid ID : ";
            cin >> edid;
            if (edid <= employee_count)
                break;
        }
        employeelist[edid - 1]->getinfo();
        cout << "Employee Edited Sccessfully ! ";
    }
}
void hrsystem::delemployee()
{
    int delid;
    cout << "Enter Employee's ID to Delete : ";
    cin >> delid;
    if (employee_count == 0)
    {
        cout << "NO Employee EXIST!\n";
        return;
    }
    bool deleted = false;
    for (int i = 0; i < employee_count; ++i)
    {
        if (employeelist[i]->getid() == delid)
        {
            if (i == employee_count - 1)
            {
                employee_count--;
            }
            else
            {
                employeelist[i] = employeelist[employee_count - 1];
                employee_count--;
            }
            deleted = true;
            break;
        }
    }
    if (deleted)
    {
        cout << "Employee DELETED SUCCESSFULLY !\n";
    }
    else
    {
        cout << "NO Employee EXIST!\n";
    }
}
void hrsystem::findemployee()
{
    int id;
    if (employee_count == 0)
        cout << "\nThere are No Employees to search for ! \n";
    else
    {
        cout << "\nEnter EmployeeID to find please..";
        cin >> id;
        while (id > employee_count)
        {
            cout << "\nThere is No Employee with this Id\n";
            cout << "Please Enter valid ID : ";
            cin >> id;
            if (id <= employee_count)
                break;
        }
        cout << employeelist[id - 1]->displaydetails() << endl;
    }
}
void hrsystem::showall()
{
    cout << employee_count;
    cout << "\t\tEmployees List :\n\n";
    for (int i = 0; i < employee_count; i++)
    {
        cout << "\n_____________________________________\n";
        cout << employeelist[i]->displaydetails() << endl;
    }
}
void hrsystem::calctotalpayroll()
{
    double total = 0;
    cout << "\t\tEmployees Total Payroll :\n\n";
    for (int i = 0; i < employee_count; i++)
    {
        total += employeelist[i]->calculatepay();
    }

    cout << "\n\tTotal Payroll = " << total;
}

#endif