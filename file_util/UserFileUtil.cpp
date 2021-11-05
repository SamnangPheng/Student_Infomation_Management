#pragma once

#include <iostream>
#include <fstream>
#include "../user_module/User.cpp"
#include <vector>
#include "../exceptions/FileNotFoundException.cpp"
using namespace std;

class UserFileUtil{
private:
    ofstream fout;
    User user;
public:
    void openOutputUserFile(string filename){
        try{
            fout.open(filename, ios::out|ios::app|ios::binary);
        }catch(FileNotFoundException& f){
            cerr<<f.what()<<endl;
        }
    }
    ifstream openInputUserFile(string filename){
        ifstream fin;
        try{
            fin.open(filename, ios::in|ios::binary);
        }catch(FileNotFoundException& f){
            cerr<<f.what()<<endl;
        }
        return fin;
    }    
    void writeUserFile(){
        fout.write((char*)& user, sizeof(User));
    }
    ifstream loadUserFile(){
        ifstream fin;
        fin.read((char*)& user, sizeof(User));
        return fin;
    }        
    void closeUserFile(){
        fout.close();
    }
};