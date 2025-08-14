// fcfs with all processes with 0 arrival time
#include <stdio.h>

int main() {
    int processes[5] = {1, 2, 3, 4, 5};
    int bt[5] = {4, 3, 1, 2, 5};
    int wt[5], tat[5];
    float avg_wt = 0, avg_tat = 0;

    wt[0] = 0;

    for (int i = 1; i < 5; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];

    for (int i = 0; i < 5; i++) {
        tat[i] = wt[i] + bt[i];
    }

    printf("P\tBT\tWT\tTAT\n");
    for (int i = 0; i < 5; i++) {
        printf("%d\t%d\t%d\t%d\n", processes[i], bt[i], wt[i], tat[i]);
        avg_wt += wt[i];
        avg_tat += tat[i];
    }
    printf("\nAverage WT = %.2f", avg_wt / 5);
    printf("\nAverage TAT = %.2f\n", avg_tat / 5);
    return 0;
}
