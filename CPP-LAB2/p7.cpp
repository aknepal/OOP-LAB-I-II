#include <iostream>
#include <iomanip>
using namespace std;

class TIME {
private:
    int hours;
    int minutes;
    int seconds;

    void normalize() {
        if (seconds >= 60) {
            minutes += seconds / 60;
            seconds %= 60;
        }
        if (minutes >= 60) {
            hours += minutes / 60;
            minutes %= 60;
        }
        if (seconds < 0) {
            minutes -= 1 + (-seconds / 60);
            seconds = 60 - (-seconds % 60);
        }
        if (minutes < 0) {
            hours -= 1 + (-minutes / 60);
            minutes = 60 - (-minutes % 60);
        }
    }

public:
    // Constructor to initialize the object to zero
    TIME() : hours(0), minutes(0), seconds(0) {}

    // Constructor to initialize the object to some constant value
    TIME(int h, int m, int s) : hours(h), minutes(m), seconds(s) {
        normalize();
    }

    // Overload + to add two TIME objects
    TIME operator+(const TIME &t) const {
        return TIME(hours + t.hours, minutes + t.minutes, seconds + t.seconds);
    }

    // Overload - to subtract two TIME objects
    TIME operator-(const TIME &t) const {
        return TIME(hours - t.hours, minutes - t.minutes, seconds - t.seconds);
    }

    // Overload > function to compare two TIME objects
    bool operator>(const TIME &t) const {
        if (hours != t.hours) {
            return hours > t.hours;
        } else if (minutes != t.minutes) {
            return minutes > t.minutes;
        } else {
            return seconds > t.seconds;
        }
    }

    // Overload << operator for output
    friend ostream& operator<<(ostream &out, const TIME &t) {
        out << setfill('0') << setw(2) << t.hours << ":"
            << setfill('0') << setw(2) << t.minutes << ":"
            << setfill('0') << setw(2) << t.seconds;
        return out;
    }

    // Overload >> operator for input
    friend istream& operator>>(istream &in, TIME &t) {
        cout << "Enter hours: ";
        in >> t.hours;
        cout << "Enter minutes: ";
        in >> t.minutes;
        cout << "Enter seconds: ";
        in >> t.seconds;
        t.normalize();
        return in;
    }

    // Member function to display time in HH:MM:SS format (alternative to << operator)
    void display() const {
        cout << setfill('0') << setw(2) << hours << ":"
             << setfill('0') << setw(2) << minutes << ":"
             << setfill('0') << setw(2) << seconds << endl;
    }
};

int main() {
    TIME t1(2, 45, 50);
    TIME t2;
    TIME t3;

    cout << "Enter time 2:" << endl;
    cin >> t2;

    t3 = t1 + t2;
    cout << "Time 1: " << t1 << endl;
    cout << "Time 2: " << t2 << endl;
    cout << "Time 1 + Time 2: " << t3 << endl;

    t3 = t1 - t2;
    cout << "Time 1 - Time 2: " << t3 << endl;

    cout << "Time 1 is greater than Time 2: " << boolalpha << (t1 > t2) << endl;

    return 0;
}
