#ifndef COMMANDS_H
#define COMMANDS_H

typedef struct _person{
    char name[20];
    char surname[20];
    int year;

    struct _person * next;

}person;

int addFront(person * root);
int printList(person * first);
int addEnd(person *root);
person * findPerson(person *first);
int deletePerson(person *first);

int addAfter(person *first);
int addBefore(person * root);
int saveFile(person * first);
int loadFile(person * root);

#endif
