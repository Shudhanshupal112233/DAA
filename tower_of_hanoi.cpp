// program to calculate the computation 
#include <stdio.h>
#include <time.h>

void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod) {
    if (n == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", from_rod, to_rod);
        return;
    }
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
    printf("Move disk %d from rod %c to rod %c\n", n, from_rod, to_rod);
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}

double measureTowerOfHanoiTime(int n) {
    clock_t start, end;
    double cpu_time_used;

    start = clock();
    towerOfHanoi(n, 'A', 'C', 'B');
    end = clock();

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    return cpu_time_used;
}

int main() {
    int n = 6; // Change the number of disks as needed

    printf("Number of disks: %d\n", n);
    printf("Time taken for Tower of Hanoi: %f seconds\n", measureTowerOfHanoiTime(n));

    return 0;
}