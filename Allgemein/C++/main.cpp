#include <iostream>

using namespace std;                //std kann in der main weggelassen werden, evtl problematisch bei mehreren

int main(){

    double summand1, summand2, ergebnis;

    std::cout << "first arg: " << std::endl;
    std::cin >> summand1;

    std::cout << "second arg: " << std::endl;
    std::cin >> summand2;

    ergebnis = summand1 + summand2;

    std::cout << summand1 << " + " << summand2 << " = " << ergebnis << std::endl;

    return 0;
}