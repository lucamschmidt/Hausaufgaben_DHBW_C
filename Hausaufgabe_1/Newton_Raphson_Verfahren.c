#include <stdio.h>					
#include <stdlib.h>																							// 11.05.2020
#include <math.h>																							// Luca Schmidt & Moritz Bieg
#include "fcn.h"																							// Newton-Verfahren f�r Funktionen mit 3 Koeffizienten und einem Absolutglied



int main()
{
	double Val1 = 1;
	double Val2 = -6;
	double Val3 = 9;
	double Val4 = -8;
	double Exp1 = 2;
	double Exp2 = 1;
	double X = -1;
	double Xnew = 0;
	double Lsg1, Lsg2;
	double (*FcnPtr)(double);
	FcnPtr = Fcn;

	printf("Newton-Raphson-Verfahren:  \n \n");
	printf("Eingegebene Funktion: (%.1f*X ^ %.1f) + (%.1f*X ^ %.1f) + %.1f*X + %.1f \n\n", Val1, Exp1, Val2, Exp2, Val3, Val4);

	while ((FcnPtr(Val1, Val2, Val3, Val4, Exp1, Exp2, X)) > 0.0000001 || (FcnPtr(Val1, Val2, Val3, Val4, Exp1, Exp2, X)) < -0.000001)
	{
		Lsg1 = FcnPtr(Val1, Val2, Val3, Val4, Exp1, Exp2, X);												// Lsg1 = Val1*X ^ Exp1 + Val2*X ^ Exp2 + Val3*X + Val4
		
		Lsg2 = Der(FcnPtr(Val1, Val2, Val3, Val4, Exp1, Exp2, X), X);										// Fcn abgeleitet

		Xnew = X - (Lsg1 / Lsg2);																			// Newton-Verfahren
		X = Xnew;
	}

	printf("Eine Nullstelle liegt ca. bei: %.5f \n \n", X);													// Ausgabe

}