#include <iostream>
#include <cstring>

using namespace std;

class Inventory {
    int quant;    
    int reorder;  
    double price; 
    char* descrip;

public:
    Inventory(int q, int r, double p, const char* d) : quant(q), reorder(r), price(p) {
        descrip = new char[strlen(d) + 1];
        strcpy(descrip, d);
    }
    ~Inventory() {
        delete[] descrip;
    }

    void print() {
        cout << "Quantity: " << quant << endl;
        cout << "Reorder: " << reorder << endl;
        cout << "Price: $" << price << endl;
        cout << "Description: " << descrip << endl;
    }
};
class Auto : public Inventory {
    char* manufacturer;

public:
    Auto(int q, int r, double p, const char* d, const char* man) : Inventory(q, r, p, d) {
        manufacturer = new char[strlen(man) + 1];
        strcpy(manufacturer, man);
    }

    ~Auto() {
        delete[] manufacturer;
    }

    
    void print() {
        Inventory::print();
        cout << "Manufacturer: " << manufacturer << endl;
    }
};

class Transmission : public Inventory {
    char* vendor;

public:
    Transmission(int q, int r, double p, const char* d, const char* ven) : Inventory(q, r, p, d) {
        vendor = new char[strlen(ven) + 1];
        strcpy(vendor, ven);
    }
    ~Transmission() {
        delete[] vendor;
    }

    void print() {
        Inventory::print();
        cout << "Vendor: " << vendor << endl;
    }
};

int main() {
    int quantity = 25;
    int reorder = 10;
    double price = 1789.98;
    char desc[] = "Transmission purchased from Aztec Inc.";
    char vendor[] = "Aztec Inc.";

    Transmission trans(quantity, reorder, price, desc, vendor);
    trans.print();

    return 0;
}
