#include <iostream>

using namespace std;

class myClass{
    public:
    string myName;          //eigenschaft
    void printName(){       //methode
        cout << "My name is " << myName << endl;
    }

};

int main(){

    // erstelle object der klasse "myClass"
    myClass obj1;

    obj1.myName = "Luca";

    obj1.printName();

    return 0;
}