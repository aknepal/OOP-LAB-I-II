#include <iostream>
#include <iomanip>
using namespace std;

class Time24;

class Time12 {
    int hour, minute, second;
    bool isPM;
public:
    Time12(int h = 0, int m = 0, int s = 0, bool pm = false) 
        : hour(h), minute(m), second(s), isPM(pm) {}
    
    int getHour() const {
        return hour;
    }
    
    int getMinute() const {
        return minute;
    }
    
    int getSecond() const {
        return second;
    }
    
    bool getIsPM() const {
        return isPM;
    }
    
    operator Time24();
};

class Time24 {
    int hour, minute, second;
public:
    Time24(int h = 0, int m = 0, int s = 0) : hour(h), minute(m), second(s) {}
    
    void display() const {
        cout << "24-Hour Format: " 
             << setw(2) << setfill('0') << hour << ":" 
             << setw(2) << setfill('0') << minute << ":" 
             << setw(2) << setfill('0') << second << endl;
    }
};

Time12::operator Time24() {
    int hour24 = hour % 12;
    if (isPM) hour24 += 12;
    if (hour == 12 && !isPM) hour24 = 0;
    return Time24(hour24, minute, second);
}

int main() {
    Time12 time12(4, 30, 45,true);
    Time24 time24 = time12; 
    time24.display();
    return 0;
}
