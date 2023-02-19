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

//Quick Sort
int partion(int arr[], int lb, int ub){
    int piovt = arr[lb];
    int start = lb;
    int end = ub;
    
    while(start < end){
        while(arr[start] <= piovt){
            start++;
        }
        while(arr[end] > piovt){
            end--;
        }
        if(start < end){
            swap(&arr[start], &arr[end]);
        }
    }
    swap(&arr[lb],&arr[end]);
    return end;
}

void quickSort(int arr[], int lb, int ub){
    if(lb<ub){
        int loc = partion(arr, lb,ub);
        quickSort(arr,lb,loc-1);
        quickSort(arr,loc+1,ub);
    }
}

//Merge Sort
void merge(int arr[], int lb, int mid, int ub){
    int i = lb;
    int j = mid+1;
    int k = lb;
    int arrn[100000] = {};
    while(i <= mid && j <= ub){
        if(arr[i] <= arr[j]){
            arrn[k] = arr[i];
            i++;
        }
        else{
            arrn[k] = arr[j];
            j++;
        }
        k++;
    }
    if(i > mid){
        while(j <= ub){
            arrn[k] = arr[j];
            j++;
            k++;
        }
    }else{
        while(i <= mid){
            arrn[k] = arr[i];
            i++;
            k++;
        }
    }
}

void mergeSort(int arr[], int lb, int ub){
    if(lb<ub){
        int mid = (lb+ub)/2;
        mergeSort(arr, lb, mid);
        mergeSort(arr, mid+1, ub);
        merge(arr, lb , mid, ub);
    }
}

int main(){
    printf("\n");
    char *randNumders = "rNumber.txt";
    char *quicksort = "quick.txt";
    char *meregesort = "merge.txt";

    FILE *randnumfptr = fopen(randNumders, "w");
    FILE *sortednumfptr;

    int n = 100000;
    int a[n];
    
    int num, startTime, endTime, rangeTill;

    //Created random array
    printf("Generating random array");
    for(int i = 0; i < n; i++){
        fprintf(randnumfptr, "%d\n", rand());
    }
    fclose(randnumfptr);

    //Quick sort
    // randnumfptr = fopen(randNumders, "r");
    // printf("\nReading random array");
    // for(int i = 0; i < n; i++){
    //     fscanf(randnumfptr, "%d" , &a[i]);
    // }
    // fclose(randnumfptr);
    // printf("\nDone\n");
    // rangeTill = 100;

    // printf("QuickSort\n");
    // sortednumfptr = fopen(quicksort, "w");
    // printf("Sorted numbers stored in (%s)",quicksort);

    // while(rangeTill <= n){
    //     startTime = clock();
    //     quickSort(a, 0,rangeTill);
    //     endTime = clock();
    //     fprintf(sortednumfptr, "%d\n",endTime-startTime);
    //     rangeTill += 100;
    // }
    // fclose(sortednumfptr);
    // printf("\nQuick sort done");

    
    //Merge Sort
    randnumfptr = fopen(randNumders, "r");
    printf("\nReading random array");
    for(int i = 0; i < n; i++){
        fscanf(randnumfptr, "%d", &a[i]);
    }
    fclose(randnumfptr);

    printf("\nDone\n");
    rangeTill = 100;

    printf("mergesort\n");
    sortednumfptr = fopen(meregesort, "w");
    printf("Sorted numbers stored in (%s)",meregesort);

    while(rangeTill <= n){
        startTime = clock();
        mergeSort(a , 0 , rangeTill);
        endTime = clock();
        fprintf(sortednumfptr, "%d\n", endTime-startTime);
        rangeTill += 100;
    }
    fclose(sortednumfptr);
    printf("\nmerge sort done");
    return 0;
}

