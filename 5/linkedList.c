#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    //from
    //http://stackoverflow.com/questions/
    //5551427/generic-data-type-in-c-void
    enum {
      typUndefined,
      typInt,           
      typUint,
      typString,
      typLong
    } iType;
    union
    {
        int i;
        unsigned int u;
        char* s;
        long l;
    } value;
} Data;

typedef struct NodeDataStruct{
    Data *data;
    struct NodeDataStruct *next;
} Node;

typedef struct {
    Node *head;
} LinkedList;

void printData(Data *d){
    switch(d->iType) {
        case typUndefined:
            printf("Undefined");
            break;
        case typInt:
            printf("%i",d->value.i);
            break;
        case typUint:
            printf("%d",d->value.u);
            break;
        case typString:
            printf("%s",d->value.s);
            break;
        case typLong:
            printf("%lu",d->value.l);
            break;
        default:
            break;
    }
}

void printLL(LinkedList *l){
    Node *n = l->head;
    while(n->next != NULL){
        printData(n->data);
        n = n->next;
        printf(", ");
    }
    printData(n->data);
    printf("\n");
}

*LinkedList getLL(int len){
    //returns LL of integers w/ length len

}

int main(){
    Data c = {.iType=typString, .value={.s="Hello!"}};
    Node tail = {.data=&c, .next=NULL};
    Data d = {.iType=typInt, .value={.i=123}};
    Node headerNode = {.data=&d, .next=&tail};
    LinkedList l = {.head=&headerNode};
    printLL(&l);
    return 0;
}
