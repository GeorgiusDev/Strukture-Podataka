#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "commands.h"

int main(){

    person root = {0};

    if(addFront(&root)==-1){
        printf("Malloc error!\n");
        return 1;
    }

    if(addFront(&root)==-1){
        printf("Malloc error!\n");
        return 1;
    }

    if(addEnd(&root)==-1){
        printf("Malloc error!\n");
        return 1;
    }

    printf("\n");

    printList(root.next);

    printf("\n");

    if(deletePerson(&root) == -1){
        printf("Person not found!\n");
    }

    printf("\n");

    printList(root.next);

    printf("\n");

    person * curr = &root;
    person * temp = curr->next;

    while(temp != NULL){
        curr=temp;
        temp=curr->next;
        free(curr);
    }
    
    curr = NULL;
    temp = NULL;

    return 0;
}