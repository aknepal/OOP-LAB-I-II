#include <iostream>
#include <cmath>
using namespace std;

class Cartesian;

class Polar {
    float radius, angle;
public:
    Polar(float r = 0.0, float a = 0.0) : radius(r), angle(a) {}
    
    float getRadius() const {
        return radius;
    }
    
    float getAngle() const {
        return angle;
    }
    
    operator Cartesian();
};

class Cartesian {
    float x, y;
public:
    Cartesian(float x = 0.0, float y = 0.0) : x(x), y(y) {}
    
    void display() const {
        cout << "Cartesian Coordinate: (" << x << ", " << y << ")" << endl;
    }
};

Polar::operator Cartesian() {
    return Cartesian(radius * cos(angle), radius * sin(angle));
}

int main() {
    float radius = 5.0;
    float angle_degrees = 45.0;
    float angle_radians = angle_degrees * M_PI / 180.0;
    
    Polar polarCoord(radius, angle_radians);
    Cartesian cartesianCoord = polarCoord;  
    cartesianCoord.display();
    return 0;
}