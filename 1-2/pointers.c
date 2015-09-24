#include <stdio.h>

void decrement(int *loc){
    *loc = *loc - 1;
}

void printSizeOf(char msg[]){
    printf("\n");
    printf("in printSizeOf\n");
    printf("Message reads: %s\n", msg);
    printf("Message cut: %s\n", msg+7);
    //printf("msg occupies %lu bytes\n", sizeof(msg));
    //printf("the msg variable holds %p\n",msg);
    //printf("the msg variable address location is stored at %p\n",&msg);
    //printf("the size of msg is %s\n", sizeof(msg));
}

int main(){
    char msg[] = "asdfsdfsdf";
    printf("msg is at: %p\n", msg);
    printf("msg + 1 is at: %p\n", msg + 1);
    //printf("msg occupies %lu bytes\n", sizeof(msg));
    //printf("the msg variable holds %p\n",msg);
    //printf("the msg variable dereferenced is stored at %p\n",&msg);
    printSizeOf(msg);
    //char *location = &msg;
    //printf("the size of msg is %s\n", sizeof(location));
    //printSizeOf(msg);
    return 0;
}
