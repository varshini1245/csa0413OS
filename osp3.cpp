#include<stdio.h>

int main() {
    int n = 4;
    int bt[] = {6, 8, 7, 3};
    int p[] = {1, 2, 3, 4};
    int wt[n], tat[n], total_wt = 0, total_tat = 0;

    // Sort the processes based on their burst times using bubble sort
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if(bt[i] > bt[j]) {
                int temp_bt = bt[i];
                bt[i] = bt[j];
                bt[j] = temp_bt;
                int temp_p = p[i];
                p[i] = p[j];
                p[j] = temp_p;
            }
        }
    }

    // Calculate waiting time of each process
    wt[0] = 0;
    for(int i=1; i<n; i++) {
        wt[i] = wt[i-1] + bt[i-1];
    }

    // Calculate turnaround time of each process
    for(int i=0; i<n; i++) {
        tat[i] = bt[i] + wt[i];
    }

    // Display the result
    printf("Process   Burst Time   Waiting Time   Turnaround Time\n");

    for(int i=0; i<n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
        printf("   P%d\t\t%d\t\t%d\t\t%d\n", p[i], bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time = %.2f\n", (float)total_wt/n);
    printf("Average Turnaround Time = %.2f\n", (float)total_tat/n);

    return 0;
}
