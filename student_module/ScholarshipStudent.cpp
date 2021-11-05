#pragma once

#include <iostream>
#include "Student.cpp"
#include "Address.cpp"
#include "Birthdate.cpp"
using namespace std;

class ScholarshipStudent: public Student{
private:
    int period;
public:
    void inputScholarshipStudent(){
              do{
                    cout<<"Scholarship Period: ";
                    cin>>period;
                    cout<<"Input Username: ";
                    cin>>username;
                }while(!isValidUsername(username));
                do{
                    cout<<"Input Sex: ";
                    cin>>sex;      
                }while(!isValidSex(sex));
                do{
                    cout<<"Input Phone Number: ";
                    cin>>phoneNumber;        
                }while(!isValidPhoneNumber(phoneNumber));
                cin>>birthdate;
                cin>>address;
            }        
    void outputScholarshipStudent(){
        cout<<"Scholarship Period: "<<period<<"Username: "<<username<<" Sex: "<<sex<<" Phone Number: "<<phoneNumber<<birthdate<<address<<endl;
    }

};