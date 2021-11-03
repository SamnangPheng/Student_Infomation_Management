#pragma once

#include <iostream>
#include <cstring>
#include <regex>
using namespace std;

class User{
private:
    string username;
    string password;
    string role;

public:
    User(): username("Unknown"), password("Unknown"), role("Unknown"){}
    User(string username, string password, string role): username(username), password(password), role(role){}

    string getUsername() const{
        return username;
    }
    string getPassword() const{
        return password;
    }
    string getRole() const{
        return role;
    }
    void setUsername(string username){
        this->username=username;
    }
     void setPassword(string password){
        this->password=password;
    }
     void setRole(string role){
        this->role=role;
    }

    bool isValidUsername(string username){
        return all_of(username.begin(), username.end(), [](char ch){
            return (isalpha(ch) || isspace(ch));
        });
    }
    bool isValidPassword(string password){
        const regex pattern("[A-Z a-z 0-9 @#!*&]+");
        return regex_match(password, pattern);
    }
    bool isValidRole(string role){
        const regex pattern("[a-z]+");
        return regex_match(role, pattern);
    }    

    void inputUser(){
        do{
            cout<<"Input Username: ";
            cin>>username;        
        }while(!isValidUsername(username));
        do{
            cout<<"Input Password: ";
            cin>>password;
        }while(!isValidPassword(password));
        do{
            cout<<"Input Role: ";
            cin>>role;            
        }while(!isValidRole(role));

    }
    void inputUserUsername(){
        do{
            cout<<"Input Username: ";
            cin>>username;        
        }while(!isValidUsername(username));
    }    
    void inputUserPassword(){
        do{
            cout<<"Input Password: ";
            cin>>password;
        }while(!isValidPassword(password));
    }
    void inputUserRole(){
        do{
            cout<<"Input Role: ";
            cin>>role;            
        }while(!isValidRole(role));
    }

    void outputUser(){
        cout<<"Username: "<<username<<" Passsword: "<<password<<" Role: "<<role<<endl;
    }
    // bool isEqualUsername(string usenname){
    //     return (this->username==username);
    // }
};