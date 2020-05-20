#ifndef FUNCTION_H
#define FUNCTION_H

//Struct für komplexe Zahlen
typedef struct{
    double real;
    double imag;
}complex;
complex zahl1com, zahl2com;

double add(double, double);
double sub(double, double);
double realmult(double, double, double, double);
double imagmult(double, double, double, double);
double realdiv(double, double, double, double);
double imagdiv(double, double, double, double);
double phi(double, double);
double amount(double, double);

#endif