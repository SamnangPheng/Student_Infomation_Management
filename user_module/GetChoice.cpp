#include <iostream>
using namespace std;

class GetChoice{
protected:
    int choice;

public:
    int getCommand(int choice){
        cout<<"Enter Choice: ";
        cin>>choice;
        return choice;
    }
};