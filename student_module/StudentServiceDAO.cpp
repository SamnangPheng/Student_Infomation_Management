#include <iostream>
#include "Student.cpp"
#include <vector>
using namespace std;

class StudentServiceDAO{
public:
    virtual void addStudent(Student student)=0;
    virtual void displayStudent()=0;
    virtual void modifyStudent(string username) = 0;
    virtual void deleteStudent(string username) = 0;

};