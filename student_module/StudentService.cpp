#pragma once

#include <iostream>
#include <vector>
#include "Student.cpp"
#include "StudentServiceDAO.cpp"
#include "../exceptions/FileNotFoundException.cpp"
#include "../exceptions/StudentNotFoundException.cpp"
#include "../exceptions/StudentDuplicatedException.cpp"
using namespace std;

class StudentService: public StudentServiceDAO{
private:
    vector<Student> studentlist;
    Student student;

public:
    void addStudent(Student student){     
        studentlist.push_back(student);
    }
    void displayStudent(){
        if(studentlist.empty()){
            StudentNotFoundException s;
            throw s;
        }        
        for(Student student: studentlist){
            student.outputStudent();
        }    
    }
    void displayStudentByUserame(string username){
        if(studentlist.empty()){
            StudentNotFoundException s;
            throw s;
        }
        for(auto it=studentlist.begin(); it!=studentlist.end(); it++){
            if((it)->getUsername().compare(username)==0){
                (it)->outputStudent();
                break;
                }else{
            StudentNotFoundException s;
            throw s;                    
                }
            }
        }     
    void modifyStudent(string username){
        if(studentlist.empty()){
            StudentNotFoundException s;
            throw s;
        }        
        for(auto it=studentlist.begin(); it!=studentlist.end(); it++){
            if((it)->getUsername().compare(username)==0){
                (it)->inputStudent();
                break;
                }
            }
        }    
    void modifyStudentUsername(string username){
        if(studentlist.empty()){
            StudentNotFoundException s;
            throw s;
        }        
        for(auto it=studentlist.begin(); it!=studentlist.end(); it++){
            if((it)->getUsername().compare(username)==0){
                (it)->inputStudentUsername();
                break;
                }
            }
        }        
    void modifyStudentSex(string username){
        if(studentlist.empty()){
            StudentNotFoundException s;
            throw s;
        }        
        for(auto it=studentlist.begin(); it!=studentlist.end(); it++){
            if((it)->getUsername().compare(username)==0){
                (it)->inputStudentSex();
                break;
                }
            }
        }
    void modifyStudentPhoneNumber(string username){
        if(studentlist.empty()){
            StudentNotFoundException s;
            throw s;
        }        
        for(auto it=studentlist.begin(); it!=studentlist.end(); it++){
            if((it)->getUsername().compare(username)==0){
                (it)->inputStudentPhoneNumber();
                break;
                }
            }
        } 
    void modifyStudentBirthdate(string username){
        if(studentlist.empty()){
            StudentNotFoundException s;
            throw s;
        }        
        for(auto it=studentlist.begin(); it!=studentlist.end(); it++){
            if((it)->getUsername().compare(username)==0){
                (it)->inputStudentBirthdate();
                break;
                }
            }
        }
    void modifyStudentAddress(string username){
        if(studentlist.empty()){
            StudentNotFoundException s;
            throw s;
        }        
        for(auto it=studentlist.begin(); it!=studentlist.end(); it++){
            if((it)->getUsername().compare(username)==0){
                (it)->inputStudentAddress();
                break;
                }
            }
        }               

    void deleteStudent(string username){
        if(studentlist.empty()){
            StudentNotFoundException s;
            throw s;
        }        
        int c;
        for(auto it=studentlist.begin(); it!=studentlist.end(); it++){
            if((it)->getUsername().compare(username)==0){
                cout<<"Do You Really Want To Delete This Student?"<<endl;
                cout<<"Enter 1 For Yes and 0 for No: ";
                cin>>c;
                if(c == 1){
                    studentlist.erase(it);
                    cout<<"\nStudent Deleted Successfully!!!"<<endl<<endl;
                    }
                break;
                }
            }
        }

};