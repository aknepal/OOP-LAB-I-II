#include<iostream>

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


class Book : public Publication {
    int pageCount;

    public:
        void getData(){
            Publication :: getData();
            cout << "Enter the page count: ";
            cin >> pageCount;
        }

        void putData(){
            Publication :: putData();
            cout << "Page count: " << pageCount << endl;
        }
};

class Tape : public Publication {
    int playingTime;

    public:
        void getData(){
            Publication :: getData();
            cout << "Enter the playing time: ";
            cin >> playingTime;
        }

        void putData(){
            Publication :: putData();
            cout << "Playing time: " << playingTime << endl;
        }
};

int main(){
    Book b;
    Tape t;

    cout << "Enter book details:" << endl;
    b.getData();
    cout << "Enter tape details:" << endl;
    t.getData();

    cout << endl;
    b.putData();
    cout << endl;
    t.putData();

    return 0; 
}