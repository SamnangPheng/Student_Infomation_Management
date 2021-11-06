#pragma once

#include <iostream>
#include <vector>
#include <regex>
#include "User.cpp"
#include "UserService.cpp"
#include "../exceptions/FileNotFoundException.cpp"
#include "../exceptions/UserNotFoundException.cpp"
#include "../exceptions/UserDuplicatedException.cpp"
#include "../exceptions/BadInputException.cpp"
using namespace std;

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
    U_MODIFY_EVERYTHING = 1,
    U_MODIFY_USERNAME,
    U_MODIFY_PASSWORD,
    U_MODIFY_ROLE
};

class ApplyUserService{
private:
    int choice;
    string username;
    string digit;
    User user;
    UserService userService;

    // bool isValidDigit(string digit){
    //     const regex pattern("\\d{1}");
    //     return regex_match(digit, pattern);
    // }
    void manageUserMenu(){
        cout<<"1. Display User Information"<<endl;
        cout<<"2. Add New User"<<endl;
        cout<<"3. Update Existing User"<<endl;
        cout<<"4. Delete User"<<endl;
        cout<<"5. Load User"<<endl;
        cout<<"6. Save User"<<endl;        
        cout<<"0. Back to Main Menu"<<endl;
        // do{
            // cout<<"Enter Choice: ";
            // cin>>choiceAdmin;
        // }while(!isValidDigit(digit));

        cout<<endl<<endl;
    }
    void modifyUserMenu(){
        cout<<"1. Modify Everything"<<endl;
        cout<<"2. Modify Username"<<endl;
        cout<<"3. Modify Password"<<endl;
        cout<<"4. Modify Role"<<endl;
        // cout<<"Input Choice: ";
        // cin>>choiceModifyUser;
        cout<<endl<<endl;
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
    void manageUserChoice(){
        do{
            manageUserMenu();
            cout<<"Input Choice: ";
            cin>>choice;            
            switch(choice){
                case DISPLAY_USER:
                    try{
                        //int choiceDisplayUser;
                        cout<<"Display"<<endl<<endl;
                        cout<<"1. Display All Users"<<endl;
                        cout<<"2. Display User By Username"<<endl;
                        cout<<"Input Choice: ";
                        cin>>choice;
                        if(choice == 1){
                            cout<<endl;
                            userService.displayUser();
                            cout<<endl;
                        }else if(choice == 2){
                            cout<<"Input Username to Diplay: ";
                            cin>>username;
                            cout<<endl;
                            userService.displayUserByUserame(username);
                            cout<<endl;
                        }else{
                            cout<<"\nInvalid Choice!!!"<<endl;
                        }

                  }catch(UserNotFoundException& u){
                        cout<<u.what()<<endl<<endl;
                    }
                    break;
                case ADD_USER:
                    try{
                        //int add;
                        cout<<"ADD"<<endl<<endl;
                        do{
                            user.inputUser();
                            userService.addUser(user);
                            cout<<"\n>>> User Added Successfully <<<"<<endl;  
                            cout<<"Do You Want to Add Another User?"<<endl;
                            cout<<"Input 1 For Yes 0 For No: ";
                            cin>>choice;
                            cout<<endl; 
                        }while(choice!=0);
                                         
                    }catch(UserDuplicatedException& u){
                        cout<<u.what()<<endl<<endl;
                    }
                    break;
                case UPDATE_USER:
                    modifyUserMenu();
                    cout<<"Input Choice: ";
                    cin>>choice;                            
                    switch(choice){
                        case U_MODIFY_EVERYTHING:
                            username = updateInput(username);
                            userService.modifyUser(username);
                        break;
                        case U_MODIFY_USERNAME:
                            username = updateInput(username);
                            userService.modifyUserUsername(username);
                        break;
                        case U_MODIFY_PASSWORD:
                            username = updateInput(username);
                            userService.modifyUserPassword(username);
                            break;
                        case U_MODIFY_ROLE:
                            username = updateInput(username);
                            userService.modifyUserRole(username);
                            break;
                        default:
                        break;                                                            
                    }
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
                //cout<<">>> Invalid Input <<<"<<endl<<endl;
                break;
            }                                        
        }while(choice!=MAIN_MENU);
    }
};