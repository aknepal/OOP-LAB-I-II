#include <iostream>
#include <iomanip>
#include <ctime>
#include <cmath>
using namespace std;

class ParkingGarage {
private:
    static int carCount;

public:
    ParkingGarage() {}

    // Overload ++ operator to increment car count
    void operator++() {
        ++carCount;
    }

    // Overload -- operator to decrement car count
    void operator--() {
        --carCount;
    }

    // Function to calculate parking charges
    double calculateCharges(const tm& entryTime, const tm& exitTime) const {
        time_t entry = mktime(const_cast<tm*>(&entryTime));
        time_t exit = mktime(const_cast<tm*>(&exitTime));
        double totalHours = difftime(exit, entry) / 3600.0;
        double charge = 2.0; // Minimum fee for up to 3 hours

        if (totalHours <= 3) {
            return charge;
        } else if (totalHours <= 24) {
            charge += 0.50 * ceil(totalHours - 3);
            return charge > 8.0 ? 8.0 : charge;
        } else {
            int days = totalHours / 24;
            double remainingHours = fmod(totalHours, 24);
            charge = days * 8.0;
            if (remainingHours > 0) {
                charge += remainingHours <= 3 ? 2.0 : 2.0 + 0.50 * ceil(remainingHours - 3);
                charge = charge > (days + 1) * 8.0 ? (days + 1) * 8.0 : charge;
            }
            return charge;
        }
    }

    // Function to display car count
    static int getCarCount() {
        return carCount;
    }
};

// Initialize static car count
int ParkingGarage::carCount = 0;

void inputDateTime(tm &time) {
    cout << "Enter year: ";
    cin >> time.tm_year;
    time.tm_year -= 1900;

    cout << "Enter month: ";
    cin >> time.tm_mon;
    time.tm_mon -= 1;

    cout << "Enter day: ";
    cin >> time.tm_mday;

    cout << "Enter hour: ";
    cin >> time.tm_hour;

    cout << "Enter minute: ";
    cin >> time.tm_min;

    time.tm_sec = 0; // seconds
    time.tm_isdst = -1; // DST flag
}

int main() {
    ParkingGarage garage;

    cout << "Enter the entry date and time:" << endl;
    tm entryTime = {};
    inputDateTime(entryTime);

    ++garage; // Car enters the garage
    cout << "Current number of cars in the garage: " << ParkingGarage::getCarCount() << endl;

    cout << "Enter the exit date and time:" << endl;
    tm exitTime = {};
    inputDateTime(exitTime);

    double charges = garage.calculateCharges(entryTime, exitTime);
    cout << fixed << setprecision(2);
    cout << "Parking charges: $" << charges << endl;

    --garage; // Car leaves the garage
    cout << "Current number of cars in the garage: " << ParkingGarage::getCarCount() << endl;

    return 0;
}