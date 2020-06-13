#include <iostream>
using namespace std;

class car{
    private:                             
        string brand;
        string model;
        int year;
    public:
        car(string x, string y, int z){
            brand = x;
            model = y;
            year = z;
        }
        string getBrand(){
            return brand;
        }
        string getModel(){
            return model;
        }
        int getYear(){
            return year;
        }
};

int main(){

    car myCar1("BMW", "X5", 1999);
    car myCar2("Ford", "Mustang", 1969);

    cout << myCar1.getBrand() << " " << myCar1.getModel() << " " << myCar1.getYear() << "\n";
    cout << myCar2.getBrand() << " " << myCar2.getModel() << " " << myCar2.getYear() << "\n";

    return 0;
}