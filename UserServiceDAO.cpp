#include <iostream>
#include "User.cpp"
#include <vector>
using namespace std;

class UserServiceDAO{
public:
    virtual void addUser(User* user)=0;
    virtual void displayUser()=0;
//    virtual void modifyUser(vector<User*>::iterator user)=0;
//    virtual void DeleteUser(vector<User*>::iterator user)=0;
    virtual void modifyUser(string username) = 0;
    virtual void deleteUser(string username) = 0;


};