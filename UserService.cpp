#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "User.cpp"
#include "UserServiceDAO.cpp"
#include "UserFileUtil.cpp"
#include "FileNotFoundException.cpp"
#include "UserNotFoundException.cpp"
#include "UserDuplicatedException.cpp"

using namespace std;

class UserService: public UserServiceDAO{
private:
    vector<User* > userlist;
    User user;
    UserFileUtil userFileUtil;
    const string filename = "userlist.dat";

public:
    void addUser(User* user){
        userlist.push_back(user);
        // ofstream fout;
        // fout.open("User.txt", ios::out|ios::app);
        // user.inputUser();
        // fout.write((char*)& user, sizeof(user));
        // fout.close();
    }
    void displayUser(){
        if(userlist.empty()){
            UserNotFoundException u;
            throw u;
        }
        for(User* user: userlist){
            (*user).outputUser();
            //cout<<endl;
        }
    // void displayUserByName(string name){
    //     for(User* user: userlist){
    //         (*user).outputUser();
    //     }
    // }
        // ifstream fin;
        // fin.open("User.txt", ios::in);
        // while(fin.read((char*)& user, sizeof(user))){
        //     user.outputUser();
        // }
        // fin.close();
    }
    void modifyUser(string username){
        // auto it=find_if(userlist.begin(), userlist.end(), [&username](User& u){
        //     return (u.getUsername() == username);
        // });
        //     if(it!=userlist.end()){
        //         (*it)->inputUser();
        for(auto it=userlist.begin(); it!=userlist.end(); it++){
            if((*it)->getUsername().compare(username)==0){
                (*it)->inputUser();
                break;
            }//else{
            //    throw UserNotFoundException();
            }
        }
    void modifyUserUsername(string username){
        for(auto it=userlist.begin(); it!=userlist.end(); it++){
            if((*it)->getUsername().compare(username)==0){
                (*it)->inputUserUsername();
                break;
                }
            }
        }        
    void modifyUserPassword(string username){
        for(auto it=userlist.begin(); it!=userlist.end(); it++){
            if((*it)->getUsername().compare(username)==0){
                (*it)->inputUserPassword();
                break;
                }
            }
        }
    void modifyUserRole(string username){
        for(auto it=userlist.begin(); it!=userlist.end(); it++){
            if((*it)->getUsername().compare(username)==0){
                (*it)->inputUserRole();
                break;
                }
            }
        }                
    vector <User*> getAllUsers(){
        User user1("dara", "123", "admin");
        User user2("lina", "345", "user");
        addUser(&user2);
        addUser(&user1);
        return userlist;
    }
    // bool verifyUsername(string username){
    //     for(auto it=userlist.begin(); it!=userlist.end(); it++){
    //         if((*it)->getUsername().compare(username)==0)
    //         return true;
    //     }
    // }
    // void modifyRole(){
    //     if(verifyUsername){
    //         vector <User*> userlist :: iterator it;
    //         (*it)->inputUserRole();
    //     }
    // }
    
    void deleteUser(string username){
        for(auto it=userlist.begin(); it!=userlist.end(); it++){
            if((*it)->getUsername().compare(username)==0){
                userlist.erase(it);
                break;
                }
            //    throw UserNotFoundException();
            }
        }

    void writeUserToFile(){
        // userFileUtil.openOutputUserFile(filename);
        ofstream fout;
        fout.open(filename, ios::out|ios::app|ios::binary);
        for(User* user: userlist){
            fout.write((char*)& user, sizeof(User));
        }
        userFileUtil.closeUserFile();
    }
    void loadUserFromFile(){
        // userFileUtil.openInputUserFile(filename);
        ifstream fin;
        fin.open(filename, ios::in|ios::binary);
        while( fin.read((char*)& user, sizeof(User))){
            userlist.push_back(&user);
        }
        userFileUtil.closeUserFile();
    }
    

    //    User* authenticateUser(string name, string passw){
    //     for(auto it=userlist.begin(); it!=userlist.end(); it++){
    //         if((*it)->getUsername().compare(name)!=0 && (*it)->getPassword().compare(passw)!=0){
    //             //(*it)->outputUser();
    //             return &user;
    //             break;
    //             }
    //         }
    //         return nullptr;            
    //     }


};