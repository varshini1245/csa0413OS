#include <stdio.h>

// Structure to represent a memory block
typedef struct {
    int size;
    int allocated;
} MemoryBlock;

// Function to allocate memory using worst-fit algorithm
void worstFit(MemoryBlock memory[], int numBlocks, int processSize) {
    int worstFitIdx = -1;  // Index of the block with the worst fit
    int i;

    // Find the block with the worst fit
    for (i = 0; i < numBlocks; i++) {
        if (!memory[i].allocated && memory[i].size >= processSize) {
            if (worstFitIdx == -1 || memory[i].size > memory[worstFitIdx].size) {
                worstFitIdx = i;
            }
        }
    }

    // Allocate the process to the block with the worst fit
    if (worstFitIdx != -1) {
        memory[worstFitIdx].allocated = 1;
        printf("Allocated process of size %d KB to memory block %d\n", processSize, worstFitIdx + 1);
    } else {
        printf("Unable to allocate process of size %d KB\n", processSize);
    }
}

int main() {
    MemoryBlock memory[] = {
        {40, 0},  // Memory block 1
        {10, 0},  // Memory block 2
        {30, 0},  // Memory block 3
        {60, 0}   // Memory block 4
    };

    int numBlocks = sizeof(memory) / sizeof(memory[0]);

    int processSizes[] = {100, 50, 30, 120, 35};
    int numProcesses = sizeof(processSizes) / sizeof(processSizes[0]);

    // Allocate memory for each process
    for (int i = 0; i < numProcesses; i++) {
        worstFit(memory, numBlocks, processSizes[i]);
    }

    return 0;
}
