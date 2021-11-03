#pragma once

#include <iostream>
#include <fstream>
#include "User.cpp"
#include "UserService.cpp"
#include <vector>
using namespace std;

class Authentication{
private:

    User user;
    UserService userService;

public:
        // vector<User> add(){
        //     User user("dara", "123", "admin");
        //     userlist.push_back(user);
        //     return userlist;
        // }
        // User* authenticateUser(string name, string passw){
            
        // for(auto it=userlist.begin(); it!=userlist.end(); it++){
        //     if((*it)->getUsername().compare(name)!=0 && (*it)->getPassword().compare(passw)!=0){
        //         //(*it)->outputUser();
        //         return &user;
        //         break;
        //         }
        //     }
        //     return nullptr;            
        // }


    User* authenticateUser(string name, string passw){
        vector<User* > userlist;
        userlist = userService.getAllUsers();
        //cout<<userlist;
        for(User* user: userlist)
            if(user->getUsername()==name && user->getPassword()==passw){
                cout<<name<<passw;
                return user;
            }
        return nullptr;
    }
};




/*
#pragma once

#include <iostream>
#include <fstream>
#include "User.cpp"
#include "UserService.cpp"
#include <vector>
using namespace std;

class Authentication{
private:
    User user;
    // UserService userService;
    // vector <User* > userlist;
public:
    User* userAuthentication(string username, string password){
        // userlist = user.outputUser();

        ifstream fin;
        fin.open("User.txt", ios::in);
        while(fin.read((char*)& user, sizeof(user))){
            if(user.getUsername()==username && user.getPassword()==password){
                return &user;
            }else{
                return nullptr;
            }   
        }
        fin.close();
    }
};
*/