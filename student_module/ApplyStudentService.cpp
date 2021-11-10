#pragma once

#include <iostream>
#include <vector>
#include "Student.cpp"
#include "ScholarshipStudent.cpp"
#include "StudentService.cpp"
#include "../exceptions/FileNotFoundException.cpp"
#include "../exceptions/StudentNotFoundException.cpp"
#include "../exceptions/StudentDuplicatedException.cpp"
#include "../exceptions/BadInputException.cpp"
using namespace std;


enum{
    DISPLAY_STUDENT = 1,
    ADD_STUDENT,
    UPDATE_STUDENT,
    DELETE_STUDENT,
    LOAD_STUDENT,
    SAVE_STUDENT    
};
enum{
    S_MAIN_MENU = 0,
    S_MODIFY_EVERYTHING = 1,
    S_MODIFY_USERNAME,
    S_MODIFY_SEX,
    S_MODIFY_PHONE_NUMBER,
    S_MODIFY_BIRTHDATE,
    S_MODIFY_ADDRESS
};

class ApplyStudentService{
private: 
    int choice;
    string username;

    Student student;
    StudentService studentService;    

    void manageStudentMenu(){
        cout<<"==============================="<<endl;
        cout<<"1. Display Student Information"<<endl;
        cout<<"2. Add New Student"<<endl;
        cout<<"3. Update Existing Student"<<endl;
        cout<<"4. Delete Student"<<endl;
        cout<<"5. Load Student"<<endl;
        cout<<"6. Save Student"<<endl;          
        cout<<"0. Back to Main Menu"<<endl;
        cout<<"==============================="<<endl;
        cout<<endl;
    }
    void modifyStudentMenu(){
        cout<<"============================="<<endl;
        cout<<"1. Modify Everything"<<endl;
        cout<<"2. Modify Username"<<endl;
        cout<<"3. Modify Sex"<<endl;
        cout<<"4. Modify Phone Number"<<endl;
        cout<<"5. Modify Birthdate"<<endl;
        cout<<"6. Modify Address"<<endl;
        cout<<"============================="<<endl;
        cout<<endl;
    }    
    string updateInput(string username){
        cout<<"Input Username To Modify: ";
        cin>>username;
        return username;
     }
    string deleteInput(string username){
        cout<<"Input Username To Delete: ";
        cin>>username;
        return username;
    }

public: 
    void manageStudentChoice(){
        do{
            manageStudentMenu();
            cout<<"Enter Choice: ";
            cin>>choice;
                switch(choice){
                    case DISPLAY_STUDENT:
                        try{
                            int choiceDisplayUser;
                            cout<<"\nDisplay"<<endl<<endl;
                            cout<<"1. Display All Students"<<endl;
                            cout<<"2. Display Student By Username"<<endl;
                            cout<<"Input Choice: ";
                            cin>>choiceDisplayUser;                            
                            if(choiceDisplayUser == 1){
                                cout<<endl;
                            cout<<"========================================"<<endl;
                            cout<<"Username \t Sex \t Phone Number"<<endl;
                                studentService.displayStudent();
                            cout<<"========================================"<<endl<<endl;
                                cout<<endl;
                            }else if(choiceDisplayUser == 2){
                                cout<<"Input Username to Diplay: ";
                                cin>>username;
                                cout<<endl;
                                cout<<"======================"<<endl;
                                studentService.displayStudentByUserame(username);
                                cout<<"======================"<<endl;                            
                                cout<<endl;
                            }else{
                                cout<<"\nInvalid Choice!!!"<<endl;
                            }                                       
                        }catch(StudentNotFoundException& s){
                            cout<<s.what()<<endl<<endl;
                        }
                    break;
                    case ADD_STUDENT:
                        try{
                            int add;
                            cout<<"\nADD"<<endl<<endl;
                        do{
                            student.inputStudent();
                            studentService.addStudent(student);
                            cout<<"Do You Want to Add Another Student?"<<endl;
                            cout<<"Input 1 For Yes 0 For No: ";
                            cin>>add;
                            cout<<endl; 
                        }while(add!=0);                                                  
                        }catch(StudentDuplicatedException& s){
                            cout<<s.what()<<endl<<endl;
                        }                                                
                    break;
                    case UPDATE_STUDENT:      
                    try{
                        modifyStudentMenu();
                        cout<<"Input Choice: ";
                        cin>>choice;
                        switch(choice){
                            case S_MODIFY_EVERYTHING:
                                username = updateInput(username);
                                studentService.modifyStudent(username);
                            break;
                            case S_MODIFY_USERNAME:
                                username = updateInput(username);
                                studentService.modifyStudentUsername(username);
                            break;
                            case S_MODIFY_SEX:
                                username = updateInput(username);
                                studentService.modifyStudentSex(username);
                                break;
                            case S_MODIFY_PHONE_NUMBER:
                                username = updateInput(username);
                                studentService.modifyStudentPhoneNumber(username);
                                break;
                            case S_MODIFY_BIRTHDATE:
                                username = updateInput(username);
                                studentService.modifyStudentBirthdate(username);
                                break;    
                            case S_MODIFY_ADDRESS:
                                username = updateInput(username);
                                studentService.modifyStudentAddress(username);
                                break;                                                
                            default:
                                break;                                                            
                        }
                    }catch(StudentNotFoundException& s){
                        cerr<<s.what();
                        cout<<endl<<endl;
                    }catch(BadInputException& b){
                        cerr<<b.what();
                        cout<<endl<<endl;
                    }                                                    
                    break;
                    case DELETE_STUDENT:
                    try{
                        username = deleteInput(username);
                        studentService.deleteStudent(username);                             
                    }catch(StudentNotFoundException& s){
                        cerr<<s.what();
                        cout<<endl;
                    }
                                          
                    break;
                    default:
                    //    cout<<">>> Invalid Input <<<"<<endl<<endl;
                    break;
            }
        }while(choice!=S_MAIN_MENU);
    }

};