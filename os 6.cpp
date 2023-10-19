#include <stdio.h>
#include <stdlib.h>
// Structure to represent a process
typedef struct {
    int process_id;
    int priority;
    int burst_time;
    int remaining_time;
} Process;
// Function to find the process with the highest priority
int findHighestPriorityProcess(Process processes[], int n) {
    int highest_priority = 10000; // Initialize with a high value
    int selected_process = -1;

    for (int i = 0; i < n; i++) {
        if (processes[i].remaining_time > 0 && processes[i].priority < highest_priority) {
            highest_priority = processes[i].priority;
            selected_process = i;
        }
    }
    return selected_process;
}
int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    Process processes[n];
    for (int i = 0; i < n; i++) {
        processes[i].process_id = i + 1;
        printf("Enter priority for process %d: ", i + 1);
        scanf("%d", &processes[i].priority);
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &processes[i].burst_time);
        processes[i].remaining_time = processes[i].burst_time;
    }
    int total_time = 0;
    printf("\nGantt Chart:\n");
    while (1) {
        int process_index = findHighestPriorityProcess(processes, n);
        if (process_index == -1) {
            // All processes are executed
            break;
        }
        printf("P%d ", processes[process_index].process_id);
        processes[process_index].remaining_time--;
        if (processes[process_index].remaining_time == 0) {
            n--;
        }
        total_time++;
    }
    printf("\n\nExecution Order:\n");
    for (int i = 0; i < total_time; i++) {
        printf("%d ", i + 1);
    }
    printf("\n");
    return 0;
}
