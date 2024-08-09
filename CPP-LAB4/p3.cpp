#include<iostream>
#include<iomanip>

using namespace std;

class Publication{
    string title;
    float price;

    public:
        void getData(){
            cout << "Enter title: ";
            cin >> title;
            cout << "Enter price: ";
            cin >> price;
        }

        void putData(){
            cout << "Title: " << title << endl;
            cout << "Price: " << price << endl;
        }
};

class Sales {
    float a[3];

    public:
        void getData(){
            cout << "Enter the sales for each of last three months: ";
            for(int i=0; i<3; i++){
                cin >> a[i];
            }
        }

        void putData(){
            cout << "Sales of last three months: ";
            for(int i=0; i<3; i++){
                cout << a[i] << setw(5);
            }
            cout << endl;
        }
};


class Book : public Publication, Sales {
    int pageCount;

    public:
        void getData(){
            Publication :: getData();
            Sales :: getData();
            cout << "Enter the page count: ";
            cin >> pageCount;
        }

        void putData(){
            Publication :: putData();
            Sales :: putData();
            cout << "Page count: " << pageCount << endl;
        }
};

class Tape : public Publication, Sales {
    int playingTime;

    public:
        void getData(){
            Publication :: getData();
            Sales :: getData();
            cout << "Enter the playing time in hours: ";
            cin >> playingTime;
        }

        void putData(){
            Publication :: putData();
            Sales :: putData();
            cout << "Playing time: " << playingTime << endl;
        }
};

int main(){
    Book b;
    Tape t;

    cout << "Enter book details" << endl;
    b.getData();
    cout << "Enter tape details" << endl;
    t.getData();

    b.putData();
    t.putData();

    return 0; 
}