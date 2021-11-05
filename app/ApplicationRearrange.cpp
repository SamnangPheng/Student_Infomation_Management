#pragma once

#include <iostream>
#include <vector>
#include "../user_module/ApplyUserService.cpp"
#include "../student_module/ApplyStudentService.cpp"
#include "../student_module/ScholarshipStudent.cpp"
#include "../exceptions/FileNotFoundException.cpp"
#include "../exceptions/BadInputException.cpp"
#include "../authentication/Authentication.cpp"
using namespace std;

enum{
    EXIT = 0,
    LOGIN = 1
};
enum{
    WELCOME_PAGE = 0,
    MANAGE_USER,
    MANAGE_STUDENT
};

class ApplicationRearrange{
private:
    int choiceWelcome;
    int choiceMain;
    string username;
    string password;
    string role;
    ApplyUserService applyUserService;
    ApplyStudentService applyStudentService;
    Authentication authentication;

    void welcomePage(){
        cout<<"\n1. Login To The System"<<endl;
        cout<<"0. Exit"<<endl;   
        cout<<"Enter Choice: ";
        cin>>choiceWelcome;   
        cout<<endl;
    }
    void mainMenu(){
        cout<<"1. Manage User"<<endl;
        cout<<"2. Manage Student"<<endl;
        cout<<"0. Back to Welcome Page"<<endl;
        cout<<"Enter Choice: ";
        cin>>choiceMain;
        cout<<endl;
    }

public:
    void run(){
        do{
            welcomePage();
            switch(choiceWelcome){
                case LOGIN:
                    cout<<"Enter Username: ";
                    cin>>username;
                    cout<<"Enter Password: ";
                    cin>>password;    
                    cout<<"Enter Role: ";                 
                    cin>>role;      
                    cout<<endl;                                          
                    do{                    
                        if(authentication.authenticateUser(username, password, role)){
                            cout<<"\nWELCOME"<<endl;
                            if(role == "admin"){
                            mainMenu();
                            switch(choiceMain){
                                case MANAGE_USER:
                                    applyUserService.manageUserChoice();
                                    break;
                                case MANAGE_STUDENT:
                                    applyStudentService.manageStudentChoice();
                                    break;
                                case WELCOME_PAGE:
                                    break;
                                default: 
                                    cout<<">>> Invalid Input <<<"<<endl<<endl;
                                    break;                                    
                                }
                            }else if(role == "user"){
                               applyStudentService.manageStudentChoice();
                            }else{
                                cout<<"\nInvalid Role"<<endl;
                                break;
                            }

                        }


                    }while(choiceMain!=WELCOME_PAGE);
                    break;
                case EXIT:
                    break;
                default: 
                    cout<<">>> Invalid Input <<<"<<endl;
                    break;
            }
        }while(choiceWelcome!=EXIT);

    }
    
};
        