#include <iostream>
#include <cstring>
using namespace std;

const int MAX_LENGTH = 100;

class STRING {
private:
    char str[MAX_LENGTH];
    int length;

public:
    // Default constructor
    STRING() : length(0) {
        str[0] = '\0';
    }

    // Constructor to initialize with a C-string
    STRING(const char* s) {
        length = strlen(s);
        if (length >= MAX_LENGTH) {
            length = MAX_LENGTH - 1;
        }
        strncpy(str, s, length);
        str[length] = '\0';
    }

    // Copy constructor
    STRING(const STRING& other) {
        length = other.length;
        strncpy(str, other.str, length);
        str[length] = '\0';
    }

    // Overload = operator for assignment
    STRING& operator=(const STRING& other) {
        if (this != &other) {
            length = other.length;
            strncpy(str, other.str, length);
            str[length] = '\0';
        }
        return *this;
    }

    // Overload + operator for concatenation
    STRING operator+(const STRING& other) const {
        STRING temp;
        temp.length = length + other.length;
        if (temp.length >= MAX_LENGTH) {
            temp.length = MAX_LENGTH - 1;
        }
        strncpy(temp.str, str, length);
        strncat(temp.str, other.str, MAX_LENGTH - length - 1);
        temp.str[temp.length] = '\0';
        return temp;
    }

    // Overload == operator for equality check
    bool operator==(const STRING& other) const {
        return strcmp(str, other.str) == 0;
    }

    // Function to display the string
    void display() const {
        cout << str << endl;
    }
};

int main() {
    STRING s1("Hello, ");
    STRING s2("World!");
    STRING s3;

    cout << "s1: ";
    s1.display();
    
    cout << "s2: ";
    s2.display();

    s3 = s1 + s2;
    cout << "s1 + s2: ";
    s3.display();

    STRING s4 = s3;
    cout << "s4 (copy of s3): ";
    s4.display();

    cout << "s3 == s4: " << boolalpha << (s3 == s4) << endl;

    STRING s5("Hello, World!");
    cout << "s3 == s5: " << boolalpha << (s3 == s5) << endl;

    return 0;
}
