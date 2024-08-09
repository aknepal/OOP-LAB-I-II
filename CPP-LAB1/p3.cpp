#include <iostream>
using namespace std;

int main() {
    int orderQuantity, storeQuantity;
    cout << "Enter the order quantity: \n";
    cin >> orderQuantity;
    cout << "Enter the store quantity:\n ";
    cin >> storeQuantity;

    if (orderQuantity > storeQuantity) {
        cout << "No enough quantity\n";
    } else {
        if (storeQuantity <= 40 && orderQuantity > 16) {
            cout << "You cannot order more than 16 items\n";
        } else {
            cout << "Your order is accepted\n";
        }
    }

    return 0;
}
