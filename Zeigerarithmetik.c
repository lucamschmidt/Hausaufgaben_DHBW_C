#include <stdio.h>
#include <stdlib.h>

int main(){

    int len = 5;

    int *vec = malloc(sizeof(int)*len);

    printf("Values of vec: \n");
    for(int i = 0; i < len; i++){
        printf("Value %d = %d\n", i, vec[i]);
    }

    printf("\nAdress of vec hex: \n");
    for(int i = 0; i<len;i++){
        printf("mem(ptr[i]) = %p\n", &vec[i]);
    }
    printf("\nin dec: \n");
    for(int i = 0; i<len;i++) printf("mem(ptr[i]) = %d\n",&vec[i]);

    return 0;
}