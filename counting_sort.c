#include <stdio.h>
#include <time.h>
#include<malloc.h>

// Function to simulate the algorithm whose computation time is being measured
void countingSort(int array[], int size) {
    int max = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] > max)
            max = array[i];
    }

    int *count = (int *)malloc((max + 1) * sizeof(int));
    int *output = (int *)malloc(size * sizeof(int));

    // Initialize count array with all elements as 0
    for (int i = 0; i <= max; ++i) {
        count[i] = 0;
    }

    // Store the count of each element
    for (int i = 0; i < size; i++) {
        count[array[i]]++;
    }

    // Store the cumulative count of each array
    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    // Build the output array
    for (int i = size - 1; i >= 0; i--) {
        output[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }

    // Copy the output array to array[], so that array[] now
    // contains sorted numbers
    for (int i = 0; i < size; i++) {
        array[i] = output[i];
    }

    free(count);
    free(output);
}


// Function to measure computation time of the algorithm
double measure_computation_time() {
    clock_t start_time, end_time;
    double computation_time;

    start_time = clock();
    countingSort(); // Call the algorithm
    end_time = clock();

    computation_time = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
    return computation_time;
}

int main() {
    double time_taken = measure_computation_time();
    
    printf("Computation time for the algorithm: %f seconds\n", time_taken);
    
    return 0;
}