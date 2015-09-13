#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void printArray(int *a, int size){
    //prints out an array of integers
    printf("[");
    if(size == 0){
        printf("]");
        return;
    }
    for(int i = 0; i < size - 1; i++){
        printf("%d,",a[i]);
    }
    printf("%d",a[size - 1]);
    printf("]");
    printf("\n");
}


void printArrayRange(int *a, int start, int end){
    //prints out an array of integers
    printf("[");
    for(int i = start; i < end - 1; i++){
        printf("%d,",a[i]);
    }
    printf("%d",a[end - 1]);
    printf("]");
    printf("\n");
}

void swap(int *a, int i0, int i1){
    //swaps integer at a[i0] with integer at a[i1]
    int temp = a[i0];
    a[i0] = a[i1];
    a[i1] = temp;
}

int * shuffledArray(int len){
    //help from 
    //http://stackoverflow.com/questions/4173610/to-generate-array-of-random-numbers-in-a-given-range-in-c
    //generates a shuffled array of integers of length len
    //containing vals in range [0,len)
    int *shuf = malloc(sizeof(int)*len);
    for(int i = 0; i < len; i++){
        shuf[i] = i;
    }
    for (int i = len - 1; i > 0; --i) {
        // generate random index
        int w = rand()%i;
        // swap items
        swap(shuf, w, i);
    }
    return shuf;
}

void bubbleSort(int *a, int size){
    if(size <= 1){
        return;
    }
    int i = 0;
    while(i < size - 1){
        if(a[i] > a[i+1]){
            swap(a, i, i+1);
            i = 0;
        } else {
            i++;
        }
    }
}

void arrayCopy(int *from, int *to, int start, int end){
    for(int i = start; i < end; i++){
        to[i] = from[i];
    }
}

void mergeSortHelper(int *a, int *aHelper, int start, int end){
    if(start >= end - 1){
        //one element only, already sorted
        return;
    }
    int middle = (end+start)/2;
    //sort left half
    mergeSortHelper(a, aHelper, start, middle);
    //sort right half
    mergeSortHelper(a, aHelper, middle, end);
    //merge the two halves
    int empty = start;
    int left = start;
    int right = middle;
    while(left < middle && right < end){
        if(a[left] < a[right]){
            aHelper[empty] = a[left];
            left++;
        } else {
            aHelper[empty] = a[right];
            right++;
        }
        empty++;
    }
    //copy any remaining elements
    while(left < middle){
        aHelper[empty] = a[left];
        empty++;
        left++;
    }
    while(right < end){
        aHelper[empty] = a[right];
        empty++;
        right++;
    }
    //copy from helper array back to original now that it's merged
    arrayCopy(aHelper, a, start, end);
}

void mergeSort(int *a, int size){
    int *helper = malloc(sizeof(int)*size);
    mergeSortHelper(a, helper, 0, size);
}

void testSortSpeed( void(*sort)(int *a, int size), 
                    int trialRuns, int arraySize){
    int total = 0, start = 0, end = 0;
    for(int i = 0; i < trialRuns; i++){
        int *test = shuffledArray(arraySize);
        start = clock();
        (*sort)(test, arraySize);
        end = clock();
        total += end - start;
    }
    double avgTime = total * 1.0 / trialRuns;
    printf("Average runtime of %f clock ticks over %d trials\n"
            , avgTime, trialRuns);
}

int main(){
    int trialRuns = 1000;
    int arraySize = 100;

    printf("Testing Bubble Sort:\n");
    void(*bubbleSortP)(int *a, int size) = &bubbleSort;
    testSortSpeed(bubbleSortP, trialRuns, arraySize);

    printf("Testing Merge Sort:\n");
    void(*mergeSortP)(int *a, int size) = &mergeSort;
    testSortSpeed(mergeSortP, trialRuns, arraySize);

    printf("Hooray for merge sort!\n");

    return 0;
}
