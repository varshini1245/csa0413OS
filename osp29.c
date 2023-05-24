#include <stdio.h>
#include <stdbool.h>

#define NUM_PARTITIONS 4

// Structure to represent a memory partition
typedef struct {
    int size;
    bool allocated;
} Partition;

// Function to allocate memory using the first-fit algorithm
void firstFit(Partition partitions[], int numPartitions, int processSize) {
    int i;
    for (i = 0; i < numPartitions; i++) {
        if (!partitions[i].allocated && partitions[i].size >= processSize) {
            partitions[i].allocated = true;
            printf("Process of size %d KB allocated to partition %d.\n", processSize, i);
            return;
        }
    }
    printf("No suitable partition found for process of size %d KB.\n", processSize);
}

int main() {
    Partition partitions[NUM_PARTITIONS] = {
        {40, false},
        {10, false},
        {30, false},
        {60, false}
    };

    int processSizes[] = {100, 50, 30, 120, 35};
    int numProcesses = sizeof(processSizes) / sizeof(processSizes[0]);

    int i;
    for (i = 0; i < numProcesses; i++) {
        firstFit(partitions, NUM_PARTITIONS, processSizes[i]);
    }

    return 0;
}
