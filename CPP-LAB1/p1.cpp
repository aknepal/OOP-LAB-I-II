#include <iostream>
using namespace std;

class DISTANCE {
private:
    int feet;
    int inches;

public:
    DISTANCE() : feet(0), inches(0) {}

    void inputDistance() {
        cout << "Enter feet: ";
        cin >> feet;
        cout << "Enter inches: ";
        cin >> inches;
        while (inches >= 12) {
            feet++;
            inches -= 12;
        }
    }
    void outputDistance() const {
        cout << "Distance: " << feet << " feet " << inches << " inches";
    }

    DISTANCE addDistance(const DISTANCE& d) const {
        DISTANCE result;
        result.inches = inches + d.inches;
        result.feet = feet + d.feet + result.inches / 12;
        result.inches %= 12;
        return result;
    }
};

int main() {
    DISTANCE d1, d2, d3;

    cout << "Enter first distance:";
    d1.inputDistance();
    cout << "Enter second distance:";
    d2.inputDistance();

    cout << "\nFirst distance:";
    d1.outputDistance();
    cout << "Second distance:";
    d2.outputDistance();

    d3 = d1.addDistance(d2);

    cout << "\nSum of distances:";
    d3.outputDistance();

    return 0;
}
