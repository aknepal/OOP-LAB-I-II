#include <iostream>
#include <cstring>
using namespace std;

class STRING {
private:
    char* str;
    int length;

public:
    // Default constructor
    STRING() : str(nullptr), length(0) {}

    // Constructor to initialize with a C-string
    STRING(const char* s) {
        length = strlen(s);
        str = new char[length + 1];
        strcpy(str, s);
    }

    // Copy constructor
    STRING(const STRING& other) {
        length = other.length;
        str = new char[length + 1];
        strcpy(str, other.str);
    }

    // Destructor
    ~STRING() {
        delete[] str;
    }

    // Overload = operator for assignment
    STRING& operator=(const STRING& other) {
        if (this != &other) {
            delete[] str;
            length = other.length;
            str = new char[length + 1];
            strcpy(str, other.str);
        }
        return *this;
    }

    // Overload + operator for concatenation
    STRING operator+(const STRING& other) const {
        STRING temp;
        temp.length = length + other.length;
        temp.str = new char[temp.length + 1];
        strcpy(temp.str, str);
        strcat(temp.str, other.str);
        return temp;
    }

    // Overload == operator for equality check
    bool operator==(const STRING& other) const {
        return strcmp(str, other.str) == 0;
    }

    // Function to display the string
    void display() const {
        if (str) {
            cout << str << endl;
        } else {
            cout << "Empty string" << endl;
        }
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
