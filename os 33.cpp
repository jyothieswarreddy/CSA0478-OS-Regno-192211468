#include <stdio.h>

int main() {
    int incomingStream[] = {4, 1, 2, 4, 5};
    int pageFaults = 0;
    int frames = 3;
    int m, n, s, pages;
    pages = sizeof(incomingStream)/sizeof(incomingStream[0]);
    printf("Incoming \t Frame 1 \t Frame 2 \t Frame 3\n");
    int temp[frames];
    for(m = 0; m < frames; m++) {
        temp[m] = -1;
    }
    for(m = 0; m < pages; m++) {
        s = 0;
        for(n = 0; n < frames; n++) {
            if(temp[n] == incomingStream[m]) {
                s++;
                pageFaults--;
            }
        }
        pageFaults++;
        if((pageFaults <= frames) && (s == 0)) {
            temp[m] = incomingStream[m];
        }
        else if(s == 0) {
            int farthestPage = -1;
            int farthestDistance = -1;
            for(n = 0; n < frames; n++) {
                int k;
                for(k = m + 1; k < pages; k++) {
                    if(temp[n] == incomingStream[k]) {
                        if(k > farthestDistance) {
                            farthestDistance = k;
                            farthestPage = n;
                            break;
                        }
                    }
                }
                if(k == pages) {
                    farthestPage = n;
                    break;
                }
            }
            temp[farthestPage] = incomingStream[m];
        }
        printf("%d\t\t", incomingStream[m]);
        for(n = 0; n < frames; n++) {
            printf("%d\t\t", temp[n]);
        }
        printf("\n");
    }
    printf("Total Page Faults: %d", pageFaults);
    return 0;
}
