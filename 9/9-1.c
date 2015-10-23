#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void callSystemMkdir(char *dirName){
    char command[120];
    sprintf(command, "mkdir %s", dirName);
    system(command);
}

void testSystemFun(){
    char dirName[80];
    printf("Enter a new directory name: ");
    fgets(dirName, 80, stdin);
    callSystemMkdir(dirName);
}

void testExecl(){
    execlp("python","python","argumentReader.py", "a", "b", "c",
            "d", NULL);
    char *env[] = {"TEST=99", NULL};
    execle("/usr/bin/python","/usr/bin/python","argumentReaderEnv.py",
            NULL,env);
}

int main ()
{
    testExecl();
    //testSystemFun();
    return 0;
}
