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

LinkedList * getLL(int len){
    //returns LL of integers w/ length len
    LinkedList *l = malloc(sizeof(LinkedList));
    Data *headData  = malloc(sizeof(Data));
    headData->iType = typInt;
    headData->value.i = 0;
    Node *head = malloc(sizeof(Node));
    head->data = headData;
    Node *n = head;
    for(int i = 1; i < len; i++){
     Data *newData  = malloc(sizeof(Data));
     newData->iType = typInt;
     newData->value.i = i;
     Node *newNode = malloc(sizeof(Node));
     newNode->data = newData;
     n->next = newNode;
     n = n->next;
    }
    l->head = head;
    return l;
}

void reverseLL(LinkedList *l){
    Node *prev = NULL;
    Node *n = l->head;
    while(n->next != NULL){
        Node *temp = n->next;
        n->next = prev;
        prev = n;
        n = temp;
    }
    n->next = prev;
    l->head = n;
}

int main(){
    LinkedList *l = getLL(5);
    printLL(l);
    reverseLL(l);
    printLL(l);
    return 0;
}
