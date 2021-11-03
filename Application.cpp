/*
#pragma once

#include <iostream>
#include <vector>
#include "User.cpp"
#include "UserService.cpp"
#include "Student.cpp"
#include "ScholarshipStudent.cpp"
#include "StudentService.cpp"
#include "FileNotFoundException.cpp"
#include "UserNotFoundException.cpp"
#include "UserDuplicatedException.cpp"
#include "StudentNotFoundException.cpp"
#include "StudentDuplicatedException.cpp"
#include "BadInputException.cpp"
#include "Authorization.cpp"
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
enum{
    MAIN_MENU = 0,
    DISPLAY_USER = 1,
    ADD_USER,
    UPDATE_USER,
    DELETE_USER,
    LOAD_USER,
    SAVE_USER
};
enum{
//    WELCOME_PAGE = 0,
    DISPLAY_STUDENT = 1,
    ADD_STUDENT,
    UPDATE_STUDENT,
    DELETE_STUDENT,
    LOAD_STUDENT,
    SAVE_STUDENT    
};
enum{
    //MANAGE_USER_MENU = 0,
    MODIFY_EVERYTHING = 1,
    MODIFY_USERNAME,
    MODIFY_PASSWORD,
    MODIFY_ROLE
};

class Application{
private:
    int choiceWelcome;
    int choiceMain;
    int choiceAdmin;
    int choiceRegistrar;
    int choiceModifyUser;
    string username;

    User user[100];
    Student student[100];
    //Student* student = nullptr;
    //int i=1;
    UserService userService;
    StudentService studentService;

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
    void manageUserMenu(){
        cout<<"1. Display User Information"<<endl;
        cout<<"2. Add New User"<<endl;
        cout<<"3. Update Existing User"<<endl;
        cout<<"4. Delete User"<<endl;
        cout<<"5. Load User"<<endl;
        cout<<"6. Save User"<<endl;        
        cout<<"0. Back to Main Menu"<<endl;
        cout<<"Enter Choice: ";
        cin>>choiceAdmin;
        cout<<endl;
    }
    void manageStudentMenu(){
        cout<<"1. Display Student Information"<<endl;
        cout<<"2. Add New Student"<<endl;
        cout<<"3. Update Existing Student"<<endl;
        cout<<"4. Delete Student"<<endl;
        cout<<"5. Load Student"<<endl;
        cout<<"6. Save Student"<<endl;          
        cout<<"0. Back to Main Menu"<<endl;
        cout<<"Enter Choice: ";
        cin>>choiceRegistrar;        
        cout<<endl;
    }
    void modifyUserMenu(){
        cout<<"1. Modify Everything"<<endl;
        cout<<"2. Modify Username"<<endl;
        cout<<"3. Modify Password"<<endl;
        cout<<"4. Modify Role"<<endl;
        cout<<"Input Choice: ";
        cin>>choiceModifyUser;
        cout<<endl;
    }
    string updateInput(string username){
        cout<<"Input Username To Modify: ";
        cin>>username;
        return username;
     }
    string deleteInput(string username){
        cout<<"Input Username To Delete: ";
        cin>>username;
        return username;
    }
    

public:
    void run(){

        do{
            welcomePage();
            switch(choiceWelcome){
                case LOGIN:
                    do{
                        mainMenu();
                            switch(choiceMain){
                                case MANAGE_USER:
                                    do{
                                        manageUserMenu();
                                        switch(choiceAdmin){
                                            case DISPLAY_USER:
                                                try{
                                                    cout<<"Display"<<endl<<endl;
                                                    userService.displayUser();
                                                    cout<<endl;
                                              }catch(UserNotFoundException& u){
                                                    cout<<u.what()<<endl;
                                                }
                                                break;
                                            case ADD_USER:
                                                try{
                                                    cout<<"ADD"<<endl<<endl;
                                                    int j;
                                                    cout<<"Number of Users To Add: ";
                                                    cin>>j;
                                                    for(int i=1; i<=j; i++){
                                                        cout<<"Input User ("<<i<<"): "<<endl;
                                                        user[i].inputUser();
                                                        userService.addUser(&user[i]);  
                                                        cout<<endl;                                          
                                                    }                            
                                                }catch(UserDuplicatedException& u){
                                                    cout<<u.what()<<endl;
                                                }
                                                //user.inputUser();
                                                break;
                                            case UPDATE_USER:
                                                modifyUserMenu();
                                                switch(choiceModifyUser){
                                                    case MODIFY_EVERYTHING:
                                                        username = updateInput(username);
                                                        userService.modifyUser(username);
                                                    break;
                                                    case MODIFY_USERNAME:
                                                        username = updateInput(username);
                                                        userService.modifyUserUsername(username);
                                                    break;
                                                    case MODIFY_PASSWORD:
                                                        username = updateInput(username);
                                                        userService.modifyUserPassword(username);
                                                        break;
                                                    case MODIFY_ROLE:
                                                        username = updateInput(username);
                                                        userService.modifyUserRole(username);
                                                        break;
                                                    default:
                                                    break;                                                            
                                                }//while(choiceModifyUser!=MANAGE_USER_MENU)
                                                break;
                                            case DELETE_USER:
                                                username = deleteInput(username);
                                                userService.deleteUser(username);
                                                break;
                                            case LOAD_USER:
                                                userService.loadUserFromFile();
                                                cout<<"All User Load Succesfully"<<endl;
                                                break;
                                            case SAVE_USER:
                                                userService.writeUserToFile();
                                                cout<<"All User Save Succesfully"<<endl;  
                                                break;                                              
                                            default:
                                            cout<<">>> Invalid Input <<<"<<endl<<endl;
                                        }                                        
                                    }while(choiceAdmin!=MAIN_MENU);
                                    break;
                                case MANAGE_STUDENT:
                                    do{
                                        manageStudentMenu();
                                        switch(choiceRegistrar){
                                            case DISPLAY_STUDENT:
                                                try{
                                                    cout<<"Display"<<endl<<endl;
                                                    studentService.displayStudent();
                                                    cout<<endl;            
                                                }catch(StudentNotFoundException& s){
                                                    cout<<s.what()<<endl;
                                                }
                                                break;
                                            case ADD_STUDENT:
                                                try{
                                                    //student = new ScholarshipStudent();
                                                   int j;
                                                    cout<<"Number of Students To Add: ";
                                                    cin>>j;
                                                    for(int i=1; i<=j; i++){
                                                        cout<<"Input Student ("<<i<<"): "<<endl;
                                                        student[i].inputStudent();
                                                        studentService.addStudent(&student[i]);  
                                                        cout<<endl;                                          
                                                    }                   
                                                }catch(StudentDuplicatedException& s){
                                                    cout<<s.what()<<endl;
                                                }                                                
                                                break;
                                            case UPDATE_STUDENT:
                                                username = updateInput(username);
                                                studentService.modifyStudent(username);                                            
                                                break;
                                            case DELETE_STUDENT:
                                                username = deleteInput(username);
                                                studentService.deleteStudent(username);                                               
                                                break;
                                            default:
                                            cout<<">>> Invalid Input <<<"<<endl<<endl;
                                        }
                                    }while(choiceRegistrar!=MAIN_MENU);
                                    break;
                                case WELCOME_PAGE:
                                    break;
                                default: 
                                    cout<<">>> Invalid Input <<<"<<endl<<endl;
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

        // string username;
        // User user;
        // User user1;
        // UserService userService;
        // user.inputUser();
        // userService.addUser(&user);
        // user1.inputUser();
        // userService.addUser(&user1);    
        // cout<<"Input username to delete: ";
        // cin>>username;
        // userService.deleteUser(username);    
        // userService.displayUser();        

        
        // string username, password;
        // UserService userService;

        // Authorization authorization;
        // authorization.Login(username, password);

        // userservice.addUser();
        // userService.displayUser();
        // cout<<endl;
        // cout<<"In a: ";
        // cin>>a;
        */