#include <stdio.h>

int main() {
    int n, m, i, j, k;
    int available[10], max[10][10], allocation[10][10], need[10][10];
    int finish[10], work[10], safe[10], count = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the number of resources: ");
    scanf("%d", &m);

    printf("Enter the available resources: ");
    for (i = 0; i < m; i++) {
        scanf("%d", &available[i]);
    }

    printf("Enter the maximum resources required by each process: ");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    printf("Enter the resources currently allocated to each process: ");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &allocation[i][j]);
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    for (i = 0; i < n; i++) {
        finish[i] = 0;
    }

    for (i = 0; i < m; i++) {
        work[i] = available[i];
    }

    while (count < n) {
        int found = 0;
        for (i = 0; i < n; i++) {
            if (finish[i] == 0) {
                int j;
                for (j = 0; j < m; j++) {
                    if (need[i][j] > work[j]) {
                        break;
                    }
                }
                if (j == m) {
                    int k;
                    for (k = 0; k < m; k++) {
                        work[k] += allocation[i][k];
                    }
                    safe[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }
        if (found == 0) {
            printf("System is not in safe state\n");
            return 0;
        }
    }

    printf("System is in safe state\n");
    printf("Safe sequence is: ");
    for (i = 0; i < n; i++) {
        printf("P%d ", safe[i]);
    }
    printf("\n");

    return 0;
}
