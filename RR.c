#include <stdio.h>

int main() {
    int n, tq;
    float tat_avg = 0, wt_avg = 0;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], rt[n], ct[n], wt[n], tat[n];
    for (int i=0; i<n; i++) {
        printf("Arrival & Burst time of P%d: ", i+1);
        scanf("%d %d", &at[i], &bt[i]);
        rt[i] = bt[i];
    }
    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    int time = 0, complete = 0, done;
    while (complete < n) {
        done = 1;
        for (int i=0; i<n; i++) {
            if (rt[i] > 0 && at[i] <= time) {
                done = 0;
                if (rt[i] > tq) {
                    time += tq;
                    rt[i] -= tq;
                } else {
                    time += rt[i];
                    ct[i] = time;
                    wt[i] = ct[i] - bt[i] - at[i];
                    if (wt[i] < 0) wt[i] = 0;
                    rt[i] = 0;
                    complete++;
                    wt_avg = wt_avg +  wt[i];
                }
            }
            
        }
        if (done) time++;
    }

    printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i=0; i<n; i++) {
        tat[i] = ct[i] - at[i];
        tat_avg = tat_avg + tat[i];
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i+1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }
    printf("\nAverage Turnaround Time = %.2f", tat_avg/n);
    printf("\nAverage Waiting Time    = %.2f\n", wt_avg/n);

}



