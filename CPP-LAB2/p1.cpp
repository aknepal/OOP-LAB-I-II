#include <iostream>
using namespace std;

class ClassB;

class ClassA {
private:
    int value;
public:
    ClassA(int v) : value(v) {}

    void display() const {
        cout << "ClassA value: " << value << endl;
    }

    friend void swapValues(ClassA &a, ClassB &b);
};

class ClassB {
private:
    int value;
public:
    ClassB(int v) : value(v) {}

    void display() const {
        cout << "ClassB value: " << value << endl;
    }
    friend void swapValues(ClassA &a, ClassB &b);
};

void swapValues(ClassA &a, ClassB &b) {
    int temp = a.value;
    a.value = b.value;
    b.value = temp;
}

int main() {
    ClassA objA(10);
    ClassB objB(20);

    cout << "Before swapping:" << endl;
    objA.display();
    objB.display();

    swapValues(objA, objB);

    cout << "After swapping:" << endl;
    objA.display();
    objB.display();

    return 0;
}
