#include <stdio.h>

int main() {
    int n;
    float avg_tat = 0, avg_wt = 0;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], rt[n], ct[n], wt[n], tat[n];
    for (int i=0; i<n; i++) {
        printf("Arrival time of P%d: ", i+1);
        scanf("%d", &at[i]);
        printf("Burst time of P%d: ", i+1);
        scanf("%d", &bt[i]);
        rt[i] = bt[i];
    }

    int complete = 0, time = 0;
    while (complete < n) {
        int shortest = -1, minm = 99999;
        for (int j=0; j<n; j++) {
            if (at[j] <= time && rt[j] > 0 && rt[j] < minm) {
                minm = rt[j];
                shortest = j;
            }
        }
        if (shortest == -1) {
            time++;
            continue;
        }
        rt[shortest]--;

        if (rt[shortest] == 0) { 
            complete++;
            ct[shortest] = time + 1;
            wt[shortest] = ct[shortest] - bt[shortest] - at[shortest];
            if (wt[shortest] < 0) wt[shortest] = 0;
        }
        time++;
    }
    printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i=0; i<n; i++) {
        tat[i] = ct[i] - at[i];
        avg_tat += tat[i];
        avg_wt += wt[i];
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i+1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }
    printf("\nAverage Turnaround Time = %.2f", avg_tat/n);
    printf("\nAverage Waiting Time    = %.2f\n", avg_wt/n);
    return 0;
}
