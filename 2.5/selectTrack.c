#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printArray(char *a, int size){
    //prints out a c string
    printf("\"");
    for(int i = 0; i < size; i++){
        printf("%c",a[i]);
    }
    printf("\"");
    printf("\n");
}

char * sliceArray(char *a, int len, char toSlice){
    int i = 0;
    while(i < len - 1 && a[i] != toSlice){
        i++;
    }
    char *sliced = malloc(sizeof(char)*i);
    memcpy(sliced, a, i);
    sliced[i] = '\0';
    return sliced;
}

int main(){
    char tracks[][80] = {
        "apples",
        "bananas",
        "oranges",
        "horses and apples"
    };
    int trackLen = 80;
    int numTracks = sizeof(tracks)/sizeof(tracks[0]);
    printf("Search for a track: ");
    char search[trackLen];
    fgets(search, sizeof(search), stdin);
    char *searchStripped = sliceArray(search, trackLen, '\n');
    printf("Search results: \n");
    for(int i = 0; i < numTracks; i++){
        char *res = strstr(tracks[i], searchStripped);
        if(res){
            printf("%s\n",tracks[i]);
        }
    }
    return 0;
}
