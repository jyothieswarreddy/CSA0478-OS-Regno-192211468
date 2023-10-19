#include <stdio.h>
int main() {
    int i, n, time_quantum, remaining_time, flag = 0, time = 0, wait_time = 0, turnaround_time = 0;
    int at[10], bt[10], rt[10];
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the time quantum: ");
    scanf("%d", &time_quantum);
    for(i=0;i<n;i++)
    {
        printf("Enter arrival time and burst time for process %d: ", i+1);
        scanf("%d %d", &at[i], &bt[i]);
        rt[i] = bt[i];
    }
    printf("\nGantt Chart:\n");
    while(1)
    {
        flag = 0;
        for(i=0;i<n;i++)
        {
            if(rt[i] > 0)
            {
                flag = 1;
                if(rt[i] > time_quantum)
                {
                    printf("| P%d |", i+1);
                    time += time_quantum;
                    rt[i] -= time_quantum;
                }
                else
                {
                    printf("| P%d |", i+1);
                    time += rt[i];
                    wait_time += time - at[i] - bt[i];
                    turnaround_time += time - at[i];
                    rt[i] = 0;
                }
            }
        }
        if(flag == 0)
            break;
    }
    printf("\n\nAverage Waiting Time: %.2f", (float)wait_time/n);
    printf("\nAverage Turnaround Time: %.2f", (float)turnaround_time/n);
    return 0;
}
