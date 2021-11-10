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
        cout<<"\n>>>>>>>>>>>>>>>>>>>>>>>> STUDENT INFORMATION MANAGEMENT <<<<<<<<<<<<<<<<<<<<<<<<<";
        cout<<"\n                                   SYSTEM";
        cout<<"\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> VERSION 1.0 <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<endl;
        cout<<"\n1. Login To The System"<<endl;
        cout<<"0. Exit"<<endl;   
        cout<<"Enter Choice: ";
        cin>>choiceWelcome;   
        cout<<endl;
    }
    void mainMenu(){
        system("cls");
        cout<<"================"<<endl;
        cout<<"1. Manage User"<<endl;
        cout<<"2. Manage Student"<<endl;
        cout<<"0. Back to Welcome Page"<<endl;
        cout<<"================"<<endl;
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
                    system("cls");
                    cout<<"Enter Username: ";
                    cin>>username;
                    cout<<"Enter Password: ";
                    cin>>password;    
                    cout<<endl;                                          
                    do{                    
                        if(authentication.authenticateUser(username, password, role="admin")){
                            system("cls");
                            cout<<"\n\tWELCOME"<<endl<<endl;
                            mainMenu();
                            switch(choiceMain){
                                case MANAGE_USER:
                                    system("cls");
                                    applyUserService.manageUserChoice();
                                    break;
                                case MANAGE_STUDENT:
                                    system("cls");
                                    applyStudentService.manageStudentChoice();
                                    break;
                                case WELCOME_PAGE:
                                    break;
                                default: 
                                    break;                                    
                                }
                        }else if(authentication.authenticateUser(username, password, role="user")){
                            system("cls");
                            applyStudentService.manageStudentChoice();
                        }else{
                            cout<<"\nInvalid Input"<<endl;
                            break;
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
        