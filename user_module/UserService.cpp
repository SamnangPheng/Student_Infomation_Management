#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "User.cpp"
#include "UserServiceDAO.cpp"
#include "../file_util/UserFileUtil.cpp"
#include "../exceptions/FileNotFoundException.cpp"
#include "../exceptions/UserNotFoundException.cpp"
#include "../exceptions/UserDuplicatedException.cpp"

using namespace std;

class UserService: public UserServiceDAO{
private:
    vector<User> userlist;
    User user;
    UserFileUtil userFileUtil;
    const string filename = "userlist.dat";

public:
    void addUser(User user){
        userlist.push_back(user);
    }
    void displayUser(){
        if(userlist.empty()){
            UserNotFoundException u;
            throw u;
        }
        for(User user: userlist){
            user.outputUser();
        }
    }
    void displayUserByUserame(string username){
        if(userlist.empty()){
            UserNotFoundException u;
            throw u;
        }
        for(auto it=userlist.begin(); it!=userlist.end(); it++){
            if((it)->getUsername().compare(username)==0){
                (it)->outputUser();
                break;
                }else{
            UserNotFoundException u;
            throw u;                    
                }
            }
        }    
    void modifyUser(string username){
        if(userlist.empty()){
            UserNotFoundException u;
            throw u;
        }
        for(auto it=userlist.begin(); it!=userlist.end(); it++){
            if((it)->getUsername().compare(username)==0){
                (it)->inputUser();
                break;
                }
            }
        }
    void modifyUserUsername(string username){
        if(userlist.empty()){
            UserNotFoundException u;
            throw u;
        }        
        for(auto it=userlist.begin(); it!=userlist.end(); it++){
            if((it)->getUsername().compare(username)==0){
                (it)->inputUserUsername();
                break;
                }
            }
        }        
    void modifyUserPassword(string username){
        if(userlist.empty()){
            UserNotFoundException u;
            throw u;
        }        
        for(auto it=userlist.begin(); it!=userlist.end(); it++){
            if((it)->getUsername().compare(username)==0){
                (it)->inputUserPassword();
                break;
                }
            }
        }
    void modifyUserRole(string username){
        if(userlist.empty()){
            UserNotFoundException u;
            throw u;
        }        
        for(auto it=userlist.begin(); it!=userlist.end(); it++){
            if((it)->getUsername().compare(username)==0){
                (it)->inputUserRole();
                break;
                }
            }
        }                

    void deleteUser(string username){
        if(userlist.empty()){
            UserNotFoundException u;
            throw u;
        }        
        int c;
        for(auto it=userlist.begin(); it!=userlist.end(); it++){
            if((it)->getUsername().compare(username)==0){
                cout<<"Do You Really Want To Delete This User?"<<endl;
                cout<<"Enter 1 For Yes and 0 for No: ";
                cin>>c;
                if(c == 1){
                    userlist.erase(it);
                    cout<<"\nUser Deleted Successfully!!!"<<endl<<endl;
                    }
                break;
                }
            }
        }

    vector <User> getAllUsers(){
        User user1("dara", "Step@123", "admin");
        User user2("lina", "Step@321", "user");
        addUser(user1);
        addUser(user2);
        return userlist;
    }
    
    void writeUserToFile(){
        ofstream fout;
        fout.open(filename, ios::out|ios::app|ios::binary);
        for(User user: userlist){
            fout.write((char*)& user, sizeof(User));
        }
        userFileUtil.closeUserFile();
    }
    void loadUserFromFile(){
        ifstream fin;
        fin.open(filename, ios::in|ios::binary);
        while( fin.read((char*)& user, sizeof(User))){
            userlist.push_back(user);
        }
        userFileUtil.closeUserFile();
    }
    
};