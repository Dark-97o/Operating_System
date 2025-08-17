#include <stdio.h>

int main() {
    int n, tq, i, time = 0, done = 0;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], rt[n], ct[n], tat[n], wt[n];

    for (i = 0; i < n; i++) {
        printf("Enter Arrival Time of P%d: ", i + 1);
        scanf("%d", &at[i]);
        printf("Enter Burst Time of P%d: ", i + 1);
        scanf("%d", &bt[i]);
        rt[i] = bt[i];  // remaining time = burst time
        ct[i] = tat[i] = wt[i] = 0;
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    while (done < n) {
        int executed = 0;
        for (i = 0; i < n; i++) {
            if (at[i] <= time && rt[i] > 0) {
                executed = 1;
                if (rt[i] > tq) {
                    time += tq;
                    rt[i] -= tq;
                } else {
                    time += rt[i];
                    rt[i] = 0;
                    ct[i] = time;
                    tat[i] = ct[i] - at[i];
                    wt[i] = tat[i] - bt[i];
                    done++;
                }
            }
        }
        if (!executed) time++;  // if no process is ready
    }

    printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");
    float avgTAT = 0, avgWT = 0;
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);
        avgTAT += tat[i];
        avgWT += wt[i];
    }

    printf("\nAverage Turnaround Time = %.2f", avgTAT / n);
    printf("\nAverage Waiting Time = %.2f\n", avgWT / n);

    return 0;
}
