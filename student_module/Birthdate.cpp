#pragma once

#include <iostream>
using namespace std;

class Birthdate{
private:
    int day;
    int month;
    int year;

public:
    Birthdate(): day(0), month(0), year(0){}
    Birthdate(int day, int month, int year): day(day), month(month), year(year){}

    int getDay() const{
        return day;
    }
    int getMonth() const{
        return month;
    }
    int getYear() const{
        return year;
    }
    void setDay(int day){
        this->day=day;
    }
     void setMonth(int month){
        this->month=month;
    }
     void setYear(int year){
        this->year=year;
    }

    void getBirthdate(){
        cout<<"Input day: ";
        cin>>day;
        cout<<"Input Month: ";
        cin>>month;
        cout<<"Input Year: ";
        cin>>year;        
    }
    void display(){
        cout<<" Day: "<<day<<" Month: "<<month<<" Year: "<<year<<endl;
    }

    friend istream& operator >>(istream& in, Birthdate& birthdate){
        cout<<"Input Birth day: ";
        in>>birthdate.day;
        cout<<"Input Birth Month: ";
        in>>birthdate.month;        
        cout<<"Input Birth Year: ";
        in>>birthdate.year;
        return in;
    }

    friend ostream& operator <<(ostream& os, Birthdate& birthdate){
        cout<<"\nBirth Day: ";
        os<<birthdate.day;
        cout<<"\nBirth Month: ";
        os<<birthdate.month;        
        cout<<"\nBirth Year: ";
        os<<birthdate.year;
        return os;
    }
};