#include <iostream>
#include <iomanip>
using namespace std;

class Time12;

class Time24 {
    int hour, minute, second;
public:
    Time24(int h = 0, int m = 0, int s = 0) : hour(h), minute(m), second(s) {}
    
    int getHour() const {
        return hour;
    }
    
    int getMinute() const {
        return minute;
    }
    
    int getSecond() const {
        return second;
    }
    
    operator Time12();
};

class Time12 {
    int hour, minute, second;
    bool isPM;
public:
    Time12(int h = 0, int m = 0, int s = 0, bool pm = false) 
        : hour(h), minute(m), second(s), isPM(pm) {}
    
    void display() const {
        cout << "12-Hour Format: " 
             << setw(2) << setfill('0') << hour << ":" 
             << setw(2) << setfill('0') << minute << ":" 
             << setw(2) << setfill('0') << second << " " 
             << (isPM ? "PM" : "AM") << endl;
    }
};

Time24::operator Time12() {
    bool pm = hour >= 12;
    int hour12 = hour % 12;
    if (hour12 == 0) hour12 = 12;
    return Time12(hour12, minute, second, pm);
}

int main() {
    Time24 time24(14, 30, 45); 
    Time12 time12 = time24;
    time12.display();
    return 0;
}
