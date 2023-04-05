#include <iostream>
#include "employee.cpp"
using namespace std;
#ifndef COMMISIONEMPLOYEE_H
#define COMMISIONEMPLOYEE_H

class commissionemployee : public employee
{
protected:
    double target;
    double rate;

public:
    commissionemployee();
    commissionemployee(double, double);
    ~commissionemployee();
    double getsalary();
    string displaydetails();
    double calculatepay();
    void getinfo();
};

commissionemployee ::commissionemployee()
{
    rate = 0;
    target = 0;
}

commissionemployee ::commissionemployee(double t, double r)
{
    rate = r;
    target = t;
}
commissionemployee ::~commissionemployee()
{
}

double commissionemployee ::getsalary()
{
    return rate * target;
}
string commissionemployee ::displaydetails()
{
    return employee::displaydetails() + "\t Target : " + to_string(target) + "\t Rate : " + to_string(rate);
}
double commissionemployee ::calculatepay()
{
    return getsalary();
}
void commissionemployee ::getinfo()
{
    employee::getinfo();
    cout << " Enter Rate : ";
    cin >> rate;
    cout << "Enter Target : ";
    cin >> target;
}
#endif