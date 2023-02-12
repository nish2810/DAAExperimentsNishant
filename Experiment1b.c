#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>

void swap(int*x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp; 
}

void printArray(int *arr, int n){
    for(int i = 0; i < n; i++){
        printf("%d\n", arr[i]);
    }
}

//Selection Sort
void selectionSortt(int *arr, int start, int size){
    for(int i = start; i < size; i++){
        int minIdx = i;
        for (int j = i; j < size; j++){
            if(arr[j] < arr[minIdx])
            {
                minIdx = j;
            }
            swap(&arr[i], &arr[minIdx]);
        }
        
    }
}

//Isertion Sort
void insertionSortt(int *arr, int start, int size){
    for(int i = start+1; i < size; i++){
        int temp = arr[i];
        int j = i - 1;
        while(j >= 0 && temp <= arr[j]){
            arr[j+1] = arr[j];
            j = j - 1;
        }
        arr[j+1] = temp;
    }
}

int main(){
    printf("\n");
    char *randNumders = "randNumber.txt";
    char *selectionSort = "selction.txt";
    char *insertionSort = "insertion.txt";

    FILE *randnumfptr = fopen(randNumders, "w");
    FILE *sortednumfptr;

    int n = 100000;
    int a[n];
    
    int num, startTime, endTime, rangeTill;

    //Created random array
    printf("Generating random array");
    for(int i = 0; i < n; i++){
        num = rand();
        fprintf(randnumfptr, "%d\n", num);
    }
    fclose(randnumfptr);

    //Insertion sort
    randnumfptr = fopen(randNumders, "r");
    printf("\nReading random array");
    for(int i = 0; i < n; i++){
        fscanf(randnumfptr, "%d" , &a[i]);
    }
    fclose(randnumfptr);
    printf("\nDone\n");
    rangeTill = 100;

    printf("Insertionsort\n");
    sortednumfptr = fopen(insertionSort, "w");
    printf("Sorted numbers stored in (%s)",insertionSort);

    while(rangeTill <= n){
        startTime = clock();
        insertionSortt(a, 0,rangeTill);
        endTime = clock();
        fprintf(sortednumfptr, "%d\n",endTime-startTime);
        rangeTill += 100;
    }
    fclose(sortednumfptr);
    printf("\nInsertion sort done");

    
    //Selection Sort
    randnumfptr = fopen(randNumders, "r");
    printf("\nReading random array");
    for(int i = 0; i < n; i++){
        fscanf(randnumfptr, "%d", &a[i]);
    }
    fclose(randnumfptr);

    printf("\nDone\n");
    rangeTill = 100;

    printf("Selectionsort\n");
    sortednumfptr = fopen(selectionSort, "w");
    printf("Sorted numbers stored in (%s)",selectionSort);

    while(rangeTill <= n){
        startTime = clock();
        selectionSortt(a , 0 , rangeTill);
        endTime = clock();
        fprintf(sortednumfptr, "%d\n", endTime-startTime);
        rangeTill += 100;
    }
    fclose(sortednumfptr);
    printf("\nSelection sort done");
    return 0;
}

