#include <iostream>
using namespace std;

class USCurrency;

class NepaleseCurrency {
    float rupees;
public:
    NepaleseCurrency(float r = 0.0) : rupees(r) {}
    
    float getRupees() const {
        return rupees;
    }
    
    operator USCurrency();
};

class USCurrency {
    float dollars;
public:
    USCurrency(float d = 0.0) : dollars(d) {}
    
    float getDollars() const {
        return dollars;
    }
    
    void display() const {
        cout << "US Currency: $" << dollars << endl;
    }
};

NepaleseCurrency::operator USCurrency() {
    return USCurrency(rupees / 98.51);
}

int main() {
    NepaleseCurrency nepaliCurrency(197.02);  
    USCurrency usCurrency = nepaliCurrency;  
    usCurrency.display();
    return 0;  
}
