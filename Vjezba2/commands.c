#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "commands.h"

int addFront(person * root){
    
    person * newPerson = (person*)malloc(sizeof(person));

    char ime[20];
    char prezime[20];

    if(newPerson == NULL){
        return -1;
    }
    
    printf("Insert name: ");
    fgets(ime,20,stdin);

    ime[strcspn(ime,"\n")] = '\0';

    strcpy(newPerson->name,ime);

    printf("Insert surname: ");
    fgets(prezime,20,stdin);

    prezime[strcspn(prezime,"\n")] = '\0';

    strcpy(newPerson->surname,prezime);

    printf("Insert year of birth: ");
    scanf("%d",&(newPerson->year));
    getchar();

    newPerson->next = root->next;
    root->next = newPerson;



    return 0;
}

int printList(person * first){
    person * curr;

    for(curr=first;curr!=NULL;curr=curr->next){
        printf("%s %s %d\n",curr->name,curr->surname,curr->year);
    }

    return 0;

}

int addEnd(person *root){

    person * newPerson = (person*)malloc(sizeof(person));

    char ime[20];
    char prezime[20];
    person *curr= NULL;

    if(newPerson == NULL){
        return -1;
    }
    
    printf("Insert name: ");
    fgets(ime,20,stdin);

    ime[strcspn(ime,"\n")] = '\0';

    strcpy(newPerson->name,ime);

    printf("Insert surname: ");
    fgets(prezime,20,stdin);

    prezime[strcspn(prezime,"\n")] = '\0';

    strcpy(newPerson->surname,prezime);

    printf("Insert year of birth: ");
    scanf("%d",&(newPerson->year));
    getchar();

    for(curr=root;curr->next!=NULL;curr=curr->next);

    curr->next = newPerson;
    newPerson->next = NULL;

    return 0;
}

person * findPerson(person * first){
    char prezime[20];

    printf("Insert the surname of such person: ");
    fgets(prezime,20,stdin);

    prezime[strcspn(prezime,"\n")] = '\0';

    person * curr = NULL;

    for(curr = first; curr != NULL; curr=curr->next){
        if(strcmp(curr->surname,prezime)==0) break;
    }

    if(curr == NULL){
        return NULL;
    }

    return curr;

}

int deletePerson(person *root){

    person * toDelete;

    person * curr;

    if((toDelete=findPerson(root->next)) == NULL){
        return -1;
    }

    /* kreni od prvog u nizu, dođi do onog člana prije onog kojeg brišemo */
    for(curr=root;curr->next != toDelete; curr = curr->next);

    curr->next = toDelete->next;
    free(toDelete);

    printf("Person deleted!\n");

    return 0;

}