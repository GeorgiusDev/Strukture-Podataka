#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max_brb 80

typedef struct _Student{
    char ime[50];
    char prezime[50];
    int bodovi;
}Student;

float rel_vr(int n);

int main(){
    Student * studenti;
    int n,i;
    n=0;

    char buffer[256];

    FILE *f = fopen("studenti.txt","r");
    if(f == NULL){
        printf("File not found!\n");
        return 1;
    }

    /* također je moguće napravit fscanf() i onda "realloc"om povećavati listu 
     * što je sigurnije od fgets-a! */

    while(fgets(buffer,256,f)){
        n++;
    }
    
    studenti = (Student *)malloc(n*sizeof(*studenti));

    rewind(f);

    for(i=0;i<n;i++){
        fscanf(f,"%s %s %d",(studenti+i)->ime,(studenti+i)->prezime,&(studenti+i)->bodovi);

        printf("Student: %s %s\nBodovi: %d\nRelativni Bodovi: %f\n\n",
        (studenti+i)->ime,
        (studenti+i)->prezime,
        (studenti+i)->bodovi,
        rel_vr((studenti+i)->bodovi));

    }

}

float rel_vr(int n){
    return ((float)n/max_brb)*100;
}