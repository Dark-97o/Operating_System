#include <stdio.h>

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], ct[n], tat[n], wt[n];
    int i;
    printf("Enter Values\n");
    for (i = 0; i < n; i++) {
        printf("Arrival Time P%d: ", i + 1);
        scanf("%d", &at[i]);
        printf("Burst Time P%d:",i+1);
        scanf("%d", &bt[i]);
    }

    // FCFS scheduling
    int time = 0;
    for (i = 0; i < n; i++) {
        if (time < at[i])
            time = at[i];
        ct[i] = time + bt[i];
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        time = ct[i];
    }          
    float tat_avg = 0 , wt_avg = 0;
    for(int i = 0; i < n; i++){
        tat_avg += tat[i];
        wt_avg += wt[i];
    }
    printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }
    printf("\nTurn around time Average:  %.2f \nWaiting Time Average: %.2f" , tat_avg /= n ,  wt_avg /= n);
    return 0;
}
