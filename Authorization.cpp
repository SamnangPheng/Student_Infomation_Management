/*
#pragma once

#include <iostream>
#include "UserService.cpp"
#include "Authentication.cpp"
using namespace std;

class Authorization{
private:
//    UserService userService;
    Authentication authentication;
public:
    void Login(string username, string password){
        cout<<"Enter Username: ";
        cin>>username;
        cout<<"Input Password: ";
        cin>>password;
    if(authentication.userAuthentication(username, password) != nullptr){
        cout<<"Hello Universe"<<endl;
        }
    }
};
*/