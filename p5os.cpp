#include <stdio.h>

int main() {
    int memory[] = {300, 600, 350, 200, 750, 125}; // memory partitions in KB
    int n = sizeof(memory)/sizeof(memory[0]); // number of memory partitions
    int process[] = {115, 500, 358, 200, 375}; // process sizes in KB
    int m = sizeof(process)/sizeof(process[0]); // number of processes
    int allocation[m]; // to store allocated memory partition index for each process, -1 indicates not allocated
    
    // Initialize allocation[] with -1
    for (int i = 0; i < m; i++)
        allocation[i] = -1;
    
    // First-fit algorithm
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (memory[j] >= process[i]) { // if memory partition is big enough
                allocation[i] = j; // allocate this memory partition to the process
                memory[j] -= process[i]; // reduce the available memory in this partition
                break; // go to next process
            }
        }
    }
    
    // Display the allocation table
    printf("Process No.\tProcess Size\tAllocated Block No.\n");
    for (int i = 0; i < m; i++) {
        printf("%d\t\t%d KB\t\t", i+1, process[i]);
        if (allocation[i] != -1)
            printf("%d\n", allocation[i]+1);
        else
            printf("Not Allocated\n");
    }
    
    return 0;
}
