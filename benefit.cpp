#include <iostream>
#include <string.h>
using namespace std;
#ifndef BENEFIT_H
#define BENEFIT_H

class benefit
{
protected:
    string plantype;
    double amount;

public:
    virtual double calculatebenefit() = 0;
    virtual string displaybenefit(){
        return "\tPlan Type : " + plantype + "\tAmount : " + to_string(amount);
    }
    virtual void readinput(){
        cout << "Enter BenefitPlan : ";
        cin >> plantype;
        cout << "Enter Amount : ";
        cin >> amount;
    }
};

// double benefit::calculatebenefit()
// {
// }
/*string benefit::displaybenefit()
{
    return "\tPlan Type : " + plantype + "\tAmount : " + to_string(amount);
}

void benefit::readinput()
{
    cout << "Enter BenefitPlan : ";
    cin >> plantype;
    cout << "Enter Amount : ";
    cin >> amount;
}*/
#endif
