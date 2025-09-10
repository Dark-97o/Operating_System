#include <stdio.h>

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], pr[n], ct[n], tat[n], wt[n], done[n];
    float avg_tat=0, avg_wt=0;

    for(int i=0;i<n;i++) {
        printf("AT BT PR of P%d: ", i+1);
        scanf("%d %d %d",&at[i],&bt[i],&pr[i]);
        done[i]=0;
    }

    int time=0, complete=0;
    while(complete<n) {
        int idx=-1, best=99999;
        for(int i=0;i<n;i++)
            if(!done[i] && at[i]<=time && pr[i]<best)
                best=pr[i], idx=i;

        if(idx==-1) { time++; continue; }

        time+=bt[idx];                  // run process fully
        ct[idx]=time;
        tat[idx]=ct[idx]-at[idx];
        wt[idx]=tat[idx]-bt[idx];
        if(wt[idx]<0) wt[idx]=0;

        avg_tat+=tat[idx];
        avg_wt+=wt[idx];
        done[idx]=1;
        complete++;
    } 

    printf("\nP\tAT\tBT\tPR\tCT\tTAT\tWT\n");
    for(int i=0;i<n;i++)
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               i+1,at[i],bt[i],pr[i],ct[i],tat[i],wt[i]);

    printf("\nAverage TAT = %.2f",avg_tat/n);
    printf("\nAverage WT  = %.2f\n",avg_wt/n);
}
