#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Задача 15 Използвайки предишното упражнение, изведете
участниците подредени по азбучен ред*/

typedef char* String;
typedef struct participants{
    int id;
    String name;
    String familyName;
    int age;
}Participants;

Participants* fillParticipants(int number);
void printParticipants(Participants *part,int number);
Participants* sortParticipants(Participants *part,int number);

int main(void){

    int number;
    printf("Enter the number of the participants:\n");
    scanf("%d",&number);

    Participants *part = (Participants*)malloc(number*sizeof(Participants));
    part = fillParticipants(number);
    part = sortParticipants(part,number);
    printParticipants(part,number);

    return 0;
}

Participants* fillParticipants(int number){

    int i;
    Participants* fullList = (Participants*)malloc(number*sizeof(Participants));
    for(i=0;i<number;i++){
        (fullList+i)->name = (String)malloc(20*sizeof(char));
        (fullList+i)->familyName = (String)malloc(20*sizeof(char));
        printf("Enter the id of the participant:\n");
        scanf("%d",&(fullList+i)->id);
        printf("Enter the name of the participant:\n");
        scanf("%s",(fullList+i)->name);
        printf("Enter the family name of the participant:\n");
        scanf("%s",(fullList+i)->familyName);
        printf("Enter the age of the participant:\n");
        scanf("%d",&(fullList+i)->age);
    }

    return fullList;
}

void printParticipants(Participants *part,int number){

    int i;
    for(i=0;i<number;i++){
        printf("Id: %d\tName: %s\tFamily name: %s\tAge: %d\t\n",(part+i)->id,(part+i)->name,(part+i)->familyName,(part+i)->age);
    }
}

Participants* sortParticipants(Participants *part,int number){
   
    int i,j;
    Participants* sortedParticipants = (Participants*)malloc(number*sizeof(Participants));
    String temp = (String)malloc(20*sizeof(char));
    int integerSort;
    for(i=0;i<number - 1;i++){
        for(j=i+1;j<number - 1;j++){
            if(strcmp(((part+j)->name),(part+j+1)->name)>0){
                strcpy(temp,(part+j)->name);
                strcpy((part+j)->name,(part+j+1)->name);
                strcpy((part+j+1)->name,temp);
                strcpy(temp,(part+j)->familyName);
                strcpy((part+j)->familyName,(part+j+1)->familyName);
                strcpy((part+j+1)->familyName,temp);
                integerSort = (part+j)->id;
                (part+j)->id = (part+j+1)->id;
                (part+j+1)->id = integerSort;
                integerSort = (part+j)->age;
                (part+j)->age = (part+j+1)->age;
                (part+j+1)->age = integerSort;
            }
        }
    }

    return part;
}