#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "commands.h"

int sortList(person *root);

int main(){

    person root = {0};
    int status=0;
    char buffer[256];

    while(1){
        printf("$: ");

        fgets(buffer,256,stdin);
        buffer[strcspn(buffer,"\n")]='\0';

        if(strcmp(buffer,"addFront")==0){
            if(addFront(&root)==-1){
                printf("Malloc error!\n");
                return 1;
            }
        }

        else if(strcmp(buffer,"addEnd")==0){
            if(addEnd(&root)==-1){
                printf("Malloc error!\n");
                return 1;
            }
        }

        else if(strcmp(buffer,"printList")==0) printList(root.next);

        else if(strcmp(buffer,"deletePerson")==0){
            if(deletePerson(&root) == -1){
                printf("Person not found!\n");
                continue;
            }
        }

        else if(strcmp(buffer,"addAfter")==0){
            if(status=(addAfter(root.next)==-1)){
                printf("Person not found!\n");
                continue;

            }
            else if(status==-2){
                printf("Malloc error!\n");
                return 1;
            }
        }

        else if(strcmp(buffer,"exit")==0) break;

        else if (strcmp(buffer,"addBefore") == 0){
                if(addBefore(&root)==-1 ){
                    printf("Malloc Error!\n"); 
                    return 1;
            }
        }

        else if(strcmp(buffer,"sortList")==0){
            if(sortList(&root) == -1){
                printf("The list is empty, nothing to sort!\n");
                continue;
            }
        }

        else if(strcmp(buffer,"saveFile")==0){
            if(saveFile(root.next)==-1){
                printf("fatal error occured!");
                continue;
            }
        }

        else if(strcmp(buffer,"loadFile")==0){
            if(loadFile(&root) == -1){
                printf("File not found, or incorrectly formated!\n");
                continue;
            }
        }

        else printf("Unknown command\n");

    }

    /* ########## memory cleanup ########## */

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

int sortList(person *root){
    person *j;
    person *k = root;
    int swapped = 0,n=0,i;

    if (root->next == NULL){
        return -1;
    }

    for(j=root->next;j!=NULL;j=j->next) n++;

    for(i=0;i<n;i++){
        swapped = 0;
        k = root;

        for(j=root->next;j->next!=NULL; ){

            if(strcmp(j->surname,j->next->surname)>0){
                person * temp = j->next;

                j->next = temp->next;
                temp->next = j;
                k->next = temp;

                swapped = 1;

                k = temp;
            }
            else {
                k = j;
                j = j->next;
            }

        }
        if(swapped == 0) break;
    }

    return 0;


}