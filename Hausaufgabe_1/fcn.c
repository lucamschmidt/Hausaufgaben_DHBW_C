#include <stdio.h>					
#include <stdlib.h>																							// 11.05.2020
#include <math.h>

double Fcn(double Val1, double Val2, double Val3, double Val4, double Exp1, double Exp2, double X)
{																										// Lsg1 = Val1*X ^ Exp1 + Val2*X ^ Exp2 + Val3*X + Val4 
	return pow((X * Val1), Exp1) + pow((X * Val2), Exp2) + Val3*X + Val4;
}

double Der(double (*Fcn)(double), double x)
{
	double dx = 1e-8;
	return (Fcn(x+dx)-Fcn(x))/dx;
}