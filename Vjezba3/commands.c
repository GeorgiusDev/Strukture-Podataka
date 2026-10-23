#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "commands.h"

/* ################ funkcije s proslog zadatka ##################### */

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

/* ##################### nove funkcije ################### */

int addAfter(person *first){
    person *found;

    if((found=findPerson(first)) == NULL){
        return -1;
    }

    person * newPerson = (person*)malloc(sizeof(person));

    char ime[20];
    char prezime[20];
    person *curr= NULL;

    if(newPerson == NULL){
        return -2;
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

    newPerson->next=found->next;
    found->next=newPerson;
    return 0;
}

int addBefore(person * root){
    person * curr;
    char buffer[20];

    printf("Enter surname, you wish to put this object before: ");
    fgets(buffer,20,stdin);

    buffer[strcspn(buffer,"\n")] = '\0';

    for(curr=root;curr!=NULL;curr=curr->next){
        if(curr->next!=NULL){
            if (strcmp(curr->next->surname,buffer)==0) break;
        }
    }

    if (curr==NULL){
        printf("Person not found!");
        return -2;
    }
    
    char ime[20];
    char prezime[20];
    person * newPerson = (person*)malloc(sizeof(person));
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

    newPerson->next = curr->next;
    curr->next=newPerson;

    return 0;
}

int saveFile(person * first){
    int n=0;
    person *curr;

    for(curr=first;curr!=NULL;curr=curr->next){
        n++;
    }

    FILE *f = fopen("lista.txt","w");

    if (f == NULL){
        return -1;
    }

    fprintf(f,"%d\n",n);

    for(curr=first;curr!=NULL;curr=curr->next){
        fprintf(f,"%s %s %d\n",curr->name,curr->surname,curr->year);
    }

    fclose(f);

    return 0;

}

int loadFile(person * root){

    int n;
    person * curr;

    FILE *f = fopen("lista.txt","r");

    char name[20],surname[20];
    int year;

    if(f==NULL){
        return -1;
    }

    if(fscanf(f,"%d",&n) != 1){
        fclose(f);
        return -1;
    }

    if(n == 0){
        printf("The list is empty!");
        fclose(f);
        return 0;
    }


    curr=root;
    while(fscanf(f,"%s %s %d",name,surname,&year)==3){

        person *newPerson=(person *)malloc(sizeof(person));
        if(newPerson == NULL){
            printf("Malloc error!");
            fclose(f);
            exit(1);
        }

        strcpy(newPerson->name,name);
        strcpy(newPerson->surname,surname);
        newPerson->year = year;
        newPerson->next = NULL;

        curr->next = newPerson;
        curr=curr->next;


    }

    fclose(f);

    return 0;
}