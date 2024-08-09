#include <iostream>
using namespace std;
class MyClass;
int addPrivateMembers(const MyClass &obj);
class MyClass {
private:
    int num1;
    int num2;

public:
    MyClass(int a, int b) : num1(a), num2(b) {}
    friend int addPrivateMembers(const MyClass &obj);
};
int addPrivateMembers(const MyClass &obj) {
    return obj.num1 + obj.num2;
}
int main() {
    MyClass obj(20, 10);
    int sum = addPrivateMembers(obj);

    cout << "Sum of private members: " << sum;

    return 0;
}
