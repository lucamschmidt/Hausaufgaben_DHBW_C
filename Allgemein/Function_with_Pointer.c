

double myFcn(double x){

    return x*x;
}

int main(){

    double value = 5;
    double res = 0;

    //fcn pointer
    double (*myFcnPtr)(double);
    myFcnPtr = myFcn;

    //with fcn
    res = myFcn(5);
    printf("myFcn(%lf) = %lf\n", value, res);

    //with pointer
    res = myFcnPtr(value);
    printf("myFcnPtr(%lf) = %lf\n", value, res);

    return 0;
}