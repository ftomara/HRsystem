#include <iostream>
#include "benefit.cpp"
using namespace std;
#ifndef DENTALBENEFIT_H
#define DENTALBENEFIT_H

class dentalbenefit : public benefit
{
protected:
    string info;

public:
    double calculatebenefit(){
        return 0.1 * amount;
    }
    string getdetails()
    {
        return "\tDental Benefit Info : " + info + "\tBenefit Amount : " + to_string(calculatebenefit());
    }
    string displaybenefit()
    {
        return benefit::displaybenefit() + getdetails();
    }
    void readinput(){
        benefit::readinput();
        cout << "Enetr Health Benefit Info : ";
        getline(cin, info);
    }
};
/*
double dentalbenefit ::calculatebenefit()
{
    return 0.1 * amount;
}
string dentalbenefit::getdetails()
{
    return "\tDental Benefit Info : " + info + "\tBenefit Amount : " + to_string(calculatebenefit());
}
string dentalbenefit::displaybenefit()
{
    return benefit::displaybenefit() + getdetails();
}
void dentalbenefit::readinput()
{
    benefit::readinput();
    cout << "Enetr Health Benefit Info : ";
    getline(cin, info);
}*/

#endif
