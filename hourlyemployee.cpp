#include <iostream>
#include "employee.cpp"
using namespace std;

#ifndef HOURLYEMPLOYEE_H
#define HOURLYEMPLOYEE_H

class hourlyemployee : public employee
{
private:
    double hoursworked;
    double rate;

public:
    hourlyemployee();
    hourlyemployee(double, double);
    virtual ~hourlyemployee();
    void addhours(int);
    double getsalary();
    string displaydetails();
    double calculatepay();
    void getinfo();
};

hourlyemployee::hourlyemployee()
{
    rate = 0;
    hoursworked = 0;
}
hourlyemployee::hourlyemployee(double r, double hw)
{
    rate = r;
    hoursworked = hw;
}
hourlyemployee::~hourlyemployee()
{
}
double hourlyemployee::calculatepay()
{
    return getsalary();
}
double hourlyemployee::getsalary()
{
    return rate * hoursworked;
}
string hourlyemployee ::displaydetails()
{
    return employee::displaydetails() + "\t Rate : " + to_string(rate) + "\t Hours Worked : " + to_string(hoursworked);
}
void hourlyemployee::addhours(int morehours)
{
    hoursworked += morehours;
}
void hourlyemployee::getinfo()
{
    employee::getinfo();
    cout << " Enter Rate : ";
    cin >> rate;
    cout << "Enter Worked Hours : ";
    cin >> hoursworked;
}
#endif