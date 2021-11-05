#pragma once

#include <iostream>
#include <exception>
using namespace std;

class StudentNotFoundException: public exception{
public:
    virtual const char* what() const throw(){
        return "Student was not found";
    }
};