#pragma once

#include <iostream>
#include <fstream>
#include "student_module/Student.cpp"
#include "exceptions/FileNotFoundException.cpp"
using namespace std;

class StudentFileUtil{
private:
    ofstream fout;
    Student student;
public:
    void openStudentFile(string filename){
        try{
            fout.open(filename, ios::out|ios::app|ios::binary);
        }catch(FileNotFoundException& f){
            cerr<<f.what()<<endl;
        }
    }
    ifstream InputStudentFile(string filename){
        ifstream fin;
        try{
            fin.open(filename, ios::in|ios::binary);
        }catch(FileNotFoundException& f){
            cerr<<f.what()<<endl;
        }
        return fin;
    }    
    void writeStudentFile(){
        fout.write((char*)& student, sizeof(Student));
    }
    void closeStudentFile(){
        fout.close();
    }
};