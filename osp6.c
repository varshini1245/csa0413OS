#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define P 3
#define R 3
void print_matrix(int matrix[P][R]) {
    for (int i = 0; i < P; i++) {
        for (int j = 0; j < R; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
void find_deadlock(int max_matrix[P][R], int alloc_matrix[P][R], int avail_resources[R]) {
    bool finish[P] = {false};
    int work[R];
    int need_matrix[P][R];
    for (int i = 0; i < R; i++) {
        work[i] = avail_resources[i];
    }
    for (int i = 0; i < P; i++) {
        for (int j = 0; j < R; j++) {
            need_matrix[i][j] = max_matrix[i][j] - alloc_matrix[i][j];
        }
    }
    int count = 0;
    int safe_sequence[P];
    while (count < P) {
        bool found = false;
        for (int i = 0; i < P; i++) {
            if (!finish[i]) {
                int j;
                for (j = 0; j < R; j++) {
                    if (need_matrix[i][j] > work[j]) {
                        break;
                    }
                }
                if (j == R) {
                    for (int k = 0; k < R; k++) {
                        work[k] += alloc_matrix[i][k];
                    }
                    finish[i] = true;
                    found = true;
                    safe_sequence[count] = i;
                    count++;
                }
            }
        }
        if (!found) {
            printf("System is in deadlock state\n");
            printf("Deadlocked processes are: ");
            for (int i = 0; i < P; i++) {
                if (!finish[i]) {
                    printf("P%d ", i+1);
                }
            }
            printf("\n");
            return;
        }
    }
    printf("System is not in deadlock state\n");
    printf("Safe sequence is: ");
    for (int i = 0; i < P; i++) {
        printf("P%d ", safe_sequence[i]+1);
    }
    printf("\n");
}

int main() {
    int max_matrix[P][R] = {
        {3, 6, 8},
        {4, 3, 3},
        {3, 4, 4}
    };
    int alloc_matrix[P][R] = {
        {3, 3, 3},
        {2, 0, 3},
        {1, 2, 4}
    };
    int avail_resources[R] = {1, 2, 0};
    printf("Max Matrix:\n");
    print_matrix(max_matrix);
    printf("Allocation Matrix:\n");
    print_matrix(alloc_matrix);
    printf("Available resources: ");
    for (int i = 0; i < R; i++) {
        printf("%d ", avail_resources[i]);
    }
    printf("\n");
    find_deadlock(max_matrix, alloc_matrix, avail_resources);
    return 0;
}
/* OUTPUT 
Max Matrix:
3 6 8
4 3 3
3 4 4
Allocation Matrix:
3 3 3
2 0 3
1 2 4
Available resources: 1 2 0
System is in deadlock state
Deadlocked processes are: P1 P2 P3  */
