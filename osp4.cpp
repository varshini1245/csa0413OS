#include <stdio.h>

int main() {
    // Initialize the resource matrices and vectors
    int claim[4][3] = {{3, 2, 2}, {6, 1, 3}, {3, 1, 4}, {4, 2, 2}};
    int allocation[4][3] = {{1, 0, 0}, {6, 1, 2}, {2, 1, 1}, {0, 0, 2}};
    int resource[3] = {9, 3, 6};
    int available[3] = {0, 0, 0};

    // Calculate the available resources
    for (int j = 0; j < 3; j++) {
        for (int i = 0; i < 4; i++) {
            available[j] += allocation[i][j];
        }
        available[j] = resource[j] - available[j];
    }

    // Initialize the finish array and the safe sequence array
    int finish[4] = {0, 0, 0, 0};
    int safe_sequence[4];
    int num_finished = 0;

    // Loop until all processes are finished or there is no safe sequence
    while (num_finished < 4) {
        int safe_found = 0;

        // Check each process to see if it can be safely finished
        for (int i = 0; i < 4; i++) {
            if (!finish[i]) {
                int can_finish = 1;
                for (int j = 0; j < 3; j++) {
                    if (claim[i][j] - allocation[i][j] > available[j]) {
                        can_finish = 0;
                        break;
                    }
                }
                if (can_finish) {
                    // Add the process to the safe sequence and update the available resources
                    safe_sequence[num_finished] = i;
                    num_finished++;
                    finish[i] = 1;
                    for (int j = 0; j < 3; j++) {
                        available[j] += allocation[i][j];
                    }
                    safe_found = 1;
                }
            }
        }
    }
	}
