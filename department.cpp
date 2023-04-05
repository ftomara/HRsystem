#include <iostream>
using namespace std;
#ifndef DEPARTMENT_H
#define DEPARTMENT_H

class department
{
private:
    int depatid;
    string departmentname;

public:
    department(int, string);
    void getinfo();
    string print();
};

department::department(int id, string name)
{
    depatid = id;
    departmentname = name;
}
void department::getinfo()
{
    cout << "Enter ID : ";
    cin >> depatid;
    cout << "Enter Department Name : ";
    getline(cin, departmentname);
}
string department::print()
{
    return "ID : " + to_string(depatid) + "\t Department Name : " + departmentname + "\n";
}
#endif