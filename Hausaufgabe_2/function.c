#include <stdio.h>
#include <math.h>

double add(double a, double b){
    return a+b;
}

double sub(double a, double b){
    return a-b;
}

double realmult(double a, double b, double c, double d){
    return (a*c-b*d);
}

double imagmult(double a, double b, double c, double d){
    return (a*d+b*c);
}

double realdiv(double a, double b, double c, double d){
    return (a*c+b*d)/(pow(c, 2)+pow(d, 2));
}

double imagdiv(double a, double b, double c, double d){
    return (b*c-a*d)/(pow(c, 2)+pow(d, 2));
}

double phi(double a, double b){
    if(a>0){
        return atan(b / a);
    }else   { 
        if(a<0 && b>=0)   {
            return atan(b / a)+M_PI;
        }else   {
            return atan(b / a)-M_PI; 
        }
    }
}

double amount(double a, double b){
    return sqrt(a * a + b * b);
}