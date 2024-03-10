// Reading random numbers from a file in C 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// function to swap two numbers 
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp; 
}

// Selection sort function
void selectionSort(int arr[20000],int n)
{
    int i, j, min_idx;
    for (i=0; i< n-1; i++){
        min_idx=i;
        for (j=i+1;j<n;j++){
            if (arr[j]< arr[min_idx]){
                min_idx = j;
            }
        }
        if (min_idx !=i ){
            swap(&arr[i],&arr[min_idx]);
        }
    }
}
// Bubble sort function
void bubbleSort(int arr[20000],int n){
    int i,j;
    for (i=0;i < n-1;i++){
        for (j=0;j<n-1;j++){
            if (arr[j]> arr[j+1]){
                swap(&arr[j],&arr[j+1]);
            }
        }
    }
}

// Insertion sort function
void insertionSort(int arr[20000],int n){
    int i, key,j;
    for (i=1;i<n;i++){
        key = arr[i];
        j=i-1;
        while (j >= 0 && arr[j]> key)
        {
            arr[j+1] = arr[j];
            j=j-1;
        }
        arr[j+1] = key;
    }
}

// Quick sort function
int partition(int arr[20000],int low ,int high){
    int pivot = arr[high];
    int i = (low -1);

    for (int j = low ; j <= high-1 ; j++){
        if (arr[j] < pivot){
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[high]);
    return (i+1);
}

void quicksort(int arr[20000],int low , int high){
    if (low < high){
        int pi = partition(arr,low,high);
        quicksort(arr,low,pi-1);
        quicksort(arr,pi+1,high);
    }
}


// Heap sort function
void heapify(int arr[20000],int n, int i){
    int largest =i;
    int left = 2*i+1;
    int right = 2*i+2;

    if (left < n && arr[left] > arr[largest]){
        largest = left;
    }
    if (right <n && arr[right] > arr[ largest ]){
        largest = right;
    }
    if (largest != i){
        swap(&arr[i], &arr[largest]);
        heapify(arr,n,largest);
    }
}

void heapsort(int arr[20000],int n){
    for (int i = n/2 -1 ; i >=0; i--){
        heapify(arr,n,i);
    }
    for (int i=n-1;i >= 0 ; i--){
        swap(&arr[0],&arr[i]);
        heapify(arr,i,0);
    }
}


int main()
{
    int i,n;
    int arr[20000];
    FILE *file = fopen("random_numbers.txt", "w");

    // Use current time as seed for random generator
    srand(time(NULL));

    for (i = 0; i < n; i++)
    {
        fprintf(file,"%d\n", rand() % 1000);
    }

    // Close the file
    fclose(file);
    // Open the file "random_numbers.txt" for reading

    fopen("random_numbers.txt", "r");

    // Read the number of random numbers to be generated

    for (int i=0;i<20000;i++){
        fscanf(file,"%d",&arr[i]);
    }
    // Close the file
    fclose(file);

    clock_t start, end;
    double cpu_time_used;
    int numbers_copy[20000];
    memcpy(numbers_copy, arr, sizeof(arr));

    // Selection sort
    start = clock();
    selectionSort(numbers_copy,20000);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken for selection sort: %f\n", cpu_time_used);

    memcpy(numbers_copy, arr, sizeof(arr));

    // Bubble sort
    start = clock();
    bubbleSort(numbers_copy,20000);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken for bubble sort: %f\n", cpu_time_used);

    memcpy(numbers_copy, arr, sizeof(arr));

    // Insertion sort
    start = clock();
    insertionSort(numbers_copy,20000);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken for insertion sort: %f\n", cpu_time_used);

    memcpy(numbers_copy, arr, sizeof(arr));

    // Quick sort
    start = clock();
    quicksort(numbers_copy,0,20000-1);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken for quick sort: %f\n", cpu_time_used);

    memcpy(numbers_copy, arr, sizeof(arr));

    // Heap sorti
    start = clock();
    heapsort(numbers_copy,20000);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken for heap sort: %f\n", cpu_time_used);
    
    return 0;
}