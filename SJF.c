#include <stdio.h>

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], ct[n], tat[n], wt[n], done[n];
    int job_ord[n];
    for (int i = 0; i < n; i++) {
        printf("Arrival Time P%d: ", i + 1);
        scanf("%d", &at[i]);
        printf("Burst Time P%d:",i+1);
        scanf("%d", &bt[i]);
        done[i] = 0;
        job_ord[i] = i + 1;
        printf("----------------------------\n");
    }
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            if(bt[i] > bt[j]){
                int temp = bt[i];
                bt[i] = bt[j]; 
                bt[j] = temp;

                int ord_temp = job_ord[i];
                job_ord[i] = job_ord[j];
                job_ord[j] = ord_temp; 
            }
        }
    }
    float tat_avg = 0 , wt_avg = 0;
    ct[0] = bt[0] + at[0];
    for(int i = 1; i < n; i++){
        ct[i] = ct[ i- 1] + bt[i];
    }

    for(int i = 0; i < n; i++){
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        tat_avg += tat[i];
        wt_avg += wt[i];
    }
    printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if(i + 1 == job_ord[j]){
                printf("P%d\t%d\t%d\t%d\t%d\t%d\n", job_ord[j], at[j], bt[j], ct[j], tat[j], wt[j]);
        
            }
        }
    }
    printf("\nTurn around time Average:  %.2f \nWaiting Time Average: %.2f" , tat_avg /= n ,  wt_avg /= n);

    return 0;
}
