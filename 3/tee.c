#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void printArr(FILE *a[], int len){
    for(int i = 0; i < len; i++){
        printf("%p\n",a[i]);
    }
}

int main(int argc, char *argv[]){

    //read options
    char ch;
    bool append;
    while((ch = getopt(argc, argv, "ai")) != EOF){
        switch(ch) {
            case 'a':
                append = true;
                break;
            case 'i':
                printf("case i!");
                break;
        }
    }
    argc -= optind;
    argv += optind;

    //open files that tee will output to
    FILE *writeFiles[argc];
    for(int i = 0; i < argc; i++){
        if(append){
            writeFiles[i] = fopen(argv[i],"a");
        } else {
            writeFiles[i] = fopen(argv[i],"w");
        }
    }

    //take input
    char line[80];
    while (scanf("%79[^\n]", line) == 1){
        //write to files and stdout
        for(int i = 0; i < argc; i++){
            fprintf(writeFiles[i], "%s\n", line);
        }
        fprintf(stdout, "%s\n", line);
    }

    //close files
    for(int i = 0; i < argc; i++){
        fclose(writeFiles[i]);
    }

}
