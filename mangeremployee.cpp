#include <iostream>
#include "salariedemployee.cpp"
using namespace std;
#ifndef MANGEREMPLOYEE_H
#define MANGEREMPLOYEE_H

class mangeremployee : public salariedemployee
{
protected:
    double bouns;

public:
    mangeremployee();
    mangeremployee(double, double);
    ~mangeremployee();
    void addbouns(double);
    double getsalary();
    string displaydetails();
    double calculatepay();
    void getinfo();
};

mangeremployee ::mangeremployee()
{
    bouns = 0;
    salary = 0;
}
mangeremployee ::mangeremployee(double b, double s) : salariedemployee(s)
{
    salary = s;
    bouns = b;
}
mangeremployee ::~mangeremployee()
{
}

double mangeremployee ::getsalary()
{
    return salary + bouns;
}
string mangeremployee ::displaydetails()
{
    return salariedemployee::displaydetails() + "\tBouns : " + to_string(bouns);
}
void mangeremployee ::addbouns(double morebouns)
{
    bouns += morebouns;
}
double mangeremployee ::calculatepay()
{
    return getsalary();
}
void mangeremployee ::getinfo()
{
    salariedemployee::getinfo();
    cout << "Enter Bouns : ";
    cin >> bouns;
}
#endif