#pragma once

#include <iostream>
#include <exception>
using namespace std;

class StudentDuplicatedException: public exception{
public:
    virtual const char* what() const throw(){
        return "This student already has in the system!!!";
    }
};