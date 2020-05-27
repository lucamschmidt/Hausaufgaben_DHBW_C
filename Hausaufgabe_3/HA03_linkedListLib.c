#include <stdio.h>                                                                          //Hausaufgabe von Moritz Bieg und Luca Schmidt
#include <stdlib.h>                                                                         //Datum: 27.05.2020
#include <string.h>
#include "HA03_linkedListLib.h"

void addListElem(listElement *start){
    
    listElement * new;
    new = (listElement *)malloc(sizeof(listElement));
    if (new == NULL) {
        printf("can't reserve storage.\n"); 
        return;
        }

    listElement * currElem = start;
    while (currElem->nextElem != NULL) currElem = currElem->nextElem;// get last elem in list
    currElem->nextElem = new; // add new to the end of list
    new->nextElem = NULL;
    
    /* fill data in new element */
    printf("Please enter last name: \n");
    scanf("%s",new->lastName);
    printf("Please enter first name: \n");
    scanf("%s",new->firstName);
    printf("Please enter age: \n");
    scanf("%d",&(new->age));
    printf("end of function\n");
}

void printList(listElement *start){
    if (start->nextElem == NULL) printf ("\n>> list is empty\n\n");
    else{
        int i = 0;
        listElement *currElem = start;
        printf("\n>> current list:\n\n");
            do {
                currElem = currElem->nextElem;
                printf("%d.)",i); i++;
                printf("\tlast Name: %s\n",currElem->lastName);
                printf("\tfirst Name: %s\n",currElem->firstName);
                printf("\tage : %d\n",currElem->age);
            } while (currElem->nextElem != NULL);
    printf("\n");
    }
}

void delListElem(listElement *start){

    printf("\n>> delListElem fcn is tbd.\n\n");

}

void delList(listElement *start){

    printf("\n>> getLenOfList fcn is tbd.\n\n");

}

int getLenOfList(listElement *start){ // we use this for save list fcn

    int counter = 0;
    listElement * currElem = start;
    while (currElem->nextElem != NULL) {// get last elem in list
        currElem = currElem->nextElem; counter++;
        }
    return counter;
}

void saveList(listElement *start){

	char filename[50];
	printf("\n >> saving data...\n\n");
	printf("filename without extension: ");
	scanf("%s",filename);
	strcat(filename, ".txt"); // adding .txt to file name
	
	FILE * fPtr;
    fPtr = fopen(filename, "w");
    if (fPtr == NULL){
        printf("Could not open file!\n");
        return;
    }
    else{
        int lenght = getLenOfList(start);
        fprintf(fPtr, "%d\n", lenght);
        listElement *currElem = start;
            while(lenght > 0) {
                currElem = currElem->nextElem;
                fprintf(fPtr, "%s\n", currElem->lastName);
                fprintf(fPtr, "%s\n", currElem->firstName);      
                fprintf(fPtr, "%d\n", currElem->age);
                lenght --;
            }
        fclose(fPtr);
        printf("\n >> save completed!\n\n");
    }
}

void loadList(listElement *start){
	
	char filename[50];
	printf("\nloading data...\n\n");
	printf("availible data: \n----------------\n");
	system("dir /b *.txt"); // dir /b *.txt for windows | print availible *.txt files in current location
	printf("\nfilname without extension: ");
	scanf("%s",filename);
	strcat(filename, ".txt"); // adding .txt to file name
	
	FILE * fPtr;
	fPtr = fopen(filename, "r");
	
    int lenght = 0;

    if (fPtr == NULL){
        printf("Could not open file!\n");
        return;
    }
    else{
        fscanf(fPtr, "%d", &lenght);
        while(lenght>0){
        listElement * new;
        new = (listElement *)malloc(sizeof(listElement));
        if (new == NULL) {
            printf("can't reserve storage.\n"); 
            return;
        }

        listElement * currElem = start;
        while (currElem->nextElem != NULL) currElem = currElem->nextElem;
        currElem->nextElem = new;
        new->nextElem = NULL;

        fscanf(fPtr, "%s",new->lastName);
        fscanf(fPtr, "%s",new->firstName);
        fscanf(fPtr, "%d",&(new->age));
        lenght --;
        } 
    }

	fclose(fPtr);
	printf("\nloading data will be append to current list...\n");
	printList(start); 
}

void exitFcn(listElement *start){

    printf("\n>> exitFcn fcn is tbd.\n\n");

}

void sortList(listElement *start){
	
	printf("\n>>sortList fcn is tbd.\n\n");
    
}

void stringToLower(char *string) {
	
    printf("\n>>stringToLower fcn is tbd.\n\n");

}
/*
JW-2020-05-27:
--------------
> well done (10/10) 
> how much time did you spend on this exercise? I think it was a litte to easy wasnt it?
*/





