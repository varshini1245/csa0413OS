#include <stdio.h>
#define MAX_PARTITIONS 6
#define MAX_PROCESSES 5
int partitions[MAX_PARTITIONS] = {300, 600, 350, 200, 750, 125};
int processes[MAX_PROCESSES] = {115, 500, 358, 200, 375};
int allocation[MAX_PROCESSES];
void best_fit()
{
int i, j;
int best_index;
for (i = 0; i < MAX_PROCESSES; i++) {
best_index = -1;
for (j = 0; j < MAX_PARTITIONS; j++) {
if (partitions[j] >= processes[i]) {
if (best_index == -1) {
best_index = j;
} else if (partitions[j] < partitions[best_index]) {
best_index = j;
}
}
}
if (best_index != -1) {
allocation[i] = best_index;
partitions[best_index] -= processes[i];
} else {
allocation[i] = -1;
}
}
}
void print_allocation()
{
int i;
printf("\nProcess No.\tProcess Size\tPartition No.\n");
for (i = 0; i < MAX_PROCESSES; i++) {
printf("%d\t\t%d\t\t", i+1, processes[i]);
if (allocation[i] != -1) {
printf("%d\n", allocation[i]+1);
} else {
printf("Not Allocated\n");
}
}
}
int main()
{
best_fit();
print_allocation();
return 0;
}
