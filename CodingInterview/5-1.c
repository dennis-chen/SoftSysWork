#include <stdio.h>
#include <stdlib.h>

short calculateParity(long num){
    //calculates parity of bit representation of a number
    short numOnes = 0;
    for(int i = 0; i < 64; i++){
        numOnes += num & 1;
        num = num >> 1;
    }
    return numOnes % 2;
}

short calculateParityFast(long num, short *lookup){
    //uses lookup tables to calculate parity of bits
    short paritySum = 0;
    long bitMask = 0xFF;
    for(int i = 0; i < 8; i++){
        paritySum += lookup[num & bitMask];
        num = num >> 8;
    }
    return paritySum % 2;
}

short* generateLookup(){
    short *table = (short*) malloc(sizeof(short)*256);
    for(long i = 0; i < 255; i++){
        table[i] = calculateParity(i);
    }
    return table;
}

int main(){
    long test = ((long)1) << 63;
    short parity = calculateParity(test);
    printf("%d\n",parity);
    return 0;
}
