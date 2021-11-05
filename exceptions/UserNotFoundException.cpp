#pragma once

#include <iostream>
#include <exception>
using namespace std;

class UserNotFoundException: public exception{
public:
    virtual const char* what() const throw(){
        return "User was not found!!!";
    }
};