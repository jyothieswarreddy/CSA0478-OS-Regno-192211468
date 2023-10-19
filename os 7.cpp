#include <stdio.h>
#include <stdlib.h>
// Structure to represent a process
typedef struct {
    int process_id;
    int arrival_time;
    int burst_time;
} Process;
// Function to find the process with the shortest burst time
int findShortestJob(Process processes[], int n) {
    int shortest_time = 10000; // Initialize with a high value
    int selected_process = -1;
    for (int i = 0; i < n; i++) {
        if (processes[i].burst_time < shortest_time && processes[i].burst_time > 0) {
            shortest_time = processes[i].burst_time;
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
        printf("Enter arrival time for process %d: ", i + 1);
        scanf("%d", &processes[i].arrival_time);
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &processes[i].burst_time);
    }
    // Sort processes based on arrival time (if not already sorted)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].arrival_time > processes[j + 1].arrival_time) {
                Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
    int total_time = 0;
    printf("\nGantt Chart:\n");
    for (int i = 0; i < n; i++) {
        int process_index = findShortestJob(processes, n);

        if (process_index == -1) {
            break;
        }
        printf("P%d ", processes[process_index].process_id);
        total_time += processes[process_index].burst_time;
        processes[process_index].burst_time = 0;
    }
    printf("\n\nExecution Order:\n");
    for (int i = 0; i < total_time; i++) {
        printf("%d ", i + 1);
    }
    printf("\n");
    return 0;
}
