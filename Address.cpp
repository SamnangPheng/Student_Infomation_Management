#pragma once

#include <iostream>
using namespace std;

class Address{
private:
    string postalCode;
    string city;
    string country;

public:
    Address(): postalCode("Unknown"), city("Unknown"), country("Unknown"){}
    Address(string postalCode, string city, string country): postalCode(postalCode), city(city), country(country){}

    string getPostalCode() const{
        return postalCode;
    }
    string getCity() const{
        return city;
    }
    string getCountry() const{
        return country;
    }
    void setPostalCode(string getPostalCode){
        this->postalCode=postalCode;
    }
     void setCity(string city){
        this->city=city;
    }
     void setCountry(string country){
        this->country=country;
    }

    void getAddress(){
        cout<<"Input Postal code: ";
        cin>>postalCode;
        cout<<"Input City: ";
        cin>>city;
        cout<<"Input Country: ";
        cin>>country;        
    }
    void display(){
        cout<<"Postal code: "<<postalCode<<" City: "<<city<<" Country: "<<country<<endl;
    }

    friend istream& operator >>(istream& in, Address& address){
        cout<<"Input Postal code: ";
        in>>address.postalCode;
        cout<<"Input City: ";
        in>>address.city;        
        cout<<"Input Country: ";
        in>>address.country;
        return in;
    }

    friend ostream& operator <<(ostream& os, Address& address){
        cout<<" Postal code: ";
        os<<address.postalCode;
        cout<<" City: ";
        os<<address.city;        
        cout<<" Country: ";
        os<<address.country;
        return os;
    }    

};