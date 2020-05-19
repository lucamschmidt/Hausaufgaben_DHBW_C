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
    scanf("%s", &zahl1);
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

    if (i == 2)
    {
        printf("Euler Darstellung: \n\n");
        //Addition
        sumreal = add(zahl1com.real, zahl2com.real);
        sumimag = add(zahl1com.imag, zahl2com.imag);
        sumamount = sqrt(sumreal * sumreal + sumimag * sumimag);
        if(sumreal>0){
            sumphi = atan(sumimag / sumreal);
        }else   { 
            if(sumreal<0 && sumimag>=0)   {
                sumphi = atan(sumimag / sumreal)+M_PI;
            }else{
                    sumphi = atan(sumimag / sumreal)-M_PI; 
                }
        }
        printf("Summe: %.2f*e^i%.2f\n", sumamount, sumphi);

        //Subtraktion
        diffreal = sub(zahl1com.real, zahl2com.real);
        diffimag = sub(zahl1com.imag, zahl2com.imag);
        diffamount = sqrt(diffreal * diffreal + diffimag * diffimag);
        diffphi = atan(diffimag / diffreal);
        if(diffreal>0){
            diffphi = atan(diffimag / diffreal);
        }else   { 
            if(diffreal<0 && diffimag>=0)   {
                diffphi = atan(diffimag / diffreal)+M_PI;
            }else{
                    diffphi = atan(diffimag / diffreal)-M_PI; 
                }
        }

        printf("Differenz: %.2f*e^i%.2f\n", diffamount, diffphi);

        //Multiplikation
        productreal = realmult(zahl1com.real, zahl1com.imag, zahl2com.real, zahl2com.imag);
        productimag = imagmult(zahl1com.real, zahl1com.imag, zahl2com.real, zahl2com.imag);
        productamount = sqrt(productreal * productreal + productimag * productimag);
        if(productreal>0){
            productphi = atan(productimag / productreal);
        }else   { 
            if(productreal<0 && productimag>=0)   {
                productphi = atan(productimag / productreal)+M_PI;
            }else{
                    productphi = atan(productimag / productreal)-M_PI; 
                }
        }
        printf("Produkt: %.2f*e^i%.2f\n", productamount, productphi);

        //Division
        quotientreal = realdiv(zahl1com.real, zahl1com.imag, zahl2com.real, zahl2com.imag);
        quotientimag = imagdiv(zahl1com.real, zahl1com.imag, zahl2com.real, zahl2com.imag);
        quotientamount = sqrt(quotientreal * quotientreal + quotientimag * quotientimag);
        if(quotientreal>0){
            quotientphi = atan(quotientimag / quotientreal);
        }else   { 
            if(quotientreal<0 && quotientimag>=0)   {
                quotientphi = atan(quotientimag / quotientreal)+M_PI;
            }else{
                    quotientphi = atan(quotientimag / quotientreal)-M_PI; 
                }
        }
        printf("Quotient: %.2f*e^i%.2f\n", quotientamount, quotientphi);
    }

    if (i == 3)
    {
        printf("Polar Darstellung: \n\n");
        //Addition
        sumreal = add(zahl1com.real, zahl2com.real);
        sumimag = add(zahl1com.imag, zahl2com.imag);
        sumamount = sqrt(sumreal * sumreal + sumimag * sumimag);
        sumphi = atan(sumimag / sumreal);
        if(sumreal>0){
            sumphi = atan(sumimag / sumreal);
        }else   { 
            if(sumreal<0 && sumimag>=0)   {
                sumphi = atan(sumimag / sumreal)+M_PI;
            }else{
                    sumphi = atan(sumimag / sumreal)-M_PI; 
                }
        }
        printf("Summe: %.2f*(cos%.2f + isin%.2f)\n", sumamount, sumphi, sumphi);

        //Subtraktion
        diffreal = sub(zahl1com.real, zahl2com.real);
        diffimag = sub(zahl1com.imag, zahl2com.imag);
        diffamount = sqrt(diffreal * diffreal + diffimag * diffimag);
        if(diffreal>0){
            diffphi = atan(diffimag / diffreal);
        }else   { 
            if(diffreal<0 && diffimag>=0)   {
                diffphi = atan(diffimag / diffreal)+M_PI;
            }else{
                    diffphi = atan(diffimag / diffreal)-M_PI; 
                }
        }
        
        printf("Differenz: %.2f*(cos%.2f + isin%.2f)\n", diffamount, diffphi, diffphi);

        //Multiplikation
        productreal = realmult(zahl1com.real, zahl1com.imag, zahl2com.real, zahl2com.imag);
        productimag = imagmult(zahl1com.real, zahl1com.imag, zahl2com.real, zahl2com.imag);
        productamount = sqrt(productreal * productreal + productimag * productimag);
        productphi = atan(productimag / productreal);
        if(productreal>0){
            productphi = atan(productimag / productreal);
        }else   { 
            if(productreal<0 && productimag>=0)   {
                productphi = atan(productimag / productreal)+M_PI;
            }else{
                    productphi = atan(productimag / productreal)-M_PI; 
                }
        }
        printf("Produkt: %.2f*(cos%.2f + isin%.2f)\n", productamount, productphi, productphi);

        //Division
        quotientreal = realdiv(zahl1com.real, zahl1com.imag, zahl2com.real, zahl2com.imag);
        quotientimag = imagdiv(zahl1com.real, zahl1com.imag, zahl2com.real, zahl2com.imag);
        quotientamount = sqrt(quotientreal * quotientreal + quotientimag * quotientimag);
        quotientphi = atan(quotientimag / quotientreal);
        if(quotientreal>0){
            quotientphi = atan(quotientimag / quotientreal);
        }else   { 
            if(quotientreal<0 && quotientimag>=0)   {
                quotientphi = atan(quotientimag / quotientreal)+M_PI;
            }else{
                    quotientphi = atan(quotientimag / quotientreal)-M_PI; 
                }
        }
        printf("Quotient: %.2f*(cos%.2f + isin%.2f)\n", quotientamount, quotientphi, quotientphi);
    }
}