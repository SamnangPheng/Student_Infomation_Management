#pragma once

#include <iostream>
#include <regex>
using namespace std;

class GetChoice{

protected:

    int getCommand(int choice){
        while(true){
            cout<<"Enter choice: ";
            cin>>choice;
            if(cin.fail()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if(cin.gcount()>1){
                continue;
            }
            if(choice<0){
                continue;
            }
            break;
        }
        return choice;
    }
};