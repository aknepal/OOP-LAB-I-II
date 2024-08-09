#include <iostream>
using namespace std;

class NepaleseCurrency;

class USCurrency {
private:
    double dollars;
public:
    USCurrency(double d) : dollars(d) {}

    double toNepalese() const {
        return dollars * 101.36;
    }

    friend bool operator==(const USCurrency &us, const NepaleseCurrency &np);
    friend bool operator!=(const USCurrency &us, const NepaleseCurrency &np);
    friend bool operator<(const USCurrency &us, const NepaleseCurrency &np);
    friend bool operator<=(const USCurrency &us, const NepaleseCurrency &np);
    friend bool operator>(const USCurrency &us, const NepaleseCurrency &np);
    friend bool operator>=(const USCurrency &us, const NepaleseCurrency &np);
};

class NepaleseCurrency {
private:
    double rupees;
public:
    NepaleseCurrency(double r) : rupees(r) {}

    double toUS() const {
        return rupees / 101.36;
    }

    friend bool operator==(const USCurrency &us, const NepaleseCurrency &np);
    friend bool operator!=(const USCurrency &us, const NepaleseCurrency &np);
    friend bool operator<(const USCurrency &us, const NepaleseCurrency &np);
    friend bool operator<=(const USCurrency &us, const NepaleseCurrency &np);
    friend bool operator>(const USCurrency &us, const NepaleseCurrency &np);
    friend bool operator>=(const USCurrency &us, const NepaleseCurrency &np);
};

bool operator==(const USCurrency &us, const NepaleseCurrency &np) {
    return us.toNepalese() == np.rupees;
}

bool operator!=(const USCurrency &us, const NepaleseCurrency &np) {
    return !(us == np);
}

bool operator<(const USCurrency &us, const NepaleseCurrency &np) {
    return us.toNepalese() < np.rupees;
}

bool operator<=(const USCurrency &us, const NepaleseCurrency &np) {
    return us.toNepalese() <= np.rupees;
}

bool operator>(const USCurrency &us, const NepaleseCurrency &np) {
    return us.toNepalese() > np.rupees;
}

bool operator>=(const USCurrency &us, const NepaleseCurrency &np) {
    return us.toNepalese() >= np.rupees;
}

int main() {
    USCurrency usd(1);
    NepaleseCurrency npr(101.36);

    cout << "US Dollar: $1" << endl;
    cout << "Nepalese Rupees: NRs 101.36" << endl;

    cout << boolalpha;
    cout << "Are they equal? " << (usd == npr) << endl;
    cout << "Are they not equal? " << (usd != npr) << endl;
    cout << "Is USD less than NPR? " << (usd < npr) << endl;
    cout << "Is USD less than or equal to NPR? " << (usd <= npr) << endl;
    cout << "Is USD greater than NPR? " << (usd > npr) << endl;
    cout << "Is USD greater than or equal to NPR? " << (usd >= npr) << endl;

    return 0;
}
