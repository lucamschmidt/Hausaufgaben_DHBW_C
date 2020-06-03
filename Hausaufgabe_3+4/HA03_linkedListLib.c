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
        int i = 1;
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
    if (start->nextElem == NULL) printf ("\n>> list is empty\n\n");
    else{
    
        int idxToDel = 0;

        printList(start);
        printf("please enter index of list element to delete...\n");
        scanf("%d", &idxToDel);

        if(getLenOfList(start) < idxToDel){
            printf("can't delete element with idx %d. list idx ends at %d\n",idxToDel,getLenOfList(start));
            return;
        }

        listElement *currElem = start;
        listElement *delElem = start;         //no need to pass start

        for(int i = 0; i < idxToDel; i++){
            currElem = currElem->nextElem;
        }
        delElem = currElem->nextElem;
        currElem->nextElem = (currElem->nextElem)->nextElem;    //alternativ: currELem->nextElem = delElem->nextElem
        free(delElem);
    }

}

void delList(listElement *start){

    if (start->nextElem == NULL) printf ("\n>> list is empty\n\n");
    else{
        listElement *currElem = start;
        listElement *delElem = start;
        while(currElem->nextElem != NULL) {
            delElem = currElem->nextElem;
            currElem->nextElem = (currElem->nextElem)->nextElem;
            free(delElem);
        } 
        printf(">> list has been deleted!\n");
    }

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

    int saveFlagg = 0;

    printf("do you want to save the current list?\n");
    printf("[1] ... yes\n");
    printf("[0] ... no\n");
    scanf("%d",&saveFlagg);

    if (saveFlagg == 1) saveList(start);
    system("cls");

}

void sortList(listElement *start){

	int choice = 0;

    printf("sort by: \n");
    printf("[1] ... lastname\n");
    printf("[2] ... firstname\n");
    printf("[3] ... age\n");
    scanf("%d", &choice);

    switch(choice){

        case 1:

        { 
        int k = 0;
        int i = 0; 
        char temp[5];
        listElement * currElem = start;
        listElement * sortElem = NULL;  
        start = start->nextElem;
  
        if (start->nextElem == NULL) printf ("\n>> list is empty\n\n");
        else{
  
        do
        { 
            k = 0; 
            currElem = start;             

            while ((currElem->nextElem)->nextElem != sortElem) 
            { 
                if (currElem->lastName[0] > (currElem->nextElem)->lastName[0]) 
                {  
                    temp[0] = currElem->lastName[0];
                    currElem->lastName[0] = sortElem->lastName[0];
                    sortElem->lastName[0] = temp[0];
                    k = 1; 
                } 
                currElem = currElem->nextElem; 
            } 
            sortElem = currElem; 
        } 
        while (k); 
        }
        }
  

        /*while(currElem->nextElem != NULL){

            for(int i = 0; i <= (strlen(currElem->lastName) || strlen((currElem->lastName)); i++){

                currElem = currElem->nextElem;
                sortElem1 = currElem->lastName[0];
                currElem = currElem->nextElem;
                sortElem2 = currElem->lastName[0];  

                if(sortElem)
            
                if(strcmp(sortElem1, sortElem2)>0){
                    strcpy(temp, sortElem1);            //Platzwechsel wenn links größer als rechts
                    strcpy(sortElem1, sortElem2);
                    strcpy(sortElem2, temp);
                }
            }
        }
    }
        break; 

        case 2:

        while(currElem->nextElem != NULL){

            for(int i = 0; i <= (strlen(((currElem->nextElem)->nextElem)->firstName) || strlen((currElem->nextElem)->firstName)); i++){

                sortElem = ((currElem->nextElem)->nextElem)->firstName[i];
                currElem = (currElem->nextElem)->firstName[i];        
            
                if(strcmp(currElem, sortElem)>0){
                    strcpy(temp, currElem);            //Platzwechsel wenn links größer als rechts
                    strcpy(currElem, sortElem);
                    strcpy(sortElem, temp);
                }
            }
        }

        break;        

        case 3: 

        while(currElem->nextElem != 0)

            for(int i = 0; i <= getLenOfList(start); i++){

                sortElem = ((currElem->nextElem)->nextElem)->age;
                currElem = (currElem->nextElem)->age;       

                if(currElem > sortElem){
                    tempdouble = currElem;            //Platzwechsel wenn links größer als rechts
                    currElem = sortElem;
                    sortElem = tempdouble;
                }
            }
        break;

        default: printf("invalid choice\n"); break;
    */
    }

}

void stringToLower(char *string) {
    
	int i;
	int len = strlen(string); // is part of string.h
	for(i=0; i<len; i++) {
		if(string[i] >= 'A' && string[i] <= 'Z') {
			string[i] += 32;
		}
	}

}
/*
JW-2020-05-27:
--------------
> well done (10/10) 
> how much time did you spend on this exercise? I think it was a litte to easy wasnt it?
*/





