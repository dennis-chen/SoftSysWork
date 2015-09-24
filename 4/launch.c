#include <stdio.h>
#include "launch.h"
#include "thruster.h"

int main(){
    beginLaunch();
    thrust();
    return 0;
}

void beginLaunch(){
    printf("Begin the launch!\n");
}
