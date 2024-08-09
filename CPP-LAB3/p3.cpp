#include <iostream>
#include <cmath>
using namespace std;

class Polar;

class Cartesian {
    float x, y;
public:
    Cartesian(float x = 0.0, float y = 0.0) : x(x), y(y) {}
    
    float getX() const {
        return x;
    }
    
    float getY() const {
        return y;
    }
    
    operator Polar();
};

class Polar {
    float radius, angle;
public:
    Polar(float r = 0.0, float a = 0.0) : radius(r), angle(a) {}
    
    void display() const {
        cout << "Polar Coordinate: (" << radius << ", " << angle << " radians)" << endl;
    }
};

Cartesian::operator Polar() {
    return Polar(sqrt(x*x + y*y), atan2(y, x));
}

int main() {
    Cartesian cartesianCoord(3.0, 4.0);  
    Polar polarCoord = cartesianCoord;  
    polarCoord.display();
    return 0;
}
