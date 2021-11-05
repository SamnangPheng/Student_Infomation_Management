#pragma once

#include <iostream>
#include <fstream>
#include "../user_module/User.cpp"
#include "../user_module/UserService.cpp"
#include <vector>
using namespace std;

class Authentication{
private:

    User user;
    UserService userService;

public:
    bool authenticateUser(string username, string password, string role){
        vector<User> userlist;
        userlist = userService.getAllUsers();
        for(User user: userlist)
            if(user.getUsername()==username && user.getPassword()==password && user.getRole()==role){
            return true;  
            }
        return false;
    }


};
