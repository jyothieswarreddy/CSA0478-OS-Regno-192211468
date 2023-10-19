#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, j, head, seek_count = 0, cur_track, max_track, direction;
    printf("Enter the number of requests: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the requests: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the initial head position: ");
    scanf("%d", &head);
    printf("Enter the maximum track number: ");
    scanf("%d", &max_track);
    printf("Enter the direction (0 for left, 1 for right): ");
    scanf("%d", &direction);
    printf("C-SCAN Disk Scheduling Algorithm:\n");
    if(direction == 0) {
        for(i = head; i >= 0; i--) {
            for(j = 0; j < n; j++) {
                if(arr[j] == i) {
                    cur_track = arr[j];
                    seek_count += abs(cur_track - head);
                    head = cur_track;
                    printf("%d -> ", cur_track);
                }
            }
        }
        seek_count += head;
        head = max_track;
        for(i = max_track; i >= 0; i--) {
            for(j = 0; j < n; j++) {
                if(arr[j] == i) {
                    cur_track = arr[j];
                    seek_count += abs(cur_track - head);
                    head = cur_track;
                    printf("%d -> ", cur_track);
                }
            }
        }
    }
    else {
        for(i = head; i <= max_track; i++) {
            for(j = 0; j < n; j++) {
                if(arr[j] == i) {
                    cur_track = arr[j];
                    seek_count += abs(cur_track - head);
                    head = cur_track;
                    printf("%d -> ", cur_track);
                }
            }
        }
        seek_count += abs(max_track - head);
        head = 0;
        for(i = 0; i <= head; i++) {
            for(j = 0; j < n; j++) {
                if(arr[j] == i) {
                    cur_track = arr[j];
                    seek_count += abs(cur_track - head);
                    head = cur_track;
                    printf("%d -> ", cur_track);
                }
            }
        }
    }
    printf("NULL\n");
    printf("Total number of seek operations: %d\n", seek_count);
    return 0;
}
