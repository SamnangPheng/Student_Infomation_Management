#pragma once

#include <iostream>
#include <vector>
#include "Student.cpp"
#include "StudentServiceDAO.cpp"
#include "FileNotFoundException.cpp"
#include "StudentNotFoundException.cpp"
#include "StudentDuplicatedException.cpp"
using namespace std;

class StudentService: public StudentServiceDAO{
private:
    vector<Student* > studentlist;
    Student student;

public:
    void addStudent(Student* student){
        studentlist.push_back(student);
    }
    void displayStudent(){
        for(Student* student: studentlist){
            (*student).outputStudent();
        }    
    }
    void modifyStudent(string username){
        for(auto it=studentlist.begin(); it!=studentlist.end(); it++){
            if((*it)->getUsername().compare(username)==0){
                (*it)->inputStudent();
                break;
                }
            }
        }    
    void modifyStudentUsername(string username){
        for(auto it=studentlist.begin(); it!=studentlist.end(); it++){
            if((*it)->getUsername().compare(username)==0){
                (*it)->inputStudentUsername();
                break;
                }
            }
        }        
    void modifyStudentSex(string username){
        for(auto it=studentlist.begin(); it!=studentlist.end(); it++){
            if((*it)->getUsername().compare(username)==0){
                (*it)->inputStudentSex();
                break;
                }
            }
        }
    void modifyStudentPhoneNumber(string username){
        for(auto it=studentlist.begin(); it!=studentlist.end(); it++){
            if((*it)->getUsername().compare(username)==0){
                (*it)->inputStudentPhoneNumber();
                break;
                }
            }
        } 
    void modifyStudentBirthdate(string username){
        for(auto it=studentlist.begin(); it!=studentlist.end(); it++){
            if((*it)->getUsername().compare(username)==0){
                (*it)->inputStudentBirthdate();
                break;
                }
            }
        }
    void modifyStudentAddress(string username){
        for(auto it=studentlist.begin(); it!=studentlist.end(); it++){
            if((*it)->getUsername().compare(username)==0){
                (*it)->inputStudentAddress();
                break;
                }
            }
        }               

    void deleteStudent(string username){
        for(auto it=studentlist.begin(); it!=studentlist.end(); it++){
            if((*it)->getUsername().compare(username)==0){
                studentlist.erase(it);
                break;
                }
            }
        }

};