#include <stdio.h>                                                      //18.05.20
#include <string.h>                                                     //Moritz Bieg & Luca Schmidt
#include <stdlib.h>                                                     //Taschenrechner für komplexe Zahlen
#include <math.h>
#include "function.h"

int main(){

    char zahl1[100];
    char zahl2[100];
    int i = 0;
    double sumreal = 0;
    double sumimag = 0;
    double diffreal = 0;
    double diffimag = 0;
    double productreal = 0;
    double productimag = 0;
    double quotientreal = 0;
    double quotientimag = 0;
    double sumamount = 0;
    double sumphi = 0;
    double diffamount = 0;
    double diffphi = 0;
    double productamount = 0;
    double productphi = 0;
    double quotientamount = 0;
    double quotientphi = 0;

    printf("Taschenrechner fuer komplexe Zahlen: \n\n");  

    //einlesen der Zahlen als String     
    printf("Geben Sie die erste komplexe Zahl ein (Realteil+Imaginaerteil(negative Werte ohne Klammer, + ist notwendig!)): ");
    scanf("%s", &zahl1); // JW 2020-05-20: this is technically wrong but will be handled by the compiler. please use >&zahl[0]< or >zahl< same in line 36: -1Pkt
    printf("Die erste Zahl lautet: %si\n\n", zahl1);
    printf("Geben Sie die zweite komplexe Zahl ein (Realteil+Imaginaerteil(negative Werte ohne Klammer, + ist notwendig!)): ");
    scanf("%s", &zahl2);
    printf("Die zweite Zahl lautet: %si\n\n", zahl2);

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


    printf("Wie wollen sie die neue Zahl ausgeben?\n1.Karthesische Darstellung\n2.Euler Darstellung\n3.Polar Darstellung\n: ");
    scanf("%d", &i);

    if (i == 1)
    {
        printf("Karthesische Darstellung: \n\n");
        //Addition
        sumreal = add(zahl1com.real, zahl2com.real);
        sumimag = add(zahl1com.imag, zahl2com.imag);

        printf("Summe: %.3f+%.3fi\n",sumreal, sumimag);

        //Subtraktion
        diffreal = sub(zahl1com.real, zahl2com.real);
        diffimag = sub(zahl1com.imag, zahl2com.imag);

        printf("Differenz: %.3f+%.3fi\n",diffreal , diffimag);

        //Multiplikation
        productreal = realmult(zahl1com.real, zahl1com.imag, zahl2com.real, zahl2com.imag);
        productimag = imagmult(zahl1com.real, zahl1com.imag, zahl2com.real, zahl2com.imag);

        printf("Produkt: %.3f+%.3fi\n", productreal, productimag);

        //Division
        quotientreal = realdiv(zahl1com.real, zahl1com.imag, zahl2com.real, zahl2com.imag);
        quotientimag = imagdiv(zahl1com.real, zahl1com.imag, zahl2com.real, zahl2com.imag);

        printf("Quotient: %.3f+%.3fi\n", quotientreal, quotientimag);
    }

    if (i == 2)
    {
        printf("Euler Darstellung: \n\n");
        //Addition
        sumreal = add(zahl1com.real, zahl2com.real);
        sumimag = add(zahl1com.imag, zahl2com.imag);
        sumamount = amount(sumreal, sumimag);
        sumphi = phi(sumreal, sumimag);

        printf("Summe: %.3f*e^i%.3f\n", sumamount, sumphi);

        //Subtraktion
        diffreal = sub(zahl1com.real, zahl2com.real);
        diffimag = sub(zahl1com.imag, zahl2com.imag);
        diffamount = amount(diffreal, diffimag);
        diffphi = phi(diffreal, diffimag);


        printf("Differenz: %.3f*e^i%.3f\n", diffamount, diffphi);

        //Multiplikation
        productreal = realmult(zahl1com.real, zahl1com.imag, zahl2com.real, zahl2com.imag);
        productimag = imagmult(zahl1com.real, zahl1com.imag, zahl2com.real, zahl2com.imag);
        productamount = amount(productreal, productimag);
        productphi = phi(productreal, productimag);

        printf("Produkt: %.3f*e^i%.3f\n", productamount, productphi);

        //Division
        quotientreal = realdiv(zahl1com.real, zahl1com.imag, zahl2com.real, zahl2com.imag);
        quotientimag = imagdiv(zahl1com.real, zahl1com.imag, zahl2com.real, zahl2com.imag);
        quotientamount = amount(quotientreal, quotientimag);
        quotientphi = phi(quotientreal, quotientimag);

        printf("Quotient: %.3f*e^i%.3f\n", quotientamount, quotientphi);
    }

    if (i == 3)
    {
        printf("Polar Darstellung: \n\n");
        //Addition
        sumreal = add(zahl1com.real, zahl2com.real);
        sumimag = add(zahl1com.imag, zahl2com.imag);
        sumamount = amount(sumreal, sumimag);
        sumphi = phi(sumreal, sumimag);

        printf("Summe: %.3f*(cos%.3f + isin%.3f)\n", sumamount, sumphi, sumphi);

        //Subtraktion
        diffreal = sub(zahl1com.real, zahl2com.real);
        diffimag = sub(zahl1com.imag, zahl2com.imag);
        diffamount = amount(diffreal, diffimag);
        diffphi = phi(diffreal, diffimag);
        
        printf("Differenz: %.3f*(cos%.3f + isin%.3f)\n", diffamount, diffphi, diffphi);

        //Multiplikation
        productreal = realmult(zahl1com.real, zahl1com.imag, zahl2com.real, zahl2com.imag);
        productimag = imagmult(zahl1com.real, zahl1com.imag, zahl2com.real, zahl2com.imag);
        productamount = amount(productreal, productimag);
        productphi = phi(productreal, productimag);

        printf("Produkt: %.3f*(cos%.3f + isin%.3f)\n", productamount, productphi, productphi);

        //Division
        quotientreal = realdiv(zahl1com.real, zahl1com.imag, zahl2com.real, zahl2com.imag);
        quotientimag = imagdiv(zahl1com.real, zahl1com.imag, zahl2com.real, zahl2com.imag);
        quotientamount = amount(quotientreal, quotientimag);
        quotientphi = phi(quotientreal, quotientimag);

        printf("Quotient: %.3f*(cos%.3f + isin%.3f)\n", quotientamount, quotientphi, quotientphi);
    }
}
/*
JW-2020-05-20:
--------------
> well done! (11/10) 
> scanf char array line 33&36: -1 Pkt
> Bonus: +2Pkt
*/