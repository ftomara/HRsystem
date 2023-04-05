#include <iostream>
#include <string>
#include <ctime>
#include <unistd.h>
#include "hrsystem.cpp"

using namespace std;

void print(string s)
{
    cout << s;
}
int main()
{

    char charr;
    hrsystem e(100);
    while (charr != 27)
    {
        sleep(2);
        system("clear");
        print("\n\n\t\t\t\t----------------------------------------- \n");
        print("\n\n\t\t\t\t\" Welcome to Employee Mangement App \"\n");
        print("\n\n\t\t\t\t----------------------------------------- \n");
        print("\t\t1.Add new Employee \n");
        print("\t\t2.Edit Employee \n");
        print("\t\t3.Delete Employee\n");
        print("\t\t4.Calculate Salary \n");
        print("\t\t5.Information Reports \n");
        print("\t\t6.Search for Employee \n");
        print("\t\tesc.Exit program\n");
        print("Enter selection --->  ");
        cin >> charr;

        switch (charr)
        {
        case 49:
            e.addemployee();
            break;
        case 50:
            e.editemployee();
            break;
        case 51:
            e.delemployee();
            break;
        case 52:
            e.calctotalpayroll();
            break;
        case 53:
            e.showall();
            break;

        case 54:
            e.findemployee();
            break;

        case 27:

            print("\t\t\t\t Session is over....\n");
            sleep(2);
            system("clear");
            break;
        default:
            print("\n\nINVALID\n");
            sleep(2);
            system("clear");
        }
    }

    return 0;
}