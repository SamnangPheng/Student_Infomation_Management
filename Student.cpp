#pragma once

#include <iostream>
#include <regex>
#include "Address.cpp"
#include "Birthdate.cpp"
using namespace std;

class Student{
protected:
    string username;
    string sex;
    string phoneNumber;
    Address address;
    Birthdate birthdate;

public:
    Student(): username("Unknown"), sex("Unknown"), phoneNumber("Unknown"){}
    Student(string username, string sex, string phoneNumber, Address address, Birthdate birthdate): username(username), sex(sex), phoneNumber(phoneNumber), address(address), birthdate(birthdate){} 
    
    string getUsername() const{
        return username;
    }
    string getSex() const{
        return sex;
    }
    string getPhoneNumber() const{
        return phoneNumber;
    }
    void setUsername(string username){
        this->username=username;
    }
     void setSex(string sex){
        this->sex=sex;
    }
     void setPhoneNumber(string phoneNumber){
        this->phoneNumber=phoneNumber;
    }

    bool isValidUsername(string username){
        return all_of(username.begin(), username.end(), [](char ch){
            return (isalpha(ch) || isspace(ch));
        });
    }    
    bool isValidSex(string sex){
        const regex pattern("[A-Z]");
        return regex_match(sex, pattern);
    }
    bool isValidPhoneNumber(string phoneNumber){
        const regex pattern("\\d{3}\\-\\d{3}-\\d{3}");
        return regex_match(phoneNumber, pattern);
    }

    virtual void inputStudent(){
              do{
                    cout<<"Input Username: ";
                    cin>>username;
                }while(!isValidUsername(username));
                do{
                    cout<<"Input Sex <M or F>: ";
                    cin>>sex;      
                }while(!isValidSex(sex));
                do{
                    cout<<"Input Phone Number <xxx-xxx-xxx>: ";
                    cin>>phoneNumber;        
                }while(!isValidPhoneNumber(phoneNumber));
                cin>>birthdate;
                cin>>address;
            }
    void inputStudentUsername(){
        do{
            cout<<"Input Username: ";
            cin>>username;        
        }while(!isValidUsername(username));
    }    
    void inputStudentSex(){
        do{
            cout<<"Input Sex <M or F>: ";
            cin>>sex;
        }while(!isValidSex(sex));
    }
    void inputStudentPhoneNumber(){
        do{
            cout<<"Input Phone Number <xxx-xxx-xxx>: ";
            cin>>phoneNumber;            
        }while(!isValidPhoneNumber(phoneNumber));
    }
    void inputStudentBirthdate(){
        cin>>birthdate;
    }
    void inputStudentAddress(){
        cin>>address;
    }

    virtual void outputStudent(){
                cout<<"Username: "<<username<<" Sex: "<<sex<<" Phone Number: "<<phoneNumber<<birthdate<<address<<endl;
            }

};