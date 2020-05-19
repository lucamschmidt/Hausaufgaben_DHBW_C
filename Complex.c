#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "function.h"

int main(){

    char zahl1[100];
    char zahl2[100];
    double sumreal = 0;
    double sumimag = 0;
    double diffreal = 0;
    double diffimag = 0;
    double productreal = 0;
    double productimag = 0;
    double quotientreal = 0;
    double quotientimag = 0;

    printf("Taschenrechner fuer komplexe Zahlen: \n\n");  

    //einlesen der Zahlen als String     
    printf("Geben Sie die erste komplexe Zahl ein (a+bi): ");
    scanf("%s", &zahl1);
    printf("Die erste Zahl lautet: %s\n\n", zahl1);
    printf("Geben Sie die zweite komplexe Zahl ein (a+bi): ");
    scanf("%s", &zahl2);
    printf("Die zweite Zahl lautet: %s\n\n", zahl2);

    //Strings aufteilen in Real und Imagteil, String zu double und abspeichern in struct
    char *split;
    char *split2;
    char delimiter[] = "+";
    split = strtok(zahl1, delimiter);
    zahl1com.real = atof(split);
    split2 = strtok(NULL, delimiter);
    zahl1com.imag = atof(split2);
    split = strtok(zahl2, delimiter);
    zahl2com.real = atof(split);
    split2 = strtok(NULL, delimiter);
    zahl2com.imag = atof(split2);

    //Addition
    sumreal = add(zahl1com.real, zahl2com.real);
    sumimag = add(zahl1com.imag, zahl2com.imag);

    printf("Summe: %.2f+%.2fi\n",sumreal, sumimag);

    //Subtraktion
    diffreal = sub(zahl1com.real, zahl2com.real);
    diffimag = sub(zahl1com.imag, zahl2com.imag);

    printf("Differenz: %.2f+%.2fi\n",diffreal , diffimag);

    //Multiplikation
    productreal = realmult(zahl1com.real, zahl1com.imag, zahl2com.real, zahl2com.imag);
    productimag = imagmult(zahl1com.real, zahl1com.imag, zahl2com.real, zahl2com.imag);

    printf("Produkt: %.2f+%.2fi\n", productreal, productimag);

    //Division
    quotientreal = realdiv(zahl1com.real, zahl1com.imag, zahl2com.real, zahl2com.imag);
    quotientimag = imagdiv(zahl1com.real, zahl1com.imag, zahl2com.real, zahl2com.imag);

    printf("Quotient: %.2f+%.2fi\n", quotientreal, quotientimag);
}