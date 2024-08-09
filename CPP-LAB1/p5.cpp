#include <iostream>
#include <string>
using namespace std;
class EMPLOYEE
{
    static int em, ee;
    int id;
    string name, desig;

public:
    void getinfo ()
    {
        cout << "enter employee id employee name   designation";
        cin >> id >> name >> desig;
        if (desig == "mr")
            ++em;
        if (desig == "e")
            ++ee;
    }
    void show()

    {
        cout << "emp id:" << id << " emp name:" << name << "  designation:" << desig<<" managers:"<<em<<" engineer:"<<ee;
    }
};
int EMPLOYEE::em = 0;
int EMPLOYEE::ee = 0;
int main()
{
    const  int n = 6;
    EMPLOYEE e[n];
    for (int i = 0; i < n; i++)
    {
        e[i].getinfo();
    }
    for (int i = 0; i < n; i++)
    {
        e[i].show();
    }
   return 0;
}