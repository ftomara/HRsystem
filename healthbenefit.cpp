#include <iostream>
#include "benefit.cpp"
using namespace std;
#ifndef HEALTHBENEFIT_H
#define HEALTHBENEFIT_H

class healthbenefit : public benefit
{
private:
    string info;
    string coverage;

public:
    double calculatebenefit();
    string getdetails();
    string displaybenefit();
    void readinput();
};

double healthbenefit ::calculatebenefit()
{
    return 0.2 * amount;
}

string healthbenefit::getdetails()
{
    return "\tHelathBenefit Info : " + info + "\t Coverage : " + coverage + "\tBenefit Amount : " + to_string(calculatebenefit());
}
string healthbenefit::displaybenefit()
{
    return benefit::displaybenefit() + getdetails();
}
void healthbenefit::readinput()
{
    benefit::readinput();
    cout << "Enetr Health Benefit Info : ";
    getline(cin, info);
    cout << "Enter Coverage : ";
    getline(cin, coverage);
}
#endif