#include <stdio.h>
#include <string.h>

struct student
{
    // name
    char name[50];
    // anschrift
    char stadt[50];
    char strasse[100];
    int hausnummer;
    int plz;
    // größe
    double groesse;
};

void ausgabe(struct student person){
    printf("\nName = %s\n", person.name);
    printf("Stadt = %s\n", person.stadt);
    printf("Strasse = %s\n", person.strasse);
    printf("Hausnummer = %d\n", person.hausnummer);
    printf("PLZ = %d\n", person.plz);
    printf("Groesse = %.2lf\n\n", person.groesse);    
}


int main(){

    
    //create obj
    struct student person1;
    struct student studenten[2];
    
    //fill with data
    strcpy(person1.name, "Luca");
    strcpy(person1.stadt, "Balingen");
    strcpy(person1.strasse, "Rohrwiesenstrasse");
    person1.hausnummer = 23;
    person1.plz = 72336;
    person1.groesse = 1.77;

    strcpy(studenten[0].name, "Peter");
    strcpy(studenten[0].stadt, "Buxdehude");
    strcpy(studenten[0].strasse, "Lagistrasse");
    studenten[0].hausnummer = 385;
    studenten[0].plz = 93746;
    studenten[0].groesse = 1.20;

    strcpy(studenten[1].name, "Manne");
    strcpy(studenten[1].stadt, "naehe Stuttgart");
    strcpy(studenten[1].strasse, "da wo das vermurkste Haus steht");
    studenten[1].hausnummer = 1;
    studenten[1].plz = 71332;
    studenten[1].groesse = 1.70;

    ausgabe(person1);
    ausgabe(studenten[0]);
    ausgabe(studenten[1]);

    return 0;
}