#include <stdio.h>
#include <limits.h>

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], rt[n], ct[n], wt[n], tat[n];
    for(int i=0; i<n; i++) {
        printf("Arrival time of P%d: ", i+1);
        scanf("%d", &at[i]);
        printf("Burst time of P%d: ", i+1);
        scanf("%d", &bt[i]);
        rt[i] = bt[i];
    }

    int complete = 0, time = 0, shortest, minm = INT_MAX, finish_time;
    int check = 0;
    while (complete != n) {
        for (int j=0; j<n; j++) {
            if ((at[j] <= time) && (rt[j] < minm) && rt[j] > 0) {
                minm = rt[j];
                shortest = j;
                check = 1;
            }
        }

        if (check == 0) { time++; continue; }
        rt[shortest]--; // run process 1 unit
        minm = rt[shortest];
        if (minm == 0) minm = INT_MAX;

        if (rt[shortest] == 0) {
            complete++;
            check = 0;
            finish_time = time + 1;
            ct[shortest] = finish_time;
            wt[shortest] = finish_time - bt[shortest] - at[shortest];
            if (wt[shortest] < 0) wt[shortest] = 0;
        }
        time++;
    }

    printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i=0; i<n; i++) {
        tat[i] = ct[i] - at[i];
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i+1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }
    int avg_tat = avg_tat/n;
    int avg_wt = avg_wt/n;
    printf("\nAverage Turnaround Time = %.2f", avg_tat);
    printf("\nAverage Waiting Time    = %.2f\n", avg_wt);
}
