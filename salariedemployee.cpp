#include <iostream>
#include "employee.cpp"
using namespace std;
#ifndef SALARIEDEMPLOYEE_H
#define SALARIEDEMPLOYEE_H

class salariedemployee : public employee
{
protected:
    double salary;

public:
    salariedemployee();
    salariedemployee(double);
    ~salariedemployee();
    double getsalary();
    string displaydetails();
    double calculatepay();
    void getinfo();
};

salariedemployee ::salariedemployee()
{
    salary = 0;
}
salariedemployee ::salariedemployee(double s)
{
    salary = s;
}
salariedemployee ::~salariedemployee()
{
}

double salariedemployee ::getsalary()
{
    return salary;
}
string salariedemployee ::displaydetails()
{
    return employee::displaydetails() + "\t Salary : " + to_string(salary);
}
double salariedemployee ::calculatepay()
{
    return getsalary();
}
void salariedemployee ::getinfo()
{
    employee::getinfo();
    cout << " Enter Salary : ";
    cin >> salary;
}
#endif