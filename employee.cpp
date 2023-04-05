#include <iostream>

#include "healthbenefit.cpp"
#include "dentalbenefit.cpp"
#include "department.cpp"
using namespace std;

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

class employee
{
protected:
    int employeeid;
    string name;
    string phone;
    string email;
    string jobtitle;
    department *dep;

private:
    // benefit benefitlist;

public:
    employee();

    virtual ~employee();
    virtual void getinfo();
    virtual string displaydetails();
    virtual double getsalary() = 0;
    virtual double calculatepay() = 0;
    void setid(int);
    int getid();
};

employee::employee()
{
    dep = nullptr;
}
employee::~employee()
{
}

string employee::displaydetails()
{
    return "\n\tName : " + name + "\t Phone : " + phone + "\t Email : " + email + "\t Job title : " + jobtitle + ((dep != nullptr) ? "\t" + dep->print() : " ");
}
void employee::getinfo()
{
    cin.ignore();
    cout << "Enter employee information Here please : ";
    cout << "\n-----------------------------------------\n";
    cout << "Enter Name :  ";
    getline(cin, name);
    cin.ignore();
    cout << "Phone number : ";
    cin >> phone;
    cout << "Email : ";
    cin >> email;
    cin.ignore();
    cout << "Job title : ";
    getline(cin, jobtitle);
}
void employee::setid(int id)
{
    employeeid = id;
}
int employee::getid()
{
    return employeeid;
}
#endif