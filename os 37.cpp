#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, head, seek_count = 0, cur_track, distance;
    printf("Enter the number of requests: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the requests: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the initial head position: ");
    scanf("%d", &head);
    printf("FCFS Disk Scheduling Algorithm:\n");
    for(i = 0; i < n; i++) {
        cur_track = arr[i];
        distance = abs(head - cur_track);
        seek_count += distance;
        head = cur_track;
        printf("%d -> ", cur_track);
    }
    printf("NULL\n");
    printf("Total number of seek operations: %d\n", seek_count);
    return 0;
}
