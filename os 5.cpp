#include <stdio.h>
int main(){
    int n, i, j, temp;
    int bt[20], p[20], wt[20], tat[20], pr[20];
    float wtavg, tatavg;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("\nEnter Burst Time and Priority for each process:\n");
    for(i=0;i<n;i++)
    {
        printf("\nProcess[%d]\n", i+1);
        printf("Burst Time: ");
        scanf("%d", &bt[i]);
        printf("Priority: ");
        scanf("%d", &pr[i]);
        p[i] = i+1;
    }
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(pr[i] > pr[j])
            {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;
                temp = pr[i];
                pr[i] = pr[j];
                pr[j] = temp;
            }
        }
    }
    wtavg = wt[0] = 0;
    tatavg = tat[0] = bt[0];
    for(i=1;i<n;i++)
    {
        wt[i] = wt[i-1] + bt[i-1];
        tat[i] = tat[i-1] + bt[i];
        wtavg += wt[i];
        tatavg += tat[i];
    }
    printf("\nProcess\tBurst Time\tPriority\tWaiting Time\tTurnaround Time");
    for(i=0;i<n;i++)
        printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d", p[i], bt[i], pr[i], wt[i], tat[i]);
    printf("\nAverage Waiting Time: %.2f", wtavg/n);
    printf("\nAverage Turnaround Time: %.2f", tatavg/n);
    return 0;
}
