#pragma once

#include <iostream>
#include <exception>
using namespace std;

class UserDuplicatedException: public exception{
public:
    virtual const char* what() const throw(){
        return "This user already has in the system!!!";
    }
};