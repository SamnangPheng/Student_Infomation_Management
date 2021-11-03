#pragma once

#include <iostream>
#include <vector>
#include "User.cpp"
#include "UserService.cpp"
#include "ApplyUserService.cpp"
#include "ApplyStudentService.cpp"
#include "ScholarshipStudent.cpp"
#include "FileNotFoundException.cpp"
#include "BadInputException.cpp"
#include "Authentication.cpp"
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
    User* userLogin;
    User user;
    UserService userService;
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
        User user1("dara", "123", "admin");
        User user2("lina", "345", "user");
        userService.addUser(&user2);
        userService.addUser(&user1);
        do{
            welcomePage();
            switch(choiceWelcome){
                case LOGIN:
                    do{
                        string username;
                        string password;
                        //string name, passw;

                        cout<<"Display"<<endl<<endl;
                        userService.displayUser();
                        cout<<endl;
                        cout<<"Enter Usrrname: ";
                        cin>>username;
                        cout<<"Enter Password: ";
                        cin>>password;
                        cout<<endl;

                        //userLogin = authentication.authenticationUser(username, password);
                        //if(userLogin->getRole()=="admin")
                        //  User* user = authentication.authenticateUser(username, password);
                        //  user->outputUser();
                        cout<<username<<password;
                        
                        if(authentication.authenticateUser(username, password)!=nullptr){
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
                        }else{
                            cout<<"H"<<endl;
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
        