#include <iostream>
//#include "myNameSpace.h"

namespace A{
    void printX(){
        int x = 5;
        std::cout << x << std::endl;
    }
}

namespace B{
    void printX(){
        int x = 10;
        std::cout << x << std::endl;
    }
}