#pragma once

#include <iostream>
#include <exception>
using namespace std;

class FileNotFoundException: public exception{
public:
    virtual const char* what() const throw(){
        return "File was not found in the system!!!";
    }
};