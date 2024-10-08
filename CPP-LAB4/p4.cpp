#include <iostream>

using namespace std;

class Date {
    int day, month, year;

    public:
        Date(int d, int m, int y) : day(d), month(m), year(y){}
        ~Date(){};
        void display(){
            cout << year << "/" << month << "/" << day << endl;
        }; 
        int getDay(){
            return day;
        };
        int getMonth(){
            return month;
        };
        int getYear(){
            return year;
        };
        void set(int d, int m, int y){
            day = d;
            month = m;
            year = y;
        }    
};

class Time {
    int hour;
    int minute;
    int second;

    public:
        Time(int h, int m, int s) : hour(h), minute(m), second(s){}
        ~Time(){};
        void display(){
            cout << hour << ":" << minute << ":" << second << endl;
        } 
        int getHour(){
            return hour;
        };   
        int getMinute(){
            return minute;
        };    
        int getSecond(){
            return second;
        };     
        void set(int h, int m, int s){
            hour = h;
            minute = m;
            second = s;
        };    
};

class DateAndTime : public Date, public Time {
    public:
        DateAndTime(int d, int m, int y, int h, int min, int s) : Date(d, m, y) , Time(h, min, s){}

        void display(){
            Date :: display();
            Time :: display();
        };
};

int main(){
    DateAndTime Watch(07,8, 2024, 11, 19, 55);
    cout << "Before resetting:" << endl;
    Watch.display();
    Watch.Date::set(21, 5, 2024);
    Watch.Time::set(2,30,42);
    cout << "After resetting:" << endl;
    Watch.display();
}